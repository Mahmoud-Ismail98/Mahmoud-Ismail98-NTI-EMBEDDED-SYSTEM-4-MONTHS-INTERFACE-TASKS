/*
 * AVR_DRIVERS.c
 *
 * Created: 10/20/2023 8:33:11 PM
 * Author : ahmed radwan
 */ 
#define F_CPU 16000000UL
#include <util/delay.h>
#include "SERVICES/Standard_Data_Types.h"
#include "SERVICES/Bit_Wise_Operations.h"
#include "MCAL/PORT/PORT.h"
#include "MCAL/DIO/DIO.h"
#include "HAL/BUTTON/BUTTON.h"
#include "HAL/7_SEGMENT/7_SEGMENT.h"
#include "HAL/LCD/LCD.h"
#include "MCAL/GIE/GIE.h"

#define DELAY_POV_VAL 15
void SevenSegment_Swaper(void);

u8 display_value1=0;
u8 display_value2=0;
u8 display_value3=0;
u8 display_value4=0;
Button_tst count_plus={.button_pin_id=DIO_D7_ID_31,.conection=BUTTON_PULL_UP};
Button_tst count_minus={.button_pin_id=DIO_D6_ID_30,.conection=BUTTON_PULL_UP};
Button_tst reset={.button_pin_id=DIO_D5_ID_29,.conection=BUTTON_PULL_UP};Button_tenuState	count_plus_state=BUTTON_NOT_PRESSED;Button_tenuState	count_minus_state=BUTTON_NOT_PRESSED;Button_tenuState	reset_state=BUTTON_NOT_PRESSED;
SevenSegment_tst display1={.Segment_PIN1=DIO_B0_ID_8,
	.Segment_PIN2=DIO_B1_ID_9,
	.Segment_PIN3=DIO_B2_ID_10,
.Segment_PIN4=DIO_B4_ID_12};
SevenSegment4pins_tst active_pins={.Segment1_active=DIO_A3_ID_3,
	.Segment2_active=DIO_A2_ID_2,
	.Segment3_active=DIO_B5_ID_13,
.Segment4_active=DIO_B6_ID_14};u32 counter=0;
int main(void)
{
	Port_vidInit();
	Button_enuInit(&count_plus);
	Button_enuInit(&count_minus);
	Button_enuInit(&reset);
	SevenSegment_INIT(&display1);
	while (1)
	{
		SevenSegment_Swaper();
		Button_enuRead(&count_plus,&count_plus_state);
		Button_enuRead(&count_minus,&count_minus_state);
		Button_enuRead(&reset,&reset_state);
		if(reset_state==BUTTON_PRESSED||counter>=9999)
		{
			counter=0;
			
			display_value1=counter%10;
			display_value2=(counter/10)%10;
			display_value3=(counter/100)%10;
			display_value4=(counter/1000)%10;
		}
		else if(count_minus_state==BUTTON_PRESSED&&counter!=0)
		{
			counter--;
			display_value1=counter%10;
			display_value2=(counter/10)%10;
			display_value3=(counter/100)%10;
			display_value4=(counter/1000)%10;
			SevenSegment_Swaper();
			_delay_ms(50);
		}
		else if(count_plus_state==BUTTON_PRESSED)
		{
			counter++;
			display_value1=counter%10;
			display_value2=(counter/10)%10;
			display_value3=(counter/100)%10;
			display_value4=(counter/1000)%10;
			SevenSegment_Swaper();
			_delay_ms(50);
			
		}
		
	}
}

void SevenSegment_Swaper(void){
	Dio_enuWriteChannel(active_pins.Segment2_active,1);
	Dio_enuWriteChannel(active_pins.Segment3_active,1);
	Dio_enuWriteChannel(active_pins.Segment4_active,1);    SevenSegment_write(&display1,display_value1);
	Dio_enuWriteChannel(active_pins.Segment1_active,0);
	_delay_ms(DELAY_POV_VAL);
	Dio_enuWriteChannel(active_pins.Segment1_active,1);
	Dio_enuWriteChannel(active_pins.Segment3_active,1);
	Dio_enuWriteChannel(active_pins.Segment4_active,1);	SevenSegment_write(&display1,display_value2);	Dio_enuWriteChannel(active_pins.Segment2_active,0);
	_delay_ms(DELAY_POV_VAL);
	Dio_enuWriteChannel(active_pins.Segment4_active,1);
	Dio_enuWriteChannel(active_pins.Segment1_active,1);
	Dio_enuWriteChannel(active_pins.Segment2_active,1);	SevenSegment_write(&display1,display_value3);
	Dio_enuWriteChannel(active_pins.Segment3_active,0);
	_delay_ms(DELAY_POV_VAL);
	Dio_enuWriteChannel(active_pins.Segment1_active,1);
	Dio_enuWriteChannel(active_pins.Segment2_active,1);
	Dio_enuWriteChannel(active_pins.Segment3_active,1);	SevenSegment_write(&display1,display_value4);
	Dio_enuWriteChannel(active_pins.Segment4_active,0);
	_delay_ms(DELAY_POV_VAL);
}