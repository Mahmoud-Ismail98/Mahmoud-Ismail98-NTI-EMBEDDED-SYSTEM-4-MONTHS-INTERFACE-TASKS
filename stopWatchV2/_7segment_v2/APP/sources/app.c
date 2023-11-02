/*
 * app.c
 *
 * Created: 11/1/2023 7:05:47 PM
 *  Author: sharb
 */ 

#include "std_types.h"
#include "../../MCAL/PORT/includes/PORT.h"
#include "../../MCAL/EXTINT/includes/ExtInt.h"
#include "../../MCAL/GIE/includes/Gie.h"
#include "../../HAL/7Segment/includes/7segment.h"
#include "../includes/app.h"
#include "util/delay.h"

u8 gl_u8_SEC_unit         = FALSE ;//first  seven segment Display
u8 gl_u8_MIN_unit         = FALSE ;//second seven segment Display
u8 gl_u8_MIN_tenth        = FALSE ;//third	seven segment Display
u8 gl_u8_SEC_tenth        = FALSE ;//fourth	seven segment Display

u8 gl_u8_switches_flag    = FALSE ;//this flag hold the state of last pressed switch(start,pause,clear)
u8 gl_u8_on_flag          = FALSE ;//this flag indicates start button is pressed and we have start timer



// init modules for app
void app_init(void)
{
	// port init to init 7segment
	PORT_voidInit();
	EXTINT_enum_Init(EXT_INT0,EXT_INT_FALLING_EDGE,start_fire);// init EXT interrupt for start switch
	EXTINT_enum_Init(EXT_INT1,EXT_INT_FALLING_EDGE,pause_fire);// init EXT interrupt for pause switch
	EXTINT_enum_Init(EXT_INT2,EXT_INT_FALLING_EDGE,clear_fire);// init EXT interrupt for clear switch
	
	// enable global intterrupt
	GIE_status(GIE_ENABLE);
	
}

// start app logic
void app_start(void)
{
   // super loop
	while(1)
	{
		
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


// calculate time
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


void start_fire(void)
{
	gl_u8_switches_flag = START_COUNT;
}
void pause_fire(void)
{
	gl_u8_switches_flag = PAUSE_COUNT;
}
void clear_fire(void)
{
	gl_u8_switches_flag = CLR_COUNT;
}