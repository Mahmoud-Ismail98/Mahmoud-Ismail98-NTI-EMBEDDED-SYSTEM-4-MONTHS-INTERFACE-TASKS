/*
 * LCD.c
 *
 * Created: 10/22/2023 9:29:31 AM
 *  Author: Wael
 */


#include "Bit_Utils.h"
#include "Std_Types.h"
#include "../MCAL/Dio/inc/Dio.h"
#include "../inc/Keypad_prv.h"
#include "../inc/Keypad_cfg.h"
#include "../inc/KeyPad.h"
extern u8 KeyPad_u8SymbolArr[4][4];

static u8 Pattern_Arr[4] = {
	KeyPad_Pattern_1,
	KeyPad_Pattern_2,
	KeyPad_Pattern_3,
	KeyPad_Pattern_4
};

static void KeyPad_voidWritePattern(u8 Copy_u8Pattern)
{
	Dio_enuWriteChannel(KeyPad_ROW1,GET_BIT(Copy_u8Pattern,3));
	Dio_enuWriteChannel(KeyPad_ROW2,GET_BIT(Copy_u8Pattern,2));
	Dio_enuWriteChannel(KeyPad_ROW3,GET_BIT(Copy_u8Pattern,1));
	Dio_enuWriteChannel(KeyPad_ROW4,GET_BIT(Copy_u8Pattern,0));
}


static u8 KeyPad_voidReadInput()
{
	u8 Local_u8RetVal = 0;
	u8 Local_u8RetValTemp = 0;
	u8 T;
	Dio_enuReadChannel(KeyPad_COL1,&Local_u8RetValTemp);
	T = Local_u8RetValTemp;
	while(T == 0)
	{
		Dio_enuReadChannel(KeyPad_COL1,&T);
	}
	Local_u8RetVal |= Local_u8RetValTemp<<3;


	Dio_enuReadChannel(KeyPad_COL2,&Local_u8RetValTemp);
	T = Local_u8RetValTemp;
	while(T == 0)
	{
		Dio_enuReadChannel(KeyPad_COL2,&T);
	}
	Local_u8RetVal |= Local_u8RetValTemp<<2;

	Dio_enuReadChannel(KeyPad_COL3,&Local_u8RetValTemp);
	T = Local_u8RetValTemp;
	while(T == 0)
	{
		Dio_enuReadChannel(KeyPad_COL3,&T);
	}
	Local_u8RetVal |= Local_u8RetValTemp<<1;

	Dio_enuReadChannel(KeyPad_COL4,&Local_u8RetValTemp);
	T = Local_u8RetValTemp;
	while(T == 0)
	{
		Dio_enuReadChannel(KeyPad_COL4,&T);
	}
	Local_u8RetVal |= Local_u8RetValTemp<<0;

	return Local_u8RetVal;
}


void KeyPad_voidGetButton(pu8 Copy_u8Button)
{
	u8 i;
	u8 Local_u8Read=0;
	for(i = 0; i < 4 ; i++)
	{
		KeyPad_voidWritePattern(Pattern_Arr[i]);
		Local_u8Read = KeyPad_voidReadInput();
		switch(Local_u8Read)
		{
			case 0b0111:  //Col 1 Row i
			*Copy_u8Button = KeyPad_u8SymbolArr[i][0];
			break;

			case 0b1011: //Col 2 Row i
			*Copy_u8Button = KeyPad_u8SymbolArr[i][1];
			break;

			case 0b1101: //Col 3 Row i
			*Copy_u8Button = KeyPad_u8SymbolArr[i][2];
			break;

			case 0b1110: //Col 4 Row i
			*Copy_u8Button = KeyPad_u8SymbolArr[i][3];
			break;
		}
	}
}

void KeyPad_voidGetNumber(pu16 Copy_u16Num)
{
	u8 Local_u8Button = 0;
	u8 Local_u8Temp = 0;
	u16 Local_u16Result = 0;
	do
	{
		KeyPad_voidGetButton(&Local_u8Button);
		if(Local_u8Button != 0  && Local_u8Button != '.')
		{
			Local_u8Temp = Local_u8Button - '0';
			Local_u16Result = (Local_u16Result*10) + Local_u8Temp;
			Local_u8Button = 0;
		}

		else
		{

		}

	}while(Local_u8Button != '.' );
	*Copy_u16Num = Local_u16Result;
}
