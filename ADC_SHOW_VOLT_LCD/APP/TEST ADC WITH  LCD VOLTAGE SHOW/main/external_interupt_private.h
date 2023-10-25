/*
 * external_interupt_private.h
 *
 * Created: 23/10/2023 11:25:34 م
 *  Author: MAHMOUD ISMAIL
 */ 


#ifndef EXTERNAL_INTERUPT_PRIVATE_H_
#define EXTERNAL_INTERUPT_PRIVATE_H_


#define   MCUCR              (*(volatile u8*) 0x55)
#define   MCUCSR             (*(volatile u8*) 0x54)
#define   GICR               (*(volatile u8*) 0x5B)
#define   GIFR               (*(volatile u8*) 0x5A)



#endif /* EXTERNAL_INTERUPT_PRIVATE_H_ */