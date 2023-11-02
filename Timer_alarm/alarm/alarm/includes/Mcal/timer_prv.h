/*
 * timer_prv.h
 *
 *  Created on: Oct 24, 2023
 *      Author: Ahmed Dwidar
 */

#ifndef MCAL_TIMER_PRV_H_
#define MCAL_TIMER_PRV_H_


/*timer0 pins*/
#define TIMER_ZERO_PIN              PORT_PIN8_ID
#define TIMER_ZERO_OC_PIN           PORT_PIN11_ID

/*bits numbers in timer registers*/
#define FOC                         BIT_NU7
#define TOIE                        BIT_NU0
#define OCIE                        BIT_NU1
#define TOV                         BIT_NU0
#define OCF                         BIT_NU1


#endif /* MCAL_TIMER_PRV_H_ */
