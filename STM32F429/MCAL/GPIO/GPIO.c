/**************************************************************************/
/* Filename						: RCC.c                            */
/* Author  	    				: Muhammad Ammar                          */
/* Date 						: Nov 5, 2023  	           	 	      	 */
/* Version 	 					: V01                                     */
/* MicroController  			: STM32F429 								 */
/* Trainee At					: NTI (4 Months)						  */
/* Instructor					: Mahmoud Embabi						  */
/**************************************************************************/



/********************************** Includes *********************************************/

#include "../../SERVICES/BIT_UTILS.h"
#include "../../SERVICES/STD_TYPES.h"
#include "../../SERVICES/MAGIC_NUMBERS.h"
#include "../../SERVICES/HELPERS.h"

#include "RCC/RCC.h"
#include "GPIO.h"
#include "GPIO_config.h"
#include "GPIO_private.h"

/********************************** Private declaration **********************************/



/********************************** Data Type Declarations ****************************/


/********************************** Macros Declarations *******************************/


/********************************** Macros Function Declarations *********************/


/******************************* Software Interfaces Implementation *******************/
Gpio_StatusErrorType Gpio_enuInit(void){
	Gpio_StatusErrorType Loc_enuGpioStatusError = GPIO_STATUS_OK;

	Gpio_concat(
	    GPIO_PORTA,
	    GPIO_u8PinChannel15_PINA15, // Start with the highest channel
	    GPIO_u8PinChannel14_PINA14,
	    GPIO_u8PinChannel13_PINA13,
	    GPIO_u8PinChannel12_PINA12,
	    GPIO_u8PinChannel11_PINA11,
	    GPIO_u8PinChannel10_PINA10,
	    GPIO_u8PinChannel9_PINA9,
	    GPIO_u8PinChannel8_PINA8,
	    GPIO_u8PinChannel7_PINA7,
	    GPIO_u8PinChannel6_PINA6,
	    GPIO_u8PinChannel5_PINA5,
	    GPIO_u8PinChannel4_PINA4,
	    GPIO_u8PinChannel3_PINA3,
	    GPIO_u8PinChannel2_PINA2,
	    GPIO_u8PinChannel1_PINA1,
	    GPIO_u8PinChannel0_PINA0 // End with the lowest channel
	);


	Gpio_concat(
	    GPIO_PORTB,
	    GPIO_u8PinChannel31_PINB15, // Corresponds to pin B15
	    GPIO_u8PinChannel30_PINB14, // Corresponds to pin B14
	    GPIO_u8PinChannel29_PINB13, // Corresponds to pin B13
	    GPIO_u8PinChannel28_PINB12, // Corresponds to pin B12
	    GPIO_u8PinChannel27_PINB11, // Corresponds to pin B11
	    GPIO_u8PinChannel26_PINB10, // Corresponds to pin B10
	    GPIO_u8PinChannel25_PINB9,  // Corresponds to pin B9
	    GPIO_u8PinChannel24_PINB8,  // Corresponds to pin B8
	    GPIO_u8PinChannel23_PINB7,  // Corresponds to pin B7
	    GPIO_u8PinChannel22_PINB6,  // Corresponds to pin B6
	    GPIO_u8PinChannel21_PINB5,  // Corresponds to pin B5
	    GPIO_u8PinChannel20_PINB4,  // Corresponds to pin B4
	    GPIO_u8PinChannel19_PINB3,  // Corresponds to pin B3
	    GPIO_u8PinChannel18_PINB2,  // Corresponds to pin B2
	    GPIO_u8PinChannel17_PINB1,  // Corresponds to pin B1
	    GPIO_u8PinChannel16_PINB0   // Corresponds to pin B0, which is indicated as 16
	);

	Gpio_concat(
	    GPIO_PORTC,
	    GPIO_u8PinChannel47_PINC15, // Corresponds to pin C15
	    GPIO_u8PinChannel46_PINC14, // Corresponds to pin C14
	    GPIO_u8PinChannel45_PINC13, // Corresponds to pin C13
	    GPIO_u8PinChannel44_PINC12, // Corresponds to pin C12
	    GPIO_u8PinChannel43_PINC11, // Corresponds to pin C11
	    GPIO_u8PinChannel42_PINC10, // Corresponds to pin C10
	    GPIO_u8PinChannel41_PINC9,  // Corresponds to pin C9
	    GPIO_u8PinChannel40_PINC8,  // Corresponds to pin C8
	    GPIO_u8PinChannel39_PINC7,  // Corresponds to pin C7
	    GPIO_u8PinChannel38_PINC6,  // Corresponds to pin C6
	    GPIO_u8PinChannel37_PINC5,  // Corresponds to pin C5
	    GPIO_u8PinChannel36_PINC4,  // Corresponds to pin C4
	    GPIO_u8PinChannel35_PINC3,  // Corresponds to pin C3
	    GPIO_u8PinChannel34_PINC2,  // Corresponds to pin C2
	    GPIO_u8PinChannel33_PINC1,  // Corresponds to pin C1
	    GPIO_u8PinChannel32_PINC0   // Corresponds to pin C0, which is indicated as 32
	);
	Gpio_concat(
	    GPIO_PORTD,
	    GPIO_u8PinChannel63_PIND15, // Corresponds to pin D15
	    GPIO_u8PinChannel62_PIND14, // Corresponds to pin D14
	    GPIO_u8PinChannel61_PIND13, // Corresponds to pin D13
	    GPIO_u8PinChannel60_PIND12, // Corresponds to pin D12
	    GPIO_u8PinChannel59_PIND11, // Corresponds to pin D11
	    GPIO_u8PinChannel58_PIND10, // Corresponds to pin D10
	    GPIO_u8PinChannel57_PIND9,  // Corresponds to pin D9
	    GPIO_u8PinChannel56_PIND8,  // Corresponds to pin D8
	    GPIO_u8PinChannel55_PIND7,  // Corresponds to pin D7
	    GPIO_u8PinChannel54_PIND6,  // Corresponds to pin D6
	    GPIO_u8PinChannel53_PIND5,  // Corresponds to pin D5
	    GPIO_u8PinChannel52_PIND4,  // Corresponds to pin D4
	    GPIO_u8PinChannel51_PIND3,  // Corresponds to pin D3
	    GPIO_u8PinChannel50_PIND2,  // Corresponds to pin D2
	    GPIO_u8PinChannel49_PIND1,  // Corresponds to pin D1
	    GPIO_u8PinChannel48_PIND0   // Corresponds to pin D0, which is indicated as 48
	);


	Gpio_concat(
	    GPIO_PORTE,
	    GPIO_u8PinChannel79_PINE15, // Corresponds to pin E15
	    GPIO_u8PinChannel78_PINE14, // Corresponds to pin E14
	    GPIO_u8PinChannel77_PINE13, // Corresponds to pin E13
	    GPIO_u8PinChannel76_PINE12, // Corresponds to pin E12
	    GPIO_u8PinChannel75_PINE11, // Corresponds to pin E11
	    GPIO_u8PinChannel74_PINE10, // Corresponds to pin E10
	    GPIO_u8PinChannel73_PINE9,  // Corresponds to pin E9
	    GPIO_u8PinChannel72_PINE8,  // Corresponds to pin E8
	    GPIO_u8PinChannel71_PINE7,  // Corresponds to pin E7
	    GPIO_u8PinChannel70_PINE6,  // Corresponds to pin E6
	    GPIO_u8PinChannel69_PINE5,  // Corresponds to pin E5
	    GPIO_u8PinChannel68_PINE4,  // Corresponds to pin E4
	    GPIO_u8PinChannel67_PINE3,  // Corresponds to pin E3
	    GPIO_u8PinChannel66_PINE2,  // Corresponds to pin E2
	    GPIO_u8PinChannel65_PINE1,  // Corresponds to pin E1
	    GPIO_u8PinChannel64_PINE0   // Corresponds to pin E0, starting from 64
	);
	Gpio_concat(
	    GPIO_PORTF,
	    GPIO_u8PinChannel95_PINF15, // Corresponds to pin F15
	    GPIO_u8PinChannel94_PINF14, // Corresponds to pin F14
	    GPIO_u8PinChannel93_PINF13, // Corresponds to pin F13
	    GPIO_u8PinChannel92_PINF12, // Corresponds to pin F12
	    GPIO_u8PinChannel91_PINF11, // Corresponds to pin F11
	    GPIO_u8PinChannel90_PINF10, // Corresponds to pin F10
	    GPIO_u8PinChannel89_PINF9,  // Corresponds to pin F9
	    GPIO_u8PinChannel88_PINF8,  // Corresponds to pin F8
	    GPIO_u8PinChannel87_PINF7,  // Corresponds to pin F7
	    GPIO_u8PinChannel86_PINF6,  // Corresponds to pin F6
	    GPIO_u8PinChannel85_PINF5,  // Corresponds to pin F5
	    GPIO_u8PinChannel84_PINF4,  // Corresponds to pin F4
	    GPIO_u8PinChannel83_PINF3,  // Corresponds to pin F3
	    GPIO_u8PinChannel82_PINF2,  // Corresponds to pin F2
	    GPIO_u8PinChannel81_PINF1,  // Corresponds to pin F1
	    GPIO_u8PinChannel80_PINF0   // Corresponds to pin F0, starting from 80
	);
	Gpio_concat(
	    GPIO_PORTG,
	    GPIO_u8PinChannel111_PING15, // Corresponds to pin G15
	    GPIO_u8PinChannel110_PING14, // Corresponds to pin G14
	    GPIO_u8PinChannel109_PING13, // Corresponds to pin G13
	    GPIO_u8PinChannel108_PING12, // Corresponds to pin G12
	    GPIO_u8PinChannel107_PING11, // Corresponds to pin G11
	    GPIO_u8PinChannel106_PING10, // Corresponds to pin G10
	    GPIO_u8PinChannel105_PING9,  // Corresponds to pin G9
	    GPIO_u8PinChannel104_PING8,  // Corresponds to pin G8
	    GPIO_u8PinChannel103_PING7,  // Corresponds to pin G7
	    GPIO_u8PinChannel102_PING6,  // Corresponds to pin G6
	    GPIO_u8PinChannel101_PING5,  // Corresponds to pin G5
	    GPIO_u8PinChannel100_PING4,  // Corresponds to pin G4
	    GPIO_u8PinChannel99_PING3,   // Corresponds to pin G3
	    GPIO_u8PinChannel98_PING2,   // Corresponds to pin G2
	    GPIO_u8PinChannel97_PING1,   // Corresponds to pin G1
	    GPIO_u8PinChannel96_PING0    // Corresponds to pin G0, starting from 96
	);



	Gpio_concat(
	    GPIO_PORTH,
	    GPIO_u8PinChannel127_PINH15, // Corresponds to pin H15
	    GPIO_u8PinChannel126_PINH14, // Corresponds to pin H14
	    GPIO_u8PinChannel125_PINH13, // Corresponds to pin H13
	    GPIO_u8PinChannel124_PINH12, // Corresponds to pin H12
	    GPIO_u8PinChannel123_PINH11, // Corresponds to pin H11
	    GPIO_u8PinChannel122_PINH10, // Corresponds to pin H10
	    GPIO_u8PinChannel121_PINH9,  // Corresponds to pin H9
	    GPIO_u8PinChannel120_PINH8,  // Corresponds to pin H8
	    GPIO_u8PinChannel119_PINH7,  // Corresponds to pin H7
	    GPIO_u8PinChannel118_PINH6,  // Corresponds to pin H6
	    GPIO_u8PinChannel117_PINH5,  // Corresponds to pin H5
	    GPIO_u8PinChannel116_PINH4,  // Corresponds to pin H4
	    GPIO_u8PinChannel115_PINH3,  // Corresponds to pin H3
	    GPIO_u8PinChannel114_PINH2,  // Corresponds to pin H2
	    GPIO_u8PinChannel113_PINH1,  // Corresponds to pin H1
	    GPIO_u8PinChannel112_PINH0   // Corresponds to pin H0, starting from 112
	);


	return Loc_enuGpioStatusError;
}


