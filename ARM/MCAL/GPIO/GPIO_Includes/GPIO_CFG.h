/*
 * GPIO_Private.h
 *
 *  Created on: Nov 6, 2023
 *      Author: computer store
 */
#ifndef GPIO_GPIO_INCLUDES_GPIO_CFG_H_
#define GPIO_GPIO_INCLUDES_GPIO_CFG_H_

#include <MCAL/GPIO/GPIO_Includes/Gpio.h>

//==============================================================================
//Method 2 for GPIO_Init_Static2
//==============================================================================

// those macros are used with GPIOx_MODER macro
#define Input				00
#define output				01
#define AF					10
#define Analog				11

// those macros are used with GPIOx_OTYPER macro
#define Output_PP 			0
#define Output_OD 			1

// those macros are used with GPIOx_OSPEEDR macro
#define Low_speed			00
#define Medium_speed		01
#define High_speed			10
#define Very_high_speed		11

// those macros are used with GPIOx_PUPDR macro
#define Floating			00
#define Pull_Up				01
#define Pull_Down			10

//GPIOA
#define GPIOA_MODER		CONC_16Values(/*PA15*/ Input,/*PA14*/ Input,/*PA13*/ Input,/*PA12*/ Input,/*PA11*/output,/*PA10*/output,/*PA9*/output,/*PA8*/ output, /*PA7*/ AF,/*PA6*/ AF,/*PA5*/ AF,/*PA4*/ AF,/*PA3*/ Analog,/*PA2*/ Analog,/*PA1*/ Analog,/*PA0*/ Analog)
#define GPIOA_OTYPER 	CONC_16Values(/*PA15*/ Output_PP,/*PA14*/ Output_PP,/*PA13*/ Output_PP,/*PA12*/ Output_PP,/*PA11*/Output_PP,/*PA10*/Output_PP,/*PA9*/Output_PP,/*PA8*/ Output_PP, /*PA7*/ Output_OD,/*PA6*/ Output_OD,/*PA5*/ Output_OD,/*PA4*/ Output_OD,/*PA3*/ Output_OD,/*PA2*/ Output_OD,/*PA1*/ Output_OD,/*PA0*/ Output_OD)
#define GPIOA_OSPEEDR 	CONC_16Values(/*PA15*/ Low_speed,/*PA14*/ Low_speed,/*PA13*/ Low_speed,/*PA12*/ Low_speed,/*PA11*/Medium_speed,/*PA10*/Medium_speed,/*PA9*/Medium_speed,/*PA8*/ Medium_speed, /*PA7*/ High_speed,/*PA6*/ High_speed,/*PA5*/ High_speed,/*PA4*/ High_speed,/*PA3*/ Very_high_speed,/*PA2*/ Very_high_speed,/*PA1*/ Very_high_speed,/*PA0*/ Very_high_speed)
#define GPIOA_PUPDR	 	CONC_16Values(/*PA15*/ Floating,/*PA14*/ Floating,/*PA13*/ Floating,/*PA12*/ Floating,/*PA11*/Pull_Up,/*PA10*/Pull_Up,/*PA9*/Pull_Up,/*PA8*/ Pull_Up, /*PA7*/ High_speed,/*PA6*/ High_speed,/*PA5*/ High_speed,/*PA4*/ High_speed,/*PA3*/ Pull_Down,/*PA2*/ Pull_Down,/*PA1*/ Pull_Down,/*PA0*/ Pull_Down)

//GPIOB
#define GPIOB_MODER	 	CONC_16Values(/*PB15*/ Input,/*PB14*/ Input,/*PB13*/ Input,/*PB12*/ Input,/*PB11*/output,/*PB10*/output,/*PB9*/output,/*PB8*/ output, /*PB7*/ AF,/*PB6*/ AF,/*PB5*/ AF,/*PB4*/ AF,/*PB3*/ Analog,/*PB2*/ Analog,/*PB1*/ Analog,/*PB0*/ Analog)
#define GPIOB_OTYPER 	CONC_16Values(/*PB15*/ Output_PP,/*PB14*/ Output_PP,/*PB13*/ Output_PP,/*PB12*/ Output_PP,/*PB11*/Output_PP,/*PB10*/Output_PP,/*PB9*/Output_PP,/*PB8*/ Output_PP, /*PB7*/ Output_OD,/*PB6*/ Output_OD,/*PB5*/ Output_OD,/*PB4*/ Output_OD,/*PB3*/ Output_OD,/*PB2*/ Output_OD,/*PB1*/ Output_OD,/*PB0*/ Output_OD)
#define GPIOB_OSPEEDR	CONC_16Values(/*PB15*/ Low_speed,/*PB14*/ Low_speed,/*PB13*/ Low_speed,/*PB12*/ Low_speed,/*PB11*/Medium_speed,/*PB10*/Medium_speed,/*PB9*/Medium_speed,/*PB8*/ Medium_speed, /*PB7*/ High_speed,/*PB6*/ High_speed,/*PB5*/ High_speed,/*PB4*/ High_speed,/*PB3*/ Very_high_speed,/*PB2*/ Very_high_speed,/*PB1*/ Very_high_speed,/*PB0*/ Very_high_speed)
#define GPIOB_PUPDR		CONC_16Values(/*PB15*/ Floating,/*PB14*/ Floating,/*PB13*/ Floating,/*PB12*/ Floating,/*PB11*/Pull_Up,/*PB10*/Pull_Up,/*PB9*/Pull_Up,/*PB8*/ Pull_Up, /*PB7*/ Pull_Up,/*PB6*/ Pull_Up,/*PB5*/ Pull_Up,/*PB4*/ Pull_Up,/*PB3*/ Pull_Down,/*PB2*/ Pull_Down,/*PB1*/ Pull_Down,/*PB0*/ Pull_Down)

