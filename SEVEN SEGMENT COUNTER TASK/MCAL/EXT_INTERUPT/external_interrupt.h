

#ifndef EXTERNAL_INTERRUPT_H_
#define EXTERNAL_INTERRUPT_H_

#include "../../services/Std_types.h"

#define EXT0_PIN	PIN_ID26
#define EXT1_PIN	PIN_ID27
#define EXT2_PIN	PIN_ID27

typedef enum
{
	INT_LOW_LEVEL,
	INT_ANY_LOGIC_CHANGE,
	INT_FALLING_EDGE,
	INT_RISING_EDGE
} enum_external_int_type_t;

typedef enum
{
	EXT_INT0=6,
	EXT_INT1=7,
	EXT_INT2=5,
} enum_extenal_int_n_t;

void Enable_EXT_INT(u8 X);

void Disable_EXT_INT(u8 X);

void extrnal_int_init(enum_extenal_int_n_t X,enum_external_int_type_t int_type,void (*PTR_TO_FUN)());
void Global_Interrupt_EnablE(void);

#endif /* EXTERNAL_INTERRUPT_H_ */