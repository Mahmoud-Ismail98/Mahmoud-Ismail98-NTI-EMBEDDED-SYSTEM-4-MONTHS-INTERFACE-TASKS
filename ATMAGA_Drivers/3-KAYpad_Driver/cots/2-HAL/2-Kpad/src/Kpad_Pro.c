/*
 * Kpad_Pro.c
 *
 *  Created on: Oct 27, 2023
 *      Author: Online
 */
#include "../../../4-SERVICS/Bit_utils.h"
#include "../../../4-SERVICS/Std_types.h"
#include "../../../1-MCAL/01-DIO/DIO_Int.h"
#include "../../2-Kpad/include/Kpad.h"
#include "../../2-Kpad/include/Kpad_Prv.h"
#include "../../2-Kpad/include/Kpad_Cfg.h"
#include "util/delay.h"

void HKPD_voidKBPInit (void)
{
	MDIO_VidSetPinDirection(KPD_ROW_PORT,Row_0_Pin,Pin_Output) ;
	MDIO_VidSetPinDirection(KPD_ROW_PORT,Row_1_Pin,Pin_Output) ;
	MDIO_VidSetPinDirection(KPD_ROW_PORT,Row_2_Pin,Pin_Output) ;
	MDIO_VidSetPinDirection(KPD_ROW_PORT,Row_3_Pin,Pin_Output) ;


	MDIO_VidSetPinDirection(KPD_COL_PORT,Col_0_Pin,Pin_Input) ;
	MDIO_VidSetPinDirection(KPD_COL_PORT,Col_1_Pin,Pin_Input) ;
	MDIO_VidSetPinDirection(KPD_COL_PORT,Col_2_Pin,Pin_Input) ;
	MDIO_VidSetPinDirection(KPD_COL_PORT,Col_3_Pin,Pin_Input) ;

}




u8 HKPD_u8GetPressedKey(void)
{
    u8 Col_State = 1;            // Initialize Col_State to 1 (assuming all columns are pulled high)
    u8 Col_arr[] = {Col_0_Pin, Col_1_Pin, Col_2_Pin, Col_3_Pin};
    u8 Row_arr[] = {Row_0_Pin, Row_1_Pin, Row_2_Pin, Row_3_Pin};
    u8 kay;
    for (u8 Row = 0; Row < 4; Row++)
    {
        // Set the current row pin low (activate the row)
        MDIO_VidSetPinValue(KPD_ROW_PORT, Row_arr[Row], Pin_Low);

        for (u8 Col = 0; Col < 4; Col++)
        {
            // Read the state of the current column
        	MDIO_VidGetPinValue(KPD_COL_PORT, Col_arr[Col], &Col_State);

            if (Col_State == 0)
            {
                // Debouncing and single press logic
                _delay_ms(50); // Debounce delay (adjust as needed)

                // Check the column state again after debounce
                MDIO_VidGetPinValue(KPD_COL_PORT, Col_arr[Col], &Col_State);

                if (Col_State == 0)
                {
                    // Key pressed, map and return the key
                	MDIO_VidSetPinValue(KPD_ROW_PORT, Row_arr[Row], Pin_High);
                	kay=KayPad_arr[Row][Col];
                    return kay;
                }
            }
        }

        // Deactivate the row before moving to the next row
        MDIO_VidSetPinValue(KPD_ROW_PORT, Row_arr[Row], Pin_High);
    }

    // No key was pressed
    return kay;
}





#if 0
u8 HKPD_u8GetPressedKey (void)
{
	u8 Col_State = 0 ;

	u8 Col_arr [] = {Col_0_Pin , Col_1_Pin , Col_2_Pin , Col_3_Pin } ;
	u8 Row_arr [] = {Row_0_Pin , Row_1_Pin , Row_2_Pin , Row_3_Pin } ;

	for (u8 Row = 0 ; Row <4 ; Row ++)
	{
		MDIO_VidSetPinValue (KPD_ROW_PORT , Row_arr[Row],Pin_Low) ;


		for (u8 Col = 0 ; Col <4 ; Col ++)
		{
			MDIO_VidGetPinValue(KPD_COL_PORT , Col_arr[Col] , &Col_State) ;
					if (Col_State == 0 )
					{
						while (Col_State == 0 )
						{
							MDIO_VidGetPinValue(KPD_COL_PORT , Col_arr [Col] , &Col_State ) ;
							_delay_ms (200) ;

							MDIO_VidSetPinValue(KPD_ROW_PORT , Row_arr [Row], Pin_High) ;
							return KayPad_arr[Row][Col] ;
						}


					}

		}
	}
	return 100 ;

}
#endif





