/*
 * SERVO_MOTOR.h
 *
 * Created: 10/31/2023 10:07:42 AM
 *  Author: Mahmoud Tariq
 */ 


#ifndef SERVO_MOTOR_H_
#define SERVO_MOTOR_H_


typedef enum{
	SERVO_MOTOR_STATUS_FAILED,
	SERVO_MOTOR_STATUS_OK,
	SERVO_MOTOR_ANGLE_VAL_ERR
	}enu_Servo_Motor_Status_t;

enu_Servo_Motor_Status_t SERVO_MOTOR_vidSetAngle(u8 copy_u8Angle);


#endif /* SERVO_MOTOR_H_ */