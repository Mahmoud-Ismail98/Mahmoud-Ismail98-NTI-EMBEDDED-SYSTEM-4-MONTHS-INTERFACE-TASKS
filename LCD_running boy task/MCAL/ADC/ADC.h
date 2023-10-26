#ifndef ADC_H_
#define ADC_H_


typedef enum{
	ADC_ERROR_FREE,
	ADC_ERROR_CHANNEL
}ADC_ERROR_STATE;


void ADC_voidInit(void);
ADC_ERROR_STATE ADC_read(u8 ADC_CHANEL,u16 *loc_AdcVal);
void ADC_Disable(void);

#define			 Free_Running_mode					0b000
#define			 Analog_Comparator					0b001
#define			 External_Interrupt_Request0		0b010
#define			 Timer_Counter0_Compare_Match		0b011
#define			 Timer_Counter0_Overflow			0b100
#define			 Timer_Counter1_Compare_Match_B		0b101
#define			 Timer_Counter1_Overflow			0b110
#define			 Timer_Counter1_Capture_Event		0b111
#define Trigger_Source_Selections Free_Running_mode
#define INTERRUPT_ENABLE 1
#define INTERUPT_DISABLE 0

#define ADMUX 		*((volatile u8 *)0x27)
#define ADCSRA 		*((volatile u8 *)0x26)
#define ADCH 		*((volatile u8 *)0x25)
#define ADCL 		*((volatile u8 *)0x24)
#define SFIOR 		*((volatile u8 *)0x50)
#define ADC_CH0		0b00000
#define ADC_CH1		0b00001
#define ADC_CH2		0b00010
#define ADC_CH3		0b00011
#define ADC_CH4		0b00100
#define ADC_CH5		0b00101
#define ADC_CH6		0b00110
#define ADC_CH7		0b00111
#define ADC_CHA	    ADC_CH0

#define	PRE_SCALER0	   0b000
#define	PRE_SCALER2	   0b001
#define	PRE_SCALER4	   0b010
#define	PRE_SCALER8	   0b011
#define	PRE_SCALER16   0b100
#define	PRE_SCALER32   0b101
#define	PRE_SCALER64   0b110
#define	PRE_SCALER128  0b111
#define PRESCALER	PRE_SCALER128

#define	 AREF				0b00
#define	 AVCC_5v			0b01
#define	 Reserved			0b10
#define	 Internal_2_5V		0b11

#define Ref_VOLT_MODE  AVCC_5v


#endif