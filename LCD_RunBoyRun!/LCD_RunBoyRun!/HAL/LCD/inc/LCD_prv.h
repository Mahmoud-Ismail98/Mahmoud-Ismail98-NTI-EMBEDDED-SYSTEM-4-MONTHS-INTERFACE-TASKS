/*
 * LCD_prv.h
 *
 * Created: 10/21/2023 9:29:51 AM
 *  Author: Ahmed Wael
 */


#ifndef LCD_PRV_H_
#define LCD_PRV_H_

/*
?
u8 customChar[] = {
	0b00000,
	0b00010,
	0b00111,
	0b00100,
	0b11111,
	0b00000,
	0b00000,
	0b00000

	?
	u8 customChar[] = {
		0b00100,
		0b00000,
		0b00100,
		0b00100,
		0b00111,
		0b01000,
		0b10000,
		0b00000
	};
	?
	u8 customChar[] = {
		0b00000,
		0b10010,
		0b00000,
		0b11110,
		0b10010,
		0b11110,
		0b00000,
		0b00000
	};
};*/

/* Init Commands */
#define LCD_FunctionSetCommand 0x28
#define LCD_DisplayOnOffCommand 0x0C
#define LCD_DisplayClearCommand 0x01
#define LCD_EntryModeCommand 0x06



#endif /* LCD_PRV_H_ */