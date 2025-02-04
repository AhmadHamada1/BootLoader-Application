/*******************************************************************************************************/
/* Created on: 2024
 *      Author: Hamada                                                             */


#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"



#include "MGPIO_Interface.h"
#include "MGPIO_Private.h"
#include "MGPIO_Config.h"



void MGPIO_voidSetPinMode(u8 Copy_u8PortName ,u8 Copy_u8PinNum ,u8 Copy_u8Mode  )
{
	switch(Copy_u8PortName)
		{
		case MGPIOA_PORT : MGPIOA->MODER |= (u32)(Copy_u8Mode << (2U * Copy_u8PinNum ))  ; break ;
		case MGPIOB_PORT : MGPIOB->MODER |= (u32)(Copy_u8Mode << (2U * Copy_u8PinNum ))  ; break ;
		case MGPIOC_PORT : MGPIOC->MODER |= (u32)(Copy_u8Mode << (2U * Copy_u8PinNum ))  ; break ;
		case MGPIOD_PORT : MGPIOD->MODER |= (u32)(Copy_u8Mode << (2U * Copy_u8PinNum ))  ; break ;
		case MGPIOE_PORT : MGPIOE->MODER |= (u32)(Copy_u8Mode << (2U * Copy_u8PinNum ))  ; break ;
		case MGPIOH_PORT : MGPIOH->MODER |= (u32)(Copy_u8Mode << (2U * Copy_u8PinNum ))  ; break ;

		default :  /*Error*/   break ;
		}
}




void MGPIO_voidSetOutputType(u8 Copy_u8PortName, u8 Copy_u8PinNum, u8 Copy_u8OutTypeMode ) 
{
	switch(Copy_u8PortName)
	{
	case MGPIOA_PORT : MGPIOA->OTYPER |= (u32)(Copy_u8OutTypeMode << (Copy_u8PinNum ))  ; break ;
	case MGPIOB_PORT : MGPIOB->OTYPER |= (u32)(Copy_u8OutTypeMode << (Copy_u8PinNum ))  ; break ;
	case MGPIOC_PORT : MGPIOC->OTYPER |= (u32)(Copy_u8OutTypeMode << (Copy_u8PinNum ))  ; break ;
	case MGPIOD_PORT : MGPIOD->OTYPER |= (u32)(Copy_u8OutTypeMode << (Copy_u8PinNum ))  ; break ;
	case MGPIOE_PORT : MGPIOE->OTYPER |= (u32)(Copy_u8OutTypeMode << (Copy_u8PinNum ))  ; break ;
	case MGPIOH_PORT : MGPIOH->OTYPER |= (u32)(Copy_u8OutTypeMode << (Copy_u8PinNum ))  ; break ;

	default :  /*Error*/   break ;
	}	

}


/*******************************************************************************************************/

void MGPIO_voidSetOutputSpeed(u8 Copy_u8PortName ,u8 Copy_u8PinNum ,u8 Copy_u8SpeedMode  )
{

	switch(Copy_u8PortName)
	{
	case MGPIOA_PORT : MGPIOA->OSPEEDR |= (u32)(Copy_u8SpeedMode << (2U * Copy_u8PinNum ))  ; break ;
	case MGPIOB_PORT : MGPIOB->OSPEEDR |= (u32)(Copy_u8SpeedMode << (2U * Copy_u8PinNum ))  ; break ;
	case MGPIOC_PORT : MGPIOC->OSPEEDR |= (u32)(Copy_u8SpeedMode << (2U * Copy_u8PinNum ))  ; break ;
	case MGPIOD_PORT : MGPIOD->OSPEEDR |= (u32)(Copy_u8SpeedMode << (2U * Copy_u8PinNum ))  ; break ;
	case MGPIOE_PORT : MGPIOE->OSPEEDR |= (u32)(Copy_u8SpeedMode << (2U * Copy_u8PinNum ))  ; break ;
	case MGPIOH_PORT : MGPIOH->OSPEEDR |= (u32)(Copy_u8SpeedMode << (2U * Copy_u8PinNum ))  ; break ;

	default :  /*Error*/   break ;
	}	
}



