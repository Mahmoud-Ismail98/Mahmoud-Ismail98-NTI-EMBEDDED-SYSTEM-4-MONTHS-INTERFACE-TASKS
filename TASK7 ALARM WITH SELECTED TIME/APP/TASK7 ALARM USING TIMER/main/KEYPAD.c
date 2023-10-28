//#include <util/delay.h>
#include "../../../services/Std_types.h"
#include "../../../services/Bit_utils.h"
#include "../../../MCAL/PORT/include/port_private.h"
#include "../../../MCAL/PORT/include/port.h"
#include "../../../MCAL/DIO/include/DIO.h"
#include "../../../HAL/KEYPAD/KEYPAD_cfg.h"
#include "../../../HAL/KEYPAD/KEYPAD.h"
#include "../../../HAL/KEYPAD/KEYPAD_private.h"





void KEYPAD_voidInit(void)
{
Port_setPinDirection(KEY_RAW0,PIN_OUTPUT);
Port_setPinDirection(KEY_RAW1,PIN_OUTPUT);
Port_setPinDirection(KEY_RAW2,PIN_OUTPUT);
Port_setPinDirection(KEY_RAW3,PIN_OUTPUT);
Port_SetPinMode(KEY_COL0,PIN_IN_PULLUP);
Port_SetPinMode(KEY_COL1,PIN_IN_PULLUP);
Port_SetPinMode(KEY_COL2,PIN_IN_PULLUP);
Port_SetPinMode(KEY_COL3,PIN_IN_PULLUP);

}
u8 RAW_NUM=4;


//u8KEYPAD_SYMBOL[4]={0b1111,0b01111,0b1011,0b1101,0b1110};
	
ERROR_KEYPAD_STATUS KEYPAD_FindKey(u8 *Loc_keyPress)
{
  ERROR_KEYPAD_STATUS ERROR_KEYPAD_RET=ERROR_FREE;
  u8 temp=0b00;
  u8 reg;
  for(u8 i=0;i<RAW_NUM;i++)
  {	  
	reg=0x0F;  
  KEYPAD_WritrPins(TGLWITHOUTASSIGN_BIT(reg,i));
  KEYPAD_ReadPins(&temp);
  switch(temp)
  {
	case 0b1110:	
	*Loc_keyPress=KEYPAD_SYMBOL[(4*i)+0]; 
	break;
	case 0b1101:	
	*Loc_keyPress=KEYPAD_SYMBOL[(4*i)+1];
	break;
	case 0b1011:	
	*Loc_keyPress=KEYPAD_SYMBOL[(4*i)+2];
	break;
	case 0b0111:	
	*Loc_keyPress=KEYPAD_SYMBOL[(4*i)+3];
	break;
	default:
	ERROR_KEYPAD_RET=NO_KEY_PRESSED;	
   }
  }   	
	return ERROR_KEYPAD_RET;
}
void KEYPAD_WritrPins(u8 value)
{		
	DIO_WritrPin(KEY_RAW0,GET_BIT(value,0));
	DIO_WritrPin(KEY_RAW1,GET_BIT(value,1));	
	DIO_WritrPin(KEY_RAW2,GET_BIT(value,2));
	DIO_WritrPin(KEY_RAW3,GET_BIT(value,3));
}

void KEYPAD_ReadPins(u8 *value)
{
	u8 loc_read=0;
	//u8 *temp=value;
	DIO_READ_PIN(KEY_COL0,&loc_read);
	*value=loc_read;
	DIO_READ_PIN(KEY_COL1,&loc_read);
	*value|=(loc_read<<1);
	DIO_READ_PIN(KEY_COL2,&loc_read);
	*value|=(loc_read<<2);
	DIO_READ_PIN(KEY_COL3,&loc_read);
	*value|=(loc_read<<3);
	
}