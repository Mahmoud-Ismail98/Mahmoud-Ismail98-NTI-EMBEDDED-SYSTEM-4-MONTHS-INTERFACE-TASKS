#include "Std_types.h"
#include "Bit_utils.h"
#include <util/delay.h>
#include "PORT.h"
#include "DIO.h"
#include "CLCD.h"

u8 border[8] = {0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00011111};
u8 Hamok4a[8] = {0b00001110,0b00001110,0b00001110,0b00000100,0b00001110,0b00000100,0b00001110,0b00011111};

#define DELAY_TIME_MS 300
void b1(){
	CLCD_VidGoToXY(0,0);
	CLCD_VidDisplayCharacter(0);
	CLCD_VidDisplayCharacter(0);
	CLCD_VidDisplayCharacter(0);
	CLCD_VidDisplayCharacter(0);
	CLCD_VidDisplayCharacter(0);
	CLCD_VidDisplayCharacter(0);
	CLCD_VidDisplayCharacter(0);
	CLCD_VidDisplayCharacter(0);
	CLCD_VidDisplayCharacter(0);
	CLCD_VidDisplayCharacter(0);
	CLCD_VidDisplayCharacter(0);
	CLCD_VidDisplayCharacter(0);
	CLCD_VidDisplayCharacter(0);
	CLCD_VidDisplayCharacter(0);
	CLCD_VidDisplayCharacter(0);
	CLCD_VidDisplayCharacter(0);
	CLCD_VidDisplayCharacter(0);
	CLCD_VidDisplayCharacter(0);
	CLCD_VidDisplayCharacter(0);
	CLCD_VidDisplayCharacter(0);
	CLCD_VidGoToXY(2,0);
	CLCD_VidDisplayCharacter(0);
	CLCD_VidDisplayCharacter(0);
	CLCD_VidDisplayCharacter(0);
	CLCD_VidDisplayCharacter(0);
	CLCD_VidDisplayCharacter(0);
	CLCD_VidDisplayCharacter(0);
	CLCD_VidDisplayCharacter(0);
	CLCD_VidDisplayCharacter(0);
	CLCD_VidDisplayCharacter(0);
	CLCD_VidDisplayCharacter(0);
	CLCD_VidDisplayCharacter(0);
	CLCD_VidDisplayCharacter(0);
	CLCD_VidDisplayCharacter(0);
	CLCD_VidDisplayCharacter(0);
	CLCD_VidDisplayCharacter(0);
	CLCD_VidDisplayCharacter(0);
	CLCD_VidDisplayCharacter(0);
	CLCD_VidDisplayCharacter(0);
	CLCD_VidDisplayCharacter(0);
	CLCD_VidDisplayCharacter(0);
	CLCD_VidGoToXY(1,11);
	CLCD_VidDisplayCharacter(' ');
}


