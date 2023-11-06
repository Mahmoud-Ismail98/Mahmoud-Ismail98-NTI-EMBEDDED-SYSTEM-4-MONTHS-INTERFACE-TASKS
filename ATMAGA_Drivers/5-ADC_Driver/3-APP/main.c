/*
 * main.c
 *
 *  Created on: Oct 28, 2023
 *      Author: Online
 */
#include "../4-SERVICS/Std_types.h"
#include "../4-SERVICS/Bit_utils.h"
#include "../1-MCAL/01-DIO/DIO_Int.h"
#include "../1-MCAL/4-GIE/Include/GIE.h"
#include "../1-MCAL/3-ADC/include/ADC_Prv.h"
#include "../1-MCAL/3-ADC/include/ADC_Cfg.h"
#include"../1-MCAL/3-ADC/include/ADC.h"
void ADC_ISR(void);
u8 App_u8Reading;
int main(void)
{
MDIO_VidSetPinValue(Port_A,Pin_0,Pin_Low);
ADC_voidInit();
GIE_VidInit();
	while(1)
	{

		ADC_u8StartConversionAsynch(SingleEnded_ADC0,&App_u8Reading,&ADC_ISR);
	}
}

void ADC_ISR(void){
	MDIO_VidSetPortValue(Port_D,App_u8Reading);

}

