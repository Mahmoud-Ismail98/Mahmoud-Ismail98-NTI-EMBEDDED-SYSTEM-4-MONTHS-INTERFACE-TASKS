/*
 * spi.c
 *
 * Created: 10/28/2023 10:58:54 PM
 *  Author: sharpel
 */ 


#include "std_types.h"
#include "bit_math.h"
#include "vect_table.h"
#include "../includes/spi_prv.h"
#include "../includes/spi_cfg.h"
#include "../includes/spi.h"
#include "../../DIO/includes/Dio.h"



void (*gl_ptr_Func)(u8)            = PTR_NULL;
static u8   sgl_u8_interruptState  = FALSE;
static u8   sgl_u8_CurrentState    = FALSE;

SPI_ERROR_STATUS_t SPI_enum_Init(SPI_IdentitySelect_t arg_enum_Identity_select)
{
	SPI_ERROR_STATUS_t loc_enum_returnStatus = SPI_OKAY;
	if(arg_enum_Identity_select >= SPI_IDENTITY_MAX)
	{
		loc_enum_returnStatus = SPI_IDENTITY_ERROR;
		
	}
	else 
	{
		#if    SPI_DATA_ORDER  == SPI_DATA_ORDER_LSB
		SET_BIT(SPCR,DORD);
		#elif  SPI_DATA_ORDER  == SPI_DATA_ORDER_MSB
		CLR_BIT(SPCR,DORD);
		#else
		#error "SPI_DATA_ORDER CFG ERROR"
		#endif
		
		#if    SPI_CLK_POLARITY  == SPI_CLK_IDLE_LOW
		CLR_BIT(SPCR,CPOL);
		#elif  SPI_CLK_POLARITY  == SPI_CLK_IDLE_HIGH
		SET_BIT(SPCR,CPOL);
		#else
		#error "SPI_CLK_POLARITY CFG ERROR"
		#endif
		
		#if    SPI_CLK_PHASE  == SPI_CLK_PHASE_SETUP_LEADING
		SET_BIT(SPCR,CPHA);
		#elif  SPI_CLK_PHASE  == SPI_CLK_PHASE_SAMPLE_LEADING
		CLR_BIT(SPCR,CPHA);
		#else
		#error "SPI_CLK_PHASE CFG ERROR"
		#endif
		
		#if    SPI_CLK_RATE  == SPI_CLK_PRESCALER_4
		CLR_BIT(SPCR,SPR0);
		CLR_BIT(SPCR,SPR1);
		#elif  SPI_CLK_RATE  == SPI_CLK_PRESCALER_16
		SET_BIT(SPCR,SPR0);
		CLR_BIT(SPCR,SPR1);
		#elif  SPI_CLK_RATE  == SPI_CLK_PRESCALER_64
		CLR_BIT(SPCR,SPR0);
		SET_BIT(SPCR,SPR1);
		#elif  SPI_CLK_RATE  == SPI_CLK_PRESCALER_128
		SET_BIT(SPCR,SPR0);
		SET_BIT(SPCR,SPR1);
		#else
		#error "SPI_CLK_RATE CFG ERROR"
		#endif
		
		#if    SPI_DOUBLE_SPEED  == SPI_DOUBLE_SPEED_ON
		SET_BIT(SPSR,SPI2X);
		#elif  SPI_DOUBLE_SPEED  == SPI_DOUBLE_SPEED_OFF
		CLR_BIT(SPSR,SPI2X);
		#else
		#error "SPI_DOUBLE_SPEED CFG ERROR"
		#endif
		if (arg_enum_Identity_select == SPI_MASTER)
		{
		   // configure MOSI,CLK,SS as outputs MISO as input
		   PORT_enu_SetPinMode(MOSI_PIN,PIN_MODE_OUTPUT_HIGH);
		   PORT_enu_SetPinMode(CLK_PIN,PIN_MODE_OUTPUT_HIGH);
		   PORT_enu_SetPinMode(SS_PIN,PIN_MODE_OUTPUT_HIGH);
		   PORT_enu_SetPinMode(MISO_PIN,PIN_MODE_INPUT_LOW);
		   
		   
		   // configure MSTR BIT
		   sgl_u8_CurrentState = TRUE;
		   SET_BIT(SPCR,MSTR);
		   SET_BIT(SPCR,SPE);
		}
		else
		{
			// configure MOSI,CLK,SS as input MISO as output
			 PORT_enu_SetPinMode(MOSI_PIN,PIN_MODE_INPUT_PULLUP);
			 PORT_enu_SetPinMode(CLK_PIN, PIN_MODE_INPUT_PULLUP);
			 PORT_enu_SetPinMode(SS_PIN,  PIN_MODE_INPUT_PULLUP);
			 PORT_enu_SetPinMode(MISO_PIN,PIN_MODE_OUTPUT_HIGH);
			 SPDR = 0x0F;
			 // configure SLave
			 CLR_BIT(SPCR,MSTR);
			 SET_BIT(SPCR,SPE);
		}
		
		// enable spi
	}
	
	return loc_enum_returnStatus;
}
SPI_ERROR_STATUS_t SPI_enum_interruptStatus(SPI_Interrupt_Status_t arg_enum_interruptStatus)
{
	SPI_ERROR_STATUS_t loc_enum_returnStatus = SPI_OKAY;
	if(arg_enum_interruptStatus >= SPI_INTERRUPT_MAX)
	{
		loc_enum_returnStatus = SPI_INTERRUPT_ERROR;
		
	}
	else if (arg_enum_interruptStatus == SPI_INTERRUPT_ENABLE)
	{
		SET_BIT(SPCR,SPIE); 
		sgl_u8_interruptState = TRUE;
	}
	else if (arg_enum_interruptStatus == SPI_INTERRUPT_DISABLE)
	{
		CLR_BIT(SPCR,SPIE); 
		sgl_u8_interruptState = FALSE;
	}
	
	else
	{
	  // do nothing
	}
	return loc_enum_returnStatus;
}
SPI_ERROR_STATUS_t SPI_enum_SetCallBack(void(*ptrFunc)(u8))
{
	SPI_ERROR_STATUS_t loc_enum_returnStatus = SPI_OKAY;
	if(ptrFunc == PTR_NULL)
	{
		loc_enum_returnStatus = SPI_PTRNULL_ERROR;
	}
	else
	{
		gl_ptr_Func = ptrFunc;
	}
	
	return loc_enum_returnStatus;
	
}
u8 SPI_enum_TrancieveChar(u8 ptr_u8_data)
{
	if( sgl_u8_CurrentState == TRUE)
	{
		
		DIO_enu_WriteChannel(SS_PIN,DIO_PIN_LEVEL_LOW);
		SPDR = ptr_u8_data;
		while(!GET_BIT(SPSR,SPIF));
		DIO_enu_WriteChannel(SS_PIN,DIO_PIN_LEVEL_HIGH);
		
	}
	else
	{
		SPDR = 0;
		while(!GET_BIT(SPSR,SPIF));
	}	
	
	return SPDR;
}




ISR(SPI_STC_INT)
{
	u8 Loc_temp = SPDR;
	if(gl_ptr_Func != PTR_NULL)
	{
		gl_ptr_Func(Loc_temp);
	}
}

