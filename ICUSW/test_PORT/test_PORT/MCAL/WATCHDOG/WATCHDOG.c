/*
 * WATCHDOG.c
 *
 * Created: 10/27/2023 1:01:30 PM
 *  Author: HP
 */ 



/*

void WDT_Init(void) {
    // Set the prescaler value
    u8 Loc_u8Reg = 0b000;
    SET_BIT(WDTCR_Reg,WDTCR_WDE);
    SET_BIT(WDTCR_Reg,WDTCR_WDCE);
    CONC() ;

    ASSIGN_REG(WDTCR_Reg,WDT_PRESCALER);
}


void WDT_Enable() {

    SET_BIT(WDTCR_Reg,WDTCR_WDE);
}


void WDT_Disable() {
    CLR_BIT(WDTCR_Reg,WDTCR_WDE);
}



*/