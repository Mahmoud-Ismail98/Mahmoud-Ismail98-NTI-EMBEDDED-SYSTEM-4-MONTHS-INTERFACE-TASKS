/*
 * app.h
 *
 * Created: 11/1/2023 7:05:35 PM
 *  Author: sharb
 */ 


#ifndef APP_H_
#define APP_H_

#define F_CPU             1000000UL

#define CLR_COUNT         0
#define START_COUNT       1
#define PAUSE_COUNT       2

#define MILLI_SEC         1
#define COUNTER_MAX       250
#define DISPLAY_MAX       9


void app_init(void); // init app
void app_start(void);//start app logic
void calcTime(void); // calculate time
void start_fire(void);// callback for start switch
void pause_fire(void);// callback for pause switch
void clear_fire(void);// callback for clear switch



#endif /* APP_H_ */