/**************************************************************************/
/* Filename						: GPIO.h                                 */
/* Author  	    				: Muhammad Ammar                          */
/* Date 						: Nov 6, 2023  	           	 	         */
/* Version 	 					: V01                                     */
/* MicroController  			: STM32429 								   */
/* Trainee At					: NTI (4 Months)						  */
/* Instructor					: Mahmoud Embabi						  */
/**************************************************************************/


#ifndef GPIO_GPIO_H_
#define GPIO_GPIO_H_



/********************************** Includes *********************************************/



/********************************** Macros Declarations *******************************/



//

#define GPIO_PINA0  0
#define GPIO_PINA1  1
#define GPIO_PINA2  2
#define GPIO_PINA3  3
#define GPIO_PINA4  4
#define GPIO_PINA5  5
#define GPIO_PINA6  6
#define GPIO_PINA7  7
#define GPIO_PINA8  8
#define GPIO_PINA9  9
#define GPIO_PINA10 10
#define GPIO_PINA11 11
#define GPIO_PINA12 12
#define GPIO_PINA13 13
#define GPIO_PINA14 14
#define GPIO_PINA15 15

#define GPIO_PINB0  16
#define GPIO_PINB1  17
#define GPIO_PINB2  18
#define GPIO_PINB3  19
#define GPIO_PINB4  20
#define GPIO_PINB5  21
#define GPIO_PINB6  22
#define GPIO_PINB7  23
#define GPIO_PINB8  24
#define GPIO_PINB9  25
#define GPIO_PINB10 26
#define GPIO_PINB11 27
#define GPIO_PINB12 28
#define GPIO_PINB13 29
#define GPIO_PINB14 30
#define GPIO_PINB15 31

#define GPIO_PINC0  32
#define GPIO_PINC1  33
#define GPIO_PINC2  34
#define GPIO_PINC3  35
#define GPIO_PINC4  36
#define GPIO_PINC5  37
#define GPIO_PINC6  38
#define GPIO_PINC7  39
#define GPIO_PINC8  40
#define GPIO_PINC9  41
#define GPIO_PINC10 42
#define GPIO_PINC11 43
#define GPIO_PINC12 44
#define GPIO_PINC13 45
#define GPIO_PINC14 46
#define GPIO_PINC15 47

#define GPIO_PIND0  48
#define GPIO_PIND1  49
#define GPIO_PIND2  50
#define GPIO_PIND3  51
#define GPIO_PIND4  52
#define GPIO_PIND5  53
#define GPIO_PIND6  54
#define GPIO_PIND7  55
#define GPIO_PIND8  56
#define GPIO_PIND9  57
#define GPIO_PIND10 58
#define GPIO_PIND11 59
#define GPIO_PIND12 60
#define GPIO_PIND13 61
#define GPIO_PIND14 62
#define GPIO_PIND15 63

#define GPIO_PINE0  64
#define GPIO_PINE1  65
#define GPIO_PINE2  66
#define GPIO_PINE3  67
#define GPIO_PINE4  68
#define GPIO_PINE5  69
#define GPIO_PINE6  70
#define GPIO_PINE7  71
#define GPIO_PINE8  72
#define GPIO_PINE9  73
#define GPIO_PINE10 74
#define GPIO_PINE11 75
#define GPIO_PINE12 76
#define GPIO_PINE13 77
#define GPIO_PINE14 78
#define GPIO_PINE15 79

#define GPIO_PINF0  80
#define GPIO_PINF1  81
#define GPIO_PINF2  82
#define GPIO_PINF3  83
#define GPIO_PINF4  84
#define GPIO_PINF5  85
#define GPIO_PINF6  86
#define GPIO_PINF7  87
#define GPIO_PINF8  88
#define GPIO_PINF9  89
#define GPIO_PINF10 90
#define GPIO_PINF11 91
#define GPIO_PINF12 92
#define GPIO_PINF13 93
#define GPIO_PINF14 94
#define GPIO_PINF15 95

#define GPIO_PING0  96
#define GPIO_PING1  97
#define GPIO_PING2  98
#define GPIO_PING3  99
#define GPIO_PING4  100
#define GPIO_PING5  101
#define GPIO_PING6  102
#define GPIO_PING7  103
#define GPIO_PING8  104
#define GPIO_PING9  105
#define GPIO_PING10 106
#define GPIO_PING11 107
#define GPIO_PING12 108
#define GPIO_PING13 109
#define GPIO_PING14 110
#define GPIO_PING15 111

