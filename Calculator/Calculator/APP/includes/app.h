/*
 * app.h
 *
 * Created: 11/1/2023 12:56:33 PM
 *  Author: sharb
 */ 


#ifndef APP_H_
#define APP_H_


#include "std_types.h"

#define  MAX_NODES        20
#define  MAX_NUM          10


#define PLUS_KEY          15
#define EQUALL_KEY        14
#define DIV_KEY           3
#define MULT_KEY          7
#define MINUS_KEY         11
#define CLR_KEY           12

// all operation that supported By calculator
typedef enum
{
	CALC_PLUS,
	CALC_MINUS,
	CALC_MULT,
	CALC_DIV,
	CALC_MAX_OPERATION,
	
}CALC_OPERATIONS_enum_t;

// node for each term 
typedef struct
{
	
	u32 u32_operand;
	u8 u8_sign;
	
}CALC_NODE_str_t;

// error states for calculator
typedef enum
{
	CALC_OKAY,
	CALC_OPERATION_ERROR,
	CALC_NULL_REF_ERROR,
	CALC_DIV_BY_ZERO,
		
}CALC_ERROR_STATES_enum_t;

void app_init(void);// init app modules
void app_start(void);// start app logic


/*
NAME: CALC_enum_ExecuteLogic
DESC: calculate two arguments with specific operation (PLUS,MINUS,MULT,DIVIDE)
ARGS: arg_u32_operand_one     ----------> first operand
      arg_u32_operand_two     ----------> second operand
	  *ptr_s64_result         ----------> result
	  CALC_OPERATIONS_enum_t  ----------> operation
RET : CALC_ERROR_STATES_enum_t status code (CALC_OKAY,CALC_OPERATION_ERROR,CALC_NULL_REF_ERROR,CALC_DIV_BY_ZERO)

*/
CALC_ERROR_STATES_enum_t CALC_enum_ExecuteLogic(s32 arg_u32_operand_one,s32 arg_u32_operand_two,s64 *ptr_s64_result,CALC_OPERATIONS_enum_t arg_enum_operation);



#endif /* APP_H_ */