Gpio_StatusErrorType Gpio_eniInitPin(const Gpio_PinConfigType* Address_Pin){

	Gpio_StatusErrorType Loc_enuGpioStatusError = GPIO_STATUS_OK;
		u8 Loc_u8PinNumber = (Address_Pin->gpio_pin_index) % SIXTEEN_VALUE;
		u8 Loc_u8PortNumber = (Address_Pin->gpio_pin_index) /SIXTEEN_VALUE;

		if(Loc_u8PinNumber > GPIO_MAX_INDEX_OF_PIN_NUMBER ){
			Loc_enuGpioStatusError = GPIO_STATUS_WRONG_PIN_ID;
			}


			else{
					/* Set mode */
				*Global_ModeArr[Loc_u8PortNumber] = ((*Global_ModeArr[Loc_u8PortNumber])& ~(THREE_VALUE<<(Loc_u8PinNumber*TWO_VALUE)) ) |\
									(((Address_Pin->gpio_select_pin_mode) &THREE_VALUE ) <<(Loc_u8PinNumber*TWO_VALUE));

					/* Set Output Type */
			   	WRITE_BIT(*Global_OutputTypeArr[Loc_u8PortNumber],Loc_u8PinNumber,((Address_Pin->gpio_select_pin_mode)>>2)& ONE_VALUE);

					/* Set Speed */
			   	*Global_OutputSpeedArr[Loc_u8PortNumber] = ((*Global_OutputSpeedArr[Loc_u8PortNumber])& ~(THREE_VALUE<<(Loc_u8PinNumber*TWO_VALUE)) ) |\
			   										(((Address_Pin->gpio_select_speed_reg) &THREE_VALUE ) <<(Loc_u8PinNumber*TWO_VALUE));
					/* set PULL UP OR PULL DOWN */

			   	*Global_PUPDArr[Loc_u8PortNumber] = ((*Global_PUPDArr[Loc_u8PortNumber])& ~(THREE_VALUE<<(Loc_u8PinNumber*TWO_VALUE)) ) |\
			   				   										(((Address_Pin->gpio_select_speed_reg) &THREE_VALUE ) <<(Loc_u8PinNumber*TWO_VALUE));
		}

			return Loc_enuGpioStatusError;
}