#define GPIO_PINH0  112
#define GPIO_PINH1  113
#define GPIO_PINH2  114
#define GPIO_PINH3  115
#define GPIO_PINH4  116
#define GPIO_PINH5  117
#define GPIO_PINH6  118
#define GPIO_PINH7  119
#define GPIO_PINH8  120
#define GPIO_PINH9  121
#define GPIO_PINH10 122
#define GPIO_PINH11 123
#define GPIO_PINH12 124
#define GPIO_PINH13 125
#define GPIO_PINH14 126
#define GPIO_PINH15 127
//
//#define GPIO_PINI0  128
//#define GPIO_PINI1  129
//#define GPIO_PINI2  130
//#define GPIO_PINI3  131
//#define GPIO_PINI4  132
//#define GPIO_PINI5  133
//#define GPIO_PINI6  134
//#define GPIO_PINI7  135
//#define GPIO_PINI8  136
//#define GPIO_PINI9  137
//#define GPIO_PINI10 138
//#define GPIO_PINI11 139
//#define GPIO_PINI12 140
//#define GPIO_PINI13 141
//#define GPIO_PINI14 142
//#define GPIO_PINI15 143
//
//#define GPIO_PINJ0  144
//#define GPIO_PINJ1  145
//#define GPIO_PINJ2  146
//#define GPIO_PINJ3  147
//#define GPIO_PINJ4  148
//#define GPIO_PINJ5  149
//#define GPIO_PINJ6  150
//#define GPIO_PINJ7  151
//#define GPIO_PINJ8  152
//#define GPIO_PINJ9  153
//#define GPIO_PINJ10 154
//#define GPIO_PINJ11 155
//#define GPIO_PINJ12 156
//#define GPIO_PINJ13 157
//#define GPIO_PINJ14 158
//#define GPIO_PINJ15 159
//
//#define GPIO_PINK0  160
//#define GPIO_PINK1  161
//#define GPIO_PINK2  162
//#define GPIO_PINK3  163
//#define GPIO_PINK4  164
//#define GPIO_PINK5  165
//#define GPIO_PINK6  166
//#define GPIO_PINK7  167
//#define GPIO_PINK8  168
//#define GPIO_PINK9  169
//#define GPIO_PINK10 170
//#define GPIO_PINK11 171
//#define GPIO_PINK12 172
//#define GPIO_PINK13 173
//#define GPIO_PINK14 174
//#define GPIO_PINK15 175







