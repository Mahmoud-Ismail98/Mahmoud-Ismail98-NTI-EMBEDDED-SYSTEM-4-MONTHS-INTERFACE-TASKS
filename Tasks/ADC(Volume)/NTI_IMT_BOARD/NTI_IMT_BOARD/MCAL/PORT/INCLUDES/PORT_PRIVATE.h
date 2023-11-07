/*
 * PORT_PRIVATE.h
 *
 * Created: 10/20/2023 11:58:06 AM
 *  Author: Mahmoud Tariq
 */ 


#ifndef PORT_PRIVATE_H_
#define PORT_PRIVATE_H_


/*for port A*/
#define DDRA     (*((volatile pu8)0x3A))
#define PORTA    (*((volatile pu8)0x3B))
#define PINA     (*((volatile pu8)0x39))

/*for port B*/
#define DDRB    (*((volatile pu8)0x37))
#define PORTB   (*((volatile pu8)0x38))
#define PINB    (*((volatile pu8)0x36))
/*for port C*/
#define DDRC    (*((volatile pu8)0x34))
#define PORTC   (*((volatile pu8)0x35))
#define PINC    (*(volatile pu8)0x33)

/*for port D*/
#define DDRD    (*(volatile pu8)0x31)
#define PORTD   (*(volatile pu8)0x32)
#define PIND     (*(volatile pu8)0x30)





#endif /* PORT_PRIVATE_H_ */