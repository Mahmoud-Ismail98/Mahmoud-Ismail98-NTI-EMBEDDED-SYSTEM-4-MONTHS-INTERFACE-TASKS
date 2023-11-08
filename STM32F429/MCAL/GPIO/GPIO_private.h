/**************************************************************************/
/* Filename						: GPIO_private.h                            */
/* Author  	    				: Muhammad Ammar                          */
/* Date 						: Nov 6, 2023  	           	 	         	 */ 
/* Version 	 					: V01                                     */
/* MicroController  			: STM32429 								   */
/* Trainee At					: NTI (4 Months)						  */
/* Instructor					: Mahmoud Embabi						  */
/**************************************************************************/


#ifndef GPIO_GPIO_PRIVATE_H_
#define GPIO_GPIO_PRIVATE_H_



/********************************** Includes *********************************************/


/********************************** Data Type Declarations ****************************/

  typedef volatile struct{
  	u32 GPIO_MODER;
  	u32 GPIO_OTYPER;
  	u32 GPIO_OSPEEDER;
  	u32 GPIO_PUPDR;
  	u32 GPIO_IDR;
  	u32 GPIO_ODR;
  	u32 GPIO_BSRR;
  	u32 GPIO_LCKR;
  	u32 GPIO_AFRL;
  	u32 GPIO_AFRH;
  }GPIOx_Type;



/********************************** Macros Declarations *******************************/

#define GPIO_A		((volatile GPIOx_Type*)(0x40020000))
#define GPIO_B		((volatile GPIOx_Type*)(0x40020400))
#define GPIO_C		((volatile GPIOx_Type*)(0x40020800))
#define GPIO_D		((volatile GPIOx_Type*)(0x40020C00))
#define GPIO_E		((volatile GPIOx_Type*)(0x40021000))
#define GPIO_F		((volatile GPIOx_Type*)(0x40021400))
#define GPIO_G		((volatile GPIOx_Type*)(0x40021800))
#define GPIO_H		((volatile GPIOx_Type*)(0x40021C00))
//#define GPIO_I		((volatile GPIOx_Type*)(0x40022000))
//#define GPIO_J		((volatile GPIOx_Type*)(0x40022400))
//#define GPIO_K		((volatile GPIOx_Type*)(0x40022800))



#define GPIO_MAX_INDEX_OF_PIN_NUMBER		FIFTEEN_VALUE
#define GPIO_MAX_INDEX_OF_CHANNEL_PORT		SEVEN_VALUE


//static volatile GPIOx_Type* Global_GPIOArr[]={GPIO_A,GPIO_B,GPIO_C,GPIO_D,GPIO_D,GPIO_E,GPIO_F,GPIO_G,GPIO_H};

static volatile u32* Global_ModeArr[]={&(GPIO_A->GPIO_MODER),&(GPIO_B->GPIO_MODER),&(GPIO_C->GPIO_MODER),&(GPIO_D->GPIO_MODER),&(GPIO_E->GPIO_MODER),&(GPIO_F->GPIO_MODER),&(GPIO_G->GPIO_MODER),&(GPIO_H->GPIO_MODER)};
static volatile u32* Global_OutputTypeArr[]={&(GPIO_A->GPIO_OTYPER),&(GPIO_B->GPIO_OTYPER),&(GPIO_C->GPIO_OTYPER),&(GPIO_D->GPIO_OTYPER),&(GPIO_E->GPIO_OTYPER),&(GPIO_F->GPIO_OTYPER),&(GPIO_G->GPIO_OTYPER),&(GPIO_H->GPIO_OTYPER)};
static volatile u32* Global_OutputSpeedArr[]={&(GPIO_A->GPIO_OSPEEDER),&(GPIO_B->GPIO_OSPEEDER),&(GPIO_C->GPIO_OSPEEDER),&(GPIO_D->GPIO_OSPEEDER),&(GPIO_E->GPIO_OSPEEDER),&(GPIO_F->GPIO_OSPEEDER),&(GPIO_G->GPIO_OSPEEDER),&(GPIO_H->GPIO_OSPEEDER)};
static volatile u32* Global_PUPDArr[]={&(GPIO_A->GPIO_PUPDR),&(GPIO_B->GPIO_PUPDR),&(GPIO_C->GPIO_PUPDR),&(GPIO_D->GPIO_PUPDR),&(GPIO_E->GPIO_PUPDR),&(GPIO_F->GPIO_PUPDR),&(GPIO_G->GPIO_PUPDR),&(GPIO_H->GPIO_PUPDR)};

