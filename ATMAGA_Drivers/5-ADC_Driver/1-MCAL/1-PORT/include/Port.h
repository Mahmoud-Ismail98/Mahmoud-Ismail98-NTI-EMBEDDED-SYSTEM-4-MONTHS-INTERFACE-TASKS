#ifndef PORT_H_
#define PORT_H_

/******************************************************/
/***********************MOODS****************************/

#define PORT_u8Output_Low              0
#define PORT_u8Output_High             1
#define PORT_u8Intput_Pullup           2
#define PORT_u8Intput_Floating         3



/******************************************************/
/********************* PINS ***************************/


#define PIN0                       0
#define PIN1                       1
#define PIN2                       2
#define PIN3                       3
#define PIN4                       4
#define PIN5                       5
#define PIN6                       6
#define PIN7                       7 
#define PIN8                       8
#define PIN9                       9 
#define PIN10                      10
#define PIN11                      11
#define PIN12                      12
#define PIN13                      13
#define PIN14                      14
#define PIN15                      15
#define PIN16                      16
#define PIN17                      17
#define PIN18                      18
#define PIN19                      19
#define PIN20                      20
#define PIN21                      21
#define PIN22                      22
#define PIN23                      23
#define PIN24                      24
#define PIN25                      25
#define PIN26                      26
#define PIN27                      27
#define PIN28                      28
#define PIN29                      29
#define PIN30                      30
#define PIN31                      31





/******************************************************************/
/*********************** DIRECTONS *********************************/

#define OUTPUT                      1
#define INTPUT                      0


/******************************************************************/
/*********************OUTPUT LEVELS *******************************/

#define   HIGH                       1
#define   LOW                        0

/******************************************************************/
/************************INPUT MODES*******************************/
#define   PULL_UP                     1
#define   FLOATING                    0


/******************************************************************/
/************************* ERROR STATES ****************************/
typedef enum {
Port_EnmOk ,
Port_EnmPinError ,
Port_EnmInvalidPinMode,
Port_EnmInvalidPort,
Port_EnmDirectionError
}Port_tenuErrorStatus;



/******************************************************************/
/********************* PROTOTYPES ********************************/

void Port_VoidInit(void);
Port_tenuErrorStatus Port_enuSetPinDirection(u8 Copy_u8PinNum ,u8 Copy_u8PinDirection );
Port_tenuErrorStatus Port_enuSetPinMode(u8 Copy_u8PinNum ,u8 Copy_u8PinMode );




#endif