//GPIOC
#define GPIOC_MODER	 	CONC_16Values(/*PC15*/ Input,/*PC14*/ Input,/*PC13*/ Input,/*PC12*/ Input,/*PC11*/output,/*PC10*/output,/*PC9*/output,/*PC8*/ output, /*PC7*/ AF,/*PC6*/ AF,/*PC5*/ AF,/*PC4*/ AF,/*PC3*/ Analog,/*PC2*/ Analog,/*PC1*/ Analog,/*PC0*/ Analog)
#define GPIOC_OTYPER 	CONC_16Values(/*PC15*/ Output_PP,/*PC14*/ Output_PP,/*PC13*/ Output_PP,/*PC12*/ Output_PP,/*PC11*/Output_PP,/*PC10*/Output_PP,/*PC9*/Output_PP,/*PC8*/ Output_PP, /*PC7*/ Output_OD,/*PC6*/ Output_OD,/*PC5*/ Output_OD,/*PC4*/ Output_OD,/*PC3*/ Output_OD,/*PC2*/ Output_OD,/*PC1*/ Output_OD,/*PC0*/ Output_OD)
#define GPIOC_OSPEEDR	CONC_16Values(/*PC15*/ Low_speed,/*PC14*/ Low_speed,/*PC13*/ Low_speed,/*PC12*/ Low_speed,/*PC11*/Medium_speed,/*PC10*/Medium_speed,/*PC9*/Medium_speed,/*PC8*/ Medium_speed, /*PC7*/ High_speed,/*PC6*/ High_speed,/*PC5*/ High_speed,/*PC4*/ High_speed,/*PC3*/ Very_high_speed,/*PC2*/ Very_high_speed,/*PC1*/ Very_high_speed,/*PC0*/ Very_high_speed)
#define GPIOC_PUPDR		CONC_16Values(/*PC15*/ Floating,/*PC14*/ Floating,/*PC13*/ Floating,/*PC12*/ Floating,/*PC11*/Pull_Up,/*PC10*/Pull_Up,/*PC9*/Pull_Up,/*PC8*/ Pull_Up, /*PC7*/ Pull_Up,/*PC6*/ Pull_Up,/*PC5*/ Pull_Up,/*PC4*/ Pull_Up,/*PC3*/ Pull_Down,/*PC2*/ Pull_Down,/*PC1*/ Pull_Down,/*PC0*/ Pull_Down)

//GPIOD
#define GPIOD_MODER		CONC_16Values(/*PD15*/ Input,/*PD14*/ Input,/*PD13*/ Input,/*PD12*/ Input,/*PD11*/output,/*PD10*/output,/*PD9*/output,/*PD8*/ output, /*PD7*/ AF,/*PD6*/ AF,/*PD5*/ AF,/*PD4*/ AF,/*PD3*/ Analog,/*PD2*/ Analog,/*PD1*/ Analog,/*PD0*/ Analog)
#define GPIOD_OTYPER 	CONC_16Values(/*PD15*/ Output_PP,/*PD14*/ Output_PP,/*PD13*/ Output_PP,/*PD12*/ Output_PP,/*PD11*/Output_PP,/*PD10*/Output_PP,/*PD9*/Output_PP,/*PD8*/ Output_PP, /*PD7*/ Output_OD,/*PD6*/ Output_OD,/*PD5*/ Output_OD,/*PD4*/ Output_OD,/*PD3*/ Output_OD,/*PD2*/ Output_OD,/*PD1*/ Output_OD,/*PD0*/ Output_OD)
#define GPIOD_OSPEEDR 	CONC_16Values(/*PD15*/ Low_speed,/*PD14*/ Low_speed,/*PD13*/ Low_speed,/*PD12*/ Low_speed,/*PD11*/Medium_speed,/*PD10*/Medium_speed,/*PD9*/Medium_speed,/*PD8*/ Medium_speed, /*PD7*/ High_speed,/*PD6*/ High_speed,/*PD5*/ High_speed,/*PD4*/ High_speed,/*PD3*/ Very_high_speed,/*PD2*/ Very_high_speed,/*PD1*/ Very_high_speed,/*PD0*/ Very_high_speed)
#define GPIOD_PUPDR	 	CONC_16Values(/*PD15*/ Floating,/*PD14*/ Floating,/*PD13*/ Floating,/*PD12*/ Floating,/*PD11*/Pull_Up,/*PD10*/Pull_Up,/*PD9*/Pull_Up,/*PD8*/ Pull_Up, /*PD7*/ Pull_Up,/*PD6*/ Pull_Up,/*PD5*/ Pull_Up,/*PD4*/ Pull_Up,/*PD3*/ Pull_Down,/*PD2*/ Pull_Down,/*PD1*/ Pull_Down,/*PD0*/ Pull_Down)