Gpio_StatusErrorType Gpio_enuWriteChannel(u8 Copy_u8ChannelId,u8 Copy_u8Level){

	Gpio_StatusErrorType Loc_enuGpioStatusError = GPIO_STATUS_OK;
		u8 Loc_u8PinNumber = Copy_u8ChannelId % SIXTEEN_VALUE;
		u8 Loc_u8PortNumber = Copy_u8ChannelId /SIXTEEN_VALUE;

		if(Loc_u8PinNumber > GPIO_MAX_INDEX_OF_PIN_NUMBER ){
			Loc_enuGpioStatusError = GPIO_STATUS_WRONG_PIN_ID;
		}

		else if(Copy_u8Level != GPIO_HIGH && Copy_u8Level!= GPIO_LOW){
			Loc_enuGpioStatusError = GPIO_STATUS_WRONG_LEVEL;
		}

			else{
				WRITE_BIT(*Global_OdreArr[Loc_u8PortNumber],Loc_u8PinNumber,Copy_u8Level);
		}

			return Loc_enuGpioStatusError;
}

Gpio_StatusErrorType Gpio_enuReadChannel(u8 Copy_u8ChannelId,pu8 Address_pu8ChannelLevel){

	Gpio_StatusErrorType Loc_enuGpioStatusError = GPIO_STATUS_OK;
		u8 Loc_u8PinNumber = Copy_u8ChannelId % SIXTEEN_VALUE;
		u8 Loc_u8PortNumber = Copy_u8ChannelId /SIXTEEN_VALUE;

		if(Loc_u8PinNumber > GPIO_MAX_INDEX_OF_PIN_NUMBER ){
			Loc_enuGpioStatusError = GPIO_STATUS_WRONG_PIN_ID;
		}

		else if(Address_pu8ChannelLevel ==  NULL){
			Loc_enuGpioStatusError = GPIO_STATUS_NULL_POINTER_ADDRESS;
		}

			else{
				*Address_pu8ChannelLevel = READ_BIT((*Global_IdrReadArr[Loc_u8PortNumber]),Loc_u8PinNumber);
		}

		return Loc_enuGpioStatusError;
}

