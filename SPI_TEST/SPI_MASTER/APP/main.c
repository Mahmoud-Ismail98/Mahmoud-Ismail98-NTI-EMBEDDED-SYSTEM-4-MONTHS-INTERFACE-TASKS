
#include "../LIB/Include/STD_TYPES.h"
#include "../LIB/Include/BIT_MATH.h"
#include "../MCAL/PORT/Include/PORT_interface.h"
#include "../MCAL/DIO/Include/DIO_interface.h"
#include "../MCAL/SPI/Include/SPI_interface.h"
#include "../HAL/LCD/Include/LCD_interface.h"

int main(void)
{
	//u8 local_u8Data[11];
	PORT_voidInit();
	SPI_voidMasterInit();
	LCD_voidInit();
	SPI_SPIEnumSendString("ahmed mohey");
	while(1);
	return 0;
}
