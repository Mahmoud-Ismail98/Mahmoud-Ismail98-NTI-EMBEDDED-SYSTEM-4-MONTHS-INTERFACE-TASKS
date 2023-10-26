#include "std_types.h"
#include "Bit_Math.h"

#include "GI_Priv.h"
#include "GI_Config.h"
#include "GI_Int.h"

/* Function: GIE_voidEnableGlobalInterrupt
 * Description: Enables the global interrupt flag, allowing interrupt requests to be processed.
 * Input: None
 * Output: None
 */
void GIE_voidEnableGlobalInterrupt(void) {
    SET_BIT(SREG, I);
}

/* Function: GIE_voidDisableGlobalInterrupt
 * Description: Disables the global interrupt flag, preventing interrupt requests from being processed.
 * Input: None
 * Output: None
 */
void GIE_voidDisableGlobalInterrupt(void) {
    CLEAR_BIT(SREG, I);
}
