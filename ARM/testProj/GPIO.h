


#ifndef GPIO_H_
#define GPIO_H_


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

u64 gpio_mode_x;
u64 gpio_Pull_x	;
u64 gpio_speed_x;
u64 gpio_pin_x;
u64 gpio_port_x;

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
#define GPIO_PUPD_u32_FLOATING								0x00000003
#define GPIO_PUPD_u32_PULL_UP								  0x00000001
#define GPIO_PUPD_u32_PULL_DOWN								0x00000002
//////////////////////////////STRUCT MODE OPTIONS////////////////////////////////////////
#define GPIO_MODE_u64_OUTPUT_PP								((u64) 0x0000000000000001)

#define GPIO_MODE_u64_OUTPUT_OD								((u64) 0x0000000100000001)

#define GPIO_MODE_u64_INPUT       						((u64) 0x0000000000000000)

#define GPIO_MODE_u64_AF_PP									  ((u64) 0x0000000000000002)

#define GPIO_MODE_u64_AF_OD									  ((u64) 0x0000000100000002)

#define GPIO_MODE_u64_ANALOG								  ((u64) 0x0000000000000003)

//////////////////////////////STRUCT SPEED OPTIONS///////////////////////////////////////
#define GPIO_SPEED_LOW      								(0x00000000)
#define GPIO_SPEED_MEDIUM   								(0x00000001)
#define GPIO_SPEED_HIGH     								(0x00000002)
#define GPIO_SPEED_VHIGH    								(0x00000003)
//////////////////////////////// PIN VALUE HIGH/LOW /////////////////////////////////////////
#define GPIO_ODR_HIGH										    (0X00000006)
#define GPIO_ODR_LOW										    (0X00000007)
/////////////////////////////// ALTERNATE FUNCTIONS OPTION///////////////////////////////////
#define GPIO_AF_0											  (0x00000000)
#define GPIO_AF_1											  (0x00000001)
#define GPIO_AF_2											  (0x00000002)
#define GPIO_AF_3											  (0x00000003)
#define GPIO_AF_4											  (0x00000004)
#define GPIO_AF_5											  (0x00000005)
#define GPIO_AF_6											  (0x00000006)
#define GPIO_AF_7											  (0x00000007)
#define GPIO_AF_8											  (0x00000008)
#define GPIO_AF_9											  (0x00000009)
#define GPIO_AF_10											(0x0000000A)
#define GPIO_AF_11											(0x0000000B)
#define GPIO_AF_12											(0x0000000C)
#define GPIO_AF_13											(0x0000000D)
#define GPIO_AF_14											(0x0000000E)
#define GPIO_AF_15											(0x0000000F)
//////////////////////////////FUNCTIONS PROTOTYPES////////////////////////////////
void GPIO_voidInitCFG(void);
Gpio_tenuErrorStatus Gpio_init(GpioPinCfg_t  *Add_CnfgStruct);
Gpio_tenuErrorStatus Gpio_setPinValue(GpioPinCfg_t  *Add_pu8CnfgStatus , u8 Copyu8PinValue);
Gpio_tenuErrorStatus Gpio_setPinnValue(u8 Copyu8Port ,u8 Copyu8Pin ,u8 Copyu8Value);
Gpio_tenuErrorStatus Gpio_TGLPin(u8 Copyu8Port ,u8 Copyu8Pin);
Gpio_tenuErrorStatus Gpio_readPinValue(GpioPinCfg_t  *Add_CnfgStruct , pu32 Add_pu8PinValue);
Gpio_tenuErrorStatus Gpio_SetAlternateFunction(GpioPinCfg_t  *Add_CnfgStruct , u8 CopyAF);
//////////////////////////////////////////////////////////////////////////////////







#endif



