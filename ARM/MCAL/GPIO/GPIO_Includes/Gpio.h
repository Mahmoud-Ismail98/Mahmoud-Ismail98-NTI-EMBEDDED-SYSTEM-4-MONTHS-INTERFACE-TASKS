
#ifndef GPIO_GPIO_INCLUDES_GPIO_H_
#define GPIO_GPIO_INCLUDES_GPIO_H_

#include <Services/Bit_utils.h>
#include <Services/Memory_Map.h>
#include <Services/Std_types.h>


////////////////////////////////////////////////////////////////////////////////
typedef enum{

	Gpio_enuOk,
	Gpio_WrongPinNumError,
	Gpio_WrongPortNumError,
	Gpio_WrongModeError,
	Gpio_WrongPuPdError,
	Gpio_WrongSpeedError,
	Gpio_WrongValueError,
	Gpio_WrongReadError,
	Gpio_WrongAFError

}Gpio_tenuErrorStatus;
////////////////////////////////CREATE THIS STRUCT///////////////////////////////////////////////
typedef struct{
uint32 gpio_mode_x;
uint32 gpio_Pull_x;
uint32 gpio_speed_x;
uint32 gpio_pin_x;
uint32 gpio_port_x;
}GpioPinCfg_t;

//////////////////////////STRUCT PORT OPTIONS////////////////////////////////////////////////////
#define GPIO_PORT_A											0
#define GPIO_PORT_B											1
#define GPIO_PORT_C											2
#define GPIO_PORT_D											3
#define GPIO_PORT_E											4
#define GPIO_PORT_H  										5
//////////////////////////STRUCT PINS OPTIONS//////////////////////////////////////////
#define GPIO_PIN_00         								0
#define GPIO_PIN_01        									1
#define GPIO_PIN_02         								2
#define GPIO_PIN_03         								3
#define GPIO_PIN_04         								4
#define GPIO_PIN_05         								5
#define GPIO_PIN_06         								6
#define GPIO_PIN_07         								7
#define GPIO_PIN_08         								8
#define GPIO_PIN_09         								9
#define GPIO_PIN_10         								10
#define GPIO_PIN_11         								11
#define GPIO_PIN_12         								12
#define GPIO_PIN_13         								13
#define GPIO_PIN_14         								14
#define GPIO_PIN_15         								15

//////////////////////////////STRUCT PULL OPTIONS////////////////////////////////////////
#define GPIO_PUPD_u32_FLOATING								((uint32) 0)
#define GPIO_PUPD_u32_PULL_UP								((uint32) 1)
#define GPIO_PUPD_u32_PULL_DOWN								((uint32) 2)

//////////////////////////////STRUCT MODE OPTIONS////////////////////////////////////////
#define GPIO_MODE_INPUT       								((uint32) 0)
#define GPIO_MODE_OUTPUT_PP									((uint32) 1)
#define GPIO_MODE_OUTPUT_OD									((uint32) 2)
#define GPIO_MODE_AF										((uint32) 3)
#define GPIO_MODE_ANALOG									((uint32) 4)

//////////////////////////////STRUCT SPEED OPTIONS///////////////////////////////////////
#define GPIO_SPEED_LOW      								((uint32) 0)
#define GPIO_SPEED_MEDIUM   								((uint32) 1)
#define GPIO_SPEED_HIGH     								((uint32) 2)
#define GPIO_SPEED_VHIGH    								((uint32) 3)

//////////////////////////////// PIN VALUE HIGH/LOW /////////////////////////////////////////
#define GPIO_PIN_HIGH										((uint32) 1)
#define GPIO_PIN_LOW										((uint32) 0)

/////////////////////////////// ALTERNATE FUNCTIONS OPTION///////////////////////////////////
#define GPIO_AF_0											((uint32)0)
#define GPIO_AF_1											((uint32)1)
#define GPIO_AF_2											((uint32)2)
#define GPIO_AF_3											((uint32)3)
#define GPIO_AF_4											((uint32)4)
#define GPIO_AF_5											((uint32)5)
#define GPIO_AF_6											((uint32)6)
#define GPIO_AF_7											((uint32)7)
#define GPIO_AF_8											((uint32)8)
#define GPIO_AF_9											((uint32)9)
#define GPIO_AF_10											((uint32)10)
#define GPIO_AF_11											((uint32)11)
#define GPIO_AF_12											((uint32)12)
#define GPIO_AF_13											((uint32)13)
#define GPIO_AF_14											((uint32)14)
#define GPIO_AF_15											((uint32)15)

//for moder_CFG (private)
#define GPIO_Input											((uint32)0)
#define GPIO_Output											((uint32)1)
#define GPIO_AF												((uint32)2)
#define GPIO_Analog											((uint32)3)

//for typer_CFG (private)
#define GPIO_Output_PP										((uint32)0)
#define GPIO_Output_OD										((uint32)1)

#define GPIO_PIN_UNLOCK										((uint32)0)
#define GPIO_PIN_LOCK										((uint32)1)


/////////////////////////////FUNCTIONS PROTOTYPES////////////////////////////////
Gpio_tenuErrorStatus Gpio_init(GpioPinCfg_t  *Add_CnfgStruct);
Gpio_tenuErrorStatus Gpio_setPinValue1(GpioPinCfg_t  *Add_pu32CnfgStatus , uint32 Copyu32PinValue);
Gpio_tenuErrorStatus Gpio_setPinValue2(uint32 Copy32Port ,uint32 Copyu32Pin ,uint32 Copyu32Value);
Gpio_tenuErrorStatus Gpio_readPinValue(GpioPinCfg_t  *Add_CnfgStruct , Puint32 Add_pu32PinValue);
Gpio_tenuErrorStatus Gpio_SetAlternateFunction(GpioPinCfg_t  *Add_CnfgStruct , uint32 CopyAF);
Gpio_tenuErrorStatus Gpio_LockPin(uint32 Copyu32Port ,uint32 Copyu32Pin[16]);

void GPIO_Init_Static1(uint32 GPIO_PORTx);
void GPIO_Init_Static2(uint32 GPIO_PORTx);
//////////////////////////////////////////////////////////////////////////////////

#endif
