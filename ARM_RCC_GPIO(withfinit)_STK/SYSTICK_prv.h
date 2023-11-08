#ifndef  SYSTICK_PRV_H
#define  SYSTICK_PRV_H

 #define    STK_BASE_ADRESS        0xE000E010
 typedef struct{

	volatile u32 CTRL ;
	volatile u32 LOAD ;
	volatile u32 VAL ;
	volatile u32 CALIB;

}SYSTICK_T;


#define MSTK ((volatile SYSTICK_T*)STK_BASE_ADRESS)
#endif 