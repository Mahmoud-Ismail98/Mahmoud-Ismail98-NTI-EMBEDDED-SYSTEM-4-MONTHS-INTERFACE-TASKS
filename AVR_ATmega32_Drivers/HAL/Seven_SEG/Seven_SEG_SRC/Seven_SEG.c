
#include <HAL/Seven_SEG/Seven_SEG_Includes/Seven_SEG_Private.h>


void Seven_SEG_Init()
{
	Port_Set_Pin_Mode(Seven_SEG1_EN_PORT, Seven_SEG1_EN_PIN, PIN_Output_Low);
	Port_Set_Pin_Mode(Seven_SEG2_EN_PORT, Seven_SEG2_EN_PIN, PIN_Output_Low);
	Port_Set_Pin_Mode(Seven_SEG3_EN_PORT, Seven_SEG3_EN_PIN, PIN_Output_Low);
	Port_Set_Pin_Mode(Seven_SEG4_EN_PORT, Seven_SEG4_EN_PIN, PIN_Output_Low);
	Port_Set_Pin_Mode(Seven_SEGx_Data0_PORT, Seven_SEGx_Data0_PIN, PIN_Output_Low);
	Port_Set_Pin_Mode(Seven_SEGx_Data1_PORT, Seven_SEGx_Data1_PIN, PIN_Output_Low);
	Port_Set_Pin_Mode(Seven_SEGx_Data2_PORT, Seven_SEGx_Data2_PIN, PIN_Output_Low);
	Port_Set_Pin_Mode(Seven_SEGx_Data3_PORT, Seven_SEGx_Data3_PIN, PIN_Output_Low);
}

void Seven_SEG_Display(uint8 SEVEN_SEGx, uint8 Display_Value)
{
	uint8 Seven_SEGx_Datax_Value =0;
	
	Seven_SEGx_Datax_Value = GET_BIT(Display_Value, 0); 
	DIO_Write_Channel(Seven_SEGx_Data0_PORT, Seven_SEGx_Data0_PIN, Seven_SEGx_Datax_Value);
	
	Seven_SEGx_Datax_Value = GET_BIT(Display_Value, 1);
	DIO_Write_Channel(Seven_SEGx_Data1_PORT, Seven_SEGx_Data1_PIN, Seven_SEGx_Datax_Value);
	
	Seven_SEGx_Datax_Value = GET_BIT(Display_Value, 2);
	DIO_Write_Channel(Seven_SEGx_Data2_PORT, Seven_SEGx_Data2_PIN, Seven_SEGx_Datax_Value);
	
	Seven_SEGx_Datax_Value = GET_BIT(Display_Value, 3);
	DIO_Write_Channel(Seven_SEGx_Data3_PORT, Seven_SEGx_Data3_PIN, Seven_SEGx_Datax_Value);
	
	switch(SEVEN_SEGx)
	{
		case SEVEN_SEG1:
		DIO_Write_Channel(Seven_SEG1_EN_PORT, Seven_SEG1_EN_PIN, PIN_High);
		break;
		
		case SEVEN_SEG2:
		DIO_Write_Channel(Seven_SEG2_EN_PORT, Seven_SEG2_EN_PIN, PIN_High);
		break;

		case SEVEN_SEG3:
		DIO_Write_Channel(Seven_SEG3_EN_PORT, Seven_SEG3_EN_PIN, PIN_High);
		break;
		
		case SEVEN_SEG4:
		DIO_Write_Channel(Seven_SEG4_EN_PORT, Seven_SEG4_EN_PIN, PIN_High);
		break;
	}
}

