#ifndef EXT_H
#define EXT_H

#include "../../SERVICES/Std_types.h"
#include "../../SERVICES/Bit_utils.h"

#define EXT_RISING_EDGE     0
#define EXT_FALLING_EDGE    1
#define EXT_LOW_MODE        2
#define EXT_ON_CHANGE       3

#define EXT_0           0
#define EXT_1           1
#define EXT_2           2



typedef enum EXT_ErorStatus{
EX_OK,EX_WRONGMODE,EX_WRONGNUM
}EXT_ErorStatus;


EXT_ErorStatus EXT_InterruptPirefralEnable(u8 Copy_u8EXTx,u8 Copy_u8Mode);
EXT_ErorStatus EXT_InterruptPirefralDisable(u8 Copy_u8EXTx);

#endif
