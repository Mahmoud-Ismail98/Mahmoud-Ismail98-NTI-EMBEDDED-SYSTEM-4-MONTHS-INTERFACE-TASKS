/***************************************************************************************/
/* Description: This function is used to read and return the key pressed on a keypad. */
/*              It scans the keypad matrix and returns the pressed key's value.       */
/* Input:      None                                                                 */
/* Output:     Returns the value of the key pressed on the keypad (0 to 15), or       */
/*             NOT_PRESSED (255) if no key is pressed.                               */
/***************************************************************************************/
u8 GET_KEY_PRESSED(void)
{
    u8 LOC_Key_Pressed = NOT_PRESSED;   // Initialize the key value as NOT_PRESSED.
    u8 LOC_Pin_State;
    u8 LOC_Col_Idx, LOC_Row_Idx;

    // Define the keypad matrix in a 2D array.
    // Initialize your KPD_ARR in the configuration file.

    static u8 LOC_KPD_ARR[COL_NUM][ROW_NUM] = KPD_ARR;

    static u8 LOC_Col_Idx_ARR[COL_NUM] = {KPD_COLUMN0, KPD_COLUMN1, KPD_COLUMN2, KPD_COLUMN3};
    static u8 LOC_Row_Idx_ARR[ROW_NUM] = {KPD_ROW0, KPD_ROW1, KPD_ROW2, KPD_ROW3};

    for (LOC_Col_Idx = 0; LOC_Col_Idx < COL_NUM; LOC_Col_Idx++)
    {
        // Activate the current column.
        Dio_enuWriteChannel(LOC_Col_Idx_ARR[LOC_Col_Idx], DIO_u8LEVEL_LOW);

        for (LOC_Row_Idx = 0; LOC_Row_Idx < ROW_NUM; LOC_Row_Idx++)
        {
            // Read the current ROW.
            Dio_enuReadChannel(LOC_Row_Idx_ARR[LOC_Row_Idx], &LOC_Pin_State);

            // Check if the switch is pressed.
            if (DIO_u8LEVEL_LOW == LOC_Pin_State)
            {
                LOC_Key_Pressed = LOC_KPD_ARR[LOC_Row_Idx][LOC_Col_Idx];

                // Polling (busy waiting) until the key is released.
                while (DIO_u8LEVEL_LOW == LOC_Pin_State)
                {
                    Dio_enuReadChannel(LOC_Row_Idx_ARR[LOC_Row_Idx], &LOC_Pin_State);
                }
                return LOC_Key_Pressed;
            }
        }

        // Deactivate the current column.
        Dio_enuWriteChannel(LOC_Col_Idx_ARR[LOC_Col_Idx], DIO_u8LEVEL_HIGH);
    }

    return LOC_Key_Pressed;
}
