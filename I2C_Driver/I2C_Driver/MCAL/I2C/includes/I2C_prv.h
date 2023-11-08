/*
 * I2C_prv.h
 *
 * Created: 10/30/2023 12:02:43 PM
 *  Author: sharb
 */ 


#ifndef I2C_PRV_H_
#define I2C_PRV_H_

#include "std_types.h"

/****************************** EEPROM Control Register ****************************/
/* EEPROM Control Register */
#define EECR	*((vu8*)0x3C)

#define    EERIE        3
#define    EEMWE        2
#define    EEWE         1
#define    EERE         0

/* EEPROM Data Register */
#define EEDR	*((vu8*)0x3D)

/* EEPROM Address Register */
#define EEAR	(*(vu16*)(0x3E))  
#define EEARL	(*(vu8*)(0x3E))
#define EEARH	(*(vu8*)(0x3F))


/* TWI stands for "Two Wire Interface" or "TWI Was I2C(tm)" */
#define TWBR    (*(vu8*)(0x20))
#define TWSR    (*(vu8*)(0x21))
#define TWAR    (*(vu8*)(0x22))
#define TWDR    (*(vu8*)(0x23))
#define TWCR    (*(vu8*)(0x56))

/* TIMSK */
#define OCIE2   7
#define TOIE2   6
#define TICIE1  5
#define OCIE1A  4
#define OCIE1B  3
#define TOIE1   2
#define OCIE0   1
#define TOIE0   0


/* TIFR */
#define OCF2    7
#define TOV2    6
#define ICF1    5
#define OCF1A   4
#define OCF1B   3
#define TOV1    2
#define OCF0    1
#define TOV0    0

/* SPMCR */
#define SPMIE   7
#define RWWSB   6
/* bit 5 reserved */
#define RWWSRE  4
#define BLBSET  3
#define PGWRT   2
#define PGERS   1
#define SPMEN   0

/* TWCR */
#define TWINT   7
#define TWEA    6
#define TWSTA   5
#define TWSTO   4
#define TWWC    3
#define TWEN    2
/* bit 1 reserved */
#define TWIE    0

/* TWAR */
#define TWA6    7
#define TWA5    6
#define TWA4    5
#define TWA3    4
#define TWA2    3
#define TWA1    2
#define TWA0    1
#define TWGCE   0

/* TWSR */
#define TWS7    7
#define TWS6    6
#define TWS5    5
#define TWS4    4
#define TWS3    3
/* bit 2 reserved */

#define TWPS1   1
#define TWPS0   0


#endif /* I2C_PRV_H_ */