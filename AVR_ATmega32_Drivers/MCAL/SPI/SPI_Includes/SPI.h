/*
 * SPI.h
 *
 * Created: 10/29/2023 12:34:10 PM
 *  Author: computer store
 */ 

#ifndef SPI_H_
#define SPI_H_

#include "Services/Std_types.h"

//==========================================
//user defined data types
//==========================================
typedef struct
{
	uint8 Master_Slave_Select;	
	uint8 Data_Order;
	uint8 SPI_Prescaler;
	uint8 Interrupt_State;
	void (* PRT_SPI_CallBack)(void);
}SPI_CFG_t;



//==========================================
//Configuration macros
//==========================================

//@ref Master_Slave_Select
#define SPI_Master						((uint8)1)
#define SPI_Slave						((uint8)0)

//@ref Data_Order
#define SPI_Data_Order_LSB				((uint8)1)
#define SPI_Data_Order_MSB				((uint8)0)


//@ref SPI_Prescaler
#define SPI_Prescaler_4					((uint8)0)
#define SPI_Prescaler_8					((uint8)1)
#define SPI_Prescaler_16				((uint8)2)
#define SPI_Prescaler_32				((uint8)3)
#define SPI_Prescaler_64				((uint8)4)
#define SPI_Prescaler_128				((uint8)5)


//@ref Interrupt_State
#define Interrupt_State_Disable			((uint8)0)
#define Interrupt_State_Enable			((uint8)1)

//==========================================
//prototypes
//==========================================
void SPI_Init(SPI_CFG_t* SPI_CFG);
void SPI_Transfer(uint8* Data);
void SPI_Slave_Set_Initial(uint8* Data);

#endif /* SPI_H_ */