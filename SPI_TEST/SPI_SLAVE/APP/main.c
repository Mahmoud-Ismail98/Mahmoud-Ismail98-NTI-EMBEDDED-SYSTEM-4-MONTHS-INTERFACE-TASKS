#include "../LIB/Include/STD_TYPES.h"
#include "../LIB/Include/BIT_MATH.h"
#include "../MCAL/PORT/Include/PORT_interface.h"
#include "../MCAL/DIO/Include/DIO_interface.h"
#include "../MCAL/SPI/Include/SPI_interface.h"
#include "../HAL/LCD/Include/LCD_interface.h"

int main(void)
{
	u8 local_u8Name[11];
	PORT_voidInit();
	SPI_voidSlaveInit();
	LCD_voidInit();
	SPI_SPIEnumReceiveString(local_u8Name,11);
	LCD_u8DisplayString(local_u8Name);
	DIO_DioEnumWriteChannel(DIO_u8_PORTB,DIO_u8_PIN0,DIO_u8_HIGH);
	while(1);
	return 0;
}

