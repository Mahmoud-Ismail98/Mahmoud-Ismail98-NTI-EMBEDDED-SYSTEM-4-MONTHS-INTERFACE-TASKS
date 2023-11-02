/************************************************************************************/
/*  Author  : Ahmed Mohey                                                           */
/*  Version : v01                                                                   */
/*  Date    : 22 Oct 2023                                                           */
/************************************************************************************/
#ifndef KPD_CONFIG_H
#define KPD_CONFIG_H

#define KPD_u8_PORT            DIO_u8_PORTB

/* Row Pins */
#define KPD_u8_R1_PIN          DIO_u8_PIN0
#define KPD_u8_R2_PIN          DIO_u8_PIN1
#define KPD_u8_R3_PIN          DIO_u8_PIN2
#define KPD_u8_R4_PIN          DIO_u8_PIN3

/* Col Pins */
#define KPD_u8_C1_PIN          DIO_u8_PIN4
#define KPD_u8_C2_PIN          DIO_u8_PIN5
#define KPD_u8_C3_PIN          DIO_u8_PIN6
#define KPD_u8_C4_PIN          DIO_u8_PIN7

#define KPD_KEYS      {{7,8,9,'/'},  \
	                   {4,5,6,'*'},  \
					   {1,2,3,'-'},  \
                       {'c',0,'=','+'}}

#endif
