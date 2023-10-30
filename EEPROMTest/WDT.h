#ifndef WDT_H_
#define WDT_H_

#define WDT_Prescaller0			0 //16.3msec
#define WDT_Prescaller1			1 //32.5msec
#define WDT_Prescaller2			2 //65  msec
#define WDT_Prescaller3			3 //0.13 sec
#define WDT_Prescaller4			4 //0.26 sec
#define WDT_Prescaller5			5 //0.52 sec
#define WDT_Prescaller6			6 //1.0  sec
#define WDT_Prescaller7			7 //2.1  sec

void WDT_voidEnablePeripheral(u8 Copy_u8WDT_Prescaller);
void WDT_voidDisablePeripheral(void);

#endif