/**************************************************************************/
/* Filename						: main.c                                  */
/* Author  	    				: Muhammad Ammar                          */
/* Date 						: 23 Oct 2023  	           	 	      	  */
/* Version 	 					: V01                                     */
/* MicroController  			: AVR 								  	  */
/* Trainee At		  			: NTI 								  	  */
/* Instructor		  			: Mahmoud Embabi 					  	  */
/**************************************************************************/



#include "../SERIVICES/include/STD_TYPES.h"
#include "../SERIVICES/include/BIT_UTILS.h"
#include "../SERIVICES/include/calculation_functions.h"
#include "../SERIVICES/include/MAGIC_NUMBERS.h"
#include "../MCAL/PORT/include/PORT.h"
#include "../MCAL/DIO/include/DIO.h"

#include <util/delay.h>
#include  "../HAL/include/LCD/LCD.h"
#include  "../HAL/include/LCD/LCD_config.h"

#include  "../HAL/include/KEYPAD/KEYPAD_config.h"
#include  "../HAL/include/KEYPAD/KEYPAD.h"
#include "../MCAL/GIE/include/GIE.h"
#include "../MCAL/EXTI/include/EXTI.h"
#include  "../HAL/include/BUTTON/BUTTON.h"
#include  "../HAL/include/SEVEN_SEGMENT/SEVEN_SEGMENT.h"
#include "../MCAL/ADC/include/ADC.h"
#include "../MCAL/TIMER0/include/TIMER0.h"
#include "../MCAL/TIMER1/include/TIMER1.h"
#include "../MCAL/TIMER2/include/TIMER2.h"
#include "../MCAL/WTD/include/WDT.h"
#include  "../HAL/include/ICUSW/ICUSW.h"
#include  "../MCAL/USART/include/USART.h"
#include  "../MCAL/SPI/include/SPI_config.h"
#include  "../MCAL/SPI/include/SPI.h"




////////////////////////////////////////////////////////////////////////////////////////

extern Lcd_4bitType Lcd;
//////////////////////////////////////////////////////////////////////////////////////

Spi_ConfigType Spi ={
		.select_clk_speed = SPI_SELECT_CLK_FREQ_DIV_128,
		.select_data_ording = SPI_SELECT_DATA_LSB_FIRST,
		.select_master_or_slave = SPI_SELECT_MASTER_MODE,
		.select_phase = SPI_SELECT_PHASE_SETUP_WRITE_FIRST_AT_LEADING_EDGE,
		.select_polarity = SPI_SELECT_POLARITY_IDLE_LOW_LEADING_EDGE_RISING
};

int main(void){

	Port_voidInit();
	u8 Data;
	Spi_enuInit(&Spi);
	Lcd_4bit_enuInit(&Lcd);





	u8 arr[]="Node2: Data is Sent";
	int i = 0;
	while(arr[i]){
		Spi_enuTransmitBlocking(SLAVE_SS1, arr[i++], &Data);
		Lcd_4bit_enuDisplayCharacter(&Lcd, Data);
		if(Data == 'l'){
			Dio_enuWriteChannel(DIO_PINC0_CHANNEL16, DIO_HIGH);
		}
	}
	while(1){



	}
	return 0;
}

