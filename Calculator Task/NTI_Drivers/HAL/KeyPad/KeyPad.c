/*
 * KeyPad.c
 *
 *  Created on: Oct 22, 2023
 *      Author: Ismail
 */

#include"../../MCAL/DIO/DIO.h"
#include"../../MCAL/PORT/PORT.h"
#include <util/delay.h>
#include "KeyPad_cfg.h"
#include"KeyPad_prv.h"
#include "KeyPad.h"


#define r1 SBIT(PORTC, 0)
#define r2 SBIT(PORTC, 1)
#define r3 SBIT(PORTC, 2)
#define r4 SBIT(PORTC, 3)
#define c1 SBIT(PINC, 4)
#define c2 SBIT(PINC, 5)
#define c3 SBIT(PINC, 6)
#define c4 SBIT(PINC, 7)

void KeyPadInit(void){

	/*Set Columns Pins Direction Output*/
	Port_enuSetPinDirection(27,PORT_u8OUTPUT);
	Port_enuSetPinDirection(28,PORT_u8OUTPUT);
	Port_enuSetPinDirection(29,PORT_u8OUTPUT);
	Port_enuSetPinDirection(30,PORT_u8OUTPUT);

		/*Set Row Pins Direction Input*/
	Port_enuSetPinDirection(18,PORT_u8INPUT);
	Port_enuSetPinDirection(19,PORT_u8INPUT);
	Port_enuSetPinDirection(20,PORT_u8INPUT);
	Port_enuSetPinDirection(21,PORT_u8INPUT);

		/*Activate Pull up Resistor */
	Port_enuSetPinMode(18,PORT_u8INPUT_PULLUP);
	Port_enuSetPinMode(19,PORT_u8INPUT_PULLUP);
	Port_enuSetPinMode(20,PORT_u8INPUT_PULLUP);
	Port_enuSetPinMode(21,PORT_u8INPUT_PULLUP);
	/*DEACTIVATE COULMNS*/
	Dio_enuWriteChannel(27,DIO_u8LEVEL_HIGH);
	Dio_enuWriteChannel(28,DIO_u8LEVEL_HIGH);
	Dio_enuWriteChannel(29,DIO_u8LEVEL_HIGH);
	Dio_enuWriteChannel(30,DIO_u8LEVEL_HIGH);

}
void KeyPad_GetPressedButton(u8 *u8PtrToPressedButton){

	 u8 Local_ColCount, Local_RowCount;
	    u8 rowVal;
	    u8 flag = 0;
	    if (u8PtrToPressedButton != NULL)
	    {
	        for (Local_ColCount = 0; Local_ColCount < KEYPADSIZE; Local_ColCount++)
	        {
	            //activate current column
	        	Dio_enuWriteChannel((u8ColArr[Local_ColCount]), DIO_u8LEVEL_LOW);
	            for (Local_RowCount = 0; Local_RowCount < KEYPADSIZE; Local_RowCount++)
	            {
	                //check row value if it is 0 then this column and row is connected
	            	Dio_enuReadChannel((u8RowArr[Local_RowCount]), &rowVal);
	                if (rowVal == 0)
	                {
	                    flag = 1;
	                    break;
	                }
	            }
	            //if the inner row loop has broken and flag is set,
	            //place value in return pointer and exit outer column loop.
	            if (flag == 1)
	            {
	                *u8PtrToPressedButton = KeyPadSwitchValues[Local_ColCount][Local_RowCount];
	                break;
	            }
	            //deactivate current column.
	            Dio_enuWriteChannel(u8ColArr[Local_ColCount], DIO_u8LEVEL_HIGH);
	        }

	    }




}



u8 keypressed(void)
  {

   DDRC=0b00001111;
   PORTC=0b11110000;

   while (1)
    {
     r1=0;     r2=1;     r3=1;     r4=1;
     _delay_us(50);
     if (c1==0){while (c1==0);return ('7');}
     if(c2==0){while (c2==0); return ('8');}
     if (c3==0){while (c3==0); return ('9');}
     if(c4==0){while (c4==0);return ('/');}

     r1=1;     r2=0;     r3=1;     r4=1;
     _delay_us(50);
     if (c1==0){while (c1==0); return ('4');}
     if(c2==0){while (c2==0); return ('5');}
     if(c3==0){while (c3==0); return ('6');}
     if(c4==0){while (c4==0); return ('*');}

     r1=1;     r2=1;     r3=0;     r4=1;
     _delay_us(50);
     if (c1==0){while (c1==0); return ('1');}
     if (c2==0){while (c2==0); return ('2');}
     if (c3==0){while (c3==0); return ('3');}
     if (c4==0){while (c4==0); return ('-');}

     r1=1;     r2=1;     r3=1;     r4=0;
     _delay_us(50);
     if (c1==0){while (c1==0); return ('C');}
     if (c2==0){while (c2==0); return ('0');}
     if (c3==0){while (c3==0); return ('=');}
     if (c4==0){while (c4==0); return ('+');}
     }

  }
