/**************************************************************************/
/* Filename						: SYSTIC_private.h                            */
/* Author  	    				: Muhammad Ammar                          */
/* Date 						: Nov 7, 2023  	           	 	         	 */ 
/* Version 	 					: V01                                     */
/* MicroController  			: STM32429 								   */
/* Trainee At					: NTI (4 Months)						  */
/* Instructor					: Mahmoud Embabi						  */
/**************************************************************************/


#ifndef SYSTICK_SYSTIC_PRIVATE_H_
#define SYSTICK_SYSTIC_PRIVATE_H_



/********************************** Includes *********************************************/



/********************************** Macros Declarations *******************************/
#define STK_CTRL  	*((volatile u32 *) 0xE000E010)
#define STK_LOAD  	*((volatile u32 *) 0xE000E014)
#define STK_VAL   	*((volatile u32 *) 0xE000E018)
#define STK_CALIB 	*((volatile u32 *) 0xE000E01C)


#define CLK_AHB_DIV_8				0
#define CLK_AHB     				1


/********************************** Macros Function Declarations *********************/


/********************************** Data Type Declarations ****************************/



/********************************** Software Interfaces Declarations *******************/



#endif /* SYSTICK_SYSTIC_PRIVATE_H_ */
