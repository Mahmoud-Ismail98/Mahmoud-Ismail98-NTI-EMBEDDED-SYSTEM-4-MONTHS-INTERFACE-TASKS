/*
 * MTIMER2_Interface.h
 *
 *  Created on: Dec 8, 2022
 *      Author: Ismail
 */

#ifndef MCAL_TIMER2_TIMER2_INTERFACE_H_
#define MCAL_TIMER2_TIMER2_INTERFACE_H_
#include"../../../Services/Bit_utils.h"
#include"../../../Services/Std_types.h"
#include"../../../MCAL/PORT/includes/PORT.h"
#include"../../../MCAL/GIE/includes/GIE.h"
#include "../includes/TIMER2_Config.h"
#include "../includes/TIMER2_Private.h"




void Timer2Init();

void Timer2SetTimer(u32 Local_u32_DesiredTime);

void Timer2Start();

void Timer2Stop();

void PWM2Init();

void PWM2SetDutyCycle(u8 Local_u8_DesiredDutyCycle);

void PWM2Start();

void PWM2Stop();

void Timer2SetCallBack (void (*Local_void_ptr) (void));


#endif /* MCAL_TIMER2_TIMER2_INTERFACE_H_ */
