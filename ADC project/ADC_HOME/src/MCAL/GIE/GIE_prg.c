/*
 * Inclusions 
 */
/* Library Files */
#include "../../../inc/LIB/Bit_utils.h"
#include "../../../inc/LIB/Std_types.h"
#include "../../../inc/MCAL/GIE/GIE_int.h"
#include "../../../inc/MCAL/GIE/GIE_reg.h"

/*
 * Public Function Definition 
 */
void M_GIE_void_EnableGlobalInterrupt(void) {
	SET_BIT(SREG,I);
}
void M_GIE_void_DisableGlobalInterrupt(void) {
	CLR_BIT(SREG,I);
}