//GPIOE
#define GPIOE_MODER		CONC_16Values(/*PE15*/ Input,/*PE14*/ Input,/*PE13*/ Input,/*PE12*/ Input,/*PE11*/output,/*PE10*/output,/*PE9*/output,/*PE8*/ output, /*PE7*/ AF,/*PE6*/ AF,/*PE5*/ AF,/*PE4*/ AF,/*PE3*/ Analog,/*PE2*/ Analog,/*PE1*/ Analog,/*PE0*/ Analog)
#define GPIOE_OTYPER 	CONC_16Values(/*PE15*/ Output_PP,/*PE14*/ Output_PP,/*PE13*/ Output_PP,/*PE12*/ Output_PP,/*PE11*/Output_PP,/*PE10*/Output_PP,/*PE9*/Output_PP,/*PE8*/ Output_PP, /*PE7*/ Output_OD,/*PE6*/ Output_OD,/*PE5*/ Output_OD,/*PE4*/ Output_OD,/*PE3*/ Output_OD,/*PE2*/ Output_OD,/*PE1*/ Output_OD,/*PE0*/ Output_OD)
#define GPIOE_OSPEEDR 	CONC_16Values(/*PE15*/ Low_speed,/*PE14*/ Low_speed,/*PE13*/ Low_speed,/*PE12*/ Low_speed,/*PE11*/Medium_speed,/*PE10*/Medium_speed,/*PE9*/Medium_speed,/*PE8*/ Medium_speed, /*PE7*/ High_speed,/*PE6*/ High_speed,/*PE5*/ High_speed,/*PE4*/ High_speed,/*PE3*/ Very_high_speed,/*PE2*/ Very_high_speed,/*PE1*/ Very_high_speed,/*PE0*/ Very_high_speed)
#define GPIOE_PUPDR	 	CONC_16Values(/*PE15*/ Floating,/*PE14*/ Floating,/*PE13*/ Floating,/*PE12*/ Floating,/*PE11*/Pull_Up,/*PE10*/Pull_Up,/*PE9*/Pull_Up,/*PE8*/ Pull_Up, /*PE7*/ Pull_Up,/*PE6*/ Pull_Up,/*PE5*/ Pull_Up,/*PE4*/ Pull_Up,/*PE3*/ Pull_Down,/*PE2*/ Pull_Down,/*PE1*/ Pull_Down,/*PE0*/ Pull_Down)

//GPIOH
#define GPIOH_MODER		CONC_16Values(/*PH15*/ Input,/*PH14*/ Input,/*PH13*/ Input,/*PH12*/ Input,/*PH11*/output,/*PH10*/output,/*PH9*/output,/*PH8*/ output, /*PH7*/ AF,/*PH6*/ AF,/*PH5*/ AF,/*PH4*/ AF,/*PH3*/ Analog,/*PH2*/ Analog,/*PH1*/ Analog,/*PH0*/ Analog)
#define GPIOH_OTYPER 	CONC_16Values(/*PH15*/ Output_PP,/*PH14*/ Output_PP,/*PH13*/ Output_PP,/*PH12*/ Output_PP,/*PH11*/Output_PP,/*PH10*/Output_PP,/*PH9*/Output_PP,/*PH8*/ Output_PP, /*PH7*/ Output_OD,/*PH6*/ Output_OD,/*PH5*/ Output_OD,/*PH4*/ Output_OD,/*PH3*/ Output_OD,/*PH2*/ Output_OD,/*PH1*/ Output_OD,/*PH0*/ Output_OD)
#define GPIOH_OSPEEDR 	CONC_16Values(/*PH15*/ Low_speed,/*PH14*/ Low_speed,/*PH13*/ Low_speed,/*PH12*/ Low_speed,/*PH11*/Medium_speed,/*PH10*/Medium_speed,/*PH9*/Medium_speed,/*PH8*/ Medium_speed, /*PH7*/ High_speed,/*PH6*/ High_speed,/*PH5*/ High_speed,/*PH4*/ High_speed,/*PH3*/ Very_high_speed,/*PH2*/ Very_high_speed,/*PH1*/ Very_high_speed,/*PH0*/ Very_high_speed)
#define GPIOH_PUPDR	 	CONC_16Values(/*PH15*/ Floating,/*PH14*/ Floating,/*PH13*/ Floating,/*PH12*/ Floating,/*PH11*/Pull_Up,/*PH10*/Pull_Up,/*PH9*/Pull_Up,/*PH8*/ Pull_Up, /*PH7*/ Pull_Up,/*PH6*/ Pull_Up,/*PH5*/ Pull_Up,/*PH4*/ Pull_Up,/*PH3*/ Pull_Down,/*PH2*/ Pull_Down,/*PH1*/ Pull_Down,/*PH0*/ Pull_Down)

