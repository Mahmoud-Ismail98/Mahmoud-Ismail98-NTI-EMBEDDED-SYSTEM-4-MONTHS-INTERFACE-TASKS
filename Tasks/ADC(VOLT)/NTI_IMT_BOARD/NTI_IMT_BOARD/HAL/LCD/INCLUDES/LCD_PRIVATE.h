/*
 * LCD_PRIVATE.h
 *
 * Created: 10/22/2023 10:05:57 AM
 *  Author: Mahmoud Tariq
 */ 


#ifndef LCD_PRIVATE_H_
#define LCD_PRIVATE_H_


  //===================LCD Commands===================
  #define LCD_FUNCTION_4BIT_2LINES         0x28
  #define LCD_FUNCTION_8BIT_2LINES         0x38                                           
  #define LCD_MOVE_DISP_RIGHT              0x1C
  #define LCD_MOVE_DISP_LEFT               0x18
  #define LCD_MOVE_CURSOR_RIGHT            0x14
  #define LCD_MOVE_CURSOR_LEFT             0x10
  #define LCD_DISP_OFF_CURSOR_OFF          0X08
  #define LCD_DISP_ON_CURSOR_ON            0x0E
  #define LCD_DISP_ON_CURSOR_BLINK         0x0F
  #define LCD_ENTRY_MODE				   0x06
  #define LCD_ENTRY_DEC				       0x04
  #define LCD_ENTRY_DEC_SHIFT			   0x05
  #define LCD_ENTRY_INC				       0x06
  #define LCD_ENTRY_INC_SHIFT			   0x07
  #define LCD_CLEAR_SCREEN			       0X01
  #define LCD_RETURN_HOME                  0x02
  #define LCD_CGRAM_BASE_ADD			   0x40
  #define LCD_DDRAM_BASE_ADD			   0x80
  #define LCD_20COL_ROW1_BASE_ADD          0X00
  #define LCD_20COL_ROW2_BASE_ADD          0X40
  #define LCD_20COL_ROW3_BASE_ADD          0X14
  #define LCD_20COL_ROW4_BASE_ADD          0X54
  #define LCD_16COL_ROW1_BASE_ADD		   0x80 
  #define LCD_16COL_ROW2_BASE_ADD		   0xC0
  
  //=================================================




#endif /* LCD_PRIVATE_H_ */