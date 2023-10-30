#ifndef ADC_H_
#define ADC_H_


typedef enum{
	ADC_ERROR_FREE,
	ADC_ERROR_CHANNEL
}ADC_ERROR_STATE;

void ADC_voidInit(void);
ADC_ERROR_STATE ADC_read(u8 ADC_CHANEL,u16 *loc_AdcVal);
void ADC_Disable(void);
void ADC_AScyn(void);
void ADC_InteruptDisable(void);
void ADC_SetCallBack(void (* copy_ptrfun)(u16 var));
void ADC_AScyn(void);



#endif