GPIOx_First_4Reg_t GPIOA_First_4Reg_CFG = {{GPIOA_MODER, GPIOA_OTYPER, GPIOA_OSPEEDR, GPIOA_PUPDR}};
GPIOx_First_4Reg_t GPIOB_First_4Reg_CFG = {{GPIOB_MODER, GPIOB_OTYPER, GPIOB_OSPEEDR, GPIOB_PUPDR}};
GPIOx_First_4Reg_t GPIOC_First_4Reg_CFG = {{GPIOC_MODER, GPIOC_OTYPER, GPIOC_OSPEEDR, GPIOC_PUPDR}};
GPIOx_First_4Reg_t GPIOD_First_4Reg_CFG = {{GPIOD_MODER, GPIOD_OTYPER, GPIOD_OSPEEDR, GPIOD_PUPDR}};
GPIOx_First_4Reg_t GPIOE_First_4Reg_CFG = {{GPIOE_MODER, GPIOE_OTYPER, GPIOE_OSPEEDR, GPIOE_PUPDR}};
GPIOx_First_4Reg_t GPIOH_First_4Reg_CFG = {{GPIOH_MODER, GPIOH_OTYPER, GPIOH_OSPEEDR, GPIOH_PUPDR}};

#define GPIOA_First_4Reg ((GPIOx_First_4Reg_t*)(GPIOA_Base_Address))
#define GPIOB_First_4Reg ((GPIOx_First_4Reg_t*)(GPIOB_Base_Address))
#define GPIOC_First_4Reg ((GPIOx_First_4Reg_t*)(GPIOC_Base_Address))
#define GPIOD_First_4Reg ((GPIOx_First_4Reg_t*)(GPIOD_Base_Address))
#define GPIOE_First_4Reg ((GPIOx_First_4Reg_t*)(GPIOE_Base_Address))
#define GPIOH_First_4Reg ((GPIOx_First_4Reg_t*)(GPIOH_Base_Address))


//==============================================================================
//Method 1 for GPIO_Init_Static1
//==============================================================================

