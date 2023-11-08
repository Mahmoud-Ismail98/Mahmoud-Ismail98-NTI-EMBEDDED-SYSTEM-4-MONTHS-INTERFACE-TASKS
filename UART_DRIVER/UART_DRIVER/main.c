/*
 * UART_DRIVER.c
 *
 * Created: 10/27/2023 7:28:02 AM
 * Author : sharb
 */ 


#include "std_types.h"
#include "MCAL/PORT/includes/Port.h"
#include "MCAL/GIE/includes/Gie.h"
#include "MCAL/UART/UART_Includes/UART.h"
#include "HAL/LCD/includes/Lcd.h"

void RecieveComplete(void);

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
int main(void)
{
    PORT_voidInit();
	GIE_status(GIE_ENABLE);
	LCD_vidInit();
	USART_init(&gl_USART_cfg);
	USART_Enable_Interrupt(USART_INT_Rx);
  
		
		
	u8 loc_temp[50] = {0};
    while (1) 
    {
// 		USART_RecieveString(loc_temp);
// 		LCD_vidDisplayString(loc_temp);
    }
}

void RecieveComplete(void)
{
	u8 loc_temp[50];
	//recieve character by interrupt
// 	u8 loc_temp;
// 	USART_RecieveChar(&loc_temp);
// 	LCD_vidDisplayCharacter(loc_temp);
	
	//recieve string by interrupt
	USART_Disable_Interrupt(USART_INT_Rx);
	USART_RecieveString(&loc_temp);
	LCD_vidDisplayString(loc_temp);
	USART_TransmitString(&loc_temp);
	USART_Enable_Interrupt(USART_INT_Rx);
	

}