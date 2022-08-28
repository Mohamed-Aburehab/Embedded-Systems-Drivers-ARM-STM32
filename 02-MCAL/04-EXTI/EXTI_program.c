/*****************************************************************************/
/*****************************************************************************/
/**********************    Author : Mohamed Aburehab    **********************/
/**********************    Layer  : MCAL                **********************/
/**********************    SWD    : EXTI                **********************/
/**********************    Version: 1.0                 **********************/
/*****************************************************************************/
/*****************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"

/**
 * @brief Initialize External Intterupts Mode
 */
void MEXTI_voidInit(){
    #if EXTI_MODE == EXTI_MODE_RISING
        SET_BIT(EXTI->RTSR, EXTI_LINE);

    #elif EXTI_MODE == EXTI_MODE_FALLING
        SET_BIT(EXTI->FTSR, EXTI_LINE);

    #elif EXTI_MODE == EXTI_MODE_ON_CHANGE
        SET_BIT(EXTI->RTSR, EXTI_LINE);
        SET_BIT(EXTI->FTSR, EXTI_LINE);
    #else 
        #error "Wrong Mode Configurations"
    #endif

    /* disable the interrupt */
    CLR_BIT(EXTI->IMR, EXTI_LINE);
}

/**
 * @brief It enables the interrupt of the line that is passed to it
 * 
 * @param Copy_u8Line The line number of the interrupt you want to enable.
 */
void MEXTI_voidEnableEXTI(u8 Copy_u8Line){
    SET_BIT(EXTI->IMR, Copy_u8Line);
}

/**
 * @brief It disables the interrupt of the line that is passed to it
 * 
 * @param Copy_u8Line The line number of the interrupt you want to disable.
 */
void MEXTI_voidDisableEXTI(u8 Copy_u8Line){
    CLR_BIT(EXTI->IMR, Copy_u8Line);
}

/**
 * @brief This function is used to trigger the interrupt manually by software
 * 
 * @param Copy_u8Line The line number of the interrupt you want to trigger the interrupt by software.
 */
void MEXTI_voidSwTrigger(u8 Copy_u8Line){
    SET_BIT(EXTI->SWIER, Copy_u8Line);
}

/**
 * It sets the interrupt mode for the specified line
 * 
 * @param Copy_u8Line The line number of the external interrupt.
 * @param Copy_u8Mode The mode to trigger the interrupt.
 */
void MEXTI_voidSetSignalLatch(u8 Copy_u8Line,u8 Copy_u8Mode){
    switch (Copy_u8Mode)
    {
    case EXTI_MODE_RISING:
        SET_BIT(EXTI->RTSR, Copy_u8Line);
        break;
    case EXTI_MODE_FALLING:
        SET_BIT(EXTI->FTSR, Copy_u8Line);
        break;
    case EXTI_MODE_ON_CHANGE:
        SET_BIT(EXTI->RTSR, Copy_u8Line);
        SET_BIT(EXTI->FTSR, Copy_u8Line);
        break;

    }
}