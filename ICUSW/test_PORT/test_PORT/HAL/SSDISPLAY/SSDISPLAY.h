/*
 * SSDISPLAY.h
 *
 * Created: 10/25/2023 6:29:41 PM
 *  Author: HP
 */ 


#ifndef SSDISPLAY_H_
#define SSDISPLAY_H_

typedef enum SSDISPLAY_tenuErrorStatus  {
	SSDISPLAY_WRONGNUMBER,               
	SSDISPLAY_OK,               
	         
}SSDISPLAY_tenuErrorStatus; 


void SSDISPLAY_VoidInit(void);
SSDISPLAY_tenuErrorStatus SSDISPLAY_tenuWriteNumber(u8 Copy_u8Number);
void SSDISPLAY_VoidWriteNumberInSpecificSegmant(u16 Copy_u16Number);



#endif /* SSDISPLAY_H_ */