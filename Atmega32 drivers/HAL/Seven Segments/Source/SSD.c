/*
 * SSD.c
 *
 * Created: 10/20/2023 10:28:57 PM
 *  Author: Mahmoud Tariq
 */ 

/*Services*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "CLCK.h"
#include "util/delay.h"
/*MCAL INCLUDES*/
#include "DIO.h"

#include "PORT.h"

/*HAL INCLUDES*/
#include "SSD_CFG.h"
#include "SSD.h"





void SSD_vInit4Bit(u8 copy_PinNum)
{   PORT_enuErrorStatus loc_val;
	loc_val = PORT_enuSetPinDirection(SSD_D1,PORT_PIN_OUTPUT);
	loc_val|= PORT_enuSetPinDirection(SSD_D2,PORT_PIN_OUTPUT);
	loc_val|= PORT_enuSetPinDirection(SSD_D3,PORT_PIN_OUTPUT);
	loc_val|= PORT_enuSetPinDirection(SSD_D4,PORT_PIN_OUTPUT);	
	
	loc_val|= PORT_enuSetPinMode(copy_PinNum,OUTPUT_HIGH);
}
void SSD_vDeInit4Bit(u8 copy_PinNum)
{   PORT_enuErrorStatus loc_val;
	
	loc_val|= PORT_enuSetPinMode(copy_PinNum,OUTPUT_LOW);
}

SSD_enuError_Status SSD_enuDisplay4Bit(u8 u8Value)
{	
	SSD_enuError_Status Return_Val = SSD_STATUS_FAILED;
	
	//if(0 == Four_bitMode) Return_Val = SSD_MODE_ERR;
	//else if(u8Value >9) Return_Val = SSD_VALUE_eRR;
	//else{
	switch(u8Value)
	{
		case 0:
		PORT_enuSetPinMode(SSD_D1,OUTPUT_LOW);
		PORT_enuSetPinMode(SSD_D2,OUTPUT_LOW);
		PORT_enuSetPinMode(SSD_D3,OUTPUT_LOW);
		PORT_enuSetPinMode(SSD_D4,OUTPUT_LOW);
		Return_Val = SSD_STATUS_OK;
		break;
		case 1:
		PORT_enuSetPinMode(SSD_D1,OUTPUT_HIGH);
		PORT_enuSetPinMode(SSD_D2,OUTPUT_LOW);
		PORT_enuSetPinMode(SSD_D3,OUTPUT_LOW);
		PORT_enuSetPinMode(SSD_D4,OUTPUT_LOW);
		Return_Val = SSD_STATUS_OK;
		break;
		case 2:
		PORT_enuSetPinMode(SSD_D1,OUTPUT_LOW);
		PORT_enuSetPinMode(SSD_D2,OUTPUT_HIGH);
		PORT_enuSetPinMode(SSD_D3,OUTPUT_LOW);
		PORT_enuSetPinMode(SSD_D4,OUTPUT_LOW);
		Return_Val = SSD_STATUS_OK;
		break;
		case 3:
		PORT_enuSetPinMode(SSD_D1,OUTPUT_HIGH);
		PORT_enuSetPinMode(SSD_D2,OUTPUT_HIGH);
		PORT_enuSetPinMode(SSD_D3,OUTPUT_LOW);
		PORT_enuSetPinMode(SSD_D4,OUTPUT_LOW);
		Return_Val = SSD_STATUS_OK;
		break;
		case 4:
		PORT_enuSetPinMode(SSD_D1,OUTPUT_LOW);
		PORT_enuSetPinMode(SSD_D2,OUTPUT_LOW);
		PORT_enuSetPinMode(SSD_D3,OUTPUT_HIGH);
		PORT_enuSetPinMode(SSD_D4,OUTPUT_LOW);
		Return_Val = SSD_STATUS_OK;
		break;
		case 5:
		PORT_enuSetPinMode(SSD_D1,OUTPUT_HIGH);
		PORT_enuSetPinMode(SSD_D2,OUTPUT_LOW);
		PORT_enuSetPinMode(SSD_D3,OUTPUT_HIGH);
		PORT_enuSetPinMode(SSD_D4,OUTPUT_LOW);
		Return_Val = SSD_STATUS_OK;
		break;
		case 6:
		PORT_enuSetPinMode(SSD_D1,OUTPUT_LOW);
		PORT_enuSetPinMode(SSD_D2,OUTPUT_HIGH);
		PORT_enuSetPinMode(SSD_D3,OUTPUT_HIGH);
		PORT_enuSetPinMode(SSD_D4,OUTPUT_LOW);
		Return_Val = SSD_STATUS_OK;
		break;
		case 7:
		PORT_enuSetPinMode(SSD_D1,OUTPUT_HIGH);
		PORT_enuSetPinMode(SSD_D2,OUTPUT_HIGH);
		PORT_enuSetPinMode(SSD_D3,OUTPUT_HIGH);
		PORT_enuSetPinMode(SSD_D4,OUTPUT_LOW);
		Return_Val = SSD_STATUS_OK;
		break;
		case 8:
		PORT_enuSetPinMode(SSD_D1,OUTPUT_LOW);
		PORT_enuSetPinMode(SSD_D2,OUTPUT_LOW);
		PORT_enuSetPinMode(SSD_D3,OUTPUT_LOW);
		PORT_enuSetPinMode(SSD_D4,OUTPUT_HIGH);
		Return_Val = SSD_STATUS_OK;
		break;
		case 9:
		PORT_enuSetPinMode(SSD_D1,OUTPUT_HIGH);
		PORT_enuSetPinMode(SSD_D2,OUTPUT_LOW);
		PORT_enuSetPinMode(SSD_D3,OUTPUT_LOW);
		PORT_enuSetPinMode(SSD_D4,OUTPUT_HIGH);
		Return_Val = SSD_STATUS_OK;
		break;
		default:break;	
	//}

	}
	return Return_Val;
}