//GPIOA
GpioPinCfg_t GPIOA_PINx_CFG[16] = {
									 {GPIO_MODE_OUTPUT_OD, GPIO_PUPD_u32_PULL_DOWN, GPIO_SPEED_VHIGH, GPIO_PIN_00, GPIO_PORT_A},
									 {GPIO_MODE_OUTPUT_OD, GPIO_PUPD_u32_PULL_DOWN, GPIO_SPEED_VHIGH, GPIO_PIN_01, GPIO_PORT_A},
									 {GPIO_MODE_OUTPUT_OD, GPIO_PUPD_u32_PULL_DOWN, GPIO_SPEED_VHIGH, GPIO_PIN_02, GPIO_PORT_A},
									 {GPIO_MODE_OUTPUT_OD, GPIO_PUPD_u32_PULL_DOWN, GPIO_SPEED_VHIGH, GPIO_PIN_03, GPIO_PORT_A},
									 {GPIO_MODE_OUTPUT_OD, GPIO_PUPD_u32_PULL_DOWN, GPIO_SPEED_VHIGH, GPIO_PIN_04, GPIO_PORT_A},
									 {GPIO_MODE_OUTPUT_OD, GPIO_PUPD_u32_PULL_DOWN, GPIO_SPEED_VHIGH, GPIO_PIN_05, GPIO_PORT_A},
									 {GPIO_MODE_OUTPUT_OD, GPIO_PUPD_u32_PULL_DOWN, GPIO_SPEED_VHIGH, GPIO_PIN_06, GPIO_PORT_A},
									 {GPIO_MODE_OUTPUT_OD, GPIO_PUPD_u32_PULL_DOWN, GPIO_SPEED_VHIGH, GPIO_PIN_07, GPIO_PORT_A},
									 {GPIO_MODE_OUTPUT_OD, GPIO_PUPD_u32_PULL_DOWN, GPIO_SPEED_VHIGH, GPIO_PIN_08, GPIO_PORT_A},
									 {GPIO_MODE_OUTPUT_OD, GPIO_PUPD_u32_PULL_DOWN, GPIO_SPEED_VHIGH, GPIO_PIN_09, GPIO_PORT_A},
									 {GPIO_MODE_OUTPUT_OD, GPIO_PUPD_u32_PULL_DOWN, GPIO_SPEED_VHIGH, GPIO_PIN_10, GPIO_PORT_A},
									 {GPIO_MODE_OUTPUT_OD, GPIO_PUPD_u32_PULL_DOWN, GPIO_SPEED_VHIGH, GPIO_PIN_11, GPIO_PORT_A},
									 {GPIO_MODE_OUTPUT_OD, GPIO_PUPD_u32_PULL_DOWN, GPIO_SPEED_VHIGH, GPIO_PIN_12, GPIO_PORT_A},
									 {GPIO_MODE_OUTPUT_OD, GPIO_PUPD_u32_PULL_DOWN, GPIO_SPEED_VHIGH, GPIO_PIN_13, GPIO_PORT_A},
									 {GPIO_MODE_OUTPUT_OD, GPIO_PUPD_u32_PULL_DOWN, GPIO_SPEED_VHIGH, GPIO_PIN_14, GPIO_PORT_A},
									 {GPIO_MODE_OUTPUT_OD, GPIO_PUPD_u32_PULL_DOWN, GPIO_SPEED_VHIGH, GPIO_PIN_15, GPIO_PORT_A}
									};

GpioPinCfg_t GPIOB_PINx_CFG[16] = {
									 {GPIO_MODE_OUTPUT_OD, GPIO_PUPD_u32_PULL_DOWN, GPIO_SPEED_VHIGH, GPIO_PIN_00, GPIO_PORT_B},
									 {GPIO_MODE_OUTPUT_OD, GPIO_PUPD_u32_PULL_DOWN, GPIO_SPEED_VHIGH, GPIO_PIN_01, GPIO_PORT_B},
									 {GPIO_MODE_OUTPUT_OD, GPIO_PUPD_u32_PULL_DOWN, GPIO_SPEED_VHIGH, GPIO_PIN_02, GPIO_PORT_B},
									 {GPIO_MODE_OUTPUT_OD, GPIO_PUPD_u32_PULL_DOWN, GPIO_SPEED_VHIGH, GPIO_PIN_03, GPIO_PORT_B},
									 {GPIO_MODE_OUTPUT_OD, GPIO_PUPD_u32_PULL_DOWN, GPIO_SPEED_VHIGH, GPIO_PIN_04, GPIO_PORT_B},
									 {GPIO_MODE_OUTPUT_OD, GPIO_PUPD_u32_PULL_DOWN, GPIO_SPEED_VHIGH, GPIO_PIN_05, GPIO_PORT_B},
									 {GPIO_MODE_OUTPUT_OD, GPIO_PUPD_u32_PULL_DOWN, GPIO_SPEED_VHIGH, GPIO_PIN_06, GPIO_PORT_B},
									 {GPIO_MODE_OUTPUT_OD, GPIO_PUPD_u32_PULL_DOWN, GPIO_SPEED_VHIGH, GPIO_PIN_07, GPIO_PORT_B},
									 {GPIO_MODE_OUTPUT_OD, GPIO_PUPD_u32_PULL_DOWN, GPIO_SPEED_VHIGH, GPIO_PIN_08, GPIO_PORT_B},
									 {GPIO_MODE_OUTPUT_OD, GPIO_PUPD_u32_PULL_DOWN, GPIO_SPEED_VHIGH, GPIO_PIN_09, GPIO_PORT_B},
									 {GPIO_MODE_OUTPUT_OD, GPIO_PUPD_u32_PULL_DOWN, GPIO_SPEED_VHIGH, GPIO_PIN_10, GPIO_PORT_B},
									 {GPIO_MODE_OUTPUT_OD, GPIO_PUPD_u32_PULL_DOWN, GPIO_SPEED_VHIGH, GPIO_PIN_11, GPIO_PORT_B},
									 {GPIO_MODE_OUTPUT_OD, GPIO_PUPD_u32_PULL_DOWN, GPIO_SPEED_VHIGH, GPIO_PIN_12, GPIO_PORT_B},
									 {GPIO_MODE_OUTPUT_OD, GPIO_PUPD_u32_PULL_DOWN, GPIO_SPEED_VHIGH, GPIO_PIN_13, GPIO_PORT_B},
									 {GPIO_MODE_OUTPUT_OD, GPIO_PUPD_u32_PULL_DOWN, GPIO_SPEED_VHIGH, GPIO_PIN_14, GPIO_PORT_B},
									 {GPIO_MODE_OUTPUT_OD, GPIO_PUPD_u32_PULL_DOWN, GPIO_SPEED_VHIGH, GPIO_PIN_15, GPIO_PORT_B}
									};

