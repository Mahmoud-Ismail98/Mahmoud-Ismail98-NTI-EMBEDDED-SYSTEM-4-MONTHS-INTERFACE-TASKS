

#ifndef SYSTICK_PRV_H
#define SYSTICK_PRV_H


#define PRIVATE_PERIPHERAL_BASE         0xE0000000
#define SYSTICK_BASE_ADDRESS            0xE000E010
																        
																        
																        
#define STK_CTRL                        0x00
#define STK_LOAD                        0x04
#define STK_VAL                         0x08
#define STK_CALIB                       0x0C

#define STK_REG(OFFSET)                   (*(vu32*)(SYSTICK_BASE_ADDRESS+OFFSET))



#define COUNTFLAG                       16
#define CLKSOURCE                       2
#define TICKINT                         1
#define ENABLE                          0


#define SYSTICK_AHB_DIV_8               8
#define SYSTICK_AHB_PROCESSOR           1


#define SYSTICK_INT_DISABLE              0
#define SYSTICK_INT_ENABLE               1



#define MAX_REG_TICKS                    16777215


#define TOMICROCONV                      1000


void SysTick_Handler(void);


#endif



