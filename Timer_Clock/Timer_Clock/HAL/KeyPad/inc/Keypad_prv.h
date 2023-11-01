/*
 * KeyPad_prv.h
 *
 * Created: 10/22/2023 9:29:51 AM
 *  Author: Ahmed Wael
 */ 


#ifndef KEYPAD_PRV_H_
#define KEYPAD_PRV_H_


u8 KeyPad_u8SymbolArr [4][4] = 
{
	{'7', '8', '9', '/'},
	{'4', '5', '6', '*'},
	{'1', '2', '3', '-'},
	{'.', '0', '=', '+'}
};

#define KeyPad_Pattern_1 0b00000111   //0x07
#define KeyPad_Pattern_2 0b00001011
#define KeyPad_Pattern_3 0b00001101
#define KeyPad_Pattern_4 0b00001110


#endif /* KEYPAD_P RV_H_ */