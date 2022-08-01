/*****************************************************************************/
/*****************************************************************************/
/**********************    Author : Mohamed Aburehab    **********************/
/**********************    Layer  : HAL                 **********************/
/**********************    SWD    : LED                 **********************/
/**********************    Version: 1.0                 **********************/
/*****************************************************************************/
/*****************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "LED_interface.h"
#include "LED_private.h"
#include "LED_config.h"

#if LED_CONNECTION_TYPE == LED_SOURCE_CONNECTION

    /**
     * @brief It takes two arguments, the port and the pin, and sets LED to on.
     * 
     * @param Copy_u8Port The port you want to use.
     * @param Copy_u8Pin The pin number connected to the LED.
     */
    void LED_voidTurnOn  (u8 Copy_u8Port, u8 Copy_u8Pin){
        MGPIO_voidSetPinDirection(Copy_u8Port, Copy_u8Pin, OUTPUT_SPEED_10MHZ_PP);
        MGPIO_voidSetPinValue(Copy_u8Port, Copy_u8Pin, GPIO_HIGH);
    }

    /**
     * @brief It takes two arguments, the port and the pin, and sets LED to off.
     * 
     * @param Copy_u8Port The port you want to use.
     * @param Copy_u8Pin The pin number connected to the LED.
     */
    void LED_voidTurnOff (u8 Copy_u8Port, u8 Copy_u8Pin){
        MGPIO_voidSetPinDirection(Copy_u8Port, Copy_u8Pin, OUTPUT_SPEED_10MHZ_PP);
        MGPIO_voidSetPinValue(Copy_u8Port, Copy_u8Pin, GPIO_LOW);
    }
    /**
     * @brief It takes two arguments, the port and the pin, and toggles the state of the led.
     * 
     * @param Copy_u8Port The port you want to use.
     * @param Copy_u8Pin The pin number connected to the LED.
     */
    void LED_voidToggle  (u8 Copy_u8Port, u8 Copy_u8Pin){
        MGPIO_voidSetPinDirection(Copy_u8Port, Copy_u8Pin, OUTPUT_SPEED_10MHZ_PP);
        MGPIO_voidSetPinValue(Copy_u8Port, Copy_u8Pin, (MGPIO_u8GetPinValue(Copy_u8Port, Copy_u8Pin) ^ 1 ));
    }

#elif LED_CONNECTION_TYPE == LED_SINK_CONNECTION

    /**
     * @brief It takes two arguments, the port and the pin, and sets LED to on.
     * 
     * @param Copy_u8Port The port you want to use.
     * @param Copy_u8Pin The pin number connected to the LED.
     */
    void LED_voidTurnOn  (u8 Copy_u8Port, u8 Copy_u8Pin){
        MGPIO_voidSetPinDirection(Copy_u8Port, Copy_u8Pin, OUTPUT_SPEED_10MHZ_PP);
        MGPIO_voidSetPinValue(Copy_u8Port, Copy_u8Pin, GPIO_LOW);
    }

    /**
     * @brief It takes two arguments, the port and the pin, and sets LED to off.
     * 
     * @param Copy_u8Port The port you want to use.
     * @param Copy_u8Pin The pin number connected to the LED.
     */
    void LED_voidTurnOff (u8 Copy_u8Port, u8 Copy_u8Pin){
        MGPIO_voidSetPinDirection(Copy_u8Port, Copy_u8Pin, OUTPUT_SPEED_10MHZ_PP);
        MGPIO_voidSetPinValue(Copy_u8Port, Copy_u8Pin, GPIO_HIGH);
    }
    /**
     * @brief It takes two arguments, the port and the pin, and toggles the state of the led.
     * 
     * @param Copy_u8Port The port you want to use.
     * @param Copy_u8Pin The pin number connected to the LED.
     */
    void LED_voidToggle  (u8 Copy_u8Port, u8 Copy_u8Pin){
        MGPIO_voidSetPinDirection(Copy_u8Port, Copy_u8Pin, OUTPUT_SPEED_10MHZ_PP);
        MGPIO_voidSetPinValue(Copy_u8Port, Copy_u8Pin, (MGPIO_u8GetPinValue(Copy_u8Port, Copy_u8Pin) ^ 1 ));
    }

#endif

