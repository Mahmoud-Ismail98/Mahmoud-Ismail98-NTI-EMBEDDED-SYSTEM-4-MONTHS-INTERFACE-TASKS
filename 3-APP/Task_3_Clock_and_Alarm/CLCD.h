/*****************************************************************************/
/*****************************************************************************/
/**********************    Author : Mohamed Aburehab    **********************/
/**********************    Layer  : HAL                 **********************/
/**********************    SWD    : CLCD                **********************/
/**********************    Version: 1.0                 **********************/
/*****************************************************************************/
/*****************************************************************************/
#ifndef CLCD_H
#define CLCD_H


void CLCD_VidInit(void);

void CLCD_VidSendCommand(u8 Copy_u8Command);

void CLCD_VidDisplayCharacter(u8 Copy_u8Command);

void CLCD_VidCreatCustomCharacter(pu8 Add_pu8CustomCharacter, u8 index);

void CLCD_VidGoToXY(u8 Copy_u8Row, u8 Copy_u8Column);

void CLCD_VidDisplayString(pu8 Add_u8String);

void CLCD_VidDisplayNumber(u64 Copy_u64Number);

#endif
