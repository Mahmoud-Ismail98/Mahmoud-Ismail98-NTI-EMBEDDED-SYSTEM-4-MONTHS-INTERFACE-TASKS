#ifndef GPIO_H_
#define GPIO_H_

//////////////////////////////STRUCT PULL OPTIONS////////////////////////////////////////
#define GPIO_PUPD_u32_FLOATING								0x00000003
#define GPIO_PUPD_u32_PULL_UP								0x00000001
#define GPIO_PUPD_u32_PULL_DOWN								0x00000002
//////////////////////////////STRUCT MODE OPTIONS////////////////////////////////////////
#define GPIO_MODE_u64_OUTPUT_PP								((u64) 0x0000000000000001)

#define GPIO_MODE_u64_OUTPUT_OD								((u64) 0x0000000100000001)

#define GPIO_MODE_u64_INPUT       							((u64) 0x0000000000000000)

#define GPIO_MODE_u64_AF_PP									((u64) 0x0000000000000002)

#define GPIO_MODE_u64_AF_OD									((u64) 0x0000000100000002)

#define GPIO_MODE_u64_ANALOG								((u64) 0x0000000000000003)

//////////////////////////////STRUCT SPEED OPTIONS///////////////////////////////////////
#define GPIO_SPEED_LOW      								(0x00000000)
#define GPIO_SPEED_MEDIUM   								(0x00000001)
#define GPIO_SPEED_HIGH     								(0x00000002)
#define GPIO_SPEED_VHIGH    								(0x00000003)
//////////////////////////////// PIN VALUE HIGH/LOW /////////////////////////////////////////
#define GPIO_HIGH			1
#define GPIO_LOW			0
/********
Select Port and pins
******/

#define PORTA	0
#define PORTB	1
#define PORTC	2
#define PORTD	3
#define PORTE	4
#define PORTH	5
////////////////////////////////////
#define PIN0		0
#define PIN1		1
#define PIN2		2
#define PIN3		3
#define PIN4		4
#define PIN5		5
#define PIN6		6
#define PIN7		7
#define PIN8		8
#define PIN9		9
#define PIN10		10
#define PIN11		11
#define PIN12		12
#define PIN13		13
#define PIN14		14
#define PIN15		15
////////////////////////////////
void PORT_voidInit(void);
void Write_GPIOPIN(u8 PORT,u8 PIN ,u8 Signal);
u8 GPIO_u16ReadPinVal(u8 PORT,u8 PIN);


#endif
