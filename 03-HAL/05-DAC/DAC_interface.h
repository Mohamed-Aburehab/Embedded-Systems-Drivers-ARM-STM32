/*****************************************************************************/
/*****************************************************************************/
/**********************    Author : Mohamed Aburehab    **********************/
/**********************    Layer  : HAL                 **********************/
/**********************    SWD    : DAC                 **********************/
/**********************    Version: 1.0                 **********************/
/*****************************************************************************/
/*****************************************************************************/

#ifndef DAC_INTERFACE_H_
#define DAC_INTERFACE_H_

/**
 * @brief It sets the direction of the pins to output and sets the speed to 2MHz 
 * and initializes SysTick.
 */
void HDAC_voidInit();

/**
 * @brief It takes a number between 0 and 255 and sets the value of the DAC to that number
 * 
 * @param Copy_u8DacValue The value you want to set the DAC to.
 */
void HDAC_voidSetDacValue(u8 Copy_u8DacValue);

#endif