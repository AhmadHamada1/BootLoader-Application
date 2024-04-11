/*
 * app.c
 *
 *  Created on: April 1, 2024
 *      Author: Hamada
 */
#include"ADisplay_Interface.h"
#include"LSTD_TYPES.h"
#include"MRCC_Interface.h"
#include"MGPIO_Interface.h"
#include"MSPI_Interface.h"
#include"HTFT_Interface.h"
#include"IMAGE.H"

void ADisplay_Init(void)
{
	/*Step 1 : System Clock is 16 MHz From HSI*/
	MRCC_voidInitSystemClk();
	/*Step 2 : Enable GPIO Peripheral Clock For Port A*/
	MRCC_voidEnablePeripheralClock(RCC_AHB1,RCC_GPIOA);

	/*Step 3 : Enable SPI1 Peripheral Clock */
	MRCC_voidEnablePeripheralClock(RCC_APB2,RCC_SPI1);

	/*Step 4 : Set Pin Direction ->> Output [CS - RST - A0]*/
	for(u8 lOC_U8Counter = APP_VALUE_0 ; lOC_U8Counter < APP_VALUE_3 ; lOC_U8Counter++)
	{
		MGPIO_voidSetPinMode(MGPIOA_PORT,lOC_U8Counter,MGPIO_MODE_OUTPUT) ;
		/*Set Pin Speed*/
		MGPIO_voidSetOutputSpeed(MGPIOA_PORT,lOC_U8Counter,MGPIO_OUTPUT_SPEED_MEDUIM) ;
		/*Pull Output Type*/
		MGPIO_voidSetOutputType(MGPIOA_PORT,lOC_U8Counter,MGPIO_OUTPUT_TYPE_PUSH_PULL) ;
	}
	/*Step 5 : Configure SPI PIN*/
	MGPIO_voidSetPinMode(MGPIOA_PORT,MGPIO_PIN5,MGPIO_MODE_ALTF) ;  // SPI1 serial clock
	MGPIO_voidSetPinMode(MGPIOA_PORT,MGPIO_PIN7,MGPIO_MODE_ALTF) ;  // SPI1 MOSI


	MGPIO_voidSetPinAltFun(MGPIOA_PORT,MGPIO_PIN5,MGPIO_ALTFN_5) ;  // SPI1 serial clock
	MGPIO_voidSetPinAltFun(MGPIOA_PORT,MGPIO_PIN7,MGPIO_ALTFN_5) ;  // SPI1 MOSI

	MGPIO_voidSetPinMode(MGPIOA_PORT,MGPIO_PIN12,MGPIO_MODE_OUTPUT);
	/*Step 6 : initializing SPI */
	MSPI_voidInit() ;
	MGPIO_voidSetPinValue(MGPIOA_PORT,MGPIO_PIN12,MGPIO_HIGH);

	/*Step 7 : initializing TFT */
	HTFT_voidInit() ;
	/* Display Image*/

		HTFT_voidDisplayImage( imag_arr) ;
		while (1)
		{

		}

}

//void ADisplay_DisplayRun(void)
//{
//
//}