void main(void){
	PORT_enuInit();

	CLCD_VidInit();
	CLCD_VidCreatCustomCharacter(border, 0);
	CLCD_VidCreatCustomCharacter(Hamok4a, 1);

	b1();
	for (u8 i = 0 ; i < 40 ; i++){
		if (i == 0){
			CLCD_VidGoToXY(0,i);
			CLCD_VidDisplayCharacter(1);
		}
		else if (i < 20){
			CLCD_VidGoToXY(0,i-1);
			CLCD_VidDisplayCharacter(0);
			CLCD_VidDisplayCharacter(1);

		}else if (i == 20){
			CLCD_VidGoToXY(0,19);
			CLCD_VidDisplayCharacter(0);
			CLCD_VidGoToXY(2,0);
			CLCD_VidDisplayCharacter(1);
		}
		else if (i > 20){
			if (i == 21){
				CLCD_VidGoToXY(2,0);
				CLCD_VidDisplayCharacter(0);
				CLCD_VidDisplayCharacter(1);
			}else {
				CLCD_VidGoToXY(2,i-21);
				CLCD_VidDisplayCharacter(0);
				CLCD_VidDisplayCharacter(1);
			}
		}
		_delay_ms(DELAY_TIME_MS);
	}
	b1();
	CLCD_VidGoToXY(0,10);
	CLCD_VidDisplayCharacter(' ');
	for (u8 i = 0 ; i < 21 ; i++){
		if (i == 0){
			CLCD_VidGoToXY(0,i);
			CLCD_VidDisplayCharacter(1);
		}
		else if (i < 11){
			CLCD_VidGoToXY(0,i-1);
			CLCD_VidDisplayCharacter(0);
			CLCD_VidDisplayCharacter(1);

		}else if (i == 12){
			CLCD_VidGoToXY(0,10);
			CLCD_VidDisplayCharacter(' ');
			CLCD_VidGoToXY(2,10);
			CLCD_VidDisplayCharacter(1);
		}
		else if (i > 12){
			if (i == 13){
				CLCD_VidGoToXY(2,10);
				CLCD_VidDisplayCharacter(0);
				CLCD_VidDisplayCharacter(1);
				_delay_ms(DELAY_TIME_MS);
			}
				CLCD_VidGoToXY(2,i-2);
				CLCD_VidDisplayCharacter(0);
				CLCD_VidDisplayCharacter(1);

		}
		_delay_ms(DELAY_TIME_MS);
	}


	b1();
	CLCD_VidGoToXY(2,10);
	CLCD_VidDisplayCharacter('/');
	CLCD_VidGoToXY(1,11);
	CLCD_VidDisplayCharacter('/');

	CLCD_VidGoToXY(0,10);
	CLCD_VidDisplayCharacter(' ');
	CLCD_VidDisplayCharacter(' ');

	for (u8 i = 0 ; i < 21 ; i++){
		if (i == 0){
			CLCD_VidGoToXY(2,i);
			CLCD_VidDisplayCharacter(1);
		}
		else if (i < 11){
			CLCD_VidGoToXY(2,i-1);
			CLCD_VidDisplayCharacter(0);
			CLCD_VidDisplayCharacter(1);

		}else if (i == 11){
			CLCD_VidGoToXY(2,10);
			CLCD_VidDisplayCharacter(0);
			CLCD_VidGoToXY(1,11);
			CLCD_VidDisplayCharacter(1);
//			_delay_ms(DELAY_TIME_MS);
			CLCD_VidGoToXY(2,10);
			CLCD_VidDisplayCharacter('/');

		}else if (i == 12){
			CLCD_VidGoToXY(1,11);
			CLCD_VidDisplayCharacter('/');
			CLCD_VidGoToXY(0,12);
			CLCD_VidDisplayCharacter(1);
//			_delay_ms(DELAY_TIME_MS);
			CLCD_VidGoToXY(1,11);
			CLCD_VidDisplayCharacter('/');
		}
		else if (i > 12){
				CLCD_VidGoToXY(0,i-2);
				CLCD_VidDisplayCharacter(0);
				CLCD_VidDisplayCharacter(1);

		}
		CLCD_VidGoToXY(0,11);
		CLCD_VidDisplayCharacter(' ');
		_delay_ms(DELAY_TIME_MS);
	}
	b1();
	CLCD_VidGoToXY(0,10);
	CLCD_VidDisplayCharacter('|');
	for (u8 i = 0 ; i < 10 ; i++){
		if (i == 0){
			CLCD_VidGoToXY(0,i);
			CLCD_VidDisplayCharacter(1);
		}
		else if (i < 10){
			CLCD_VidGoToXY(0,i-1);
			CLCD_VidDisplayCharacter(0);
			CLCD_VidDisplayCharacter(1);

		}
		_delay_ms(DELAY_TIME_MS);
	}
	CLCD_VidGoToXY(0,0);
	CLCD_VidDisplayString("     HAHAHAHA!");
	CLCD_VidDisplayString("                    ");
	CLCD_VidDisplayString("                    ");
	CLCD_VidDisplayString("                    ");


	while(1);
}
