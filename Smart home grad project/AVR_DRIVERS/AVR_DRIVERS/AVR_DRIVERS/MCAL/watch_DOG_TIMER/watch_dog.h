/*
 * watch_dog.h
 *
 * Created: 10/27/2023 11:15:43 AM
 *  Author: ahmed radwan
 */ 


#ifndef WATCH_DOG_H_
#define WATCH_DOG_H_

#define WATCH_DOG_ENABLE()				SET_BIT(WDTCR,3)
#define WATCH_DOG_DISABLE()			    CLR_BIT(WDTCR,3)
#define WATCH_DOG_DISABLE_enable()      SET_BIT(WDTCR,4)


#define WATCH_DOG_SET_PRESCALER() (WDTCR|=WATCH_DOG_PRESCALER_CFG)

typedef enum {OSC_16k,
			  OSC_32k,
			  OSC_64k,
			  OSC_128k,
			  OSC_256k,
			  OSC_512k,
			  OSC_1024k,
			  OSC_2048k}WATCH_DOG_enutPrescaler;
			  
void watch_dog_init(void);
void watch_dog_enable(void);
void watch_dog_disable(void);
void watch_dog_reset(void);



#endif /* WATCH_DOG_H_ */