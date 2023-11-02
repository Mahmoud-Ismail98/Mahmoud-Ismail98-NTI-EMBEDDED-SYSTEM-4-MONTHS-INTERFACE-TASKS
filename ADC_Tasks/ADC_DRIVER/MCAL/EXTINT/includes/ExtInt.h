/*
 * ExtInt.h
 *
 * Created: 10/22/2023 10:01:49 AM
 *  Author: sharb
 */ 


#ifndef EXTINT_H_
#define EXTINT_H_

// enum for EXT interrupt index
typedef enum
{
	EXT_INT0,
	EXT_INT1,
	EXT_INT2,
	EXT_INT_INDEX_MAX
}enum_EXT_INT_index_t;

// enum for EXT interrupt sense control
typedef enum
{
	EXT_INT_RISING_EDGE,
	EXT_INT_FALLING_EDGE,
	EXT_INT_LOW_LEVEL,
	EXT_INT_ANY_CHANGE,
	EXT_INT_SENSE_MAX
}enum_EXT_INT_SenseControl_t;

// enum for status codes
typedef enum
{
	EXT_INT_OKAY,
	EXT_INT_INDEX_ERROR,
	EXT_INT_SENSE_ERROR,
	EXT_INT_PTRNULL_ERROR,
}enum_EXT_INT_ERROR_t;


/*
NAME: EXTINT_enum_Init
DESC: init External interrupt and set sense control and set call back function
ARGS: enum_EXT_INT_index_t        ----------> EXT interrupt index
      enum_EXT_INT_SenseControl_t ----------> EXT interrupt Sense Control
	  void(*ptrFunc)()            ----------> Call back Function
RET : enum_EXT_INT_ERROR_t status code (EXT_INT_OKAY,EXT_INT_INDEX_ERROR,EXT_INT_SENSE_ERROR,EXT_INT_PTRNULL_ERROR)

*/
enum_EXT_INT_ERROR_t EXTINT_enum_Init(enum_EXT_INT_index_t arg_enum_ExtIntIndex,enum_EXT_INT_SenseControl_t arg_enum_SenseControl,void(*ptrFunc)(void));

#endif /* EXTINT_H_ */