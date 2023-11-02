/*
 * ExtInt_prv.h
 *
 * Created: 10/22/2023 10:22:13 AM
 *  Author: sharb
 */ 


#ifndef EXTINT_PRV_H_
#define EXTINT_PRV_H_

#include "std_types.h"
#include "ExtInt.h"

#define MCUCR  (*(vu8*)(0x55))
#define MCUCSR (*(vu8*)(0x54))
#define GICR   (*(vu8*)(0x5B))
#define GIFR   (*(vu8*)(0x5A))

static void EXT_INT_enable_PIE(enum_EXT_INT_index_t arg_enum_EXTINT_Index);

#define ISC00      0
#define ISC01      1
#define ISC10      2
#define ISC11      3

#define ISC2       6

#define INT0       6
#define INT1       7
#define INT2       5



#endif /* EXTINT_PRV_H_ */