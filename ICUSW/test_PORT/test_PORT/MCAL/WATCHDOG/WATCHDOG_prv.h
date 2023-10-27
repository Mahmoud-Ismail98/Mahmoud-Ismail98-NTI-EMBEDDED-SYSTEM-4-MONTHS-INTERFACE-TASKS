/*
 * WATCHDOG_prv.h
 *
 * Created: 10/27/2023 1:01:58 PM
 *  Author: HP
 */ 


#ifndef WATCHDOG_PRV_H_
#define WATCHDOG_PRV_H_

#define WDTCR_Reg (*(volatile u8)0x41)


#define WDTCR_WDTOE    4
#define WDTCR_WDE      3
#define WDTCR_WDP2     2
#define WDTCR_WDP1     1
#define WDTCR_WDP0     0



#define WDT_PRESCALER_16MS   (0b000)
#define WDT_PRESCALER_32MS   (0b001)
#define WDT_PRESCALER_64MS   (0b010)
#define WDT_PRESCALER_128MS  (0b011)
#define WDT_PRESCALER_256MS  (0b100)
#define WDT_PRESCALER_512MS  (0b101)
#define WDT_PRESCALER_1S     (0b110)
#define WDT_PRESCALER_2S     (0b111)



#endif /* WATCHDOG_PRV_H_ */