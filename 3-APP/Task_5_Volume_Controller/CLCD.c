/*****************************************************************************/
/*****************************************************************************/
/**********************    Author : Mohamed Aburehab    **********************/
/**********************    Layer  : HAL                 **********************/
/**********************    SWD    : CLCD                **********************/
/**********************    Version: 1.0                 **********************/
/*****************************************************************************/
/*****************************************************************************/
#include "Std_types.h"
#include "Bit_utils.h"
#include <util/delay.h>

#include "DIO.h"

#include "CLCD.h"
#include "CLCD_prv.h"
#include "CLCD_cfg.h"

void CLCD_VidInit(void){
    /* wait for more than 30ms */ 
    _delay_ms(50);

    /* display clear */
    CLCD_VidSendCommand(0x00);
    _delay_ms(5);
    CLCD_VidSendCommand(0x01);
    _delay_ms(5);

#if CLCD_MODE == CLCD_MODE_8BIT
    /* function set */
    CLCD_VidSendCommand(0x38);
    _delay_ms(1);

    /* display on or off */
    CLCD_VidSendCommand(0x0C);
    _delay_ms(1);

    /* display clear */
    CLCD_VidSendCommand(0x01);
    _delay_ms(2);

    /* entry mode */
    CLCD_VidSendCommand(0x06);
    _delay_ms(2);

#elif CLCD_MODE == CLCD_MODE_4BIT


    /* function set */
    CLCD_VidSendCommand(0x02);
    _delay_ms(3);
    CLCD_VidSendCommand(0x02);
    _delay_ms(3);
    CLCD_VidSendCommand(0x08);

    _delay_ms(5);

    /* display on or off */
    CLCD_VidSendCommand(0x00);
    _delay_ms(3);
    CLCD_VidSendCommand(0x0C);

    _delay_ms(3);

    /* display clear */
    CLCD_VidSendCommand(0x00);
    _delay_ms(5);
    CLCD_VidSendCommand(0x01);
    _delay_ms(5);

    /* entry mode */
    CLCD_VidSendCommand(0x00);
    _delay_ms(5);
    CLCD_VidSendCommand(0x06);
    _delay_ms(5);

#endif

    /* display clear */
    CLCD_VidSendCommand(0x00);
    _delay_ms(5);
    CLCD_VidSendCommand(0x01);
    _delay_ms(5);


}

void CLCD_VidSendCommand(u8 Copy_u8Command){
    /* setting RS pin to low for command */ 
    DIO_enuWriteChannel(CLCD_CONTROL_PIN_RS, DIO_CHANNEL_LEVEL_LOW);
    /* setting RW pin to low for write */
    DIO_enuWriteChannel(CLCD_CONTROL_PIN_RW, DIO_CHANNEL_LEVEL_LOW);

    #if CLCD_MODE == CLCD_MODE_8BIT

    CLCD_prvSend8bData(Copy_u8Command);
    CLCD_prvSendEnablePulse();

    #elif CLCD_MODE == CLCD_MODE_4BIT

    CLCD_prvSend4bData(Copy_u8Command);
    CLCD_prvSendEnablePulse();

    #endif


}




void CLCD_VidDisplayCharacter(u8 Copy_u8Command){
    /* setting RS pin to High for data */
    DIO_enuWriteChannel(CLCD_CONTROL_PIN_RS, DIO_CHANNEL_LEVEL_HIGH);
    /* setting RW pin to low for write */
    DIO_enuWriteChannel(CLCD_CONTROL_PIN_RW, DIO_CHANNEL_LEVEL_LOW);


    #if CLCD_MODE == CLCD_MODE_8BIT

    CLCD_prvSend8bData(Copy_u8Command);
    CLCD_prvSendEnablePulse();

    #elif CLCD_MODE == CLCD_MODE_4BIT

    CLCD_prvSend4bData(Copy_u8Command >> 4);
    CLCD_prvSendEnablePulse();

    _delay_ms(1);
    CLCD_prvSend4bData(Copy_u8Command);
    CLCD_prvSendEnablePulse();

    #endif
    _delay_ms(1);

}

