/*
 * LM35.c
 *
 * Created: 10/30/2023 5:34:41 PM
 *  Author: Mahmoud Tariq
 */ 
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "CLCK.h"

#include "ADC.h"

#include "LM35.h"

void lm35_VidInit(void)
{
	ADC_vidInit();
}
u16 lm35_u16Read(u8 copy_u8ADC_Channel,pu16 add_pu16_lm35_val)
{
	ADC_ReadChannel(copy_u8ADC_Channel,add_pu16_lm35_val);
	return ( (*add_pu16_lm35_val)*0.5)-1;

}