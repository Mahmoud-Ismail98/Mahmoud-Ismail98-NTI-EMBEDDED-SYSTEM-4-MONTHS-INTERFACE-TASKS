/*
 * GIE.h
 *
 * Created: 10/22/2023 3:12:09 PM
 *  Author: Mahmoud Tariq
 */ 


#ifndef GIE_H_
#define GIE_H_


#define GI   1
#define Global_Interrupt_Enable  7
#define SREG (*((volatile pu8)0x5F))

void GI_vidInit(void);
void GI_vidClear(void);
void GI_vidSet(void);



#endif /* GIE_H_ */