GpioPinCfg_t GPIOC_PINx_CFG[16] = {
									 {GPIO_MODE_OUTPUT_OD, GPIO_PUPD_u32_PULL_DOWN, GPIO_SPEED_VHIGH, GPIO_PIN_00, GPIO_PORT_C},
									 {GPIO_MODE_OUTPUT_OD, GPIO_PUPD_u32_PULL_DOWN, GPIO_SPEED_VHIGH, GPIO_PIN_01, GPIO_PORT_C},
									 {GPIO_MODE_OUTPUT_OD, GPIO_PUPD_u32_PULL_DOWN, GPIO_SPEED_VHIGH, GPIO_PIN_02, GPIO_PORT_C},
									 {GPIO_MODE_OUTPUT_OD, GPIO_PUPD_u32_PULL_DOWN, GPIO_SPEED_VHIGH, GPIO_PIN_03, GPIO_PORT_C},
									 {GPIO_MODE_OUTPUT_OD, GPIO_PUPD_u32_PULL_DOWN, GPIO_SPEED_VHIGH, GPIO_PIN_04, GPIO_PORT_C},
									 {GPIO_MODE_OUTPUT_OD, GPIO_PUPD_u32_PULL_DOWN, GPIO_SPEED_VHIGH, GPIO_PIN_05, GPIO_PORT_C},
									 {GPIO_MODE_OUTPUT_OD, GPIO_PUPD_u32_PULL_DOWN, GPIO_SPEED_VHIGH, GPIO_PIN_06, GPIO_PORT_C},
									 {GPIO_MODE_OUTPUT_OD, GPIO_PUPD_u32_PULL_DOWN, GPIO_SPEED_VHIGH, GPIO_PIN_07, GPIO_PORT_C},
									 {GPIO_MODE_OUTPUT_OD, GPIO_PUPD_u32_PULL_DOWN, GPIO_SPEED_VHIGH, GPIO_PIN_08, GPIO_PORT_C},
									 {GPIO_MODE_OUTPUT_OD, GPIO_PUPD_u32_PULL_DOWN, GPIO_SPEED_VHIGH, GPIO_PIN_09, GPIO_PORT_C},
									 {GPIO_MODE_OUTPUT_OD, GPIO_PUPD_u32_PULL_DOWN, GPIO_SPEED_VHIGH, GPIO_PIN_10, GPIO_PORT_C},
									 {GPIO_MODE_OUTPUT_OD, GPIO_PUPD_u32_PULL_DOWN, GPIO_SPEED_VHIGH, GPIO_PIN_11, GPIO_PORT_C},
									 {GPIO_MODE_OUTPUT_OD, GPIO_PUPD_u32_PULL_DOWN, GPIO_SPEED_VHIGH, GPIO_PIN_12, GPIO_PORT_C},
									 {GPIO_MODE_OUTPUT_OD, GPIO_PUPD_u32_PULL_DOWN, GPIO_SPEED_VHIGH, GPIO_PIN_13, GPIO_PORT_C},
									 {GPIO_MODE_OUTPUT_OD, GPIO_PUPD_u32_PULL_DOWN, GPIO_SPEED_VHIGH, GPIO_PIN_14, GPIO_PORT_C},
									 {GPIO_MODE_OUTPUT_OD, GPIO_PUPD_u32_PULL_DOWN, GPIO_SPEED_VHIGH, GPIO_PIN_15, GPIO_PORT_C}
									};

