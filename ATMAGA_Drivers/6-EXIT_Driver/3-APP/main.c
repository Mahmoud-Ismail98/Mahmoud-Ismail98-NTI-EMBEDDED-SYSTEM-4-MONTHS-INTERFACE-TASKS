/*
 * main.c
 *
 *  Created on: Oct 28, 2023
 *      Author: Online
 */
#include "../4-SERVICS/Std_types.h"
#include "../4-SERVICS/Bit_utils.h"
#include"../1-MCAL/1-PORT/include/Port.h"
#include "../1-MCAL/2-DIO/include/DIO.h"
#include "../1-MCAL/4-GIE/Include/GIE.h"
#include "../1-MCAL/5-EXIT/include/EXIT_Prv.h"
#include "../1-MCAL/5-EXIT/include/EXIT_Cfg.h"
#include"../1-MCAL/5-EXIT/include/EXIT.h"
#include "util/delay.h"
void INT0_ISR(void);

int main (){
Port_VoidInit();
Port_enuSetPinMode(PIN26,PORT_u8Intput_Pullup);
EXTI_voidInt0Init();
EXTI_voidInt0SetCallBack(&INT0_ISR);
GIE_VidInit();

while (1)
{

}
}
void INT0_ISR(void){
	Dio_enuWritechannal(DIO_Channal1,DIO_HIGH);
}
