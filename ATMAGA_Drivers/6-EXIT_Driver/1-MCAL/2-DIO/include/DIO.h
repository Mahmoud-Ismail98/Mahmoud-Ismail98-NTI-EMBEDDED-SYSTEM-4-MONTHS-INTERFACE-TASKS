#ifndef DIO_H_
#define DIO_H_

/******************************************************************/
/*********************** DIRECTONS *********************************/

#define OUTPUT                      1
#define INTPUT                      0


/******************************************************************/
/*********************OUTPUT LEVELS *******************************/

#define   DIO_HIGH                  1
#define   DIO_LOW                   0

/******************************************************************/
/************************INPUT MODES*******************************/
#define    DIO_PULL_UP              1
#define    DIO_FLOATING             0

/******************************************************************/
/************************ CHANNALS *******************************/
#define DIO_Channal0                    0
#define DIO_Channal1                    1
#define DIO_channal2                    2
#define DIO_channal3                    3
#define DIO_channal4                    4
#define DIO_channal5                    5
#define DIO_channal6                    6
#define DIO_channal7                    7
#define DIO_channal8                    8
#define DIO_channal9                    9
#define DIO_channal10                   10
#define DIO_channal11                   11
#define DIO_channal12                   12
#define DIO_channal13                   13
#define DIO_channal14                   14
#define DIO_channal15                   15
#define DIO_channal16                   16
#define DIO_channal17                   17
#define DIO_channal18                   18
#define DIO_channal19                   19
#define DIO_channal20                   20
#define DIO_channal21                   21
#define DIO_channal22                   22
#define DIO_channal23                   23
#define DIO_channal24                   24
#define DIO_channal25                   25
#define DIO_channal26                   26
#define DIO_channal27                   27
#define DIO_channal28                   28
#define DIO_channal29                   29
#define DIO_channal30                   30
#define DIO_channal31                   31

/******************************************************************/
/************************* ERROR STATES ****************************/
typedef enum {
Dio_EnmDioOk ,
Dio_EnmChannalIdError ,
Dio_EnmChannalLevelError,
Dio_EnmInvalidPortID,
Dio_EnmValue
}Dio_tenuErrorStatus;

/******************************************************************/
/************************* PROTOTYPES ****************************/

Dio_tenuErrorStatus Dio_enuWritechannal(u8 Copy_u8ChannalId , u8 Copy_u8Level);
Dio_tenuErrorStatus Dio_enuReadchannal(u8 Copy_u8ChannalId , pu8 Add_pu8ChannalLevel);
Dio_tenuErrorStatus Dio_enuWritePort(u8 Copy_u8PortId , u8 Copy_u8Value);
Dio_tenuErrorStatus Dio_enuReadPort(u8 Copy_u8PortId ,  pu8 Add_puPortValue);
Dio_tenuErrorStatus Dio_enuFlipChannal(u8 Copy_u8ChannalId);










#endif
