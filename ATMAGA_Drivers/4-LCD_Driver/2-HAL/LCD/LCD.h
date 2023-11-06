/*
 * LCD.h
 *
 * Created: 10/21/2023 2:19:27 PM
 *  Author: FADY
 */ 


#ifndef LCD_H_
#define LCD_H_

void CLCD_VoidInit(void);
void CLCD_voidSendCommand(u8 Copy_u8Command);
void CLCD_voidSendData(u8 Copy_u8Data);
void ClCD_voidSendString(const char* Copy_ChString );
void CLCD_voidGoToXY(u8 Copy_u8XPos,u8 Copy_u8YPos);
void CLCD_voidCreateSpeacialCharater(u8* Copy_pu8Arr, u8 Copy_u8index,u8 Copy_u8XPos,u8 Copy_u8YPos);
void CLCD_voidClearDisplay();
void CLCD_VidSendNumber(u32 Copy_u32Data);
#endif /* LCD1_H_ */
