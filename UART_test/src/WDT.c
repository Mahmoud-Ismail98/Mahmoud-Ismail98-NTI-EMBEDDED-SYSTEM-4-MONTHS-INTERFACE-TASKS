#include "../inc/LIB/Std_types.h"
#include "../inc/LIB/Bit_utils.h"

#include "../inc/MCAL/WDT/WDT.h"
#include "../inc/MCAL/WDT/WDT_private.h"

void WDT_voidEnablePeripheral(u8 Copy_u8WDT_Prescaller)
{
	u8 Local_WDTBitWise = 0b00001000;
	Local_WDTBitWise = Local_WDTBitWise | Copy_u8WDT_Prescaller;
	WDTCR = Local_WDTBitWise;
}
void WDT_voidDisablePeripheral(void)
{
	WDTCR = (1<<WDTOE) | (1<<WDE);
	WDTCR = 0x00;
}
