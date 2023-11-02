/*
 * 7_seg_cfg.h
 *
 *  Created on: Oct 21, 2023
 *      Author: Ahmed Dwidar
 */

#ifndef HAL_SEVENSEG_CFG_H_
#define HAL_SEVENSEG_CFG_H_

#include<avr/io.h>
/*list of numbers for the user to display*/

/*
SEVENSEG_ZERO        (0x7E)
SEVENSEG_ONE         (0x0C)
SEVENSEG_TWO         (0xA6)
SEVENSEG_THREE       (0x9E)
SEVENSEG_FOUR        (0xCC)
SEVENSEG_FIVE        (0xDA)
SEVENSEG_SIX         (0xFA)
SEVENSEG_SEVEN       (0xOE)
SEVENSEG_EIGHT       (0xFE)
SEVENSEG_NINE        (0xCE)
 */

/*list of ports to choose*/
/*
PORTA
PORTB
PORTC
PORTD
 */
#define SEVENSEG_PORT         PORTC
#define DISPLAY_PORT          PORTA
/*list of ports to choose*/
/*
PORTA
PORTB
PORTC
PORTD
 */
#define DECODER_USE           TRUE

#endif /* HAL_SEVENSEG_CFG_H_ */
