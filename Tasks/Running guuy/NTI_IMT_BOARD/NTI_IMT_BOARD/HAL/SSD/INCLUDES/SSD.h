/*
 * SSD.h
 *
 * Created: 10/20/2023 10:28:45 PM
 *  Author: Mahmoud Tariq
 */ 


#ifndef SSD_H_
#define SSD_H_


/*Enable Pins*/
#define SSD_Numbers   4
#define SSD1_EN       PORTB_PIN1
#define SSD2_EN		  PORTB_PIN2
#define SSD3_EN		  
#define SSD4_EN		  


typedef enum{
	SSD_STATUS_OK,
	SSD_STATUS_FAILED,
	SSD_MODE_ERR,
	SSD_NULL_PTR_eRR,
	SSD_PIN_NO_ERR,
	SSD_PORT_NO_ERR,
	SSD_VALUE_eRR
	
}SSD_enuError_Status;
void SSD_vInit(u8 copy_u8PortId );
void SSD_vDeInit4Bit(u8 copy_PinNum);
void SSD_vDisplay(u8 copy_u8PortId , u8 copy_u8Value);

void SSD_vInit4Bit(u8);


void SSD_Display4Nums(u8 copy_num1 , u8 copy_num2, u8 copy_num3,u8 copy_num4);
void SSD_Display2Nums(u8 copy_num1 , u8 copy_num2);

SSD_enuError_Status SSD_enuDisplay4Bit(u8 copy_u8Value);



#endif /* SSD_H_ */