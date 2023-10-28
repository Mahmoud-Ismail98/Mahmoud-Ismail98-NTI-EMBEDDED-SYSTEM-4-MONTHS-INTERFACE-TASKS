#include "Std_types.h"
#include "Bit_utils.h"
#include <util/delay.h>
#include "PORT.h"
#include "DIO.h"
#include "CLCD.h"
#include "KEYPAD.h"

void main(void){
	PORT_enuInit();

	CLCD_VidInit();
	CLCD_VidDisplayString("Culculator");
	CLCD_VidGoToXY(1,0);

	u16 Local_u16OP1 = 0;
	u16 Local_u16OP2 = 0;
	u8  Local_u8Signal = 0;
	u8 equallFlag = 0;
	u8 equationindex = 0;
	u16 res = 0;
	while(1){
		u8 button;
		button = KEYPAD_u8GetButton();
		if (button == 'c'){
			/* display clear */
			CLCD_VidSendCommand(0x00);
			_delay_ms(5);
			CLCD_VidSendCommand(0x01);
			_delay_ms(5);
			CLCD_VidDisplayString("Culculator");
			CLCD_VidGoToXY(1,0);
			Local_u16OP1 = 0;
			Local_u16OP2 = 0;
			Local_u8Signal = 0;
			equallFlag = 0;
			equationindex = 0;
			res = 0;
		}else {
			CLCD_VidDisplayCharacter(button);
			switch(button){
			case '+' : Local_u8Signal = '+'; equationindex++ ;break;
			case '-' : Local_u8Signal = '-'; equationindex++ ;break;
			case '*' : Local_u8Signal = '*'; equationindex++ ;break;
			case '/' : Local_u8Signal = '/'; equationindex++ ;break;
			case '=' : equallFlag = 1; equationindex++ ;break;
			default :
				if (equationindex == 0){
					if (Local_u16OP1 == 0){
						Local_u16OP1 = button - '0';
					}else {
						Local_u16OP1 *= 10;
						Local_u16OP1 += button - '0';
					}
				}
				if (equationindex == 1){
					if (Local_u16OP2 == 0){
						Local_u16OP2 = button - '0';
					}else {
						Local_u16OP2 *= 10;
						Local_u16OP2 += button - '0';
					}
				}
				break;
			}
			if (equallFlag == 1 && equationindex >= 1){
				CLCD_VidGoToXY(2,0);
				switch (Local_u8Signal){
				case '+' : CLCD_VidDisplayNumber(Local_u16OP1 + Local_u16OP2) ;break;
				case '-' :
					if (Local_u16OP1 > Local_u16OP2){
						CLCD_VidDisplayNumber(Local_u16OP1 - Local_u16OP2);
					}
					else {
						CLCD_VidDisplayCharacter('-');
						CLCD_VidDisplayNumber(Local_u16OP2 - Local_u16OP1);
					};break;
				case '*' : CLCD_VidDisplayNumber(Local_u16OP1 * Local_u16OP2) ;break;
				case '/' : if (Local_u16OP2 != 0) {
					CLCD_VidDisplayNumber(Local_u16OP1 / Local_u16OP2) ;
				}else {
					CLCD_VidGoToXY(3,0);
					CLCD_VidDisplayString("error can't div by 0");
				};break;
				}
			}
		}
	}
}