void MGPIO_voidSetPullState(u8 Copy_u8PortName ,u8 Copy_u8PinNum ,u8 Copy_u8PullType  )
{
	switch(Copy_u8PortName)
	{
	case MGPIOA_PORT : MGPIOA->PUPDR |= (u32)(Copy_u8PullType << (2U * Copy_u8PinNum ))  ; break ;
	case MGPIOB_PORT : MGPIOB->PUPDR |= (u32)(Copy_u8PullType << (2U * Copy_u8PinNum ))  ; break ;
	case MGPIOC_PORT : MGPIOC->PUPDR |= (u32)(Copy_u8PullType << (2U * Copy_u8PinNum ))  ; break ;
	case MGPIOD_PORT : MGPIOD->PUPDR |= (u32)(Copy_u8PullType << (2U * Copy_u8PinNum ))  ; break ;
	case MGPIOE_PORT : MGPIOE->PUPDR |= (u32)(Copy_u8PullType << (2U * Copy_u8PinNum ))  ; break ;
	case MGPIOH_PORT : MGPIOH->PUPDR |= (u32)(Copy_u8PullType << (2U * Copy_u8PinNum ))  ; break ;

	default :  /*Error*/   break ;
	}	
}




u8 MGPIO_u8GetPInValue(u8 Copy_u8PortName ,u8 Copy_u8PinNum)
{

	u8 LOC_u8PinValue = 0 ; 
	switch(Copy_u8PortName)
	{
	case MGPIOA_PORT : LOC_u8PinValue = GET_BIT(MGPIOA->IDR,Copy_u8PinNum)  ; break ;
	case MGPIOB_PORT : LOC_u8PinValue = GET_BIT(MGPIOB->IDR,Copy_u8PinNum)  ; break ;
	case MGPIOC_PORT : LOC_u8PinValue = GET_BIT(MGPIOC->IDR,Copy_u8PinNum)  ; break ;
	case MGPIOD_PORT : LOC_u8PinValue = GET_BIT(MGPIOD->IDR,Copy_u8PinNum)  ; break ;
	case MGPIOE_PORT : LOC_u8PinValue = GET_BIT(MGPIOE->IDR,Copy_u8PinNum)  ; break ;
	case MGPIOH_PORT : LOC_u8PinValue = GET_BIT(MGPIOH->IDR,Copy_u8PinNum)  ; break ;

	default :  /*Error*/   break ;
	}	

	return LOC_u8PinValue ; 
}



void MGPIO_voidSetPinValue(u8 Copy_u8PortName ,u8 Copy_u8PinNum, u8 Copy_u8PinValue)
{
	if(Copy_u8PinValue == MGPIO_HIGH)
	{
		switch(Copy_u8PortName)
		{
		case MGPIOA_PORT : SET_BIT(MGPIOA->ODR,Copy_u8PinNum)  ; break ; 
		case MGPIOB_PORT : SET_BIT(MGPIOB->ODR,Copy_u8PinNum)  ; break ; 
		case MGPIOC_PORT : SET_BIT(MGPIOC->ODR,Copy_u8PinNum)  ; break ;
		case MGPIOD_PORT : SET_BIT(MGPIOD->ODR,Copy_u8PinNum)  ; break ; 
		case MGPIOE_PORT : SET_BIT(MGPIOE->ODR,Copy_u8PinNum)  ; break ; 
		case MGPIOH_PORT : SET_BIT(MGPIOH->ODR,Copy_u8PinNum)  ; break ; 	
		default :  /*Error*/   break ; 
		}
	}
	else
	{
		switch(Copy_u8PortName)
		{
		case MGPIOA_PORT : CLR_BIT(MGPIOA->ODR,Copy_u8PinNum)  ; break ; 
		case MGPIOB_PORT : CLR_BIT(MGPIOB->ODR,Copy_u8PinNum)  ; break ; 
		case MGPIOC_PORT : CLR_BIT(MGPIOC->ODR,Copy_u8PinNum)  ; break ;
		case MGPIOD_PORT : CLR_BIT(MGPIOD->ODR,Copy_u8PinNum)  ; break ; 
		case MGPIOE_PORT : CLR_BIT(MGPIOE->ODR,Copy_u8PinNum)  ; break ; 
		case MGPIOH_PORT : CLR_BIT(MGPIOH->ODR,Copy_u8PinNum)  ; break ; 	
		default :  /*Error*/   break ; 
		}
	}
}



