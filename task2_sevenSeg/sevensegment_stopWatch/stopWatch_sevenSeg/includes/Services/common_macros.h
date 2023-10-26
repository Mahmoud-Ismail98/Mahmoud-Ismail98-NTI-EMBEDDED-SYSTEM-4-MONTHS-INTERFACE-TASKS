/*
 * common_macros.c
 *
 *  Created on: Oct 15, 2023
 *      Author: Ahmed Dwidar
 */

#ifndef common_macros
#define common_macros

/* set bit  */
#define SET_BIT(REG,BIT)        ( REG |= (1<<BIT) )

/* clear bit  */
#define CLEAR_BIT(REG,BIT)      ( REG &= ~(1<<BIT) )

/* toggle bit*/
#define TOGGLE_BIT(REG,BIT)     ( REG ^=(1<<BIT) )

/* clear or set a whole register */
#define SET_REG(REG)            (REG = 1)
#define CLEAR_REG(REG)          (REG = 0)

#define ASSIGN_BITS(REG,VALUE)     ( REG |= VALUE )  //  value 0-3

#define ASSIGN_SECOND_TWO_BITS(REG,VALUE)    (REG = ( (REG | VALUE)<<2 ) )  //  value 0-3

#define ASSIGN_THIRD_TWO_BITS(REG,VALUE)     (REG = ( (REG | VALUE)<<4 ) ) //  value 0-3

#define ASSIGN_FOURTH_TWO_BITS(REG,VALUE)    (REG = ( (REG | VALUE)<<6 ) )  //  value 0-3

/* Rotate right the register value with specific number of rotates */
#define ROR(REG,BIT)            (REG = ((1>>BIT) | ( 8 - (1<<BIT) ) ) )

/* Rotate left the register value with specific number of rotates */
#define ROL(REG,BIT)            (REG = ((1<<BIT) | ( 8 - (1>>BIT) ) ) )

/* assigning register with */
#define ASSIGN_REG(REG,VALUE)   (REG = VALUE)

/* Check if a specific bit is cleared in any register and return true if yes */
#define BIT_IS_CLEAR(REG,BIT) (!(REG & (1<<BIT)))

/* get the value of a bit (1 or 0) */
#define GET_BIT(REG,BIT) ( ( REG & (1<<BIT) ) >> BIT )

/*toggle bit as it is*/
#define TOGGLE_WITHOUT_ASSIGN_BIT(Reg,Bit)         	Reg^(1<<Bit)

#define CONC(B7,B6,B5,B4,B3,B2,B1,B0)			CONC_HELPER(B7,B6,B5,B4,B3,B2,B1,B0)
#define CONC_HELPER(B7,B6,B5,B4,B3,B2,B1,B0)		0b##B7##B6##B5##B4##B3##B2##B1##B0

#endif
