/*
 * Gie.c
 *
 * Created: 10/22/2023 10:01:19 AM
 *  Author: sharb
 */ 



#include "bit_math.h"
#include "Gie_prv.h"
#include "Gie.h"


GIE_ERROR_t GIE_status(GIE_STATUS_t arg_enu_GIE_status)
{
	GIE_ERROR_t loc_enu_returnValue = GIE_OKAY;
	if( arg_enu_GIE_status >= GIE_STATUS_ERROR)
	{
		loc_enu_returnValue = GIE_ERROR;
	}
	else if ( arg_enu_GIE_status == GIE_ENABLE)
	{
		SET_BIT(SREG,ENABLE_BIT);
	}
	else if ( arg_enu_GIE_status == GIE_ENABLE)
	{
		CLR_BIT(SREG,ENABLE_BIT);
	}
	else
	{
		// do nothing
	}
	
	return loc_enu_returnValue;
}