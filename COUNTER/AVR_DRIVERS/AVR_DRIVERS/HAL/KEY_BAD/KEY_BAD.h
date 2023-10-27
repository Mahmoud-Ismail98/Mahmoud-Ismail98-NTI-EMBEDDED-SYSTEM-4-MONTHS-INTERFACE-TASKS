/*
 * KEY_BAD.h
 *
 * Created: 10/22/2023 12:19:56 PM
 *  Author: ahmed radwan
 */ 


#ifndef KEY_BAD_H_
#define KEY_BAD_H_

/*************************macros section***********************************/
#define  NO_OF_ROWS    4
#define  NO_OF_COLUMS  4
 
/************************* macros section end ***********************************/


/*********************************** user defined data types section ***********************************/
typedef struct{
	Dio_tenuPins key_bad_rows_pins[NO_OF_ROWS];
	Dio_tenuPins key_bad_col_pins[NO_OF_COLUMS];
	}KEY_BAD_ST;
	
	typedef enum{
		KEY_BAD_E_OK,
		KEY_BAD_NULL_PTR
		}KEY_BAD_tenuErrorStatus;

/*********************************** user defined data types section end ***********************************/



/*****************function prototypes section*******************************************/
KEY_BAD_tenuErrorStatus key_bad_Init(KEY_BAD_ST*key_bad);
KEY_BAD_tenuErrorStatus key_bad_Get_value(KEY_BAD_ST*key_bad,ptr_u8 value);

/*****************function prototypes section end*******************************************/




#endif /* KEY_BAD_H_ */