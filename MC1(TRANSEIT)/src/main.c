/*
 * main.c
 *
 *  Created on: April 1, 2024
 *      Author: Hamada
 */
#include"LSTD_TYPES.h"
#include"MEXTI_Interface.h"
#include"MGPIO_Interface.h"
#include"MNVIC_Interface.h"
#include"MRCC_Interface.h"
#include"MUSART_Interface.h"
#include"MSTK_Interface.h"
#include"app.h"
//#include"OS.h"
#include "WT_GPIO_Test.h"





#define NO_OF_RECORDS1				2954U

//#define NO_OF_RECORDS2				359U
#define NO_OF_RECORDS2				489U


#define NO_OF_ELEMENTS_IN_RECORD	45U



#define ATHF_VALUE_0			0U
#define ATHF_VALUE_1			1U

void ATransmitHexFile_VoidSendData (void)
{
	/*indication for entering the ISR of Interrupt 0*/
	MGPIO_voidSetPinValue(MGPIOA_PORT,MGPIO_PIN1,MGPIO_LOW);
	/*local counter to loop*/
	u8 LOC_U8Counter = ATHF_VALUE_0;
	/*local counter to loop inside the 2D array*/
	u16 LOC_U16Counter=ATHF_VALUE_0;
	while (LOC_U16Counter<NO_OF_RECORDS1)
	{
		while (LOC_U8Counter<NO_OF_ELEMENTS_IN_RECORD)
		{
			MUSART_voidSendData(&arr1[LOC_U16Counter][LOC_U8Counter],ATHF_VALUE_1);
			LOC_U8Counter++;
		}
		LOC_U16Counter++;
		LOC_U8Counter=ATHF_VALUE_0;

	}

}

void OS_HEX (void)
{
	/*indication for entering the ISR of Interrupt 0*/
	MGPIO_voidSetPinValue(MGPIOA_PORT,MGPIO_PIN1,MGPIO_LOW);
	/*local counter to loop*/
	u8 LOC_U8Counter = ATHF_VALUE_0;
	/*local counter to loop inside the 2D array*/
	u16 LOC_U16Counter=ATHF_VALUE_0;
	while (LOC_U16Counter<NO_OF_RECORDS2)
	{
		while (LOC_U8Counter<NO_OF_ELEMENTS_IN_RECORD)
		{
			MUSART_voidSendData(&arr2[LOC_U16Counter][LOC_U8Counter],ATHF_VALUE_1);
			LOC_U8Counter++;
		}
		LOC_U16Counter++;
		LOC_U8Counter=ATHF_VALUE_0;

	}

}

void main (void)
{
	/*calling the function to init the application*/
	//	ATransmitHexFile_Init();
	/*Step 1 : System Clock is 16 MHz From HSI*/
	MRCC_voidInitSystemClk();

	/*Step 2 : Enable GPIO Peripheral Clock For Port A*/
	MRCC_voidEnablePeripheralClock(AHB1,MRCC_GPIOA);
	MRCC_voidEnablePeripheralClock(AHB1,MRCC_GPIOB);

	/*Step 3 : Enable USART1 Peripheral Clock */
	MRCC_voidEnablePeripheralClock(APB2 ,MRCC_USART1);
	/*Step 4 : Enable System Configuration Peripheral Clock*/
	MRCC_voidEnablePeripheralClock(APB2,MRCC_SYSCFG);
	/*Step 5 : Set Pin Direction ->> input button*/
	MGPIO_voidSetPinMode(MGPIOA_PORT,MGPIO_PIN1,MGPIO_MODE_OUTPUT) ;
	/*Set Pin Speed*/
	MGPIO_voidSetOutputSpeed(MGPIOA_PORT,MGPIO_PIN1,MGPIO_OUTPUT_SPEED_MEDUIM) ;

	/* Input*/
	MGPIO_voidSetPinMode(MGPIOA_PORT,MGPIO_PIN0,MGPIO_MODE_INPUT) ;
	/* Input Type = pullup*/
	MGPIO_voidSetPullState(MGPIOA_PORT,MGPIO_PIN0,MGPIO_PULL_UP);

	/* Input*/
	MGPIO_voidSetPinMode(MGPIOB_PORT,MGPIO_PIN2,MGPIO_MODE_INPUT) ;
	/* Input Type = pullup*/
	MGPIO_voidSetPullState(MGPIOB_PORT,MGPIO_PIN2,MGPIO_PULL_UP);

	/*Step 6 : Set Pin Mode For Pins 9 , 10 -> Alternative Function */
	MGPIO_voidSetPinMode(MGPIOA_PORT,MGPIO_PIN9,MGPIO_MODE_ALTF) ;    //TX-> USART1
	MGPIO_voidSetPinMode(MGPIOA_PORT,MGPIO_PIN10,MGPIO_MODE_ALTF) ;   //RX-> USART1


	/*Step 7 : Set Pin Alternative function For Pins 9 , 10  */
	MGPIO_voidSetPinAltFun(MGPIOA_PORT,MGPIO_PIN9,MGPIO_ALTFN_7) ;    //TX-> USART1
	MGPIO_voidSetPinAltFun(MGPIOA_PORT,MGPIO_PIN10,MGPIO_ALTFN_7) ;   //RX-> USART1
	/*Step 8 : MUSART Initialization*/
	MUSART_voidInit() ; /*11500bps , 1 stop bits  , no parity , 8  bit data*/

	/*Step 9 : Enable MUSART */
	MUSART_voidEnable() ;

	/*Step 10: Set trigger interrupt to falling edge*/
	MEXTI_voidSetTriggerSource(MEXTI_LINE_0,MEXTI_FALLING_EDGE);

	MEXTI_voidSetExtiConfig(MEXTI_LINE_0 , MEXTI_PORTA);
	/*Step 10: Assign the function to call to ISR of EXTI0*/


	MEXTI0_VoidCallBack(ATransmitHexFile_VoidSendData);

	/*ENABLE EXTI0 PERIPHERAL*/
	MEXTI_voidEnableEXTI(MEXTI_LINE_0);

	/*ENABLE MNVIC FOR EXTI0*/
	MNVIC_voidEnableInterrupt(MNVIC_EXTI0);

	/*Step 10: Set trigger interrupt to falling edge*/
	MEXTI_voidSetTriggerSource(MEXTI_LINE_2,MEXTI_FALLING_EDGE);

	MEXTI_voidSetExtiConfig(MEXTI_LINE_2 , MEXTI_PORTB);
	/*Step 10: Assign the function to call to ISR of EXTI0*/


	MEXTI2_VoidCallBack(OS_HEX);
	/*ENABLE EXTI0 PERIPHERAL*/
	MEXTI_voidEnableEXTI(MEXTI_LINE_2);

	/*ENABLE MNVIC FOR EXTI0*/
	MNVIC_voidEnableInterrupt(MNVIC_EXTI2);

	/*indication for start sending*/
	MGPIO_voidSetPinValue(MGPIOA_PORT,MGPIO_PIN1,MGPIO_HIGH);

	//==============================================================================================

	/*calling the function to run the application*/
	//	ATransmitHexFile_RunApplication();
	while(1)
	{
		/*do nothing*/
	}
}
