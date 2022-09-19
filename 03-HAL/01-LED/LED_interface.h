/*****************************************************************************/
/*****************************************************************************/
/**********************    Author : Mohamed Aburehab    **********************/
/**********************    Layer  : HAL                 **********************/
/**********************    SWD    : LED                 **********************/
/**********************    Version: 2.0                 **********************/
/*****************************************************************************/
/*****************************************************************************/

#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_

/**
 * @brief It takes two arguments, the port and the pin, and sets LED to on.
 * 
 * @param Copy_u8Port The port you want to use.
 * @param Copy_u8Pin The pin number connected to the LED.
 */
void LED_voidTurnOn  (u8 Copy_u8Port, u8 Copy_u8Pin);

/**
 * @brief It takes two arguments, the port and the pin, and sets LED to off.
 * 
 * @param Copy_u8Port The port you want to use.
 * @param Copy_u8Pin The pin number connected to the LED.
 */
void LED_voidTurnOff (u8 Copy_u8Port, u8 Copy_u8Pin);

/**
 * @brief It takes two arguments, the port and the pin, and toggles the state of the led.
 * 
 * @param Copy_u8Port The port you want to use.
 * @param Copy_u8Pin The pin number connected to the LED.
 */
void LED_voidToggle  (u8 Copy_u8Port, u8 Copy_u8Pin);

#endif