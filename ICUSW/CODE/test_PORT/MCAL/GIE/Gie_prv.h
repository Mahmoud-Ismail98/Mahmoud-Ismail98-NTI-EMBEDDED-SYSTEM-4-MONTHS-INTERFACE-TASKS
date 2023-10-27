/*
 * GIE_PRV.h
 *
 * Created: 10/21/2023 11:44:23 AM
 *  Author: FADY
 */
#ifndef GIE_PRV
#define GIE_PRV
#include "../../SERVICES/Std_types.h"
#include "../../SERVICES/Bit_utils.h"

#define SREG    *((volatile u8*)0x5F)

/* SREG BITS */
#define SREG_globalInterruptEnable 7
#endif