//// Output Push-Pull
//#define GPIO_MODE_OUTPUT_PUSHPULL_FLOAT_SPEED_LOW             0
//#define GPIO_MODE_OUTPUT_PUSHPULL_FLOAT_SPEED_MEDIUM          1
//#define GPIO_MODE_OUTPUT_PUSHPULL_FLOAT_SPEED_HIGH            2
//#define GPIO_MODE_OUTPUT_PUSHPULL_FLOAT_SPEED_VERYHIGH        3
//
//#define GPIO_MODE_OUTPUT_PUSHPULL_PULLUP_SPEED_LOW            4
//#define GPIO_MODE_OUTPUT_PUSHPULL_PULLUP_SPEED_MEDIUM         5
//#define GPIO_MODE_OUTPUT_PUSHPULL_PULLUP_SPEED_HIGH           6
//#define GPIO_MODE_OUTPUT_PUSHPULL_PULLUP_SPEED_VERYHIGH       7
//
//#define GPIO_MODE_OUTPUT_PUSHPULL_PULLDOWN_SPEED_LOW          8
//#define GPIO_MODE_OUTPUT_PUSHPULL_PULLDOWN_SPEED_MEDIUM       9
//#define GPIO_MODE_OUTPUT_PUSHPULL_PULLDOWN_SPEED_HIGH         10
//#define GPIO_MODE_OUTPUT_PUSHPULL_PULLDOWN_SPEED_VERYHIGH     11
//
//// Output Open-Drain
//#define GPIO_MODE_OUTPUT_OPENDRAIN_FLOAT_SPEED_LOW            12
//#define GPIO_MODE_OUTPUT_OPENDRAIN_FLOAT_SPEED_MEDIUM         13
//#define GPIO_MODE_OUTPUT_OPENDRAIN_FLOAT_SPEED_HIGH           14
//#define GPIO_MODE_OUTPUT_OPENDRAIN_FLOAT_SPEED_VERYHIGH       15
//#define GPIO_MODE_OUTPUT_OPENDRAIN_PULLUP_SPEED_LOW           16
//#define GPIO_MODE_OUTPUT_OPENDRAIN_PULLUP_SPEED_MEDIUM        17
//#define GPIO_MODE_OUTPUT_OPENDRAIN_PULLUP_SPEED_HIGH          18
//#define GPIO_MODE_OUTPUT_OPENDRAIN_PULLUP_SPEED_VERYHIGH      19
//#define GPIO_MODE_OUTPUT_OPENDRAIN_PULLDOWN_SPEED_LOW         20
//#define GPIO_MODE_OUTPUT_OPENDRAIN_PULLDOWN_SPEED_MEDIUM      21
//#define GPIO_MODE_OUTPUT_OPENDRAIN_PULLDOWN_SPEED_HIGH        22
//#define GPIO_MODE_OUTPUT_OPENDRAIN_PULLDOWN_SPEED_VERYHIGH    23
//
//// Alternate Function Push-Pull
//#define GPIO_MODE_AF_PUSHPULL_FLOAT_SPEED_LOW                 24
//#define GPIO_MODE_AF_PUSHPULL_FLOAT_SPEED_MEDIUM              25
//#define GPIO_MODE_AF_PUSHPULL_FLOAT_SPEED_HIGH                26
//#define GPIO_MODE_AF_PUSHPULL_FLOAT_SPEED_VERYHIGH            27
//#define GPIO_MODE_AF_PUSHPULL_PULLUP_SPEED_LOW                28
//#define GPIO_MODE_AF_PUSHPULL_PULLUP_SPEED_MEDIUM             29
//#define GPIO_MODE_AF_PUSHPULL_PULLUP_SPEED_HIGH               30
//#define GPIO_MODE_AF_PUSHPULL_PULLUP_SPEED_VERYHIGH           31
//#define GPIO_MODE_AF_PUSHPULL_PULLDOWN_SPEED_LOW              32
//#define GPIO_MODE_AF_PUSHPULL_PULLDOWN_SPEED_MEDIUM           33
//#define GPIO_MODE_AF_PUSHPULL_PULLDOWN_SPEED_HIGH             34
//#define GPIO_MODE_AF_PUSHPULL_PULLDOWN_SPEED_VERYHIGH         35
//
//// Alternate Function Open-Drain
//#define GPIO_MODE_AF_OPENDRAIN_FLOAT_SPEED_LOW                36
//#define GPIO_MODE_AF_OPENDRAIN_FLOAT_SPEED_MEDIUM             37
//#define GPIO_MODE_AF_OPENDRAIN_FLOAT_SPEED_HIGH               38
//#define GPIO_MODE_AF_OPENDRAIN_FLOAT_SPEED_VERYHIGH           39
//#define GPIO_MODE_AF_OPENDRAIN_PULLUP_SPEED_LOW               40
//#define GPIO_MODE_AF_OPENDRAIN_PULLUP_SPEED_MEDIUM            41
//#define GPIO_MODE_AF_OPENDRAIN_PULLUP_SPEED_HIGH              42
//#define GPIO_MODE_AF_OPENDRAIN_PULLUP_SPEED_VERYHIGH          43
//#define GPIO_MODE_AF_OPENDRAIN_PULLDOWN_SPEED_LOW             44
//#define GPIO_MODE_AF_OPENDRAIN_PULLDOWN_SPEED_MEDIUM          45
//#define GPIO_MODE_AF_OPENDRAIN_PULLDOWN_SPEED_HIGH            46
//#define GPIO_MODE_AF_OPENDRAIN_PULLDOWN_SPEED_VERYHIGH        47
//
//// Input Modes (No Speed)
//#define GPIO_MODE_INPUT_FLOAT                                48
//#define GPIO_MODE_INPUT_PULLUP                               49
//#define GPIO_MODE_INPUT_PULLDOWN                             50
//
//// Analog Modes (No Speed or Pull)
//#define GPIO_MODE_ANALOG                                     51
//


#define GPIO_PORTA 	0
#define GPIO_PORTB 	1
#define GPIO_PORTC 	2
#define GPIO_PORTD 	3
#define GPIO_PORTE 	4
#define GPIO_PORTF 	5
#define GPIO_PORTG	6
#define GPIO_PORTH	7

//#define GPIO_PORTI	8
//#define GPIO_PORTJ	9
//#define GPIO_PORTK	10


#define GPIO_HIGH 			ONE_VALUE
#define GPIO_LOW			ZERO_VALUE
/********************************** Macros Function Declarations *********************/


/********************************** Data Type Declarations ****************************/

typedef enum{
	GPIO_STATUS_FAIL,
	GPIO_STATUS_OK,
	GPIO_STATUS_WRONG_PIN_ID,
	GPIO_STATUS_WRONG_LEVEL,
	GPIO_STATUS_NULL_POINTER_ADDRESS,
	GPIO_STATUS_WRONG_PORT_ID,
	GPIO_STATUS_LOCKED_IS_FAILED
}Gpio_StatusErrorType;

typedef enum{
	GPIO_SELECT_PIN_MODE_INPUT=0b0000,
	GPIO_SELECT_PIN_MODE_OUTPUT_PUSH_PULL=0b0001,
	GPIO_SELECT_PIN_MODE_OUTPUT_OPEN_DRAIN=0b0101,
	GPIO_SELECT_PIN_MODE_AF=0b0010,
	GPIO_SELECT_PIN_MODE_ANALOG = 0b0011
}Gpio_SelectPinModeType;


