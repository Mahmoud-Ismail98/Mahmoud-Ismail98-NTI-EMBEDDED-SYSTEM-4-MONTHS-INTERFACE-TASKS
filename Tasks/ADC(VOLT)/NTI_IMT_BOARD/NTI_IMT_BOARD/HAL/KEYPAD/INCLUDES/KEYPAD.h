/*
 * KEYPAD.h
 *
 * Created: 11/2/2023 3:21:51 PM
 *  Author: Mahmoud Tariq
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_


#define r0 PORTC_PIN5
#define r1 PORTC_PIN4
#define r2 PORTC_PIN3
#define r3 PORTC_PIN2

#define c0 PORTD_PIN7
#define c1 PORTD_PIN6
#define c2 PORTD_PIN5
#define c3 PORTD_PIN4

void KeyPad_vidInit(void);
u8 KEYPAD_u8GetKey(void);



#endif /* KEYPAD_H_ */