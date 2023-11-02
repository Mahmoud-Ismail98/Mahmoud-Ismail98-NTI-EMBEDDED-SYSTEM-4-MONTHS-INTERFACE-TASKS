/*
 * main.c
 *
 * Created: 10/20/2023 12:01:32 PM
 *  Author: Mohamed Alaa
 */ 

#define F_CPU 8000000

#include <MCAL/PORT/PORT_Includes/Port.h>
#include <MCAL/DIO/DIO_Includes/DIO.h>
#include <HAL/LCD/LCD_Includes/LCD.h>
#include <util/delay.h>
#include <HAL/LCD/LCD_Includes/LCD.h>
#include <MCAL/GIE/GIE_Includes/GIE.h>
#include <MCAL/EXTI/EXTI_Includes/EXTI.h>
#include <Services/Std_types.h>
#include <MCAL/ADC/ADC_Includes/ADC.h>
#include <MCAL/Timer/Timer_Includes/Timer.h>
#include <HAL/Keypad/Keypad_Includes/Keypad.h>
#include <MCAL/Watchdog/Watchdog_Includes/Watchdog.h>
#include <HAL/Seven_SEG/Seven_SEG_Includes/Seven_SEG.h>
#include <MCAL/SPI/SPI_Includes/SPI.h>
#include <MCAL/USART/USART_Includes/USART.h>
#include <limits.h>
#include <stdint.h>


#define SPI_master_mode
//#define SPI_slave_mode

void SPI_CallBack(void);
void RecieveComplete(void);

uint8 G_temp[30] = {0};
uint8 G_Index = 0;

USART_cfg_t gl_USART_cfg =
{
	USART_Mode_NormalAsynchronous,
	USART_No_Parity,
	USART_stopBits1,
	USART_DataBits8,
	USART_BAUD_9600,
	PTR_NULL,
	RecieveComplete
};

uint8 spi_data = 0;
uint8 uart_flag = 0;

int main(void)
{
	#ifdef SPI_master_mode
	SPI_CFG_t spi_cfg = {SPI_Master, SPI_Data_Order_LSB, SPI_Prescaler_16, Interrupt_State_Disable, SPI_CallBack};
	#endif
	
	#ifdef SPI_slave_mode
	SPI_CFG_t spi_cfg = {SPI_Slave, SPI_Data_Order_LSB, SPI_Prescaler_16, Interrupt_State_Enable, SPI_CallBack};
	#endif

	PORT_Init();
	LCD_Init();
	GIE_Enable();
	USART_init(&gl_USART_cfg);
	USART_Enable_Interrupt(USART_INT_Rx);
	SPI_Init(&spi_cfg);
	while (1)
	{
		if (uart_flag)
		{
			LCD_GoTO_XY(LCD_Line2, LCD_Col1);
			LCD_Display_String((const Puint8)(const Puint8)"SPI: ");
			#ifdef SPI_master_mode
			while (G_temp[G_Index] != 0)
			{
				SPI_Transfer(&G_temp[G_Index]);	//SPI send and receive
				LCD_Display_Character(G_temp[G_Index]); //display the received data by SPI
				G_Index++;
			}
			#endif
			
			uart_flag = 0;
		}
	}
}

void RecieveComplete(void)
{
	LCD_Clear();
	uart_flag = 1;
	G_Index = 0;
	for (uint8 Cnt = 0; G_temp[Cnt] ; ++Cnt)
	{
		G_temp[Cnt] = 0;
	}
	//receive string by interrupt
	USART_RecieveString(G_temp);
	LCD_Display_String((const Puint8)"UART: ");
	LCD_Display_String((const Puint8)G_temp);
	
}

void SPI_CallBack(void)
{
	SPI_Transfer(&G_temp[G_Index]);
	LCD_Display_Character(G_temp[G_Index]);
	G_Index++;
}