Gpio_StatusErrorType  Gpio_enuWritePort(u8 Copy_u8PortId,u16 Copy_u16Value){

	Gpio_StatusErrorType Loc_enuGpioStatusError = GPIO_STATUS_OK;


		if(Copy_u8PortId > GPIO_MAX_INDEX_OF_CHANNEL_PORT ){
			Loc_enuGpioStatusError = GPIO_STATUS_WRONG_PORT_ID;
		}

			else{
				ASSIGN_REG(* Global_OdreArr[Copy_u8PortId],Copy_u16Value);
		}

			return Loc_enuGpioStatusError;
}

Gpio_StatusErrorType  Gpio_enuReadPort(u8 Copy_u8PortId,pu16 Address_pu8PortVAlue){

	Gpio_StatusErrorType Loc_enuGpioStatusError = GPIO_STATUS_OK;


		if(Copy_u8PortId > GPIO_MAX_INDEX_OF_CHANNEL_PORT ){
			Loc_enuGpioStatusError = GPIO_STATUS_WRONG_PORT_ID;
		}

		else if(NULL == Address_pu8PortVAlue){
			Loc_enuGpioStatusError = GPIO_STATUS_NULL_POINTER_ADDRESS;
		}
			else{
				ASSIGN_REG((* Address_pu8PortVAlue),(* Global_IdrReadArr[Copy_u8PortId]));
		}

			return Loc_enuGpioStatusError;
}
Gpio_StatusErrorType  Gpio_enuFlipChannel(u8 Copy_u8ChannelId){

	Gpio_StatusErrorType Loc_enuGpioStatusError = GPIO_STATUS_OK;
		u8 Loc_u8PinNumber = Copy_u8ChannelId % SIXTEEN_VALUE;
		u8 Loc_u8PortNumber = Copy_u8ChannelId /SIXTEEN_VALUE;

		if(Loc_u8PinNumber > GPIO_MAX_INDEX_OF_PIN_NUMBER ){
			Loc_enuGpioStatusError = GPIO_STATUS_WRONG_PIN_ID;
		}


			else{
				TOGGLE_BIT(*Global_OdreArr[Loc_u8PortNumber],Loc_u8PinNumber);
		}

			return Loc_enuGpioStatusError;
}

