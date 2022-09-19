/*****************************************************************************/
/*****************************************************************************/
/**********************    Author : Mohamed Aburehab    **********************/
/**********************    Layer  : HAL                 **********************/
/**********************    SWD    : LEDMRX              **********************/
/**********************    Version: 2.0                 **********************/
/*****************************************************************************/
/*****************************************************************************/

#ifndef LEDMRX_PRIVATE_H_
#define LEDMRX_PRIVATE_H_

/**
 * @brief It disables all columns by setting all the columns to high.
 */
static void DisableAllColumns(void);

/**
 * @brief sets the value of the rows of the LED matrix to the value of the passed argument. 
 *
 * @param Copy_u8Value the value to be set on the rows
 */
static void SetRowValues(u8 Copy_u8Value);

#endif