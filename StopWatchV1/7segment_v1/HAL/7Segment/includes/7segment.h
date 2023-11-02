/*
 * _7segment.h
 *
 * Created: 11/2/2023 11:49:03 AM
 *  Author: sharb
 */ 


#ifndef _7SEGMENT_H_
#define _7SEGMENT_H_



#define FIRST_7SEGMENT    4
#define SECOND_7SEGMENT   3
#define THIRD_7SEGMENT    2
#define FOURTH_7SEGMENT   1


/*
NAME: _7SEGMENT_vidDisplay
DESC: Display Number from 0 to 9 on specific seven segment
ARGS: u8 number to be displayed, u8 selection of seven segment
RET : void

*/
void _7SEGMENT_vidDisplay(u8 arg_u8_num,u8 arg_u8_select);

#endif /* 7SEGMENT_H_ */