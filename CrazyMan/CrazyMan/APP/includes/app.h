/*
 * app.h
 *
 * Created: 11/1/2023 7:05:35 PM
 *  Author: sharb
 */ 


#ifndef APP_H_
#define APP_H_

#define F_CPU 1000000UL
#define MAN_INDEX       1

void app_init(void);
void app_start(void);

void welcomeScreen(void);
void Screen_one(void);
void Screen_two(void);
void Screen_three(void);
void Screen_four(void);
void GameOver(void);



#endif /* APP_H_ */