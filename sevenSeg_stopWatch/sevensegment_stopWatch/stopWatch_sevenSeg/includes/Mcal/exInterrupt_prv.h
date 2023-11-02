/*
 * exInterrupt_prv.h
 *
 *  Created on: Oct 22, 2023
 *      Author: Ahmed Dwidar
 */

#ifndef MCAL_EXINTERRUPT_PRV_H_
#define MCAL_EXINTERRUPT_PRV_H_


#define EX_INT1_PIN        PORT_PIN26_ID
#define EX_INT2_PIN        PORT_PIN27_ID
#define EX_INT3_PIN        PORT_PIN28_ID

#define GICR            ( *( (volatile u8*)0x5B) )
#define GIFR            ( *( (volatile u8*)0x5A) )
#define MCUCR           ( *( (volatile u8*)0x55) )
#define MCUCSR          ( *( (volatile u8*)0x54) )


#endif /* MCAL_EXINTERRUPT_PRV_H_ */