void CLCD_VidCreatCustomCharacter(u8 Add_pu8CustomCharacter[8], u8 index){
    CLCD_VidSendCommand((64 + index*8) >> 4);
    _delay_ms(1);
    CLCD_VidSendCommand((64+index*8));
    _delay_ms(1);
    for(u8 Local_u8Iterator = 0; Local_u8Iterator <8; Local_u8Iterator++){
    	CLCD_VidDisplayCharacter(Add_pu8CustomCharacter[Local_u8Iterator]);
    	_delay_ms(1);
    }
    _delay_ms(1);
    CLCD_VidSendCommand(0x80>>4);
    _delay_ms(1);
    CLCD_VidSendCommand(0x80);
    _delay_ms(1);

}

void CLCD_VidGoToXY(u8 Copy_u8Row, u8 Copy_u8Column){
	u8 command = 0x80 ;
	switch(Copy_u8Row){
	case 0 : command += 0x00 + Copy_u8Column ;break;
	case 1 : command += 0x40 + Copy_u8Column ;break;
	case 2 : command += 0x14 + Copy_u8Column ;break;
	case 3 : command += 0x54 + Copy_u8Column ;break;
	}

	CLCD_VidSendCommand( command >> 4);
	_delay_ms(5);
	CLCD_VidSendCommand(command);
	_delay_ms(5);
}

void CLCD_VidDisplayString(pu8 Add_u8String){

    u8 local_u8Iterator = 0;
    while ( Add_u8String[local_u8Iterator] != '\0'){
        CLCD_VidDisplayCharacter(Add_u8String[local_u8Iterator]);
        local_u8Iterator ++;
    }
    

}

void CLCD_VidDisplayNumber(u64 Copy_u64Number){
	u64 local_u8numberInReverse = 1;
	if (Copy_u64Number == 0){
		CLCD_VidDisplayCharacter( 0x30 + 0);
	}else {
		while (Copy_u64Number != 0) {
			local_u8numberInReverse *= 10  ;
			local_u8numberInReverse += (Copy_u64Number % 10);
			Copy_u64Number /= 10;
		}
		while (local_u8numberInReverse != 1) {
			CLCD_VidDisplayCharacter( 0x30 + (local_u8numberInReverse % 10));
			local_u8numberInReverse /= 10;
		}
	}

}

#if CLCD_MODE == CLCD_MODE_8BIT

static void CLCD_prvSend8bData(u8 Copy_u8Command){
    DIO_enuWriteChannel(CLCD_DATA_PIN_0, GET_BIT(Copy_u8Command, GET_BIT(Copy_u8Command, 7)));
    DIO_enuWriteChannel(CLCD_DATA_PIN_1, GET_BIT(Copy_u8Command, GET_BIT(Copy_u8Command, 6)));
    DIO_enuWriteChannel(CLCD_DATA_PIN_2, GET_BIT(Copy_u8Command, GET_BIT(Copy_u8Command, 5)));
    DIO_enuWriteChannel(CLCD_DATA_PIN_3, GET_BIT(Copy_u8Command, GET_BIT(Copy_u8Command, 4)));
    DIO_enuWriteChannel(CLCD_DATA_PIN_4, GET_BIT(Copy_u8Command, GET_BIT(Copy_u8Command, 3)));
    DIO_enuWriteChannel(CLCD_DATA_PIN_5, GET_BIT(Copy_u8Command, GET_BIT(Copy_u8Command, 2)));
    DIO_enuWriteChannel(CLCD_DATA_PIN_6, GET_BIT(Copy_u8Command, GET_BIT(Copy_u8Command, 1)));
    DIO_enuWriteChannel(CLCD_DATA_PIN_7, GET_BIT(Copy_u8Command, GET_BIT(Copy_u8Command, 0)));
}
#elif CLCD_MODE == CLCD_MODE_4BIT

static void CLCD_prvSend4bData(u8 Copy_u8Command){
    DIO_enuWriteChannel(CLCD_DATA_PIN_4, GET_BIT(Copy_u8Command, 0));
    DIO_enuWriteChannel(CLCD_DATA_PIN_5, GET_BIT(Copy_u8Command, 1));
    DIO_enuWriteChannel(CLCD_DATA_PIN_6, GET_BIT(Copy_u8Command, 2));
    DIO_enuWriteChannel(CLCD_DATA_PIN_7, GET_BIT(Copy_u8Command, 3));
    
}

#endif

static void CLCD_prvSendEnablePulse(){
    DIO_enuWriteChannel(CLCD_CONTROL_PIN_EN, DIO_CHANNEL_LEVEL_HIGH);
    _delay_us(2);
    DIO_enuWriteChannel(CLCD_CONTROL_PIN_EN, DIO_CHANNEL_LEVEL_LOW);
}
