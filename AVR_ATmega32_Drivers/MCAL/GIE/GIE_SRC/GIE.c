/*
 * GIE.c
 *
 * Created: 10/22/2023 3:15:18 PM
 *  Author: Mohamed Alaa
 */ 

#include <MCAL/GIE/GIE_Includes/GIE_CFG.h>
#include <MCAL/GIE/GIE_Includes/GIE.h>
#include <MCAL/GIE/GIE_Includes/GIE_Private.h>
#include <Services/Bit_utils.h>



void GIE_Init(void)
{
	SET_BIT(SREG_REG, Global_Interrupt_Bit);
}

