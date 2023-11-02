/*
 * Counter_7SEG_CFG.h
 *
 * Created: 10/21/2023 9:26:11 AM
 *  Author: computer store
 */ 


#ifndef SEVEN_SEG_CFG_H_
#define SEVEN_SEG_CFG_H_

#include <MCAL/PORT/PORT_Includes/Port.h>

#define Seven_SEG1_EN_PORT			PORTA_ADD
#define Seven_SEG2_EN_PORT			PORTA_ADD
#define Seven_SEG3_EN_PORT			PORTB_ADD
#define Seven_SEG4_EN_PORT			PORTB_ADD		
		
#define Seven_SEG1_EN_PIN			PORT_PIN3
#define Seven_SEG2_EN_PIN			PORT_PIN2		
#define Seven_SEG3_EN_PIN			PORT_PIN5		
#define Seven_SEG4_EN_PIN			PORT_PIN6		
		
#define Seven_SEGx_Data0_PORT		PORTB_ADD
#define Seven_SEGx_Data1_PORT		PORTB_ADD
#define Seven_SEGx_Data2_PORT		PORTB_ADD
#define Seven_SEGx_Data3_PORT		PORTB_ADD
		
#define Seven_SEGx_Data0_PIN		PORT_PIN0
#define Seven_SEGx_Data1_PIN		PORT_PIN1
#define Seven_SEGx_Data2_PIN		PORT_PIN2
#define Seven_SEGx_Data3_PIN		PORT_PIN4


#endif /* COUNTER_7SEG_CFG_H_ */