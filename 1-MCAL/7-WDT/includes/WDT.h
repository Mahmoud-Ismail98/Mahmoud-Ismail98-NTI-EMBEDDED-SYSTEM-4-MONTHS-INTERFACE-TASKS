/*****************************************************************************/
/*****************************************************************************/
/**********************    Author : Mohamed Aburehab    **********************/
/**********************    Layer  : MCAL                **********************/
/**********************    SWD    : WDT                **********************/
/**********************    Version: 1.0                 **********************/
/*****************************************************************************/
/*****************************************************************************/
#ifndef WDT_H
#define WDT_H
 
#define SLEEP_TIME_16_3_MS		0
#define SLEEP_TIME_32_5_MS		1
#define SLEEP_TIME_65_MS		2
#define SLEEP_TIME_0_13_S		3
#define SLEEP_TIME_0_26_S		4
#define SLEEP_TIME_0_52_S		5
#define SLEEP_TIME_1_0_S		6
#define SLEEP_TIME_2_1_S		7

void WDT_voidEnable(void);

void WDT_voidDisable(void);

void WDT_voidSleep(u8 Copy_u8SleepTime);

#endif
