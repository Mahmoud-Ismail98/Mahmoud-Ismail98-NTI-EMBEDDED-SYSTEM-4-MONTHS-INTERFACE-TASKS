#ifndef PORT_PRIVATE_H_
#define PORT_PRIVATE_H_




/*PORT NUMBER*/
#define u8PORTA 					    0
#define u8PORTB							1
#define u8PORTC 			     		2
#define u8PORTD						    3
/*DIRECTION*/	
#define PIN_INPUT  0
#define PIN_OUTPUT 1
/*MODE*/
#define PIN_OUT_HIGH   1
#define PIN_OUT_LOW    0
#define PIN_IN_FLOAT   2
#define PIN_IN_PULLUP  3

#define PORTA (*(volatile u8*) 0x3B)
#define DDRA  (*(volatile u8*) 0x3A)
#define PINA  (*(volatile u8*) 0x39)
#define PORTB (*(volatile u8*) 0x38)
#define DDRB  (*(volatile u8*) 0x37)
#define PINB  (*(volatile u8*) 0x36)
#define PORTC (*(volatile u8*) 0x35)
#define DDRC  (*(volatile u8*) 0x34)
#define PINC  (*(volatile u8*) 0x33)
#define PORTD (*(volatile u8*) 0x32)
#define DDRD  (*(volatile u8*) 0x31)
#define PIND  (*(volatile u8*) 0x30)

/*PORTA*/
#define PIN_ID0     0
#define PIN_ID1     1
#define PIN_ID2     2
#define PIN_ID3     3
#define PIN_ID4     4
#define PIN_ID5     5
#define PIN_ID6     6
#define PIN_ID7     7
/*PORTB*/
#define PIN_ID8     8
#define PIN_ID9     9
#define PIN_ID10    10
#define PIN_ID11    11
#define PIN_ID12    12
#define PIN_ID13    13
#define PIN_ID14    14
#define PIN_ID15    15
/*PORTC*/
#define PIN_ID16    16
#define PIN_ID17    17
#define PIN_ID18    18
#define PIN_ID19    19
#define PIN_ID20    20
#define PIN_ID21    21
#define PIN_ID22    22
#define PIN_ID23    23
/*PORTB*/
#define PIN_ID24    24
#define PIN_ID25    25
#define PIN_ID26    26
#define PIN_ID27    27
#define PIN_ID28    28
#define PIN_ID29    29
#define PIN_ID30    30
#define PIN_ID31    31
#endif