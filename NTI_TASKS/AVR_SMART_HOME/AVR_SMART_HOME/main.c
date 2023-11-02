#include <avr/io.h>
#include <util/delay.h>

#include "Port.h"
#include "Dio.h"
#include "LCD_interface.h"
#include "KEYPAD.h"
#include "Timer1.h"
#include "SPI.h"


u8 value = 0;
u8 password[4] = {0};
u8 password_re[4] = {0};

u8 State = 0 ; 


SPI_st_T spi1master=
{
	.CLK_phase=SPI_CLOCK_SAMPLE_LEADING,
	.CLK_polarity=SPI_CLOCK_IDEL_HIGH,
	.dataorder=SPI_LSB_FIRST_CFG,
	.freq_cfg=SPI_FOSC_DIV_128,
	.mode_s=SPI_MASTER_MODE,
	.SPI_interrupt_cfg=SPI_INT_DIS_CFG
};




int main(void)
{

	Port_vidInit();
	LCD_vidInit();
	Servo_Init();
	spi_INT(&spi1master);

	_delay_ms(10000);
	LCD_vidWriteString("ENTER PASSWORD:");
	LCD_vidSendCommand(0x0C); // Turn off cursor

	_delay_ms(10000);
	LCD_vidSendCommand(0x01);

	char asterisk = '*';
	u8 incorrectAttempts = 0;

for (u8 i = 0; i < 4; i++)
{
	do
	{
		value = GET_KEY_PRESSED();
	} while (value == NOT_PRESSED);

	LCD_vidWriteCharctr(asterisk);
	password[i] = value;
	value = 0;
}

	while (1) 
	{
		
	switch (State)
	{
		case 0 : 
		        spi_transmit(&spi1master,'C');

		break; 
		
		case 1 :
				spi_transmit(&spi1master,'A');

		break ; 
		
		case 2:
		      	spi_transmit(&spi1master,'B');

		break ; 
		 
	}
		while (incorrectAttempts < 3)
		{
			State = 0 ; 
			_delay_ms(1000);
			LCD_vidSendCommand(0x01);

			LCD_vidWriteString(" ENTER KEY");
			LCD_voidGotToXY(1,0) ; 
            LCD_vidWriteString(" To Unlock");
			
			_delay_ms(1000);
			LCD_vidSendCommand(0x01);

			for (u8 i = 0; i < 4; i++)
			{
				do
				{
					value = GET_KEY_PRESSED();
				} while (value == NOT_PRESSED);

				LCD_vidWriteCharctr(asterisk);
				password_re[i] = value;
				value = 0;

				if (i == 3)
				{
					LCD_vidSendCommand(0x01);
					break;
				}
			}

			u8 correct = 1;

			for (u8 i = 0; i < 4; i++)
			{
				if (password_re[i] != password[i])
				{
					correct = 0;
					break;
				}
			}

			if (correct)
			{
				_delay_ms(100);
				LCD_vidWriteString(" Welcome");
				_delay_ms(200);
				LCD_vidSendCommand(0x01);

				LCD_vidWriteString(" DOOR OPEN");
				Servo_SetDegree(90);
				State = 1 ; 
				_delay_ms(1000);
				LCD_vidSendCommand(0x01);
				_delay_ms(2000);
				LCD_vidWriteString(" DOOR CLOSED");
				_delay_ms(2000);
				Servo_SetDegree(0);
				
				break;
			}
			else
			{
				LCD_vidWriteString(" Wrong PASSWORD");
				_delay_ms(1000);
				LCD_vidSendCommand(0x01);
				incorrectAttempts++;
			}
		}

		if (incorrectAttempts >= 3)
		{
			LCD_vidWriteString(" Cheating");
			_delay_ms(3000); 
			State = 2 ; 
		
		}
		
	}


}
