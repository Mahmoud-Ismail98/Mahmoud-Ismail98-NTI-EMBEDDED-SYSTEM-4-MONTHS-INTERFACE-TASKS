/*
 * SERVO_MOTOR.c
 *
 * Created: 10/31/2023 10:08:03 AM
 *  Author: Mahmoud Tariq
 */ 

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "CLCK.h"

#include "GPTM.h"

#include "SERVO_MOTOR.h"



enu_Servo_Motor_Status_t SERVO_MOTOR_vidSetAngle(u8 copy_u8Angle)

{	enu_Servo_Motor_Status_t Return_val = SERVO_MOTOR_STATUS_FAILED;
	if(copy_u8Angle>256) Return_val = SERVO_MOTOR_ANGLE_VAL_ERR;
	else{
		GPTM_timer0_setPwm(copy_u8Angle);
	    } 
}