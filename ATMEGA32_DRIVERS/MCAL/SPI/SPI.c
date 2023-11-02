#include "std_types.h"
#include "Bit_utils.h"
#include "Dio.h"
#include "SPI_priv.h"
#include "SPI_cfg.h"
#include "SPI.h"

/* Function: SPI_voidInitialize
 * Description: Initializes the SPI communication module with specified configurations.
 * Inputs: None
 * Outputs: None
 */
void SPI_voidInitialize(void) {
    /* Configure data order (LSB_FIRST or MSB_FIRST) */
    #if (DATA_ORDER_MODE == LSB_FIRST)
    SET_BIT(SPCR, DORD);
    #elif (DATA_ORDER_MODE == MSB_FIRST)
    CLR_BIT(SPCR, DORD);
    #else
    #error "WRONG MODE SELECTED"
    #endif

    /* Configure master or slave mode (MASTER or SLAVE) */
    #if (MASTER_MODE == MASTER)
    SET_BIT(SPCR, MSTR);
    #elif (MASTER_MODE == SLAVE)
    CLR_BIT(SPCR, MSTR);
    #else
    #error "PLEASE SELECT MASTER OR SLAVE"
    #endif

    /* Configure clock polarity (LEAD_FALLING_TRAILING_RISING or LEAD_RISING_TRAILING_FALLING) */
    #if (CLOCK_PLOARITY_MODE == LEAD_FALLING_TRAILING_RISING)
    SET_BIT(SPCR, CPOL);
    #elif (CLOCK_PLOARITY_MODE == LEAD_RISING_TRAILING_FALLING)
    CLR_BIT(SPCR, CPOL);
    #else
    #error "WRONG MODE SELECTED"
    #endif

    /* Configure clock phase (LEAD_SETUP_TRAILING_SAMPLE or LEAD_SAMPLE_TRAILING_SETUP) */
    #if (CLOCK_PHASE_MODE == LEAD_SETUP_TRAILING_SAMPLE)
    SET_BIT(SPCR, CPHA);
    #elif (CLOCK_PHASE_MODE == LEAD_SAMPLE_TRAILING_SETUP)
    CLR_BIT(SPCR, CPHA);
    #else
    #error "WRONG MODE SELECTED"
    #endif

    /* Configure the clock frequency (SCK_FREQUENCY) */
    #if (SCK_FREQUENCY == FOSC_4)
    CLR_BIT(SPSR, SPI2X);
    CLR_BIT(SPCR, SPR1);
    CLR_BIT(SPCR, SPR0);
    #elif (SCK_FREQUENCY == FOSC_16)
    CLR_BIT(SPSR, SPI2X);
    CLR_BIT(SPCR, SPR1);
    SET_BIT(SPCR, SPR0);
    #elif (SCK_FREQUENCY == FOSC_64_0)
    CLR_BIT(SPSR, SPI2X);
    SET_BIT(SPCR, SPR1);
    CLR_BIT(SPCR, SPR0);
    #elif (SCK_FREQUENCY == FOSC_128)
    CLR_BIT(SPSR, SPI2X);
    SET_BIT(SPCR, SPR1);
    SET_BIT(SPCR, SPR0);
    #elif (SCK_FREQUENCY == FOSC_2)
    SET_BIT(SPSR, SPI2X);
    CLR_BIT(SPCR, SPR1);
    CLR_BIT(SPCR, SPR0);
    #elif (SCK_FREQUENCY == FOSC_8)
    SET_BIT(SPSR, SPI2X);
    CLR_BIT(SPCR, SPR1);
    SET_BIT(SPCR, SPR0);
    #elif (SCK_FREQUENCY == FOSC_32)
    SET_BIT(SPSR, SPI2X);
    SET_BIT(SPCR, SPR1);
    CLR_BIT(SPCR, SPR0);
    #elif (SCK_FREQUENCY == FOSC_64_1)
    SET_BIT(SPSR, SPI2X);
    SET_BIT(SPCR, SPR1);
    SET_BIT(SPCR, SPR0);
    #else
    #error "PLEASE SELECT RIGHT FREQUENCY"
    #endif

    /* Enable or disable SPI communication (ENABLE or DISABLE) */
    #if (SPI_ENABLE == ENABLE)
    SET_BIT(SPCR, SPE);
    #elif (SPI_ENABLE == DISABLE)
    CLR_BIT(SPCR, SPE);
    #else
    #error "PLEASE SELECT ENABLE OR DISABLE"
    #endif
}

/* Function: SPI_Transmit
 * Description: Transmits a byte over SPI communication.
 * Inputs:
 *   - copy_u8Data: The byte to be transmitted.
 * Outputs:
 *   - The received byte.
 */
u8 SPI_Transmit(u8 copy_u8Data) {
    SPDR = copy_u8Data;

    /* Wait for transmission to complete */
    while (GET_BIT(SPSR, SPIF) == 0);

    return SPDR;
}

/* Function: SPI_Receive
 * Description: Receives a byte over SPI communication.
 * Inputs: None
 * Outputs:
 *   - The received byte.
 */
u8 SPI_Receive(void) {
    /* Wait for reception to complete */
    while (GET_BIT(SPSR, SPIF) == 0);

    return SPDR;
}