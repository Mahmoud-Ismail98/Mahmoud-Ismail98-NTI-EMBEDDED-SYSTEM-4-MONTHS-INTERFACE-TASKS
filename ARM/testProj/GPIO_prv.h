


#ifndef GPIO_PRV_H_
#define GPIO_PRV_H_


typedef struct
{
	vu32  GPIOx_MODER;
	vu32  GPIOx_OTYPER;
	vu32  GPIOx_OSPEEDER;
	vu32  GPIOx_PUDR;
	vu32  GPIOx_IDR;
	vu32  GPIOx_ODR;
	vu32  GPIOx_BSRR;
	vu32  GPIOx_LCKR;
	vu32  GPIOx_AFRL;
	vu32  GPIOx_AFRH;
	
}GPIOx_t;


#define GPIO_H_BASE_ADDRESS         0x40021C00
#define GPIO_E_BASE_ADDRESS         0x40021000
#define GPIO_D_BASE_ADDRESS         0x40020C00
#define GPIO_C_BASE_ADDRESS         0x40020800
#define GPIO_B_BASE_ADDRESS         0x40020400
#define GPIO_A_BASE_ADDRESS         0x40020000

#define GPIO_A                      ((GPIOx_t*)(GPIO_A_BASE_ADDRESS))
#define GPIO_B                      ((GPIOx_t*)(GPIO_B_BASE_ADDRESS))
#define GPIO_C                      ((GPIOx_t*)(GPIO_C_BASE_ADDRESS))
#define GPIO_D                      ((GPIOx_t*)(GPIO_D_BASE_ADDRESS))
#define GPIO_E                      ((GPIOx_t*)(GPIO_E_BASE_ADDRESS))
#define GPIO_H                      ((GPIOx_t*)(GPIO_H_BASE_ADDRESS))


																																					
#define GPIOPIN_0         								0
#define GPIOPIN_1        									1
#define GPIOPIN_2         								2
#define GPIOPIN_3         								3
#define GPIOPIN_4         								4
#define GPIOPIN_5         								5
#define GPIOPIN_6         								6
#define GPIOPIN_7         								7
#define GPIOPIN_8         								8
#define GPIOPIN_9         								9
#define GPIOPIN_10         								10
#define GPIOPIN_11         								11
#define GPIOPIN_12         								12
#define GPIOPIN_13         								13
#define GPIOPIN_14         								14
#define GPIOPIN_15         								15
																							



#define MAX_PORT_NUMBER              5
#define MAX_PIN_NUMBER               15
#define DONT_CARE                    0xFF

#define INPUT                        0
#define OUTPUT                       1
#define ALTFUN                       2
#define ANALOGUE                     3

/////////////////////
#define PUSHPULL                     0
#define OPENDRAIN                    1

///////////////////
#define LOWSPD                       0
#define MEDIUMSPD                    1
#define HIGHSPD                      2
#define VHIGHSPD                     3
///////////////
#define FLOATING                     0
#define PULLUP                       1
#define PULLDOWN                     2


	                                    

#define PORTx_PINx_CFG(port,pin,mode,type,pud,spd)                        (port->GPIOx_MODER&=(~(3<<pin*2)));   \
                                                                          (port->GPIOx_MODER|=(mode<<pin*2));   \
                                                                           if(type != DONT_CARE){               \
																																					(port->GPIOx_OTYPER&=(~(1<<pin*2)));  \
                                                                          (port->GPIOx_OTYPER|=(type<<pin));}   \
																																					 if(pud != DONT_CARE){                \
																																					(port->GPIOx_PUDR&=(~(3<<pin*2)));    \
                                                                          (port->GPIOx_PUDR|=(pud<<pin*2));}    \
																																					 if(spd != DONT_CARE){                \
																																					(port->GPIOx_OSPEEDER&=(~(3<<pin*2))); \
                                                                          (port->GPIOx_OSPEEDER|=(spd<<pin*2));}
																																					  																																				 
																																					
																																					
																																					
			

														



#endif