Gpio_StatusErrorType  Gpio_enuChangePinSpeed(u8 Copy_u8ChannelId, Gpio_SelectSpeedRegType Copy_enuSpeed){

	Gpio_StatusErrorType Loc_enuGpioStatusError = GPIO_STATUS_OK;
		u8 Loc_u8PinNumber = Copy_u8ChannelId % SIXTEEN_VALUE;
		u8 Loc_u8PortNumber = Copy_u8ChannelId /SIXTEEN_VALUE;

		if(Loc_u8PinNumber > GPIO_MAX_INDEX_OF_PIN_NUMBER ){
			Loc_enuGpioStatusError = GPIO_STATUS_WRONG_PIN_ID;
		}

			else{
				*Global_OutputSpeedArr[Loc_u8PortNumber] = ((*Global_OutputSpeedArr[Loc_u8PortNumber])& ~(THREE_VALUE<<(Loc_u8PinNumber*TWO_VALUE)) ) |\
							   										((Copy_enuSpeed &THREE_VALUE ) <<(Loc_u8PinNumber*TWO_VALUE));
		}

			return Loc_enuGpioStatusError;
}
Gpio_StatusErrorType  Gpio_enuChangePinPullupPulldown(u8 Copy_u8ChannelId, Gpio_SelectPullUpPullDownType Copy_enuPullUpPullDown){

	Gpio_StatusErrorType Loc_enuGpioStatusError = GPIO_STATUS_OK;
		u8 Loc_u8PinNumber = Copy_u8ChannelId % SIXTEEN_VALUE;
		u8 Loc_u8PortNumber = Copy_u8ChannelId /SIXTEEN_VALUE;

		if(Loc_u8PinNumber > GPIO_MAX_INDEX_OF_PIN_NUMBER ){
			Loc_enuGpioStatusError = GPIO_STATUS_WRONG_PIN_ID;
		}
			else{
			   	*Global_PUPDArr[Loc_u8PortNumber] = ((*Global_PUPDArr[Loc_u8PortNumber])& ~(THREE_VALUE<<(Loc_u8PinNumber*TWO_VALUE)) ) |\
			   				   										((Copy_enuPullUpPullDown &THREE_VALUE ) <<(Loc_u8PinNumber*TWO_VALUE));
		}

			return Loc_enuGpioStatusError;
}


