/*
 * app.c
 *
 * Created: 11/1/2023 7:05:47 PM
 *  Author: sharb
 */ 

#include "std_types.h"
#include "../../MCAL/PORT/includes/PORT.h"
#include "../../HAL/7Segment/includes/7segment.h"
#include "../../HAL/PushButton/includes/PushButton.h"
#include "../includes/app.h"
#include "util/delay.h"

u8 gl_u8_SEC_unit         = FALSE ;//first  seven segment Display
u8 gl_u8_MIN_unit         = FALSE ;//second seven segment Display
u8 gl_u8_MIN_tenth        = FALSE ;//third	seven segment Display
u8 gl_u8_SEC_tenth        = FALSE ;//fourth	seven segment Display

u8 gl_u8_switches_flag    = FALSE ;//this flag hold the state of last pressed switch(start,pause,clear)
u8 gl_u8_on_flag          = FALSE ;//this flag indicates start button is pressed and we have start timer


// init app
void app_init(void)
{
	// port init to init 7segment and Buttons pins
	PORT_voidInit();
}


// start app
void app_start(void)
{
	// local to hold state of Button
	PUSH_BUTTON_STATE_enu_t loc_u8_Buttons_State  = BUTTON_LOGIC_HIGH;
	
	// SuperLoop
	while(1)
	{
		// read start button state
		loc_u8_Buttons_State = PUSHBUTTON_vidGetState(START_SWITCH);
		
		//case pressed
		if (loc_u8_Buttons_State == BUTTON_LOGIC_LOW)
		{
			//loop until user realese the button 
			while (loc_u8_Buttons_State == BUTTON_LOGIC_LOW)
			{
				loc_u8_Buttons_State = PUSHBUTTON_vidGetState(START_SWITCH);
			}
			
			// assign switches flag to START_COUNT ---> start is pressed 
			gl_u8_switches_flag = START_COUNT;
		}
		
		// case start is not pressed
		else
		{
			// read pause button state
			loc_u8_Buttons_State = PUSHBUTTON_vidGetState(PAUSE_SWITCH);
			
			//case pressed
			if (loc_u8_Buttons_State == BUTTON_LOGIC_LOW)
			{
				//loop until user realese the button 
				while (loc_u8_Buttons_State == BUTTON_LOGIC_LOW)
				{
					loc_u8_Buttons_State = PUSHBUTTON_vidGetState(PAUSE_SWITCH);
				}
				
				// assign switches flag to PAUSE_COUNT ---> pause is pressed 
				gl_u8_switches_flag = PAUSE_COUNT;
			}
			
			
			// case pause is not pressed
			else
			{
				// read clear button state
				loc_u8_Buttons_State = PUSHBUTTON_vidGetState(CLR_SWITCH);
				
				//case pressed
				if (loc_u8_Buttons_State == BUTTON_LOGIC_LOW)
				{
					//loop until user realese the button 
					while (loc_u8_Buttons_State == BUTTON_LOGIC_LOW)
					{
						loc_u8_Buttons_State = PUSHBUTTON_vidGetState(CLR_SWITCH);
					}
					
					// assign switches flag to CLR_COUNT ---> clear is pressed 
					gl_u8_switches_flag = CLR_COUNT;
				}
				// case clear is not pressed
				else
				{
					//do nothing
				}
			}
		}
		
		// switch which button is pressed
		switch(gl_u8_switches_flag)
		{
			
			//case clear is pressed
			case CLR_COUNT:
			{
				gl_u8_SEC_unit  = FALSE;//CLEAR 
				gl_u8_SEC_tenth = FALSE;//CLEAR 
				gl_u8_MIN_unit  = FALSE;//CLEAR 
				gl_u8_MIN_tenth = FALSE;//CLEAR 
				gl_u8_on_flag   = FALSE;//CLEAR 
				break;
			}
			
			//case pause is pressed
			case PAUSE_COUNT:
			{
				// stop the timer
				gl_u8_on_flag   = FALSE;
				break;
			}
			
			// case start is pressed
			case START_COUNT:
			{
				// start timer
				gl_u8_on_flag = TRUE;
				break;
			}
		}
		
		
		// DISPLAY CURRENT VALUE OF SECONDS AND MINUTES ON FOUR SEVEN SEGMENT
		_7SEGMENT_vidDisplay(gl_u8_SEC_unit,FIRST_7SEGMENT);    
		_7SEGMENT_vidDisplay(gl_u8_SEC_tenth,SECOND_7SEGMENT);
		_7SEGMENT_vidDisplay(gl_u8_MIN_unit,THIRD_7SEGMENT);
		_7SEGMENT_vidDisplay(gl_u8_MIN_tenth,FOURTH_7SEGMENT);
		
		// calculate time
		calcTime();
	}
}


void calcTime(void)
{
	static u32 loc_u32_counter = FALSE;
	
	// case timer off
	if ( gl_u8_on_flag == FALSE)
	{
		loc_u32_counter = FALSE;
	}
	// case timer on
	else
	{
		_delay_ms(MILLI_SEC);
		loc_u32_counter++;  // increament static loc counter
		if (loc_u32_counter == COUNTER_MAX) // ONE SECOND PASSED?
		{
			gl_u8_SEC_unit++; // increament second
			loc_u32_counter = FALSE; // Clear static loc counter
			
			// check on seconds unit
			if (gl_u8_SEC_unit > DISPLAY_MAX)
			{
				gl_u8_SEC_tenth++; // increament tenth
				gl_u8_SEC_unit = FALSE; // clear unit
			}
			// check on seconds tenth
			else if (gl_u8_SEC_tenth > DISPLAY_MAX)
			{
				gl_u8_MIN_unit++;  // increament Minutes unit
				gl_u8_SEC_tenth = FALSE; // clear second tenth
			}
			// check on minutes unit
			else if (gl_u8_MIN_unit > DISPLAY_MAX)
			{
				gl_u8_MIN_tenth++; // increament tenth
				gl_u8_MIN_unit = FALSE; //clear units
			}
			// check on minutes tenth
			else if (gl_u8_MIN_tenth > DISPLAY_MAX)
			{
				gl_u8_switches_flag = CLR_COUNT;//overflow and clear stop watch
			}
		}
		
	}
	
}