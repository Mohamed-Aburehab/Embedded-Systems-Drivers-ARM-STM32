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
 * It sets the row values, enables the column, waits 2.5ms, disables the column, and repeats for all
 * columns
 * 
 * @param Copy_u8Data is a pointer to an array of 8 bytes, each byte represents a row in the matrix.
 */
void HLEDMRX_voidDisplay(u8 *Copy_u8Data);

#endif