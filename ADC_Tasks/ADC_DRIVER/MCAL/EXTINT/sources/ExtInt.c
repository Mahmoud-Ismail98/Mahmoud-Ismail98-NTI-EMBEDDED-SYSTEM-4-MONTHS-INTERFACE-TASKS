/*
 * ExtInt.c
 *
 * Created: 10/22/2023 10:24:18 PM
 *  Author: sharpel
 */ 


#include "std_types.h"
#include "bit_math.h"
#include "vect_table.h"
#include "../includes/ExtInt_prv.h"
#include "../includes/ExtInt.h"



// static global array of pointers to function (to assign callback for each EXT interrupt)
static void(*gl_ptrtoFunc_arr[EXT_INT_INDEX_MAX])(void)={PTR_NULL,PTR_NULL,PTR_NULL};
	
	
	
/*
NAME: EXTINT_enum_Init
DESC: init External interrupt and set sense control and set call back function
ARGS: enum_EXT_INT_index_t        ----------> EXT interrupt index
      enum_EXT_INT_SenseControl_t ----------> EXT interrupt Sense Control
	  void(*ptrFunc)()            ----------> Call back Function
RET : enum_EXT_INT_ERROR_t status code (EXT_INT_OKAY,EXT_INT_INDEX_ERROR,EXT_INT_SENSE_ERROR,EXT_INT_PTRNULL_ERROR)

*/

enum_EXT_INT_ERROR_t EXTINT_enum_Init(enum_EXT_INT_index_t arg_enum_ExtIntIndex,enum_EXT_INT_SenseControl_t arg_enum_SenseControl,void(*ptrFunc)(void))
{
	
	// loc return status code
	enum_EXT_INT_ERROR_t loc_enum_returnStatus = EXT_INT_OKAY;
	
	// case wrong index
	if( arg_enum_ExtIntIndex >= EXT_INT_INDEX_MAX)
	{
		loc_enum_returnStatus = EXT_INT_INDEX_ERROR;
	}
	// case wrong sense choice
	else if( arg_enum_SenseControl >= EXT_INT_SENSE_MAX)
	{
		loc_enum_returnStatus = EXT_INT_SENSE_ERROR;
	}
	
	//case NULL ptr
	else if( ptrFunc == PTR_NULL)
	{
		loc_enum_returnStatus = EXT_INT_PTRNULL_ERROR;
	}
	else
	{
		// set call back
		gl_ptrtoFunc_arr[arg_enum_ExtIntIndex]	= ptrFunc;
		
		
		//switch EXT  interrupt index
		switch(arg_enum_ExtIntIndex)
		{
			case EXT_INT0 :
			{
				if ( arg_enum_SenseControl == EXT_INT_RISING_EDGE )
				{
					SET_BIT(MCUCR,ISC00);
					SET_BIT(MCUCR,ISC01);
				}
				else if ( arg_enum_SenseControl == EXT_INT_FALLING_EDGE )
				{
					CLR_BIT(MCUCR,ISC00);
					SET_BIT(MCUCR,ISC01);
				}
				else if ( arg_enum_SenseControl == EXT_INT_LOW_LEVEL )
				{
					CLR_BIT(MCUCR,ISC00);
					CLR_BIT(MCUCR,ISC01);
				}
				else if ( arg_enum_SenseControl == EXT_INT_ANY_CHANGE )
				{
					SET_BIT(MCUCR,ISC00);
					CLR_BIT(MCUCR,ISC01);
				}
				else
				{
					// do nothing
				}
				break;
			}
			
			case EXT_INT1 :
			{
				if ( arg_enum_SenseControl == EXT_INT_RISING_EDGE )
				{
					SET_BIT(MCUCR,ISC10);
					SET_BIT(MCUCR,ISC11);
				}
				else if ( arg_enum_SenseControl == EXT_INT_FALLING_EDGE )
				{
					CLR_BIT(MCUCR,ISC10);
					SET_BIT(MCUCR,ISC11);
				}
				else if ( arg_enum_SenseControl == EXT_INT_LOW_LEVEL )
				{
					CLR_BIT(MCUCR,ISC10);
					CLR_BIT(MCUCR,ISC11);
				}
				else if ( arg_enum_SenseControl == EXT_INT_ANY_CHANGE )
				{
					SET_BIT(MCUCR,ISC10);
					CLR_BIT(MCUCR,ISC11);
				}
				else
				{
					// do nothing
				}
				break;
			}
			
			case EXT_INT2 :
			{
				if ( arg_enum_SenseControl == EXT_INT_RISING_EDGE )
				{
					SET_BIT(MCUCSR,ISC2);
				}
				else if ( arg_enum_SenseControl == EXT_INT_FALLING_EDGE )
				{
					CLR_BIT(MCUCSR,ISC2);
				}
				else
				{
					loc_enum_returnStatus = EXT_INT_SENSE_ERROR;
				}
				break;
			}
		}
		
		EXT_INT_enable_PIE(arg_enum_ExtIntIndex);
		
	}


	return loc_enum_returnStatus;
}



static void EXT_INT_enable_PIE(enum_EXT_INT_index_t arg_enum_EXTINT_Index)
{
	if ( arg_enum_EXTINT_Index == EXT_INT0 )
	{
		SET_BIT(GICR,INT0);
	}
	else if ( arg_enum_EXTINT_Index == EXT_INT1 )
	{
		SET_BIT(GICR,INT1);
	}
	else if ( arg_enum_EXTINT_Index == EXT_INT2 )
	{
		SET_BIT(GICR,INT2);
	}
	else
	{
		// do nothing
	}
}


ISR(EXT_INT_0)
{
	if( gl_ptrtoFunc_arr[EXT_INT0] != PTR_NULL)
	{
		gl_ptrtoFunc_arr[EXT_INT0]();
	}
	else 
	{
		// do nothing
	}
}

ISR(EXT_INT_1)
{
	if( gl_ptrtoFunc_arr[EXT_INT1] != PTR_NULL)
	{
		gl_ptrtoFunc_arr[EXT_INT1]();
	}
	else
	{
		// do nothing
	}
}

ISR(EXT_INT_2)
{
	if( gl_ptrtoFunc_arr[EXT_INT2] != PTR_NULL)
	{
		gl_ptrtoFunc_arr[EXT_INT2]();
	}
	else
	{
		// do nothing
	}
}