/*
 * Inclusions 
 */
/* Library Files */
#include "Std_types.h"
#include "Bit_utils.h"
/* Module Files */
#include "GIE_int.h"
#include "GIE_reg.h"

/*
 * Public Function Definition 
 */
void M_GIE_void_EnableGlobalInterrupt(void) {
	SET_BIT(SREG,I);
}
void M_GIE_void_DisableGlobalInterrupt(void) {
	CLR_BIT(SREG,I);
}