static volatile u32* Global_IdrReadArr[]={&(GPIO_A->GPIO_IDR),&(GPIO_B->GPIO_IDR),&(GPIO_C->GPIO_IDR),&(GPIO_D->GPIO_IDR),&(GPIO_E->GPIO_IDR),&(GPIO_F->GPIO_IDR),&(GPIO_G->GPIO_IDR),&(GPIO_H->GPIO_IDR)};
static volatile u32* Global_OdreArr[]={&(GPIO_A->GPIO_ODR),&(GPIO_B->GPIO_ODR),&(GPIO_C->GPIO_ODR),&(GPIO_D->GPIO_ODR),&(GPIO_E->GPIO_ODR),&(GPIO_F->GPIO_ODR),&(GPIO_G->GPIO_ODR),&(GPIO_H->GPIO_ODR)};

static volatile u32* Global_BsrrArr[]={&(GPIO_A->GPIO_BSRR),&(GPIO_B->GPIO_BSRR),&(GPIO_C->GPIO_BSRR),&(GPIO_D->GPIO_BSRR),&(GPIO_E->GPIO_BSRR),&(GPIO_F->GPIO_BSRR),&(GPIO_G->GPIO_BSRR),&(GPIO_H->GPIO_BSRR)};
static volatile u32* Global_LockRegArr[]={&(GPIO_A->GPIO_LCKR),&(GPIO_B->GPIO_LCKR),&(GPIO_C->GPIO_LCKR),&(GPIO_D->GPIO_LCKR),&(GPIO_E->GPIO_LCKR),&(GPIO_F->GPIO_LCKR),&(GPIO_G->GPIO_LCKR),&(GPIO_H->GPIO_LCKR)};

static volatile u32* Global_AFLowArr[]={&(GPIO_A->GPIO_AFRL),&(GPIO_B->GPIO_AFRL),&(GPIO_C->GPIO_AFRL),&(GPIO_D->GPIO_AFRL),&(GPIO_E->GPIO_AFRL),&(GPIO_F->GPIO_AFRL),&(GPIO_G->GPIO_AFRL),&(GPIO_H->GPIO_AFRL)};
static volatile u32* Global_AFHighArr[]={&(GPIO_A->GPIO_AFRH),&(GPIO_B->GPIO_AFRH),&(GPIO_C->GPIO_AFRH),&(GPIO_D->GPIO_AFRH),&(GPIO_E->GPIO_AFRH),&(GPIO_F->GPIO_AFRH),&(GPIO_G->GPIO_AFRH),&(GPIO_H->GPIO_AFRH)};







/* Mode */
#define GPIO_MODE_INPUT 		00
#define GPIO_MODE_OUTPUT		01
#define GPIO_MODE_AF		    10
#define GPIO_MODE_ANALOG		11

/* Output Type */
#define GPIO_OUTPUT_PUSH_PULL		0
#define GPIO_OUTPUT_OPEN_DRAIN		1

/* SPEED Type */
#define GPIO_LOW_SPEED		    00
#define GPIO_MEDIUM_SPEED		01
#define GPIO_HIGH_SPEED	        10
#define GPIO_VHIGH_SPEED		11

/* Pull up Pull down Type */
#define GPIO_NO_PULL_UP_NO_PULL_DOWN			00
#define GPIO_PULL_UP							01
#define GPIO_PULL_DOWN							10



/********************************** Macros Function Declarations *********************/