typedef enum{
	GPIO_SELET_SPEED_LOW,
	GPIO_SELET_SPEED_MEDIUM,
	GPIO_SELET_SPEED_HIGH,
	GPIO_SELET_SPEED_VHIGH
}Gpio_SelectSpeedRegType;

typedef enum{
	GPIO_SELET_NO_PULLUP_NO_PULLDOWM,
	GPIO_SELET_PULLUP,
	GPIO_SELET_PULLDOWN
}Gpio_SelectPullUpPullDownType;


typedef struct{
	Gpio_SelectPinModeType gpio_select_pin_mode;
	Gpio_SelectSpeedRegType gpio_select_speed_reg;
	Gpio_SelectPullUpPullDownType gpio_select_pullup_pulldown;
	u8 gpio_pin_index;

}Gpio_PinConfigType;


/*
 * @ page 273
 */
typedef enum{
	GPIO_SELET_AF0_SYSTEM,
	GPIO_SELET_AF1_TIMER1_TIMER2,
	GPIO_SELET_AF2_TIMER3_TIMER4_TIMER5,
	GPIO_SELET_AF3_TIMER8_TIMER9_TIMER10_TIMER11,
	GPIO_SELET_AF4_I2C1_I2C2_I2C3,
	GPIO_SELET_AF5_SPI1_SPI2_SPI3_dot_SPI6,
	GPIO_SELET_AF6_SPI2_SPI3_SAI1,
	GPIO_SELET_AF7_USART1_USART2_USART3,
	GPIO_SELET_AF8_USART4_USART5_dot_USART8,
	GPIO_SELET_AF9_CAN1_CAN2_LTDC_TIM12_TIM13_TIM14,
	GPIO_SELET_AF10_OTG_FS_OTG_HS,
	GPIO_SELET_AF11_ETH,
	GPIO_SELET_AF12_FMC_SDIO_OTG_HS,
	GPIO_SELET_AF13_DCMI,
	GPIO_SELET_AF14_LTDC,
	GPIO_SELET_AF15_EVENTOUT
}Gpio_SelectAFType;

/********************************** Software Interfaces Declarations *******************/
Gpio_StatusErrorType Gpio_enuInit(void);
Gpio_StatusErrorType Gpio_eniInitPin(const Gpio_PinConfigType* Address_Pin);

Gpio_StatusErrorType Gpio_enuWriteChannel(u8 Copy_u8ChannelId,u8 Copy_u8Level);
Gpio_StatusErrorType Gpio_enuReadChannel(u8 Copy_u8ChannelId,pu8 Address_pu8ChannelLevel);

Gpio_StatusErrorType  Gpio_enuWritePort(u8 Copy_u8PortId,u16 Copy_u16Value);
Gpio_StatusErrorType  Gpio_enuReadPort(u8 Copy_u8PortId,pu16 Address_pu16PortVAlue);
Gpio_StatusErrorType  Gpio_enuFlipChannel(u8 Copy_u8ChannelId);

Gpio_StatusErrorType  Gpio_enuChangePinSpeed(u8 Copy_u8ChannelId, Gpio_SelectSpeedRegType Copy_enuSpeed);
Gpio_StatusErrorType  Gpio_enuChangePinPullupPulldown(u8 Copy_u8ChannelId, Gpio_SelectPullUpPullDownType Copy_enuPullUpPullDown);


Gpio_StatusErrorType Gpio_enuSetPinChannelAtomic(u8 Copy_u8ChannelId);
Gpio_StatusErrorType Gpio_enuClearPinChannelAtomic(u8 Copy_u8ChannelId);
Gpio_StatusErrorType Gpio_enuSetAF(u8 Copy_u8ChannelId,Gpio_SelectAFType Copy_enuAF);
Gpio_StatusErrorType Gpio_enuEnableLockPinRegister(u8 Copy_u8ChannelId);

Gpio_StatusErrorType Gpio_enuEnableClockGIPOx(u8 Copy_u8PortId);
Gpio_StatusErrorType Gpio_enuDisableClockGIPOx(u8 Copy_u8PortId);
Gpio_StatusErrorType Gpio_enuEnableClockAllGPIOs(void);


Gpio_StatusErrorType Gpio_enuEnableClockGIPOxInLowPowerMode(u8 Copy_u8PortId);
Gpio_StatusErrorType Gpio_enuDisableClockGIPOxInLowPowerMode(u8 Copy_u8PortId);
Gpio_StatusErrorType Gpio_enuEnableClockAllGPIOsInLowPowerMode(void);

#endif /* GPIO_GPIO_H_ */
