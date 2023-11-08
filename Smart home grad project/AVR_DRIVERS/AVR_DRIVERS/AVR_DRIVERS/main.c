/*
 * AVR_DRIVERS.c
 *
 * Created: 10/20/2023 8:33:11 PM
 * Author : ahmed radwan
 */

#include "SERVICES/Standard_Data_Types.h"
#include <util/delay.h>
#include "SERVICES/Bit_Wise_Operations.h"
#include "MCAL/PORT/PORT.h"
#include "MCAL/DIO/DIO.h"
#include "HAL/BUTTON/BUTTON.h"
#include "HAL/7_SEGMENT/7_SEGMENT.h"
#include "HAL/LCD/LCD_COMANDS.h"
#include "HAL/LCD/LCD.h"
#include "MCAL/GIE/GIE.h"
#include "MCAL/EXTI/EXTI.h"
#include "MCAL/TIMER0/TIMER0.h"
#include "HAL/KEY_PAD/KEY_PAD.h"
#include "MCAL/watch_DOG_TIMER/watch_dog.h"
#include "MCAL/ICUSW/ICUSW.h"
#include "MCAL/USART/USART.h"
#include "MCAL/SPI/Inc/SPI.h"
#include "MCAL/SPI/Inc/SPI_PRIV.h"

void Start_display(void);
void Room_display(void);
void Room1_fn(void);
void Room2_fn(void);
void Room3_fn(void);

LCD_4BIT_ST lcd = {.lcd_pins[0] = PIN_B0_ID_8,
				   .lcd_pins[1] = PIN_B1_ID_9,
				   .lcd_pins[2] = PIN_B2_ID_10,
				   .lcd_pins[3] = PIN_B3_ID_11,
				   .lcd_pin_rs = PIN_A3_ID_3,
				   .lcd_pin_e = PIN_A2_ID_2};
 SPI_st_T spi1slave={
	  .CLK_phase=SPI_CLOCK_SAMPLE_LEADING,
	  .CLK_polarity=SPI_CLOCK_IDEL_HIGH,
	  .dataorder=SPI_LSB_FIRST_CFG,
	  .freq_cfg=SPI_FOSC_DIV_128,
	  .mode_s=SPI_SLAVE_MODE,
	  .SPI_interrupt_cfg=SPI_INT_EN_CFG
  };
SPI_st_T spi1master={
	   .CLK_phase=SPI_CLOCK_SAMPLE_LEADING,
	   .CLK_polarity=SPI_CLOCK_IDEL_HIGH,
	   .dataorder=SPI_LSB_FIRST_CFG,
	   .freq_cfg=SPI_FOSC_DIV_128,
	   .mode_s=SPI_MASTER_MODE,
	   .SPI_interrupt_cfg=SPI_INT_DIS_CFG
  };
  u8 Main_state='9';
  u8 USART_state=0;
  u8 USART_Roomstate=0;
  u8 isr_int0_flag=0;
  u8 alarmstate=0;
  u8 closestate=0;
  

void EXTI0_ISR (void);

int main(void)
{
	Port_vidInit();
	LCD_vidInit_4bit(&lcd);
	GIE_INIT();
	USART_INT();
	spi_INT(&spi1slave);
	spi_Recive_ASYNC(&Main_state);
	EXI_INT(EXTI_INT0,EXTI_MODE_FALING_EDGE,EXTI0_ISR);
	//USART_vidRECIVE_Blokind(&USART_state);
	//LCD_vidDisplayChar_4bit(&lcd,Main_state);
	while (1)
	{
		if(0==isr_int0_flag)
		{
			switch (Main_state)
			{
				case'A'://open state
					Start_display();
					USART_vidRECIVE_Blokind(&USART_state);
					if(USART_state!=0)
					{
						switch(USART_state)
						{
						 case '1':
							Room1_fn();
							break;
						 case '2':
							Room2_fn();
							 break;
						 case '3':
							Room3_fn();
							 break;
						 default:
						 
						  break;
						}
						USART_state=0;
					}
					
				  break;
				case 'B'://alarm state
				    if(alarmstate==0)
					{
						LCD_vidDisplayString_4bit(&lcd,"alarm state");
						Dio_enuWriteChannel (DIO_D6_ID_30,DIO_PIN_HIGH);
						alarmstate=1;
					}
					break;
				case 'C':// close the home "ideal state"
				    if(closestate==0)
					{
						LCD_vidDisplayString_4bit(&lcd,"close state");
						closestate=1;
					}
					break;
			}
		}
	}
	return 0;
}

//LCD_vidDisplayString_4bit(&lcd,);
//LCD_vidGotoXY_4bit(&lcd,);

