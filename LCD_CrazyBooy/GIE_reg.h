#ifndef _GIE_REG_H
#define _GIE_REG_H

#define SREG *((volatile u8 *)0x5F)

#define I 7 /* Global Interrupt Enable 		  */
#define T 6 /* Bit Copy Storage				  */
#define H 5 /* Half Carry Flag                */
#define S 4 /* Sign Flag 					  */
#define V 3 /* Two's Complement Overflow Flag */
#define N 2 /* Negative Flag 				  */
#define Z 1 /* Zero Flag 					  */
#define C 0 /* Carry Flag 					  */

#endif /* _GIE_REG_H */