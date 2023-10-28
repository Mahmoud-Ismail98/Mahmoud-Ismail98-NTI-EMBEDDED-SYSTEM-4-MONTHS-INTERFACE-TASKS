#include "Std_types.h"
#include "Bit_utils.h"
#include <util/delay.h>
#include "PORT.h"
#include "DIO.h"
#include "CLCD.h"
#include "KEYPAD.h"
#include "Timer.h"
#include "GIE.h"

u8 alarm_Val = 0;

void Timer0_AlarmCallBack(){
	static u8 overFlowCounts = 0 ;
	overFlowCounts ++;
	if (alarm_Val == 0){
		CLCD_VidGoToXY(3,0);
		CLCD_VidDisplayString("Run buzzer");
		if (overFlowCounts == 10){
			overFlowCounts = 0 ;
			DIO_enuFlipChannel(PORT_C_CHANNEL_6);
		}
	}else {
		if (overFlowCounts == 62){
			overFlowCounts = 0 ;
			alarm_Val --;
			CLCD_VidGoToXY(3,0);
			CLCD_VidDisplayNumber(alarm_Val);
			CLCD_VidDisplayCharacter(' ');
		}
	}
}

void Timer0_TimerCallBack(){
	static u32 overFlowCounts = 0 ;
	static u8 seconds = 0;
	static u8 min = 0;
	static u8 hours = 0 ;

	overFlowCounts ++;
	if (overFlowCounts == 62){

		overFlowCounts = 0 ;
		alarm_Val --;
		CLCD_VidGoToXY(3,0);
		if (seconds < 59){
			seconds ++;
		}else {
			if (min < 59){
				seconds = 0;
				min ++;
			}else {
				seconds = 0 ;
				min = 0 ;
				hours ++;
			}
		}
		CLCD_VidGoToXY(2,0);
		if (hours < 10){
			CLCD_VidDisplayCharacter('0');
			CLCD_VidDisplayNumber(hours);
		}else {
			CLCD_VidDisplayNumber(hours);
		}
		CLCD_VidDisplayCharacter(':');
		if (min < 10){
			CLCD_VidDisplayCharacter('0');
			CLCD_VidDisplayNumber(min);
		}else {
			CLCD_VidDisplayNumber(min);
		}
		CLCD_VidDisplayCharacter(':');
		if (seconds < 10){
			CLCD_VidDisplayCharacter('0');
			CLCD_VidDisplayNumber(seconds);
		}else {
			CLCD_VidDisplayNumber(seconds);
		}

	}
}
void main(void){
	PORT_enuInit();
	GIE_vidEnable();
	CLCD_VidInit();
	CLCD_VidDisplayString("Choose Mode");
	CLCD_VidGoToXY(1,0);
	CLCD_VidDisplayString("1- Alarm");
	CLCD_VidGoToXY(2,0);
	CLCD_VidDisplayString("2- Clock");

	Timer0_cfg CFGTIMER0 = {TIMER_0_MODE_NORMAL, OC0_MODE_NORMAL_PORT, TIMER_0_INTERRUPT_MODE_ENABLE_CTC, CLOCK_MODE_1024_PRESCALER};
	TIMER_0_void_setValue(0);
	TIMER_0_void_setCTCValue(250);




	u8 button;
	button = KEYPAD_u8GetButton();
	CLCD_VidGoToXY(3,0);
	CLCD_VidDisplayCharacter(button);
	_delay_ms(500);
	if (button == '1'){
		/* display clear */
		CLCD_VidSendCommand(0x00);
		_delay_ms(5);
		CLCD_VidSendCommand(0x01);
		_delay_ms(5);
		CLCD_VidDisplayString("1- Alarm");
		CLCD_VidGoToXY(1,0);
		CLCD_VidDisplayString("time in seconds = ");
		CLCD_VidGoToXY(2,0);
		while(1){
			u8 sec= KEYPAD_u8GetButton();
			CLCD_VidDisplayCharacter(sec);
			if (sec >= '0' && sec <= '9'){
				if (alarm_Val == 0){
					alarm_Val += sec - '0';
				}else {
					alarm_Val *= 10;
					alarm_Val += sec - '0';
				}
			}else {
				break;
			}
		}
//		sec -= '0';
//		alarm_Val = sec;
		Timer0_enuErrorStateCTCSetCallBack(&Timer0_AlarmCallBack);
		TIMER_0_voidInit(&CFGTIMER0);

	}else if (button == '2'){
		/* display clear */
		CLCD_VidSendCommand(0x00);
		_delay_ms(5);
		CLCD_VidSendCommand(0x01);
		_delay_ms(5);
		CLCD_VidDisplayString("Clock");
		CLCD_VidGoToXY(1,0);
		CLCD_VidDisplayString("HH:MM:SS");
		CLCD_VidGoToXY(2,0);
		Timer0_enuErrorStateCTCSetCallBack(&Timer0_TimerCallBack);
		TIMER_0_voidInit(&CFGTIMER0);

	}else {
		/* display clear */
		CLCD_VidSendCommand(0x00);
		_delay_ms(5);
		CLCD_VidSendCommand(0x01);
		_delay_ms(5);
		CLCD_VidDisplayString("Wrong input");
	}
	while(1){
	}
}
