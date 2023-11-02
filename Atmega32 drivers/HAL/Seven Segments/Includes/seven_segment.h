/*
 * seven_segment.h
 *
 * Created: 29/10/2023 07:27:13 م
 *  Author: EGYPT
 */ 


#ifndef SEVEN_SEGMENT_H_
#define SEVEN_SEGMENT_H_


void segments_init (void);

void Enable_segment(u8 pin_num) ;

void Disable_all_segments(void);

#endif /* SEVEN_SEGMENT_H_ */