/*
 * eeprom.h
 *
 * Created: 10/30/2023 10:39:04 PM
 *  Author: sharb
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_


#include "std_types.h"

#define EEPROM_ADDRESS 			0xA0
#define EEPROM_PAGE_SIZE 		64
#define PAGE_ADDRESS			0x0000


void eeprom_init(void);
void eeprom_write_byte(u16 address, u8 data);
void eeprom_write_string(u16 Copy_u8Address,u8* str);
void eeprom_read_string(u16 Copy_u8Address, u8* str);
u8 eeprom_read_byte(u16 address);



#endif /* EEPROM_H_ */