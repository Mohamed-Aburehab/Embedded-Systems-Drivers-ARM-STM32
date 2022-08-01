/*****************************************************************************/
/*****************************************************************************/
/**********************    Author : Mohamed Aburehab    **********************/
/**********************    Layer  : HAL                 **********************/
/**********************    SWD    : LED                 **********************/
/**********************    Version: 1.0                 **********************/
/*****************************************************************************/
/*****************************************************************************/

#ifndef SSD_INTERFACE_H_
#define SSD_INTERFACE_H_
#define SSD_COMMON_CATHODE                  0
#define SSD_COMMON_ANODE                    1
/**
 * @brief It takes four arguments, the port, the start pin,
 *        the Seven sigment display type and the Number.
 * 
 * @param Copy_u8Port The port you want to use.
 * @param Copy_u8StartPin the first pin to be connected to the SSD
 * ! make sure the pins connected to the SSD be in increasing order with step of 1 
 *  ex(a:0, b:1, c:3, ...)
 * @param SSD_u8Type The seven sigment display type (SSD_COMMON_CATHODE, SSD_COMMON_ANODE).
 * @param Copy_u8Number The number to be displayed on the display .
 */

void SSD_voidDisplay(u8 Copy_u8Port, u8 Copy_u8StartPin,u8 SSD_u8Type, u8 Copy_u8Number);
#endif