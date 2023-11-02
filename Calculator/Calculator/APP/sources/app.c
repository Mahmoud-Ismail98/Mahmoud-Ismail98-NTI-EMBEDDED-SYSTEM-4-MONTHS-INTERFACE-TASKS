/*
 * app.c
 *
 * Created: 11/1/2023 12:56:53 PM
 *  Author: sharb
 */ 


#include "std_types.h"
#include "../../MCAL/PORT/includes/PORT.h"
#include "../../HAL/LCD/includes/Lcd.h"
#include "../../HAL/KEYPAD/includes/Keypad.h"
#include "../includes/app.h"


// global keys of calculator
u8 gl_u8_char_array[16] =
{
	 7 , 8 , 9 , '/',
	 4 , 5 , 6 , 'x',
	 1 , 2 , 3 , '-',
	'c', 0 ,'=', '+',
};

// buffer to hold nodes
CALC_NODE_str_t  gl_str_calc_buffer[MAX_NODES];


// flag to control app flow
u8 gl_app_state = FALSE;
// final result
s64 gl_result   = FALSE;


// init app modules
void app_init(void)
{
	PORT_voidInit(); // init lcd and keypad pins logic
	LCD_vidInit();  // init Lcd
}

// start app logic
void app_start(void)
{
	// init key
	KEYPAD_enu_PressedKey_t  loc_enum_keyPressed  = KEY_NOTHING;
	CALC_ERROR_STATES_enum_t loc_enumCalcState    = CALC_OKAY  ;
	u32                     loc_u32_number_temp   = FALSE      ;
	u32                     loc_u32_number_temp2  = FALSE      ;
	u8                      loc_u8_buff_counter   = FALSE      ;
	u8                      loc_u8_sign_flag      = FALSE      ;
	u8                      loc_u8_mul_flag       = FALSE      ;
	while(1)
	{
		// get key from keypad
		loc_enum_keyPressed = KEYPAD_GetKey();
		
		if(gl_app_state == FALSE)
		{
			if (loc_enum_keyPressed != KEY_NOTHING)
		    {
				// case number is prressed
				if (gl_u8_char_array[loc_enum_keyPressed] < MAX_NUM)
				{
					// DISPLAY NUMBER
					LCD_vidDisplayNumber(gl_u8_char_array[loc_enum_keyPressed]);
					loc_u32_number_temp*=MAX_NUM; // mult temp by 10
					loc_u32_number_temp+=gl_u8_char_array[loc_enum_keyPressed];//store value of number in it's position
				}
				// case operation
				else
				{
					// temp had value
					if (loc_u32_number_temp != FALSE)
					{
					    if ( loc_enum_keyPressed == PLUS_KEY || loc_enum_keyPressed == MINUS_KEY || loc_enum_keyPressed == EQUALL_KEY)
						{
							if(loc_u8_mul_flag != FALSE) // case mult was performed
							{
							   loc_enumCalcState = CALC_enum_ExecuteLogic(loc_u32_number_temp2,loc_u32_number_temp,&loc_u32_number_temp,loc_u8_mul_flag);
							   loc_u8_mul_flag =FALSE;
							   if ( loc_enumCalcState == CALC_DIV_BY_ZERO) gl_app_state = TRUE; // turn app state
							}
							
							gl_str_calc_buffer[loc_u8_buff_counter].u32_operand   = loc_u32_number_temp;//assign operand in node
							gl_str_calc_buffer[loc_u8_buff_counter].u8_sign       = loc_u8_sign_flag;   //assign sign in node
							loc_u8_buff_counter++; // increament counter of buffer
							loc_u32_number_temp = FALSE; // clear temp
						}
						else if ( loc_enum_keyPressed == DIV_KEY || loc_enum_keyPressed == MULT_KEY)
						{
							if ( loc_u32_number_temp2 == FALSE) // FIRST OPERATION
							{
								loc_u32_number_temp2 = loc_u32_number_temp;
							}
							// case nested DIVIDE/MULT operations
							else
							{
								loc_enumCalcState = CALC_enum_ExecuteLogic(loc_u32_number_temp2,loc_u32_number_temp,&loc_u32_number_temp2,loc_u8_mul_flag);
								if ( loc_enumCalcState == CALC_DIV_BY_ZERO) gl_app_state = TRUE;
							}
							loc_u32_number_temp  = FALSE;
						}	
					}
					
					// divide is enterd
					if (loc_enum_keyPressed == DIV_KEY)
					{
						LCD_vidDisplayCharacter(gl_u8_char_array[loc_enum_keyPressed]);
						loc_u8_mul_flag = CALC_DIV;
					}
					// mult
					else if (loc_enum_keyPressed == MULT_KEY)
					{
						LCD_vidDisplayCharacter(gl_u8_char_array[loc_enum_keyPressed]);
						loc_u8_mul_flag = CALC_MULT;
					}
					//plus
					else if (loc_enum_keyPressed == PLUS_KEY)
					{
						LCD_vidDisplayCharacter(gl_u8_char_array[loc_enum_keyPressed]);
						loc_u8_sign_flag = CALC_PLUS;
						
					}
					//minus
					else if (loc_enum_keyPressed == MINUS_KEY)
					{
						LCD_vidDisplayCharacter(gl_u8_char_array[loc_enum_keyPressed]);
						loc_u8_sign_flag = CALC_MINUS;
						
					}
					//equal
					else if (loc_enum_keyPressed == EQUALL_KEY)
					{
						// display equall
						LCD_vidDisplayCharacter(gl_u8_char_array[loc_enum_keyPressed]);
						gl_result = FALSE;
						for(u8 i = FALSE;i<loc_u8_buff_counter;i++)
						{
							// calculate all nodes
							CALC_enum_ExecuteLogic(gl_result,gl_str_calc_buffer[i].u32_operand,&gl_result,gl_str_calc_buffer[i].u8_sign);
						}
						// display result
						LCD_vidDisplayNumber(gl_result);
					}
					//clr
					else if (loc_enum_keyPressed == CLR_KEY)
					{
						LCD_vidClrDisplay();
						gl_result            = FALSE ;
						loc_u8_sign_flag     = FALSE;
						loc_u8_mul_flag      = FALSE;
						loc_u8_buff_counter  = FALSE;
						loc_u32_number_temp  = FALSE;
						loc_u32_number_temp2 = FALSE ;
						
					}
					else
					{
						//nothing
					}
				}
			
		    }
			else
			{
				// nothing pressed
			}
		}
	    else
		{
			LCD_vidClrDisplay();
			LCD_vidDisplayString("DIVIDE BY ZERO ERROR");
			if (loc_enum_keyPressed == 12)
			{
				LCD_vidClrDisplay();
				gl_result            = FALSE ;
				loc_u8_sign_flag     = FALSE;
				loc_u8_mul_flag      = FALSE;
				loc_u8_buff_counter  = FALSE;
				loc_u32_number_temp  = FALSE;
				loc_u32_number_temp2 = FALSE;
				gl_app_state         = FALSE;
				
			}
		}
		//case key pressed
		
	}
}



