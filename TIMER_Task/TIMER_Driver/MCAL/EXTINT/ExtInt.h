/*
 * ExtInt.h
 *
 * Created: 10/22/2023 10:01:49 AM
 *  Author: sharb
 */ 


#ifndef EXTINT_H_
#define EXTINT_H_

typedef enum
{
	EXT_INT0,
	EXT_INT1,
	EXT_INT2,
	EXT_INT_INDEX_MAX
}enum_EXT_INT_index_t;

typedef enum
{
	EXT_INT_RISING_EDGE,
	EXT_INT_FALLING_EDGE,
	EXT_INT_LOW_LEVEL,
	EXT_INT_ANY_CHANGE,
	EXT_INT_SENSE_MAX
}enum_EXT_INT_SenseControl_t;

typedef enum
{
	EXT_INT_OKAY,
	EXT_INT_INDEX_ERROR,
	EXT_INT_SENSE_ERROR,
	EXT_INT_PTRNULL_ERROR,
}enum_EXT_INT_ERROR_t;

enum_EXT_INT_ERROR_t EXTINT_enum_Init(enum_EXT_INT_index_t arg_enum_ExtIntIndex,enum_EXT_INT_SenseControl_t arg_enum_SenseControl,void(*ptrFunc)(void));
enum_EXT_INT_ERROR_t EXTINT_enum_DeInit(enum_EXT_INT_index_t arg_enum_ExtIntIndex);

#endif /* EXTINT_H_ */