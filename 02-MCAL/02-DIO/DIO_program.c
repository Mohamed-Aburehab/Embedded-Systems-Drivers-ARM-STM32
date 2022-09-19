/*****************************************************************************/
/*****************************************************************************/
/**********************    Author : Mohamed Aburehab    **********************/
/**********************    Layer  : MCAL                **********************/
/**********************    SWD    : DIO                 **********************/
/**********************    Version: 2.0                 **********************/
/*****************************************************************************/
/*****************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"

/**
 * @brief This function is used to set the direction of a specific pin in a specific port.
 * 
 * @param Copy_u8Port The port you want to set the pin direction for.
 * @param Copy_u8Pin The pin number you want to set its direction.
 * @param Copy_u8Mode is the mode of the pin.
 */
void MGPIO_voidSetPinDirection(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Mode){
    switch (Copy_u8Port)
    {
    case MGPIO_PORT_A: 
        /* for pins from 0 to 7 */
        if (Copy_u8Pin <= 7){
            GPIOA_CRL &= ~((0b1111)<<(Copy_u8Pin * 4)); /* Clear Pin Configuration */
            GPIOA_CRL |= ((Copy_u8Mode)<<(Copy_u8Pin * 4)); /* Set Pin Configuration */
        } 
        /* for pins from 8 to 15 */
        else if (Copy_u8Pin <= 15){
            Copy_u8Pin = Copy_u8Pin -8 ;
            GPIOA_CRH &= ~((0b1111)<<(Copy_u8Pin * 4)); /* Clear Pin Configuration */
            GPIOA_CRH |= ((Copy_u8Mode)<<(Copy_u8Pin * 4)); /* Set Pin Configuration */
        } break;
    case MGPIO_PORT_B:
        /* for pins from 0 to 7 */
        if (Copy_u8Pin <= 7){
            GPIOB_CRL &= ~((0b1111)<<(Copy_u8Pin * 4)); /* Clear Pin Configuration */
            GPIOB_CRL |= ((Copy_u8Mode)<<(Copy_u8Pin * 4)); /* Set Pin Configuration */
        } 
        /* for pins from 8 to 15 */
        else if (Copy_u8Pin <= 15){
            Copy_u8Pin = Copy_u8Pin -8 ;
            GPIOB_CRH &= ~((0b1111)<<(Copy_u8Pin * 4)); /* Clear Pin Configuration */
            GPIOB_CRH |= ((Copy_u8Mode)<<(Copy_u8Pin * 4)); /* Set Pin Configuration */
        } break;
    case MGPIO_PORT_C: 
        /* for pins from 0 to 7 */
        if (Copy_u8Pin <= 7){
            GPIOC_CRL &= ~((0b1111)<<(Copy_u8Pin * 4)); /* Clear Pin Configuration */
            GPIOC_CRL |= ((Copy_u8Mode)<<(Copy_u8Pin * 4)); /* Set Pin Configuration */
        } 
        /* for pins from 8 to 15 */
        else if (Copy_u8Pin <= 15){
            Copy_u8Pin = Copy_u8Pin -8 ;
            GPIOC_CRH &= ~((0b1111)<<(Copy_u8Pin * 4)); /* Clear Pin Configuration */
            GPIOC_CRH |= ((Copy_u8Mode)<<(Copy_u8Pin * 4)); /* Set Pin Configuration */
        }break;
    }
}

/**
 * @brief This function is used to set the value of a certain pin in a certain port.
 * 
 * @param Copy_u8Port The port you want to set the pin value on.
 * @param Copy_u8Pin The pin number you want to set its value.
 * @param Copy_u8Value The value you want to set the pin to.
 */
void MGPIO_voidSetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value){
    /* Checking if the value is high. */
    if (Copy_u8Value == MGPIO_VALUE_HIGH){
        /* Setting the value of the pin to high. */
        switch (Copy_u8Port)
        {
            case MGPIO_PORT_A: SET_BIT(GPIOA_ODR, Copy_u8Pin); break;
            case MGPIO_PORT_B: SET_BIT(GPIOB_ODR, Copy_u8Pin); break;
            case MGPIO_PORT_C: SET_BIT(GPIOC_ODR, Copy_u8Pin); break;
        }
    /* Checking if the value is low. */
    }
    else if (Copy_u8Value == MGPIO_VALUE_LOW){
        /* Setting the value of the pin to low. */
        switch (Copy_u8Port)
        {
            case MGPIO_PORT_A: CLR_BIT(GPIOA_ODR, Copy_u8Pin); break;
            case MGPIO_PORT_B: CLR_BIT(GPIOB_ODR, Copy_u8Pin); break;
            case MGPIO_PORT_C: CLR_BIT(GPIOC_ODR, Copy_u8Pin); break;
        }
    }
}


/**
 * @brief This function is used to get the value of a certain pin in a certain port
 * 
 * @param Copy_u8Port The port you want to get the value from.
 * @param Copy_u8Pin The pin number you want to get the value of.
 * 
 * @return The pin value.
 */
u8 MGPIO_u8GetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin){
    /* A local variable that is used to store the pin current value. */
    u8 Local_u8Result = 0;
    /* Checking the value of the port. */
    switch (Copy_u8Port)
    {
        /* Getting the value of the pin. */
        case MGPIO_PORT_A: Local_u8Result = GET_BIT(GPIOA_IDR, Copy_u8Pin); break;
        case MGPIO_PORT_B: Local_u8Result = GET_BIT(GPIOB_IDR, Copy_u8Pin); break;
        case MGPIO_PORT_C: Local_u8Result = GET_BIT(GPIOC_IDR, Copy_u8Pin); break;
    }
    /* Returning the value of the pin. */
    return Local_u8Result;
}
