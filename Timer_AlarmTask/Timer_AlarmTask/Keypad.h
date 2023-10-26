/*
 * KeyPad.h
 *
 * Created: 10/22/2023 9:29:51 AM
 *  Author: Ahmed Wael
 */


#ifndef KEYPAD_H_
#define KEYPAD_H_



/*
KeyPad_voidGetButton(pu8 Add_u8Button);

Description:
			This function polls on each Button and return the value of pressed button as a character in Add_u8Button
*/
void KeyPad_voidGetButton(pu8 Add_u8Button);



/*
KeyPad_voidGetNumber(pu16 Add_u16Num);

Description:
			This function takes a number from Keypad,Press ON/C to after entering number, This Stuck in While Loop till ON/C is Pressed.
*/
void KeyPad_voidGetNumber(pu16 Add_u16Num);  //




#endif /* KEYPAD_H_ */