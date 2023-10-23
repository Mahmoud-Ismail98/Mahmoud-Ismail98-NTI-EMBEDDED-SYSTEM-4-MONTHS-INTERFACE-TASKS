/*
 * KeyPad.c
 *
 *  Created on: Oct 22, 2023
 *      Author: Ismail
 */
#include "KeyPad.h"
#include <util/delay.h>
void KeyPad_Init(){
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
	        	Dio_enuWriteChannel(u8ColArr[Local_ColCount], DIO_u8LEVEL_LOW);
	            for (Local_RowCount = 0; Local_RowCount < KEYPADSIZE; Local_RowCount++)
	            {
	                //check row value if it is 0 then this column and row is connected
	            	Dio_enuReadChannel(u8RowArr[Local_RowCount], &rowVal);
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
	                *u8PtrToPressedButton = KeyPad_SwitchValues[Local_ColCount][Local_RowCount];
	                break;
	            }
	            //deactivate current column.
	            Dio_enuWriteChannel(u8ColArr[Local_ColCount], DIO_u8LEVEL_HIGH);
	        }

	    }




}
