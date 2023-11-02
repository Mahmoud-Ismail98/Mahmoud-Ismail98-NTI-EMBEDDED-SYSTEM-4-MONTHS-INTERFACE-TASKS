#include "../LIB/Include/STD_TYPES.h"
#include "../LIB/Include/BIT_MATH.h"
#include "../MCAL/PORT/Include/PORT_interface.h"
#include "../MCAL/DIO/Include/DIO_interface.h"
#include "../MCAL/GIE/Include/GIE_interface.h"
#include "../MCAL/UART/Include/UART_interface.h"
#include "../HAL/LCD/Include/LCD_interface.h"

int main(void)
{
	u8 local_u8string[11];

	PORT_voidInit();
	GIE_voidInit(GIE_u8_ENABLE);
	UART_voidInit();
	LCD_voidInit();
//	UART_UARTEnumSendString("ahmed mohey");
	UART_UARTEnumReceiveString(local_u8string,11);
	LCD_u8DisplayString(local_u8string);
	while(1);
	return 0;
}
