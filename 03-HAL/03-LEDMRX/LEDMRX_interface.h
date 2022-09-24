/*****************************************************************************/
/*****************************************************************************/
/**********************    Author : Mohamed Aburehab    **********************/
/**********************    Layer  : HAL                 **********************/
/**********************    SWD    : LEDMRX              **********************/
/**********************    Version: 2.0                 **********************/
/*****************************************************************************/
/*****************************************************************************/

#ifndef LEDMRX_INTERFACE_H_
#define LEDMRX_INTERFACE_H_

/**
 * @brief It initializes the microcontroller pins configurations
 */
void HLEDMRX_voidInit(void);

/**
 * @brief It takes a pointer to an array of 8 bytes, and displays the contents of that array on the LED
 * matrix.
 * 
 * @param Copy_u8Data The data to be displayed.
 */
void HLEDMRX_voidDisplay(u8 *Copy_u8Data);

/**
 * @brief It takes a pointer to an array of 64 bytes, and displays the first 8 bytes on the first row, then
 * the next 8 bytes on the second row, and so on. 
 * 
 * @param Copy_u8Data is the array of the animation frames
 */
void HLEDMRX_voidDisplayAnimation(u8 *Copy_u8Data);

#endif