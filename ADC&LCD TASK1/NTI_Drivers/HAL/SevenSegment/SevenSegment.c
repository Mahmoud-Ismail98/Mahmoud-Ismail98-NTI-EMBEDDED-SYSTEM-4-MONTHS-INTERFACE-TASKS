/*
 * SevenSegment.c
 *
 *  Created on: Oct 20, 2023
 *      Author: Ismail
 */

#include "SevenSegment.h"
#include "SevenSegment_cfg.h"
#include "SevenSegment_prv.h"
#include"../../MCAL/PORT/PORT.h"
#include"../../MCAL/DIO/DIO.h"
void SEVENSEGMENT_Init(SevenSeg_t* Ptr_SevenSegObj){
	u8 pinSegement;
	u8 pinButton;
	for(pinSegement=1; pinSegement<9;pinSegement++){
		Port_enuSetPinDirection(pinSegement,PORT_u8OUTPUT);
		}
		for(pinButton=26; pinButton<29;pinButton++){
			Port_enuSetPinDirection(pinButton,PORT_u8INPUT);
			}

		for(pinSegement=1; pinSegement<9;pinSegement++){
			Port_enuSetPinMode(pinSegement,PORT_u8OUTPUT_HIGH);
		}
		for(pinButton=26; pinButton<29;pinButton++){
			Port_enuSetPinMode(pinButton,PORT_u8INPUT_PULLUP);
			}
}
void SEVENSEGMENT_SetMode(SevenSeg_t* Ptr_SevenSegObj,u8 Copy_u8SevenSegMode){
	if(Copy_u8SevenSegMode==SEVEN_SEG_ON){

		Dio_enuWriteChannel(Ptr_SevenSegObj->PinEn,DIO_u8LEVEL_HIGH);
	}
	else if(Copy_u8SevenSegMode==SEVEN_SEG_OFF){
		Dio_enuWriteChannel(Ptr_SevenSegObj->PinEn,DIO_u8LEVEL_LOW);

	}
	else {

		// wrong Mode ordered
	}

}
/*void SEVENSEGMENT_Display(SevenSeg_t* Ptr_SevenSegObj,u8 Copy_u8SevenSegValue){
if(Copy_u8SevenSegValue>=0 && Copy_u8SevenSegValue<10){
	switch (Copy_u8SevenSegValue){
	case 0:

		Dio_enuWritePort(DIO_u8PORTA,NUMBER_ZERO);
		break;
	case 1:
		Dio_enuWritePort(DIO_u8PORTA,NUMBER_ONE);

		break;
	case 2:
		Dio_enuWritePort(DIO_u8PORTA,NUMBER_TWO);
		break;
		case 3:
			Dio_enuWritePort(DIO_u8PORTA,NUMBER_THREE);

			break;
			case 4:

				Dio_enuWritePort(DIO_u8PORTA,NUMBER_FOUR);
				break;
				case 5:
					Dio_enuWritePort(DIO_u8PORTA,NUMBER_FIVE);

					break;
					case 6:
						Dio_enuWritePort(DIO_u8PORTA,NUMBER_SIX);
						break;
						case 7:
							Dio_enuWritePort(DIO_u8PORTA,NUMBER_SEVEN);
							break;
							case 8:

						Dio_enuWritePort(DIO_u8PORTA,NUMBER_EIGHT);
								break;
								case 9:
									Dio_enuWritePort(DIO_u8PORTA,NUMBER_NINE);

									break;

								default :
									Dio_enuWritePort(DIO_u8PORTA,NUMBER_ZERO);
									break;
	}
}
else{
// PRINT ERROR STATE
}

}
*/
