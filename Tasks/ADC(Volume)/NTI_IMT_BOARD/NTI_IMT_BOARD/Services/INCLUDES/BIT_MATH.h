/*
 * BIT_MATH.h
 *
 * Created: 10/20/2023 11:58:50 AM
 *  Author: Mahmoud Tariq
 */ 


#ifndef BIT_MATH_H_
#define BIT_MATH_H_


#define SET_BIT(REG,BIT)       REG  |=   (1 <<  BIT)
#define CLR_BIT(REG,BIT)       REG  &=~  (1 <<  BIT)
#define GET_BIT(REG,BIT)       (REG&(1<<BIT)) >>BIT
#define TGL_BIT(REG,BIT)       REG  ^=   (1 <<  BIT)
#define RSHFT_REG(REG,NO)      REG>>NO
#define LSHFT_REG(REG,NO)      REG<<NO
#define ASSIGN_REG(REG,VAL)    REG = VAL

/*Macros for 8 bit registers*/
#define CRSHIFT_REG(REG,NO)       REG>>NO | REG<<(8-NO)
#define CLSHIFT_REG(REG,NO)       REG<<NO | REG>>(8-NO)
#define SWAB_NIB(REG)             REG>>4    | REG<<4

#define SET_REG(REG)								REG = 0xFFU
#define CLR_REG(REG)             REG = 0x00U
#define TGL_REG(REG)             REG^=0xFFU
#define SET_H_NIB(REG)	         REG|=0xF0U
#define SET_L_NIB(REG)	         REG|=(0x0F)
#define CLR_L_NIB(REG)	         REG&=0xF0U
#define CLR_H_NIB(REG)	         REG&=0x0FU
#define TGL_H_NIB(REG)	         REG^=0xF0U
#define TGL_L_NIB(REG)	         REG^=0x0FU

#define ASSIGN_H_NIB(REG,VAL)      REG= (REG&0x0FU) | (VAL  <<4)
#define ASSIGN_L_NIB(REG,VAL)	   REG =(REG & 0xF0) | (VAL)											 //REG= (REG&0xF0U) | ( (VAL<<4)>>4)
//#define GET_H_NIB(REG)	         (REG&0xF0U) >> 4
#define GET_H_NIB(REG)	         (REG&(0xF0U)) >> 4
//#define GET_L_NIB(REG)	         (REG << 4) >> 4
#define GET_L_NIB(REG)           	(REG&(0x0F))
#define TGLWITHOUTASSIGN_BIT(Reg,Bit)         	Reg^(1<<Bit)

//#define Write_Bit(REG,BIT,High_OR_Low)	(REG = High_OR_Low == 1 ?	( REG | (1<<BIT)) : ( REG & ~(1<<BIT)))




#endif /* BIT_MATH_H_ */