Gpio_StatusErrorType Gpio_enuSetPinChannelAtomic(u8 Copy_u8ChannelId){

	Gpio_StatusErrorType Loc_enuGpioStatusError = GPIO_STATUS_OK;
		u8 Loc_u8PinNumber = Copy_u8ChannelId % SIXTEEN_VALUE;
		u8 Loc_u8PortNumber = Copy_u8ChannelId /SIXTEEN_VALUE;

		if(Loc_u8PinNumber > GPIO_MAX_INDEX_OF_PIN_NUMBER ){
			Loc_enuGpioStatusError = GPIO_STATUS_WRONG_PIN_ID;
		}


			else{
				ASSIGN_REG((* Global_BsrrArr[Loc_u8PortNumber]),(ONE_VALUE<<Loc_u8PinNumber));
		}

			return Loc_enuGpioStatusError;
}
Gpio_StatusErrorType Gpio_enuClearPinChannelAtomic(u8 Copy_u8ChannelId){

	Gpio_StatusErrorType Loc_enuGpioStatusError = GPIO_STATUS_OK;
		u8 Loc_u8PinNumber = Copy_u8ChannelId % SIXTEEN_VALUE;
		u8 Loc_u8PortNumber = Copy_u8ChannelId /SIXTEEN_VALUE;

		if(Loc_u8PinNumber > GPIO_MAX_INDEX_OF_PIN_NUMBER ){
			Loc_enuGpioStatusError = GPIO_STATUS_WRONG_PIN_ID;
		}


			else{
				ASSIGN_REG((* Global_BsrrArr[Loc_u8PortNumber]),(ONE_VALUE<<(Loc_u8PinNumber+SIXTEEN_VALUE)));
		}

			return Loc_enuGpioStatusError;
}

