/*****************************************************************************/
/*****************************************************************************/
/**********************    Author : Mohamed Aburehab    **********************/
/**********************    Layer  : MCAL                **********************/
/**********************    SWD    : DIO                 **********************/
/**********************    Version: 2.0                 **********************/
/*****************************************************************************/
/*****************************************************************************/

#ifndef GPIO_INTERFACE_H_
#define GPIO_INTERFACE_H_

/* Value Macros */
#define MGPIO_VALUE_LOW                 0
#define MGPIO_VALUE_HIGH                1

/* Port Macros */
#define MGPIO_PORT_A                    0
#define MGPIO_PORT_B                    1
#define MGPIO_PORT_C                    2

/* Pins Macros */
#define MGPIO_PIN_0                     0
#define MGPIO_PIN_1                     1
#define MGPIO_PIN_2                     2
#define MGPIO_PIN_3                     3
#define MGPIO_PIN_4                     4
#define MGPIO_PIN_5                     5
#define MGPIO_PIN_6                     6
#define MGPIO_PIN_7                     7
#define MGPIO_PIN_8                     8
#define MGPIO_PIN_9                     9
#define MGPIO_PIN_10                    10
#define MGPIO_PIN_11                    11
#define MGPIO_PIN_12                    12
#define MGPIO_PIN_13                    13
#define MGPIO_PIN_14                    14
#define MGPIO_PIN_15                    15

/* Modes Macros */
    /* INPUT */
#define MGPIO_INPUT_ANALOG                    0b0000      // Input for ADC 
#define MGPIO_INPUT_FLOATING                  0b0100      // Input Floating (no resistors) 
#define MGPIO_INPUT_PULLUP_PULLDOWN           0b1000      // Input Pulled up or Pulled down

    /* OUTPUT */
        /* 10 MHZ */
#define MGPIO_OUTPUT_SPEED_10MHZ_PP           0b0001      // Push Pull Output 
#define MGPIO_OUTPUT_SPEED_10MHZ_OD           0b0101      // Open Drain Output 
#define MGPIO_OUTPUT_SPEED_10MHZ_AFPP         0b1001      // Push Pull Alternative Function
#define MGPIO_OUTPUT_SPEED_10MHZ_AFOD         0b1101      // Open Drain Alternative Function

        /* 2 MHZ */
#define MGPIO_OUTPUT_SPEED_2MHZ_PP            0b0010      // Push Pull Output 
#define MGPIO_OUTPUT_SPEED_2MHZ_OD            0b0110      // Open Drain Output 
#define MGPIO_OUTPUT_SPEED_2MHZ_AFPP          0b1010      // Push Pull Alternative Function
#define MGPIO_OUTPUT_SPEED_2MHZ_AFOD          0b1110      // Open Drain Alternative Function

        /* 50 MHZ */
#define MGPIO_OUTPUT_SPEED_50MHZ_PP           0b0011      // Push Pull Output 
#define MGPIO_OUTPUT_SPEED_50MHZ_OD           0b0111      // Open Drain Output 
#define MGPIO_OUTPUT_SPEED_50MHZ_AFPP         0b1011      // Push Pull Alternative Function
#define MGPIO_OUTPUT_SPEED_50MHZ_AFOD         0b1111      // Open Drain Alternative Function

/* Functions Prototype */
/**
 * @brief This function is used to set the direction of a specific pin in a specific port.
 * 
 * @param Copy_u8Port The port you want to set the pin direction for.
 * @param Copy_u8Pin The pin number you want to set its direction.
 * @param Copy_u8Mode is the mode of the pin.
 */
void MGPIO_voidSetPinDirection(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Mode);

/**
 * @brief This function is used to set the value of a certain pin in a certain port.
 * 
 * @param Copy_u8Port The port you want to set the pin value on.
 * @param Copy_u8Pin The pin number you want to set its value.
 * @param Copy_u8Value The value you want to set the pin to.
 */
void MGPIO_voidSetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value);

/**
 * @brief This function is used to get the value of a certain pin in a certain port
 * 
 * @param Copy_u8Port The port you want to get the value from.
 * @param Copy_u8Pin The pin number you want to get the value of.
 * 
 * @return The pin value.
 */
u8 MGPIO_u8GetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin);

#endif