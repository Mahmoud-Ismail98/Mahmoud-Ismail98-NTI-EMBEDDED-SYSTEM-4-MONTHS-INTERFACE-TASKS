/*
 * LM35.h
 *
 * Created: 10/30/2023 5:34:27 PM
 *  Author: Mahmoud Tariq
 */ 


#ifndef LM35_H_
#define LM35_H_



void lm35_VidInit(void);
u16 lm35_u16Read(u8 copy_u8ADC_Channel,pu16 add_pu16_lm35_val);


#endif /* LM35_H_ */