GpioPinCfg_t GPIOD_PINx_CFG[16] = {
									 {GPIO_MODE_OUTPUT_OD, GPIO_PUPD_u32_PULL_DOWN, GPIO_SPEED_VHIGH, GPIO_PIN_00, GPIO_PORT_D},
									 {GPIO_MODE_OUTPUT_OD, GPIO_PUPD_u32_PULL_DOWN, GPIO_SPEED_VHIGH, GPIO_PIN_01, GPIO_PORT_D},
									 {GPIO_MODE_OUTPUT_OD, GPIO_PUPD_u32_PULL_DOWN, GPIO_SPEED_VHIGH, GPIO_PIN_02, GPIO_PORT_D},
									 {GPIO_MODE_OUTPUT_OD, GPIO_PUPD_u32_PULL_DOWN, GPIO_SPEED_VHIGH, GPIO_PIN_03, GPIO_PORT_D},
									 {GPIO_MODE_OUTPUT_OD, GPIO_PUPD_u32_PULL_DOWN, GPIO_SPEED_VHIGH, GPIO_PIN_04, GPIO_PORT_D},
									 {GPIO_MODE_OUTPUT_OD, GPIO_PUPD_u32_PULL_DOWN, GPIO_SPEED_VHIGH, GPIO_PIN_05, GPIO_PORT_D},
									 {GPIO_MODE_OUTPUT_OD, GPIO_PUPD_u32_PULL_DOWN, GPIO_SPEED_VHIGH, GPIO_PIN_06, GPIO_PORT_D},
									 {GPIO_MODE_OUTPUT_OD, GPIO_PUPD_u32_PULL_DOWN, GPIO_SPEED_VHIGH, GPIO_PIN_07, GPIO_PORT_D},
									 {GPIO_MODE_OUTPUT_OD, GPIO_PUPD_u32_PULL_DOWN, GPIO_SPEED_VHIGH, GPIO_PIN_08, GPIO_PORT_D},
									 {GPIO_MODE_OUTPUT_OD, GPIO_PUPD_u32_PULL_DOWN, GPIO_SPEED_VHIGH, GPIO_PIN_09, GPIO_PORT_D},
									 {GPIO_MODE_OUTPUT_OD, GPIO_PUPD_u32_PULL_DOWN, GPIO_SPEED_VHIGH, GPIO_PIN_10, GPIO_PORT_D},
									 {GPIO_MODE_OUTPUT_OD, GPIO_PUPD_u32_PULL_DOWN, GPIO_SPEED_VHIGH, GPIO_PIN_11, GPIO_PORT_D},
									 {GPIO_MODE_OUTPUT_OD, GPIO_PUPD_u32_PULL_DOWN, GPIO_SPEED_VHIGH, GPIO_PIN_12, GPIO_PORT_D},
									 {GPIO_MODE_OUTPUT_OD, GPIO_PUPD_u32_PULL_DOWN, GPIO_SPEED_VHIGH, GPIO_PIN_13, GPIO_PORT_D},
									 {GPIO_MODE_OUTPUT_OD, GPIO_PUPD_u32_PULL_DOWN, GPIO_SPEED_VHIGH, GPIO_PIN_14, GPIO_PORT_D},
									 {GPIO_MODE_OUTPUT_OD, GPIO_PUPD_u32_PULL_DOWN, GPIO_SPEED_VHIGH, GPIO_PIN_15, GPIO_PORT_D}
									};

GpioPinCfg_t GPIOE_PINx_CFG[16] = {
									 {GPIO_MODE_OUTPUT_OD, GPIO_PUPD_u32_PULL_DOWN, GPIO_SPEED_VHIGH, GPIO_PIN_00, GPIO_PORT_E},
									 {GPIO_MODE_OUTPUT_OD, GPIO_PUPD_u32_PULL_DOWN, GPIO_SPEED_VHIGH, GPIO_PIN_01, GPIO_PORT_E},
									 {GPIO_MODE_OUTPUT_OD, GPIO_PUPD_u32_PULL_DOWN, GPIO_SPEED_VHIGH, GPIO_PIN_02, GPIO_PORT_E},
									 {GPIO_MODE_OUTPUT_OD, GPIO_PUPD_u32_PULL_DOWN, GPIO_SPEED_VHIGH, GPIO_PIN_03, GPIO_PORT_E},
									 {GPIO_MODE_OUTPUT_OD, GPIO_PUPD_u32_PULL_DOWN, GPIO_SPEED_VHIGH, GPIO_PIN_04, GPIO_PORT_E},
									 {GPIO_MODE_OUTPUT_OD, GPIO_PUPD_u32_PULL_DOWN, GPIO_SPEED_VHIGH, GPIO_PIN_05, GPIO_PORT_E},
									 {GPIO_MODE_OUTPUT_OD, GPIO_PUPD_u32_PULL_DOWN, GPIO_SPEED_VHIGH, GPIO_PIN_06, GPIO_PORT_E},
									 {GPIO_MODE_OUTPUT_OD, GPIO_PUPD_u32_PULL_DOWN, GPIO_SPEED_VHIGH, GPIO_PIN_07, GPIO_PORT_E},
									 {GPIO_MODE_OUTPUT_OD, GPIO_PUPD_u32_PULL_DOWN, GPIO_SPEED_VHIGH, GPIO_PIN_08, GPIO_PORT_E},
									 {GPIO_MODE_OUTPUT_OD, GPIO_PUPD_u32_PULL_DOWN, GPIO_SPEED_VHIGH, GPIO_PIN_09, GPIO_PORT_E},
									 {GPIO_MODE_OUTPUT_OD, GPIO_PUPD_u32_PULL_DOWN, GPIO_SPEED_VHIGH, GPIO_PIN_10, GPIO_PORT_E},
									 {GPIO_MODE_OUTPUT_OD, GPIO_PUPD_u32_PULL_DOWN, GPIO_SPEED_VHIGH, GPIO_PIN_11, GPIO_PORT_E},
									 {GPIO_MODE_OUTPUT_OD, GPIO_PUPD_u32_PULL_DOWN, GPIO_SPEED_VHIGH, GPIO_PIN_12, GPIO_PORT_E},
									 {GPIO_MODE_OUTPUT_OD, GPIO_PUPD_u32_PULL_DOWN, GPIO_SPEED_VHIGH, GPIO_PIN_13, GPIO_PORT_E},
									 {GPIO_MODE_OUTPUT_OD, GPIO_PUPD_u32_PULL_DOWN, GPIO_SPEED_VHIGH, GPIO_PIN_14, GPIO_PORT_E},
									 {GPIO_MODE_OUTPUT_OD, GPIO_PUPD_u32_PULL_DOWN, GPIO_SPEED_VHIGH, GPIO_PIN_15, GPIO_PORT_E}
									};