Gpio_StatusErrorType Gpio_enuSetAF(u8 Copy_u8ChannelId,Gpio_SelectAFType Copy_enuAF){

	Gpio_StatusErrorType Loc_enuGpioStatusError = GPIO_STATUS_OK;
		u8 Loc_u8PinNumber = Copy_u8ChannelId % SIXTEEN_VALUE;
		u8 Loc_u8PortNumber = Copy_u8ChannelId /SIXTEEN_VALUE;
		u8 Loc_u8TempPinNumber =Loc_u8PinNumber %EIGHT_VALUE;   // from 0 to 7

		if(Loc_u8PinNumber > GPIO_MAX_INDEX_OF_PIN_NUMBER ){
			Loc_enuGpioStatusError = GPIO_STATUS_WRONG_PIN_ID;
		}


			else{

				if(Loc_u8PinNumber<EIGHT_VALUE){
					*Global_AFLowArr[Loc_u8PortNumber] =  ((*Global_AFLowArr[Loc_u8PortNumber])& ~(0xF<<(Loc_u8PinNumber*FOUR_VALUE)) ) |\
												((Copy_enuAF & 0xF ) <<(Loc_u8PinNumber*FOUR_VALUE));

				}
				else{
					*Global_AFHighArr[Loc_u8PortNumber] =  ((*Global_AFHighArr[Loc_u8PortNumber])& ~(0xF<<(Loc_u8TempPinNumber*FOUR_VALUE)) ) |\
																	((Copy_enuAF & 0xF ) <<(Loc_u8TempPinNumber*FOUR_VALUE));
				}
		}

			return Loc_enuGpioStatusError;
}
Gpio_StatusErrorType Gpio_enuEnableLockPinRegister(u8 Copy_u8ChannelId){

	Gpio_StatusErrorType Loc_enuGpioStatusError = GPIO_STATUS_OK;
		u8 Loc_u8PinNumber = Copy_u8ChannelId % SIXTEEN_VALUE;
		u8 Loc_u8PortNumber = Copy_u8ChannelId /SIXTEEN_VALUE;
		volatile u8 Loc_u8LockedRead;

		if(Loc_u8PinNumber > GPIO_MAX_INDEX_OF_PIN_NUMBER ){
			Loc_enuGpioStatusError = GPIO_STATUS_WRONG_PIN_ID;
		}


			else{

				// Set the LCKx , and the LCKK bit
				*Global_LockRegArr[Loc_u8PortNumber]= (ONE_VALUE << Loc_u8PinNumber) | (ONE_VALUE << SIXTEEN_VALUE);

				// Reset the LCKK bit
				*Global_LockRegArr[Loc_u8PortNumber] = (ONE_VALUE << Loc_u8PinNumber); // you can't use CLEAR_BIT(,) .. it must be Write

				// Set the LCKx , and the LCKK bit again
				*Global_LockRegArr[Loc_u8PortNumber]= (ONE_VALUE << Loc_u8PinNumber) | (ONE_VALUE << SIXTEEN_VALUE);

				// Read back the LCKK bit to confirm the lock
				Loc_u8LockedRead = READ_BIT((*Global_LockRegArr[Loc_u8PortNumber]),SIXTEEN_VALUE);
				if(Loc_u8LockedRead == ZERO_VALUE){
					Loc_enuGpioStatusError = GPIO_STATUS_LOCKED_IS_FAILED;
				}
				else{
					Loc_enuGpioStatusError = GPIO_STATUS_OK;
				}
		}

			return Loc_enuGpioStatusError;
}


Gpio_StatusErrorType Gpio_enuEnableClockGIPOx(u8 Copy_u8PortId){

	Gpio_StatusErrorType Loc_enuGpioStatusError = GPIO_STATUS_OK;
	volatile Rcc_StatusErrorType Loc_enuRccStatusError = RCC_STATUS_OK;


		if(Copy_u8PortId > GPIO_MAX_INDEX_OF_CHANNEL_PORT ){
			Loc_enuGpioStatusError = GPIO_STATUS_WRONG_PORT_ID;
		}

			else{
			Loc_enuRccStatusError = Rcc_enuEnablePeripheralClk(RCC_BUS_INDEX_AHB1, Copy_u8PortId);

		}

			return Loc_enuGpioStatusError;
}
Gpio_StatusErrorType Gpio_enuDisableClockGIPOx(u8 Copy_u8PortId){

	Gpio_StatusErrorType Loc_enuGpioStatusError = GPIO_STATUS_OK;
	volatile Rcc_StatusErrorType Loc_enuRccStatusError = RCC_STATUS_OK;

		if(Copy_u8PortId > GPIO_MAX_INDEX_OF_CHANNEL_PORT ){
			Loc_enuGpioStatusError = GPIO_STATUS_WRONG_PORT_ID;
		}

			else{
				Loc_enuRccStatusError = Rcc_enuDisablePeripheralClk(RCC_BUS_INDEX_AHB1, Copy_u8PortId);

		}

			return Loc_enuGpioStatusError;
}
Gpio_StatusErrorType Gpio_enuEnableClockAllGPIOs(void){
	Gpio_StatusErrorType Loc_enuGpioStatusError = GPIO_STATUS_OK;
	volatile Rcc_StatusErrorType Loc_enuRccStatusError = RCC_STATUS_OK;

	Loc_enuRccStatusError = Rcc_enuEnablePeripheralClk(RCC_BUS_INDEX_AHB1, GPIO_PORTA);
	Loc_enuRccStatusError = Rcc_enuEnablePeripheralClk(RCC_BUS_INDEX_AHB1, GPIO_PORTB);
	Loc_enuRccStatusError = Rcc_enuEnablePeripheralClk(RCC_BUS_INDEX_AHB1, GPIO_PORTC);
	Loc_enuRccStatusError = Rcc_enuEnablePeripheralClk(RCC_BUS_INDEX_AHB1, GPIO_PORTD);
	Loc_enuRccStatusError = Rcc_enuEnablePeripheralClk(RCC_BUS_INDEX_AHB1, GPIO_PORTE);
	Loc_enuRccStatusError = Rcc_enuEnablePeripheralClk(RCC_BUS_INDEX_AHB1, GPIO_PORTF);
	Loc_enuRccStatusError = Rcc_enuEnablePeripheralClk(RCC_BUS_INDEX_AHB1, GPIO_PORTH);
	Loc_enuRccStatusError = Rcc_enuEnablePeripheralClk(RCC_BUS_INDEX_AHB1, GPIO_PORTG);



	return Loc_enuGpioStatusError;
}



