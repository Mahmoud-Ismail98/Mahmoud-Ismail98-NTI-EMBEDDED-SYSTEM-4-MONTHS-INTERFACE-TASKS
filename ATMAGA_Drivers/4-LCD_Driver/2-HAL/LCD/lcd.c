/*
 * LCD.C
 *
 * Created: 10/21/2023 2:19:27 PM
 *  Author: FADY
 */ 
#include "../../4-SERVICS/Bit_utils.h"
#include "../../4-SERVICS/Std_types.h"
#include "../../1-MCAL/1-PORT/include/Port.h"
#include "../../1-MCAL/01-DIO/DIO_Int.h"
#include "../LCD/lcd_prv.h"
#include "../LCD/LCD_cfg.h"
#include "../LCD/LCD.h"
#include "util/delay.h"

void CLCD_VoidInit(void){
/* Wait for more than 30ms*/
_delay_ms(31);
/* Function Set Command 2Lines ,5*8 Size */
CLCD_voidSendCommand(SET_FUNCTION_8BIT_5x8_TwoLine);
_delay_ms(1);
/* Display_On_Off_Control : Display Enable */
CLCD_voidSendCommand(Display_On_Off_Control);
_delay_ms(1);
/* Clear Display */
CLCD_voidSendCommand(Display_clear);
_delay_ms(1);


}
void CLCD_voidSendCommand(u8 Copy_u8Command){
/*Set Rs Pin Low For Command */
MDIO_VidSetPinValue(LCDCTR_PORT,LCD_RS_PIN,Pin_Low);
/* Set R/W Pin Low To Write For Command */
MDIO_VidSetPinValue(LCDCTR_PORT,LCD_RW_PIN,Pin_Low);
/* Set Command To Data Pins */
MDIO_VidSetPortValue(LCDData_PORT,Copy_u8Command);
/* Set EN Pin High To Send Command*/
MDIO_VidSetPinValue(LCDCTR_PORT,LCD_EN_PIN,Pin_High);
_delay_ms(2);
MDIO_VidSetPinValue(LCDCTR_PORT,LCD_EN_PIN,Pin_Low);

}
void CLCD_voidSendData(u8 Copy_u8Data){
	/*Set Rs Pin High For Data */
	MDIO_VidSetPinValue(LCDCTR_PORT,LCD_RS_PIN,Pin_High);
	/* Set R/W Pin Low To Write For Data */
	MDIO_VidSetPinValue(LCDCTR_PORT,LCD_RW_PIN,Pin_Low);
	/* Set Data To Data Pins */
	MDIO_VidSetPortValue(LCDData_PORT,Copy_u8Data);
	/* Set EN Pin High To Send Data*/
	MDIO_VidSetPinValue(LCDCTR_PORT,LCD_EN_PIN,Pin_High);
	_delay_ms(2);
	MDIO_VidSetPinValue(LCDCTR_PORT,LCD_EN_PIN,Pin_Low);

}
void ClCD_voidSendString(const char* Copy_ChString ){
	u8 Iteration =0;
	while (Copy_ChString[Iteration]!='\0')
     {
     CLCD_voidSendData(Copy_ChString[Iteration]);
     Iteration++;
	}
}
void CLCD_voidGoToXY(u8 Copy_u8XPos,u8 Copy_u8YPos){
	u8 Local_u8Adress;
if (Copy_u8XPos == 0){

	Local_u8Adress= Copy_u8YPos;

}
else if (Copy_u8XPos == 1)
{
	/* location At Secand line */
	Local_u8Adress = Copy_u8YPos + CGRAM_Address;
}
CLCD_voidSendCommand(Local_u8Adress + 128);
}
void CLCD_voidCreateSpeacialCharater(u8* Copy_pu8Arr, u8 Copy_u8index,u8 Copy_u8XPos,u8 Copy_u8YPos)
{
	u8 Local_u8CGRAMAdress = 0;
	/* Calculate CGRAM Address  */
	 Local_u8CGRAMAdress = Copy_u8index * 8;
	 /* Send CGRAM Adress command to LCD */
  CLCD_voidSendCommand(Local_u8CGRAMAdress + 64);
for (u8 Local_u8Iterator = 0; Local_u8Iterator < 8;Local_u8Iterator++ )
{
	CLCD_voidSendData(Copy_pu8Arr[Local_u8Iterator]);
}
CLCD_voidGoToXY(Copy_u8XPos,Copy_u8YPos);
CLCD_voidSendData(Copy_u8index);
}

void CLCD_voidClearDisplay(){
	CLCD_voidSendCommand(Display_clear);
}
u8 Global_u8Basyflag = 0;
void CLCD_VidSendNumber(u32 Copy_u32Data){

	if (Copy_u32Data == 0 && Global_u8Basyflag == 0)
	{
		CLCD_voidSendData('0');
	}
	else
	{
		Global_u8Basyflag = 1;
		if (Copy_u32Data!= 0)
			{

			CLCD_VidSendNumber(Copy_u32Data/10);
				CLCD_voidSendData (((Copy_u32Data % 10)+'0'));

			}
	}

	Global_u8Basyflag=0;
}



