/*
 * KEYPAD.h
 *
 * Created: 10/25/2023 6:24:40 PM
 *  Author: HP
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_


#define KEYPAD_NOT_PRESSED        0xff

typedef enum KEYPAD_tenuErorStatus
{
KEYPAD_OK,KEYPAD_NULLPTR
}KEYPAD_tenuErorStatus ;

KEYPAD_tenuErorStatus KEYPAD_u8GetKeyState(pu8 Copy_pu8ReturnedKey);



#endif /* KEYPAD_H_ */