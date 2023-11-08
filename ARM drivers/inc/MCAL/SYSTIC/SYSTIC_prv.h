#ifndef SYSTIC_PRV_H
#define SYSTIC_PRV_H

#include "Std_types.h"

typedef struct
{
	volatile u32 CTRL;
	volatile u32 LOAD;
	volatile u32 VAL;
	volatile u32 CALIB;
}STK_t;
#define STK 	((STK_t *)0xE000E010)


#define AHB		0
#define AHB_8	1
#define	STK_INTenable		2
#define	STK_INTdisable		3
#endif