GpioPinCfg_t GPIOH_PINx_CFG[16] = {
									 {GPIO_MODE_OUTPUT_OD, GPIO_PUPD_u32_PULL_DOWN, GPIO_SPEED_VHIGH, GPIO_PIN_00, GPIO_PORT_H},
									 {GPIO_MODE_OUTPUT_OD, GPIO_PUPD_u32_PULL_DOWN, GPIO_SPEED_VHIGH, GPIO_PIN_01, GPIO_PORT_H},
									 {GPIO_MODE_OUTPUT_OD, GPIO_PUPD_u32_PULL_DOWN, GPIO_SPEED_VHIGH, GPIO_PIN_02, GPIO_PORT_H},
									 {GPIO_MODE_OUTPUT_OD, GPIO_PUPD_u32_PULL_DOWN, GPIO_SPEED_VHIGH, GPIO_PIN_03, GPIO_PORT_H},
									 {GPIO_MODE_OUTPUT_OD, GPIO_PUPD_u32_PULL_DOWN, GPIO_SPEED_VHIGH, GPIO_PIN_04, GPIO_PORT_H},
									 {GPIO_MODE_OUTPUT_OD, GPIO_PUPD_u32_PULL_DOWN, GPIO_SPEED_VHIGH, GPIO_PIN_05, GPIO_PORT_H},
									 {GPIO_MODE_OUTPUT_OD, GPIO_PUPD_u32_PULL_DOWN, GPIO_SPEED_VHIGH, GPIO_PIN_06, GPIO_PORT_H},
									 {GPIO_MODE_OUTPUT_OD, GPIO_PUPD_u32_PULL_DOWN, GPIO_SPEED_VHIGH, GPIO_PIN_07, GPIO_PORT_H},
									 {GPIO_MODE_OUTPUT_OD, GPIO_PUPD_u32_PULL_DOWN, GPIO_SPEED_VHIGH, GPIO_PIN_08, GPIO_PORT_H},
									 {GPIO_MODE_OUTPUT_OD, GPIO_PUPD_u32_PULL_DOWN, GPIO_SPEED_VHIGH, GPIO_PIN_09, GPIO_PORT_H},
									 {GPIO_MODE_OUTPUT_OD, GPIO_PUPD_u32_PULL_DOWN, GPIO_SPEED_VHIGH, GPIO_PIN_10, GPIO_PORT_H},
									 {GPIO_MODE_OUTPUT_OD, GPIO_PUPD_u32_PULL_DOWN, GPIO_SPEED_VHIGH, GPIO_PIN_11, GPIO_PORT_H},
									 {GPIO_MODE_OUTPUT_OD, GPIO_PUPD_u32_PULL_DOWN, GPIO_SPEED_VHIGH, GPIO_PIN_12, GPIO_PORT_H},
									 {GPIO_MODE_OUTPUT_OD, GPIO_PUPD_u32_PULL_DOWN, GPIO_SPEED_VHIGH, GPIO_PIN_13, GPIO_PORT_H},
									 {GPIO_MODE_OUTPUT_OD, GPIO_PUPD_u32_PULL_DOWN, GPIO_SPEED_VHIGH, GPIO_PIN_14, GPIO_PORT_H},
									 {GPIO_MODE_OUTPUT_OD, GPIO_PUPD_u32_PULL_DOWN, GPIO_SPEED_VHIGH, GPIO_PIN_15, GPIO_PORT_H}
									};

#endif /* GPIO_GPIO_INCLUDES_GPIO_CFG_H_ */
