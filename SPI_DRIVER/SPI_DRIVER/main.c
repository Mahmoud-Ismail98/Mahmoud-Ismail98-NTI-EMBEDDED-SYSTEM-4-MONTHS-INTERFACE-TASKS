/*
 * SPI_DRIVER.c
 *
 * Created: 10/28/2023 10:57:50 PM
 * Author : Sharpel
 */ 


#include "std_types.h"
#include "MCAL/SPI/includes/spi.h"
#include "HAL/LCD/includes/Lcd.h"
#include "MCAL/UART/includes/UART.h"
#define F_CPU   8000000UL
#include "util/delay.h"


void MASTER(void);
u8 charTest[250]="";
int main(void)
{
   MASTER();
}
USART_cfg_t gl_USART_cfg =
{
	USART_Mode_NormalAsynchronous,
	USART_No_Parity,
	USART_stopBits1,
	USART_DataBits8,
	USART_BAUD_9600,
	PTR_NULL,
};
void MASTER(void)
{
	u8 loc_temp   = 0x0F;
	u8 locReading = 0;
	USART_init(&gl_USART_cfg);
	SPI_enum_Init(SPI_MASTER);
	_delay_ms(1000);
	while (1)
	{
		_delay_ms(10);
		if (locReading == 0)
		{
			USART_RecieveString(charTest);
			if (SPI_enum_TrancieveChar(loc_temp)==loc_temp);
			loc_temp =0;
			locReading = 1 ;
			_delay_ms(5);
		}
		else if(locReading == 1)
		{
			SPI_enum_TrancieveChar(charTest[loc_temp++]);
			if(charTest[loc_temp] == STR_NULL)
			locReading = 0;
			loc_temp = 0x0F;
		}
		

	}
}



