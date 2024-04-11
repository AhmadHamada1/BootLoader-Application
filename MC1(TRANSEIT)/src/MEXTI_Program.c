

#include"LSTD_TYPES.h"
#include"LBIT_MATH.h"



#include"MEXTI_Private.h"
#include"MEXTI_Interface.h"
#include"MEXTI_Config.h"



static void (*EXTI0_CallBack)(void) = 0 ;
static void (*EXTI1_CallBack)(void) = 0 ;
static void (*EXTI2_CallBack)(void) = 0 ;

static void (*EXTI5_CallBack)(void) = 0 ;


void MEXTI_voidEnableEXTI(MEXTI_LINE_t Copy_uddtLineNum)
{
	SET_BIT(MEXTI->IMR,Copy_uddtLineNum) ;
}


void MEXTI_voidDisableEXTI(MEXTI_LINE_t Copy_uddtLineNum)
{
	CLR_BIT(MEXTI->IMR,Copy_uddtLineNum) ;
}


void MEXTI_voidSoftwareInterrupt(MEXTI_LINE_t Copy_uddtLineNum)
{
	SET_BIT(MEXTI->SWIER,Copy_uddtLineNum) ;    // to clear it write 1 to PR
}
void MEXTI_voidSetTriggerSource(MEXTI_LINE_t Copy_uddtLineNum,MEXTI_TriggerMode_t Copy_uddtTriggerMode)
{
	switch(Copy_uddtTriggerMode)
	{
	case (MEXTI_RISING_EDGE) :  SET_BIT(MEXTI->RTSR,Copy_uddtLineNum) ; break ;
	case (MEXTI_FALLING_EDGE):  SET_BIT(MEXTI->FTSR,Copy_uddtLineNum) ; break ;
	case (MEXTI_ON_CHANGE)   :  SET_BIT(MEXTI->RTSR,Copy_uddtLineNum) ;
	SET_BIT(MEXTI->FTSR,Copy_uddtLineNum) ; break ;
	default : /*Do Nothing*/ break ;
	}

}


void MEXTI_voidSetExtiConfig(MEXTI_LINE_t Copy_uddtLineNum , u8 Copy_u8GpioPortNum)
{

	switch(Copy_uddtLineNum)
	{
	case (MEXTI_LINE_0) :  MSYSCFG_EXTICR1 &= EXTI_CONFG_MASK1   ;  //0xFFFFFFF0
	MSYSCFG_EXTICR1 |= Copy_u8GpioPortNum ;
	break ;
	case (MEXTI_LINE_1) :  MSYSCFG_EXTICR1 &= EXTI_CONFG_MASK2   ;  //0xFFFFFF0F
	MSYSCFG_EXTICR1 |= Copy_u8GpioPortNum<<4 ;
	break ;
	case (MEXTI_LINE_2) :  MSYSCFG_EXTICR1 &= EXTI_CONFG_MASK3   ;  //0xFFFFF0FF
	MSYSCFG_EXTICR1 |= Copy_u8GpioPortNum<<8 ;
	break ;
	case (MEXTI_LINE_3) :  MSYSCFG_EXTICR1 &= EXTI_CONFG_MASK4   ;  //0xFFFF0FFF
	MSYSCFG_EXTICR1 |= Copy_u8GpioPortNum<<12 ;
	break ;

	case (MEXTI_LINE_5) :  MSYSCFG_EXTICR2 &= EXTI_CONFG_MASK2  ;  //0xFFFF0FFF
	MSYSCFG_EXTICR2 |= Copy_u8GpioPortNum<<4 ;
	break ;
	default : /*Do Nothing*/ break ;
	}

}


/*****************************************************END_FUNCTION*****************************************/


void MEXTI0_VoidCallBack(void (*ptr)(void))
{
	EXTI0_CallBack = ptr ;
}
void MEXTI1_VoidCallBack(void (*ptr)(void))
{

	EXTI1_CallBack = ptr ;
}
void MEXTI2_VoidCallBack(void (*ptr)(void))
{

	EXTI2_CallBack = ptr ;
}
void MEXTI5_VoidCallBack(void (*ptr)(void))
{

	EXTI5_CallBack = ptr ;
}

void EXTI0_IRQHandler(void)
{
	EXTI0_CallBack() ;
	SET_BIT(MEXTI->PR,0) ;     //without That it will Do Interrupt Always
}

void EXTI1_IRQHandler(void)
{
	EXTI1_CallBack() ;
	SET_BIT(MEXTI->PR,1) ;
}

void EXTI2_IRQHandler(void)
{
	EXTI2_CallBack() ;
	SET_BIT(MEXTI->PR,2) ;     //without That it will Do Interrupt Always
}

void EXTI9_5_IRQHandler(void)
{
	EXTI5_CallBack() ;
	SET_BIT(MEXTI->PR,5) ;
}