/*
#define Gpio_concat(_INDEX_,															 \
                    _X15_PULL_TYPE_, _X15_SPEED_TYPE_, _X15_OUTPUT_TYPE_, _X15_MODE_TYPE_,\
                    _X14_PULL_TYPE_, _X14_SPEED_TYPE_, _X14_OUTPUT_TYPE_, _X14_MODE_TYPE_,\
                    _X13_PULL_TYPE_, _X13_SPEED_TYPE_, _X13_OUTPUT_TYPE_, _X13_MODE_TYPE_,\
                    _X12_PULL_TYPE_, _X12_SPEED_TYPE_, _X12_OUTPUT_TYPE_, _X12_MODE_TYPE_,\
                    _X11_PULL_TYPE_, _X11_SPEED_TYPE_, _X11_OUTPUT_TYPE_, _X11_MODE_TYPE_,\
                    _X10_PULL_TYPE_, _X10_SPEED_TYPE_, _X10_OUTPUT_TYPE_, _X10_MODE_TYPE_,\
                    _X9_PULL_TYPE_, _X9_SPEED_TYPE_, _X9_OUTPUT_TYPE_, _X9_MODE_TYPE_,\
                    _X8_PULL_TYPE_, _X8_SPEED_TYPE_, _X8_OUTPUT_TYPE_, _X8_MODE_TYPE_,\
                    _X7_PULL_TYPE_, _X7_SPEED_TYPE_, _X7_OUTPUT_TYPE_, _X7_MODE_TYPE_,\
                    _X6_PULL_TYPE_, _X6_SPEED_TYPE_, _X6_OUTPUT_TYPE_, _X6_MODE_TYPE_,\
                    _X5_PULL_TYPE_, _X5_SPEED_TYPE_, _X5_OUTPUT_TYPE_, _X5_MODE_TYPE_,\
                    _X4_PULL_TYPE_, _X4_SPEED_TYPE_, _X4_OUTPUT_TYPE_, _X4_MODE_TYPE_,\
                    _X3_PULL_TYPE_, _X3_SPEED_TYPE_, _X3_OUTPUT_TYPE_, _X3_MODE_TYPE_,\
                    _X2_PULL_TYPE_, _X2_SPEED_TYPE_, _X2_OUTPUT_TYPE_, _X2_MODE_TYPE_,\
                    _X1_PULL_TYPE_, _X1_SPEED_TYPE_, _X1_OUTPUT_TYPE_, _X1_MODE_TYPE_,\
                    _X0_PULL_TYPE_, _X0_SPEED_TYPE_, _X0_OUTPUT_TYPE_, _X0_MODE_TYPE_)\
																Gpio_concatHelper(_INDEX_,\
																		_X15_PULL_TYPE_, _X15_SPEED_TYPE_, _X15_OUTPUT_TYPE_, _X15_MODE_TYPE_,\
																		_X14_PULL_TYPE_, _X14_SPEED_TYPE_, _X14_OUTPUT_TYPE_, _X14_MODE_TYPE_,\
																		_X13_PULL_TYPE_, _X13_SPEED_TYPE_, _X13_OUTPUT_TYPE_, _X13_MODE_TYPE_,\
																		_X12_PULL_TYPE_, _X12_SPEED_TYPE_, _X12_OUTPUT_TYPE_, _X12_MODE_TYPE_,\
																		_X11_PULL_TYPE_, _X11_SPEED_TYPE_, _X11_OUTPUT_TYPE_, _X11_MODE_TYPE_,\
																		_X10_PULL_TYPE_, _X10_SPEED_TYPE_, _X10_OUTPUT_TYPE_, _X10_MODE_TYPE_,\
																		_X9_PULL_TYPE_, _X9_SPEED_TYPE_, _X9_OUTPUT_TYPE_, _X9_MODE_TYPE_,\
																		_X8_PULL_TYPE_, _X8_SPEED_TYPE_, _X8_OUTPUT_TYPE_, _X8_MODE_TYPE_,\
																		_X7_PULL_TYPE_, _X7_SPEED_TYPE_, _X7_OUTPUT_TYPE_, _X7_MODE_TYPE_,\
																		_X6_PULL_TYPE_, _X6_SPEED_TYPE_, _X6_OUTPUT_TYPE_, _X6_MODE_TYPE_,\
																		_X5_PULL_TYPE_, _X5_SPEED_TYPE_, _X5_OUTPUT_TYPE_, _X5_MODE_TYPE_,\
																		_X4_PULL_TYPE_, _X4_SPEED_TYPE_, _X4_OUTPUT_TYPE_, _X4_MODE_TYPE_,\
																		_X3_PULL_TYPE_, _X3_SPEED_TYPE_, _X3_OUTPUT_TYPE_, _X3_MODE_TYPE_,\
																		_X2_PULL_TYPE_, _X2_SPEED_TYPE_, _X2_OUTPUT_TYPE_, _X2_MODE_TYPE_,\
																		_X1_PULL_TYPE_, _X1_SPEED_TYPE_, _X1_OUTPUT_TYPE_, _X1_MODE_TYPE_,\
																		_X0_PULL_TYPE_, _X0_SPEED_TYPE_, _X0_OUTPUT_TYPE_, _X0_MODE_TYPE_)

*/

#define Gpio_concat(...)		Gpio_concatHelper(__VA_ARGS__)


