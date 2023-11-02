/*
 * app.h
 *
 * Created: 11/1/2023 7:05:35 PM
 *  Author: sharb
 */ 


#ifndef APP_H_
#define APP_H_

#include "std_types.h"
#include "../../MCAL/DIO/includes/Dio.h"
#define F_CPU 1000000UL




#define START_SWITCH      DIO_PORTA_PIN5
#define PAUSE_SWITCH      DIO_PORTA_PIN6
#define CLR_SWITCH        DIO_PORTA_PIN7


#define CLR_COUNT         0
#define START_COUNT       1
#define PAUSE_COUNT       2


#define MILLI_SEC        1
#define COUNTER_MAX      250
#define DISPLAY_MAX      9


void app_init(void); //init modules
void app_start(void); // start app logic
void calcTime(void);  // check on timer



#endif /* APP_H_ */