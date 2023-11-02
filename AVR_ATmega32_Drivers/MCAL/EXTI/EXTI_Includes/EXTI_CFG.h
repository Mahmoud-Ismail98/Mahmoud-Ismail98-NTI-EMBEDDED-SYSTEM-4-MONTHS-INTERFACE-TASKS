/*
 * EXTI_CFG.h
 *
 * Created: 10/22/2023 3:42:30 PM
 *  Author: Mohamed Alaa
 */ 


#ifndef EXTI_CFG_H_
#define EXTI_CFG_H_

#include <MCAL/EXTI/EXTI_Includes/EXTI.h>


#define EXTI_INT0_Detect		EXTI_Falling_Edge
#define EXTI_INT1_Detect		EXTI_Falling_Edge
#define EXTI_INT2_Detect		EXTI_Disabled	//can be rising or falling or disabled edge only but must be disabled in eta32 when the LCD is used because it's used in the LCD connections

#define EXTI_INT0_PCallBack		PTR_NULL
#define EXTI_INT1_PCallBack		PTR_NULL
#define EXTI_INT2_PCallBack		PTR_NULL


#endif /* EXTI_CFG_H_ */