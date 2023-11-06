#include <avr/std.h>
void LED_init() {
   MDIO_VidSetPinValue(Port_A,Pin_0,Pin_Output);

}
void LED_toggle() {
    PORTB ^= (1 << 0);
}

void test() {
    for (int i = 0; i < 10; i++) {
        
        _delay_ms(1000);

        if (i == 4) {
            // Indicate the Watchdog reset by rapid LED blinking
            for (int j = 0; j < 5; j++) {
                LED_toggle();
                _delay_ms(500);
            }
            WDT_VoidDisable(); // Disable the Watchdog Timer
        }

        LED_toggle(); // Simulate the LED for normal task
    }
}nt main() {
    WDT_VoidEnable(); 

    test(); 

    while (1) {

	}

    return 0;
}