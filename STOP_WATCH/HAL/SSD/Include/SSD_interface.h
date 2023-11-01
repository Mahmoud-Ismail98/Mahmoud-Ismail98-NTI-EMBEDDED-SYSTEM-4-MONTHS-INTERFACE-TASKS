/************************************************************************************/
/*  Author  : Ahmed Mohey                                                           */
/*  Version : v01                                                                   */
/*  Date    : 21 Oct 2023                                                           */
/************************************************************************************/
#ifndef SSD_INTERFACE_H
#define SSD_INTERFACE_H

/* Macros for Data Port */
#define SSD_DATA_PORT             DIO_u8_PORTB
#define SSD_ENABLE_PORT           DIO_u8_PORTC

/* Macros for Data Pins */
#define SSD_DATA_PIN_0            DIO_u8_PIN0
#define SSD_DATA_PIN_1            DIO_u8_PIN1
#define SSD_DATA_PIN_2            DIO_u8_PIN2
#define SSD_DATA_PIN_3            DIO_u8_PIN3

/* Macros for Enable Pins */
#define SSD_ENABLE_PIN_0          DIO_u8_PIN0
#define SSD_ENABLE_PIN_1          DIO_u8_PIN1
#define SSD_ENABLE_PIN_2          DIO_u8_PIN2
#define SSD_ENABLE_PIN_3          DIO_u8_PIN3

void SSD_voidEnable1(void);
void SSD_voidEnable2(void);
void SSD_voidEnable3(void);
void SSD_voidEnable4(void);

void SSD_voidDisable1(void);
void SSD_voidDisable2(void);
void SSD_voidDisable3(void);
void SSD_voidDisable4(void);

void SSD_voidWriteNumber(u8 copy_u8Number);

void SSD_voidWriteTo2SS(u8 copy_u8Num,f32 copy_f32TimeSec);

void SSD_voidWriteTo4SS(u32 copy_u32Num);

#endif
