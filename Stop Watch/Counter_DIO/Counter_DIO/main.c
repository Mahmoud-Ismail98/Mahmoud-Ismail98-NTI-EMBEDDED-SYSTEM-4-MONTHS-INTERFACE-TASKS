/*
 * Counter_DIO.c
 *
 * Created: 10/20/2023 3:23:00 PM
 * Author : Wael
 */ 
#include"Bit_utils.h"     
#include"Std_types.h"	 

#include "Dio.h"
#include "Port.h"
#include "SegBCD.h"

#define F_CPU 16000000
#include "util/delay.h"
int main(void)
{
	Port_vidInit();
	
	
    while (1) 
    {
		
		 SegBSD_vTime();

    }
}

