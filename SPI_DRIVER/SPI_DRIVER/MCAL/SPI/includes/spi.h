/*
 * spi.h
 *
 * Created: 10/28/2023 10:59:39 PM
 *  Author: sharb
 */ 


#ifndef SPI_H_
#define SPI_H_

typedef enum
{
	SPI_MASTER,
	SPI_SLAVE,
	SPI_IDENTITY_MAX
}SPI_IdentitySelect_t;

typedef enum
{
	SPI_INTERRUPT_ENABLE,
	SPI_INTERRUPT_DISABLE,
	SPI_INTERRUPT_MAX
}SPI_Interrupt_Status_t;

typedef enum
{
	SPI_OKAY,
	SPI_IDENTITY_ERROR,
	SPI_INTERRUPT_ERROR,
	SPI_PTRNULL_ERROR

}SPI_ERROR_STATUS_t;


SPI_ERROR_STATUS_t SPI_enum_Init(SPI_IdentitySelect_t arg_enum_Identity_select);
SPI_ERROR_STATUS_t SPI_enum_interruptStatus(SPI_Interrupt_Status_t arg_enum_interruptStatus);
SPI_ERROR_STATUS_t SPI_enum_SetCallBack(void(*ptrFunc)(u8));
u8 SPI_enum_TrancieveChar(u8 ptr_u8_data);
#endif /* SPI_H_ */