void MGPIO_voidDirectSetReset(u8 Copy_u8PortName ,u8 Copy_u8PinNum, u8 Copy_u8PinValue)
{

	if(Copy_u8PinValue == MGPIO_HIGH)
	{
		switch(Copy_u8PortName)
		{
		case MGPIOA_PORT : MGPIOA->BSRR = (1U<<Copy_u8PinNum)  ; break ;                                         
		case MGPIOB_PORT : MGPIOB->BSRR = (1U<<Copy_u8PinNum)  ; break ; 
		case MGPIOC_PORT : MGPIOC->BSRR = (1U<<Copy_u8PinNum)  ; break ;
		case MGPIOD_PORT : MGPIOD->BSRR = (1U<<Copy_u8PinNum)  ; break ; 
		case MGPIOE_PORT : MGPIOE->BSRR = (1U<<Copy_u8PinNum)  ; break ; 
		case MGPIOH_PORT : MGPIOH->BSRR = (1U<<Copy_u8PinNum)  ; break ; 	
		default :  /*Error*/   break ; 
		}
	}
	else
	{
		Copy_u8PinNum += 16 ;
		switch(Copy_u8PortName)
		{
		case MGPIOA_PORT : MGPIOA->BSRR = (1U<<Copy_u8PinNum)  ; break ; 
		case MGPIOB_PORT : MGPIOB->BSRR = (1U<<Copy_u8PinNum)  ; break ; 
		case MGPIOC_PORT : MGPIOC->BSRR = (1U<<Copy_u8PinNum)  ; break ;
		case MGPIOD_PORT : MGPIOD->BSRR = (1U<<Copy_u8PinNum)  ; break ; 
		case MGPIOE_PORT : MGPIOE->BSRR = (1U<<Copy_u8PinNum)  ; break ; 
		case MGPIOH_PORT : MGPIOH->BSRR = (1U<<Copy_u8PinNum)  ; break ; 	
		default :  /*Error*/   break ; 
		}
	}


}





void MGPIO_voidPinLock(u8 Copy_u8PortName ,u8 Copy_u8PinNum)
{
	//TODO: 
}



void MGPIO_voidSetPinAltFun(u8 Copy_u8PortName ,u8 Copy_u8PinNum, u8 Copy_u8AlFun) 
{
	if(Copy_u8PinNum <=7U)
	{
		switch(Copy_u8PortName)
		{
		case MGPIOA_PORT:MGPIOA->AFRL  |=(u32)(Copy_u8AlFun << (4U*Copy_u8PinNum)) ; break ;
		case MGPIOB_PORT:MGPIOB->AFRL  |=(u32)(Copy_u8AlFun << (4U*Copy_u8PinNum)) ; break ;
		case MGPIOC_PORT:MGPIOC->AFRL  |=(u32)(Copy_u8AlFun << (4U*Copy_u8PinNum)) ; break ;
		default : break ;
		}
	}
	else
	{
		switch(Copy_u8PortName)
		{
		case MGPIOA_PORT:MGPIOA->AFRH  |=(u32)(Copy_u8AlFun << (4U*(Copy_u8PinNum%8))) ; break ;
		case MGPIOB_PORT:MGPIOB->AFRH  |=(u32)(Copy_u8AlFun << (4U*(Copy_u8PinNum%8))) ; break ;
		case MGPIOC_PORT:MGPIOC->AFRH  |=(u32)(Copy_u8AlFun << (4U*(Copy_u8PinNum%8))) ; break ;
		default : break ;
		}

	}
}




