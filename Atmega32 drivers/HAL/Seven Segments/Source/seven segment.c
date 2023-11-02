/*
 * seven_segment.c
 *
	Author : Abdelrahman Mohamed
 */ 
segments_init(void){
	
	Port_enuSetPinDirection(EN_DIGIT1,OUT_PIN);
	Port_enuSetPinDirection(EN_DIGIT2,OUT_PIN);
	Port_enuSetPinDirection(EN_DIGIT3,OUT_PIN);
	Port_enuSetPinDirection(EN_DIGIT4,OUT_PIN);
	
	Dio_enuWriteChannel(EN_DIGIT1, DIO_u8LEVEL_HIGH );
	Dio_enuWriteChannel(EN_DIGIT2, DIO_u8LEVEL_HIGH );
	Dio_enuWriteChannel(EN_DIGIT3, DIO_u8LEVEL_HIGH );
	Dio_enuWriteChannel(EN_DIGIT4, DIO_u8LEVEL_HIGH );
	BIT_0 , BIT_1 ,BIT_2,BIT_3=0;
}

Disable_all_segments(void){
	
		Dio_enuWriteChannel(EN_DIGIT1, DIO_u8LEVEL_LOW);
		Dio_enuWriteChannel(EN_DIGIT2, DIO_u8LEVEL_LOW );
		Dio_enuWriteChannel(EN_DIGIT3, DIO_u8LEVEL_LOW );
		Dio_enuWriteChannel(EN_DIGIT4, DIO_u8LEVEL_LOW );
	
}

void Enable_segment(u8 pin_num) {
	
	Dio_enuWriteChannel(pin_num, DIO_u8LEVEL_HIGH );
}

void display_num(u8 num){
	num/=1000;
	
	
	
}