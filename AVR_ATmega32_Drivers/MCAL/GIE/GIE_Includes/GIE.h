/*
 * GIE.h
 *
 * Created: 10/22/2023 3:14:08 PM
 *  Author: Mohamed Alaa
 */ 


#ifndef GIE_H_		
#define GIE_H_		
#include <Services/Std_types.h>
#include <Services/Bit_utils.h>

// mapping to SREG register
#define SREG_REG	(*(volatile Puint8)0x5F)

typedef enum
{
	GIE_NO_Error,
	GIE_Inavlid_Input,
}GIE_Error_state;

#define GIE_Enabled		1
#define GIE_Disabled	0	

#define Global_Interrupt_Bit	7

#define GIE_Enable()	SET_BIT(SREG_REG, Global_Interrupt_Bit);
#define GIE_Disable()	CLR_BIT(SREG_REG, Global_Interrupt_Bit);

void GIE_Init(void);



#endif /* GIE_H_ */