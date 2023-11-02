
#ifndef SEVEN_SEG_H_
#define SEVEN_SEG_H_

#include <Services/Std_types.h>

#define SEVEN_SEG1		0
#define SEVEN_SEG2		1
#define SEVEN_SEG3		2
#define SEVEN_SEG4		3


//========================================================
//Seven segment APIs prototypes
//========================================================
void Seven_SEG_Init();
void Seven_SEG_Display(uint8 SEVEN_SEGx, uint8 Display_Value);


#endif /* COUNTER_7SEG_H_ */