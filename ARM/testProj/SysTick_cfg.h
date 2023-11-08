#ifndef SYSTICK_CFG_H
#define SYSTICK_CFG_H




/*
   we can update Freq of Cpu During Run Time By using 
*/

#define F_CPU                  16000000UL

/*
  Clock Source Options
	
	1- SYSTICK_AHB_DIV_8
	2- SYSTICK_AHB_PROCESSOR
*/

#define SYSTICK_CLKSOURCE       SYSTICK_AHB_DIV_8



/*
  Clock Source Options
	
	1- SYSTICK_INT_DISABLE
	2- SYSTICK_INT_ENABLE
*/

#define SYSTICK_TICKINT       SYSTICK_INT_ENABLE






#endif