/*
NAME: CALC_enum_ExecuteLogic
DESC: calculate two arguments with specific operation (PLUS,MINUS,MULT,DIVIDE)
ARGS: arg_u32_operand_one     ----------> first operand
      arg_u32_operand_two     ----------> second operand
	  *ptr_s64_result         ----------> result
	  CALC_OPERATIONS_enum_t  ----------> operation
RET : CALC_ERROR_STATES_enum_t status code (CALC_OKAY,CALC_OPERATION_ERROR,CALC_NULL_REF_ERROR,CALC_DIV_BY_ZERO)

*/
CALC_ERROR_STATES_enum_t CALC_enum_ExecuteLogic(s32 arg_u32_operand_one,s32 arg_u32_operand_two,s64 *ptr_s64_result,CALC_OPERATIONS_enum_t arg_enum_operation)
{
	// loc return status
	CALC_ERROR_STATES_enum_t loc_enum_returnValue  = CALC_OKAY ;
	
	// check on operation
	if( arg_enum_operation >= CALC_MAX_OPERATION)
	{
		loc_enum_returnValue = CALC_OPERATION_ERROR;
	}
	// check on null ptr
	else if ( ptr_s64_result == PTR_NULL)
	{
		loc_enum_returnValue = CALC_NULL_REF_ERROR;
	}
	else
	{
		// switch operation
		switch (arg_enum_operation)
		{
			case CALC_PLUS:
			{
				*ptr_s64_result = arg_u32_operand_one + arg_u32_operand_two;
				break;
			}
			
			case CALC_MINUS:
			{
				*ptr_s64_result = arg_u32_operand_one - arg_u32_operand_two;
				break;
			}
			case CALC_MULT:
			{
				*ptr_s64_result = arg_u32_operand_one * arg_u32_operand_two;
				break;
			}
			case CALC_DIV:
			{
				// case divide by zero
				if ( arg_u32_operand_two == FALSE)
				{
					loc_enum_returnValue = CALC_DIV_BY_ZERO;
					*ptr_s64_result      = PTR_NULL;
				}
				else
				{
				   *ptr_s64_result = arg_u32_operand_one / arg_u32_operand_two;	
				}
				
				break;
			}
		}
		
	}
	return loc_enum_returnValue;
}
