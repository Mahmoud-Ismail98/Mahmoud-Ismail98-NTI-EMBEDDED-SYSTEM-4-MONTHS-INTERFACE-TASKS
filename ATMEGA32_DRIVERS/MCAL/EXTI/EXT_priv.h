#ifndef _EXTI_PRIV_H
#define _EXTI_PRIV_H

/* MCUCR Register (0x55) - MCU Control Register */
#define MCUCR       *(volatile u8 *) 0x55
#define ISC11       3  // Bit 3: ISC11, External Interrupt Request 1 Sense Control bit 1
#define ISC10       2  // Bit 2: ISC10, External Interrupt Request 1 Sense Control bit 0
#define ISC01       1  // Bit 1: ISC01, External Interrupt Request 0 Sense Control bit 1
#define ISC00       0  // Bit 0: ISC00, External Interrupt Request 0 Sense Control bit 0

/* GICR Register (0x5B) - General Interrupt Control Register */
#define GICR        *(volatile u8 *) 0x5B
#define INT1        7  // Bit 7: INT1, External Interrupt Request 1 Enable
#define INT0        6  // Bit 6: INT0, External Interrupt Request 0 Enable
#define INT2        5  // Bit 5: INT2, External Interrupt Request 2 Enable

/* GIFR Register (0x5A) - General Interrupt Flag Register */
#define GIFR        *(volatile u8 *) 0x5A
#define INTF1       7  // Bit 7: INTF1, External Interrupt Request 1 Flag
#define INTF0       6  // Bit 6: INTF0, External Interrupt Request 0 Flag
#define INTF2       5  // Bit 5: INTF2, External Interrupt Request 2 Flag

/* MCUCSR Register (0x54) - MCU Control and Status Register */
#define MCUCSR      *(volatile u8 *) 0x54
#define ISC2        6  // Bit 6: ISC2, External Interrupt Request 2 Sense Control

/* Constants */
#define ENABLED     1  // Enable state
#define DISABLED    0  // Disable state


#endif