#define Gpio_concatHelper(_INDEX_,\
                    _X15_PULL_TYPE_, _X15_SPEED_TYPE_, _X15_OUTPUT_TYPE_, _X15_MODE_TYPE_,\
                    _X14_PULL_TYPE_, _X14_SPEED_TYPE_, _X14_OUTPUT_TYPE_, _X14_MODE_TYPE_,\
                    _X13_PULL_TYPE_, _X13_SPEED_TYPE_, _X13_OUTPUT_TYPE_, _X13_MODE_TYPE_,\
                    _X12_PULL_TYPE_, _X12_SPEED_TYPE_, _X12_OUTPUT_TYPE_, _X12_MODE_TYPE_,\
                    _X11_PULL_TYPE_, _X11_SPEED_TYPE_, _X11_OUTPUT_TYPE_, _X11_MODE_TYPE_,\
                    _X10_PULL_TYPE_, _X10_SPEED_TYPE_, _X10_OUTPUT_TYPE_, _X10_MODE_TYPE_,\
                    _X9_PULL_TYPE_, _X9_SPEED_TYPE_, _X9_OUTPUT_TYPE_, _X9_MODE_TYPE_,\
                    _X8_PULL_TYPE_, _X8_SPEED_TYPE_, _X8_OUTPUT_TYPE_, _X8_MODE_TYPE_,\
                    _X7_PULL_TYPE_, _X7_SPEED_TYPE_, _X7_OUTPUT_TYPE_, _X7_MODE_TYPE_,\
                    _X6_PULL_TYPE_, _X6_SPEED_TYPE_, _X6_OUTPUT_TYPE_, _X6_MODE_TYPE_,\
                    _X5_PULL_TYPE_, _X5_SPEED_TYPE_, _X5_OUTPUT_TYPE_, _X5_MODE_TYPE_,\
                    _X4_PULL_TYPE_, _X4_SPEED_TYPE_, _X4_OUTPUT_TYPE_, _X4_MODE_TYPE_,\
                    _X3_PULL_TYPE_, _X3_SPEED_TYPE_, _X3_OUTPUT_TYPE_, _X3_MODE_TYPE_,\
                    _X2_PULL_TYPE_, _X2_SPEED_TYPE_, _X2_OUTPUT_TYPE_, _X2_MODE_TYPE_,\
                    _X1_PULL_TYPE_, _X1_SPEED_TYPE_, _X1_OUTPUT_TYPE_, _X1_MODE_TYPE_,\
                    _X0_PULL_TYPE_, _X0_SPEED_TYPE_, _X0_OUTPUT_TYPE_, _X0_MODE_TYPE_)  do{\
                    																*Global_ModeArr[_INDEX_] = (0b##_X15_MODE_TYPE_##_X14_MODE_TYPE_##_X13_MODE_TYPE_##_X12_MODE_TYPE_##\
					                                                                  			 	 	 	 _X11_MODE_TYPE_##_X10_MODE_TYPE_##_X9_MODE_TYPE_##_X8_MODE_TYPE_##_X7_MODE_TYPE_##_X6_MODE_TYPE_##\
																											 _X5_MODE_TYPE_##_X4_MODE_TYPE_##_X3_MODE_TYPE_##_X2_MODE_TYPE_##_X1_MODE_TYPE_##_X0_MODE_TYPE_);\
																					*Global_OutputTypeArr[_INDEX_] = (0b##_X15_OUTPUT_TYPE_##_X14_OUTPUT_TYPE_##_X13_OUTPUT_TYPE_##_X12_OUTPUT_TYPE_##\
																								 	 	 	_X11_OUTPUT_TYPE_##_X10_OUTPUT_TYPE_##_X9_OUTPUT_TYPE_##_X8_OUTPUT_TYPE_##_X7_OUTPUT_TYPE_##_X6_OUTPUT_TYPE_##\
																								 	 	 	 _X5_OUTPUT_TYPE_##_X4_OUTPUT_TYPE_##_X3_OUTPUT_TYPE_##_X2_OUTPUT_TYPE_##_X1_OUTPUT_TYPE_##_X0_OUTPUT_TYPE_);\
																								 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 \
																						*Global_OutputSpeedArr[_INDEX_] = (0b##_X15_SPEED_TYPE_##_X14_SPEED_TYPE_##_X13_SPEED_TYPE_##_X12_SPEED_TYPE_##\
																								 	 	 	_X11_SPEED_TYPE_##_X10_SPEED_TYPE_##_X9_SPEED_TYPE_##_X8_SPEED_TYPE_##_X7_SPEED_TYPE_##_X6_SPEED_TYPE_##\
																								 	 	 	 _X5_SPEED_TYPE_##_X4_SPEED_TYPE_##_X3_SPEED_TYPE_##_X2_SPEED_TYPE_##_X1_SPEED_TYPE_##_X0_SPEED_TYPE_);\
																								 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	\
																						*Global_PUPDArr[_INDEX_] = (0b##_X15_PULL_TYPE_##_X14_PULL_TYPE_##_X13_PULL_TYPE_##_X12_PULL_TYPE_##\
																						                               _X11_PULL_TYPE_##_X10_PULL_TYPE_##_X9_PULL_TYPE_##_X8_PULL_TYPE_##_X7_PULL_TYPE_##_X6_PULL_TYPE_##\
																								 	 	 				_X5_PULL_TYPE_##_X4_PULL_TYPE_##_X3_PULL_TYPE_##_X2_PULL_TYPE_##_X1_PULL_TYPE_##_X0_PULL_TYPE_);\
					                                                                      }while(0)



//
//
//#define Gpio_concat(_INDEX_, ...) Gpio_concatHelper(_INDEX_, __VA_ARGS__)
//





/********************************** Software Interfaces Declarations *******************/



#endif /* GPIO_GPIO_PRIVATE_H_ */
