#include "Std_types.h"
#include "Bit_utils.h"
#include "UART.h"
#include "UART_cfg.h"
#include "UART_priv.h"

/* Function: UART_voidInit
 * Description: Initializes the UART communication module with specified configurations.
 * Inputs: None
 * Outputs: None
 */
void UART_voidInit(void) {
    u8 Local_u8UCSRC = 0x80; // Initialize the UBRRH value for 8-bit data frame

    u16 baudRate = BR; // Baud rate from the configuration
    UBRRL = baudRate;
    UCSRA = 0;
    UCSRB = 0;

    /* Accessing THE */
    CLR_BIT(UCSRC, URSEL);

    /* To access the UBRRH and assign the baud rate */
    UCSRC = baudRate >> 8;

    /* Configure transmission speed (U2X or NORMAL) */
    #if USART_Transmission_Speed == U2X
    SET_BIT(UCSRA, U2X);
    #elif USART_Transmission_Speed == NORMAL_TRANSMISSION_SPEED
    CLR_BIT(UCSRA, U2X);
    #endif

    /* Configure character size (5-bit to 9-bit) */
    #if Character_Size == Character_5_bit
    CLR_BIT(Local_u8UCSRC, UCSZ0);
    CLR_BIT(Local_u8UCSRC, UCSZ1);
    CLR_BIT(UCSRB, UCSZ2);
    #elif Character_Size == Character_6_bit
    SET_BIT(Local_u8UCSRC, UCSZ0);
    CLR_BIT(Local_u8UCSRC, UCSZ1);
    CLR_BIT(UCSRB, UCSZ2);
    #elif Character_Size == Character_7_bit
    CLR_BIT(Local_u8UCSRC, UCSZ0);
    SET_BIT(Local_u8UCSRC, UCSZ1);
    CLR_BIT(UCSRB, UCSZ2);
    #elif Character_Size == Character_8_bit
    SET_BIT(Local_u8UCSRC, UCSZ0);
    SET_BIT(Local_u8UCSRC, UCSZ1);
    CLR_BIT(UCSRB, UCSZ2);
    #elif Character_Size == Character_9_bit
    SET_BIT(Local_u8UCSRC, UCSZ0);
    SET_BIT(Local_u8UCSRC, UCSZ1);
    SET_BIT(UCSRB, UCSZ2);
    #endif

    /* Configure number of stop bits (1 or 2) */
    #if NUMBER_OF_BITS == ONE_STOP_BIT
    CLR_BIT(Local_u8UCSRC, USBS);
    #elif NUMBER_OF_BITS == TWO_STOP_BIT
    CLR_BIT(Local_u8UCSRC, USBS);
    #endif

    /* Configure parity mode (NO_PARITY, EVEN_PARITY, or ODD_PARITY) */
    #if PARITY_MODE == NO_PARITY
    CLR_BIT(Local_u8UCSRC, UPM0);
    CLR_BIT(Local_u8UCSRC, UPM1);
    #elif PARITY_MODE == EVEN_PARITY
    CLR_BIT(Local_u8UCSRC, UPM0);
    SET_BIT(Local_u8UCSRC, UPM1);
    #elif PARITY_MODE == ODD_PARITY
    SET_BIT(Local_u8UCSRC, UPM0);
    SET_BIT(Local_u8UCSRC, UPM1);
    #endif

    /* Configure USART mode (Asynchronous or Synchronous) */
    #if USART_Mode_Select == Asynchronous_Operation
    CLR_BIT(Local_u8UCSRC, UMSEL);
    #elif USART_Mode_Select == Synchronous_Operation
    SET_BIT(Local_u8UCSRC, UMSEL);
    #endif

    /* Enable receiver and transmitter */
    SET_BIT(UCSRB, RXEN);
    SET_BIT(UCSRB, TXEN);

    UCSRC = Local_u8UCSRC;
}

/* Function: UART_SendByte
 * Description: Sends a single byte over UART communication.
 * Inputs:
 *   - data: The byte to be sent.
 * Outputs: None
 */
void UART_SendByte(u8 data) {
    while (GET_BIT(UCSRA, UDRE) == 0);
    UDR = data;
}

/* Function: UART_SendString
 * Description: Sends a null-terminated string over UART communication.
 * Inputs:
 *   - str: Pointer to the string to be sent.
 * Outputs: None
 */
void UART_SendString(u8 *str) {
    u8 i = 0;
    while (str[i] != '\0') {
        UART_SendByte(str[i]);
        _delay_ms(2000); // Delay between characters (adjust as needed)
        i++;
    }
}

/* Function: UART_ReceiveByte
 * Description: Receives a single byte over UART communication.
 * Inputs: None
 * Outputs:
 *   - The received byte.
 */
char UART_ReceiveByte(void) {
    u8 data = 0;
    while (GET_BIT(UCSRA, RXC) == 0);
    data = UDR;
    return data;
}

/* Function: UART_ReceiveString
 * Description: Receives a string over UART communication until a null terminator is encountered.
 * Inputs: None
 * Outputs:
 *   - Pointer to the received string.
 */
u8 *UART_ReceiveString(void) {
    static u8 received_Data[50];
    u8 i = 0;
    while (received_Data[i] != '\0') {
        received_Data[i] = UART_ReceiveByte();
        i++;
    }
    return received_Data;
}