/*

void SSD_Display4Nums(u8 copy_num1 , u8 copy_num2, u8 copy_num3,u8 copy_num4)
{
SSD_vInit4Bit(SSD1_EN);
SSD_vInit4Bit(SSD2_EN);
SSD_vInit4Bit(SSD3_EN);
SSD_vInit4Bit(SSD4_EN);
SSD_enuDisplay4Bit(0);
SSD_vInit4Bit(SSD1_EN);
SSD_vDeInit4Bit(SSD2_EN);
SSD_vDeInit4Bit(SSD3_EN);
SSD_vDeInit4Bit(SSD4_EN);
SSD_enuDisplay4Bit(copy_num4);
_delay_ms(3);
SSD_vDeInit4Bit  (SSD1_EN);
SSD_vInit4Bit    (SSD2_EN);
SSD_vDeInit4Bit  (SSD3_EN);
SSD_vDeInit4Bit  (SSD4_EN);
SSD_enuDisplay4Bit(copy_num3);
_delay_ms(4);
SSD_vDeInit4Bit  (SSD1_EN);
SSD_vDeInit4Bit    (SSD2_EN);
SSD_vInit4Bit  (SSD3_EN);
SSD_vDeInit4Bit  (SSD4_EN);
SSD_enuDisplay4Bit(copy_num2);
_delay_ms(5);
SSD_vDeInit4Bit  (SSD1_EN);
SSD_vDeInit4Bit    (SSD2_EN);
SSD_vDeInit4Bit  (SSD3_EN);
SSD_vInit4Bit  (SSD4_EN);
SSD_enuDisplay4Bit(copy_num1);
_delay_ms(6);
}*/

void SSD_Display2Nums(u8 copy_num1 , u8 copy_num2){
	
	
	SSD_vInit4Bit(SSD1_EN);
	SSD_vDeInit4Bit(SSD2_EN);
	
	SSD_enuDisplay4Bit(copy_num2);
	_delay_ms(4);
	SSD_vDeInit4Bit  (SSD1_EN);
	SSD_vInit4Bit    (SSD2_EN);
	
	SSD_enuDisplay4Bit(copy_num1);
	_delay_ms(8);
	
}