void Start_display(void)
{
	LCD_vidSendcommand_4bit(&lcd,LCD_CLEAR_DISPLAY);
	LCD_vidDisplayString_4bit(&lcd," Welcome to the home ");
	_delay_ms(300);
	LCD_vidSendcommand_4bit(&lcd,LCD_CLEAR_DISPLAY);
	LCD_vidGotoXY_4bit(&lcd,1,0);
	LCD_vidDisplayString_4bit(&lcd," CHOSE Room: ");
	LCD_vidGotoXY_4bit(&lcd,2,0);
	LCD_vidDisplayString_4bit(&lcd,"1)Room1: ");
	LCD_vidGotoXY_4bit(&lcd,3,0);
	LCD_vidDisplayString_4bit(&lcd,"2)Room2: ");
	LCD_vidGotoXY_4bit(&lcd,4,0);
	LCD_vidDisplayString_4bit(&lcd,"3)Room3: ");
}
void Room_display(void)
{
		LCD_vidSendcommand_4bit(&lcd,LCD_CLEAR_DISPLAY);
		LCD_vidGotoXY_4bit(&lcd,1,0);
		LCD_vidDisplayString_4bit(&lcd," CHOSE option: ");
		LCD_vidGotoXY_4bit(&lcd,2,0);
		LCD_vidDisplayString_4bit(&lcd,"1)light: ");
		LCD_vidGotoXY_4bit(&lcd,3,0);
		LCD_vidDisplayString_4bit(&lcd,"2)AiR cond: ");
}
void Room1_fn(void)
{
	Room_display();
	USART_vidRECIVE_Blokind(&USART_Roomstate);
	LCD_vidSendcommand_4bit(&lcd,LCD_CLEAR_DISPLAY);
	LCD_vidGotoXY_4bit(&lcd,1,0);
	if(USART_Roomstate=='1')
	{
	 Dio_enuFlipChannel(DIO_C2_ID_18);
	 LCD_vidDisplayString_4bit(&lcd,"air cond done ");
	 _delay_ms(200);
	
	}
	else if(USART_Roomstate=='2')
	{
	 Dio_enuFlipChannel(DIO_C3_ID_19);
	 LCD_vidDisplayString_4bit(&lcd,"light done ");
	 _delay_ms(200);
	}
	else
	{
		LCD_vidDisplayString_4bit(&lcd,"wrong choise ");
		_delay_ms(200);
	}
	USART_Roomstate=0;
}
void Room2_fn(void)
{
	Room_display();
	USART_vidRECIVE_Blokind(&USART_Roomstate);
	LCD_vidSendcommand_4bit(&lcd,LCD_CLEAR_DISPLAY);
	LCD_vidGotoXY_4bit(&lcd,1,0);
	if(USART_Roomstate=='1')
	{
		Dio_enuFlipChannel(DIO_C4_ID_20);
		LCD_vidDisplayString_4bit(&lcd,"air cond done ");
		_delay_ms(200);
		
	}
	else if(USART_Roomstate=='2')
	{
		Dio_enuFlipChannel(DIO_C5_ID_21);
		LCD_vidDisplayString_4bit(&lcd,"light done ");
		_delay_ms(200);
	}
	USART_Roomstate=0;
}
void Room3_fn(void)
{
	Room_display();
	USART_vidRECIVE_Blokind(&USART_Roomstate);
	LCD_vidSendcommand_4bit(&lcd,LCD_CLEAR_DISPLAY);
	LCD_vidGotoXY_4bit(&lcd,1,0);
	if(USART_Roomstate=='1')
	{
		Dio_enuFlipChannel(DIO_C6_ID_22);
		LCD_vidDisplayString_4bit(&lcd,"air cond done ");
		_delay_ms(200);
		
	}
	else if(USART_Roomstate=='2')
	{
		Dio_enuFlipChannel(DIO_C7_ID_23);
		LCD_vidDisplayString_4bit(&lcd,"light done ");
		_delay_ms(200);
	}
	USART_Roomstate=0;
}
void EXTI0_ISR (void)
{
		LCD_vidSendcommand_4bit(&lcd,LCD_CLEAR_DISPLAY);
		LCD_vidGotoXY_4bit(&lcd,1,0);

		Dio_enuWriteChannel (DIO_C2_ID_18,DIO_PIN_LOW);
		Dio_enuWriteChannel (DIO_C3_ID_19,DIO_PIN_LOW);
		Dio_enuWriteChannel (DIO_C4_ID_20,DIO_PIN_LOW);
		Dio_enuWriteChannel (DIO_C5_ID_21,DIO_PIN_LOW);
		Dio_enuWriteChannel (DIO_C6_ID_22,DIO_PIN_LOW);
		Dio_enuWriteChannel (DIO_C7_ID_23,DIO_PIN_LOW);
		if(0==isr_int0_flag)
		{
			Dio_enuWriteChannel (DIO_D5_ID_29,DIO_PIN_HIGH);
			Dio_enuWriteChannel (DIO_D6_ID_30,DIO_PIN_HIGH);
			isr_int0_flag=1;
		}
		else
		{
			Dio_enuWriteChannel (DIO_D5_ID_29,DIO_PIN_LOW);
			Dio_enuWriteChannel (DIO_D6_ID_30,DIO_PIN_LOW);
			isr_int0_flag=0;
		}
		
}