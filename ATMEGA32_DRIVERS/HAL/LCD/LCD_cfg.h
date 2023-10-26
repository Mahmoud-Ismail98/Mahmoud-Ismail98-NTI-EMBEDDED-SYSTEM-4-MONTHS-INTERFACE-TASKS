


#ifndef CLCD_CONFIG_H_H
#define CLCD_CONFIG_H_H


#define CLCD_DATA_PORT   DIO_u8PORTC




#define CLCD_CTRL_PORT   DIO_u8PORTB

 
#define LCD_TYPE      LCD_16_2
#define LCD_MODE      LCD_4_BIT



    /* Control Pins */
#define RS_PIN      DIO_u8CHANNEL08
#define RW_PIN      DIO_u8CHANNEL09  
#define EN_PIN      DIO_u8CHANNEL10

           /*Data Pins */
#define DATA_PIN0    DIO_u8CHANNEL20
#define DATA_PIN1    DIO_u8CHANNEL21
#define DATA_PIN2    DIO_u8CHANNEL22
#define DATA_PIN3    DIO_u8CHANNEL23

#define DATA_PIN4    DIO_u8CHANNEL16
#define DATA_PIN5    DIO_u8CHANNEL17
#define DATA_PIN6    DIO_u8CHANNEL18
#define DATA_PIN7    DIO_u8CHANNEL19
   
#endif