Gpio_StatusErrorType Gpio_enuEnableClockGIPOxInLowPowerMode(u8 Copy_u8PortId){

	Gpio_StatusErrorType Loc_enuGpioStatusError = GPIO_STATUS_OK;
	volatile Rcc_StatusErrorType Loc_enuRccStatusError = RCC_STATUS_OK;


		if(Copy_u8PortId > GPIO_MAX_INDEX_OF_CHANNEL_PORT ){
			Loc_enuGpioStatusError = GPIO_STATUS_WRONG_PORT_ID;
		}

			else{
			Loc_enuRccStatusError = Rcc_enuEnablePeripheralClkInLowPowerMode(RCC_BUS_INDEX_AHB1, Copy_u8PortId);

		}

			return Loc_enuGpioStatusError;
}
Gpio_StatusErrorType Gpio_enuDisableClockGIPOxInLowPowerMode(u8 Copy_u8PortId){

	Gpio_StatusErrorType Loc_enuGpioStatusError = GPIO_STATUS_OK;
	volatile Rcc_StatusErrorType Loc_enuRccStatusError = RCC_STATUS_OK;

		if(Copy_u8PortId > GPIO_MAX_INDEX_OF_CHANNEL_PORT ){
			Loc_enuGpioStatusError = GPIO_STATUS_WRONG_PORT_ID;
		}

			else{
				Loc_enuRccStatusError = Rcc_enuDisablePeripheralClkInLowPowerMode(RCC_BUS_INDEX_AHB1, Copy_u8PortId);

		}

			return Loc_enuGpioStatusError;
}
Gpio_StatusErrorType Gpio_enuEnableClockAllGPIOsInLowPowerMode(void){
	Gpio_StatusErrorType Loc_enuGpioStatusError = GPIO_STATUS_OK;
	volatile Rcc_StatusErrorType Loc_enuRccStatusError = RCC_STATUS_OK;

	Loc_enuRccStatusError = Rcc_enuEnablePeripheralClkInLowPowerMode(RCC_BUS_INDEX_AHB1, GPIO_PORTA);
	Loc_enuRccStatusError = Rcc_enuEnablePeripheralClkInLowPowerMode(RCC_BUS_INDEX_AHB1, GPIO_PORTB);
	Loc_enuRccStatusError = Rcc_enuEnablePeripheralClkInLowPowerMode(RCC_BUS_INDEX_AHB1, GPIO_PORTC);
	Loc_enuRccStatusError = Rcc_enuEnablePeripheralClkInLowPowerMode(RCC_BUS_INDEX_AHB1, GPIO_PORTD);
	Loc_enuRccStatusError = Rcc_enuEnablePeripheralClkInLowPowerMode(RCC_BUS_INDEX_AHB1, GPIO_PORTE);
	Loc_enuRccStatusError = Rcc_enuEnablePeripheralClkInLowPowerMode(RCC_BUS_INDEX_AHB1, GPIO_PORTF);
	Loc_enuRccStatusError = Rcc_enuEnablePeripheralClkInLowPowerMode(RCC_BUS_INDEX_AHB1, GPIO_PORTH);
	Loc_enuRccStatusError = Rcc_enuEnablePeripheralClkInLowPowerMode(RCC_BUS_INDEX_AHB1, GPIO_PORTG);



	return Loc_enuGpioStatusError;
}






/**************************** Private Software Interface Implementation **************/

