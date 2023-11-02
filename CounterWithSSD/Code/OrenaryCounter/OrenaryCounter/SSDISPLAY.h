/*
 * SSDISPLAY.h
 *
 * Created: 10/25/2023 6:29:41 PM
 *  Author: HP
 */ 


#ifndef SSDISPLAY_H_
#define SSDISPLAY_H_

typedef enum SSDISPLAY_enuErrorStatus  {
	SSDISPLAY_WRONGNUMBER,               
	SSDISPLAY_OK,               
	         
}SSDISPLAY_enuErrorStatus; 



SSDISPLAY_enuErrorStatus SSDISPLAY_enuWriteNumber(u8 Copy_u8Number,u8 Copy_u8Seg);




#endif /* SSDISPLAY_H_ */