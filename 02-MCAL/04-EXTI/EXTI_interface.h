/*****************************************************************************/
/*****************************************************************************/
/**********************    Author : Mohamed Aburehab    **********************/
/**********************    Layer  : MCAL                **********************/
/**********************    SWD    : EXTI                **********************/
/**********************    Version: 1.0                 **********************/
/*****************************************************************************/
/*****************************************************************************/

#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

                            /* Lines Definitions */
#define EXTI_LINE_0                   0
#define EXTI_LINE_1                   1
#define EXTI_LINE_2                   2
#define EXTI_LINE_3                   3
#define EXTI_LINE_4                   4
#define EXTI_LINE_5                   5
#define EXTI_LINE_6                   6
#define EXTI_LINE_7                   7
#define EXTI_LINE_8                   8
#define EXTI_LINE_9                   9
#define EXTI_LINE_10                  10
#define EXTI_LINE_11                  11
#define EXTI_LINE_12                  12 
#define EXTI_LINE_13                  13 
#define EXTI_LINE_14                  14 
#define EXTI_LINE_15                  15

                            /* Modes Definitions */
#define EXTI_MODE_RISING                   0
#define EXTI_MODE_FALLING                  1
#define EXTI_MODE_ON_CHANGE                2

                            /*Functions Prototype */

/**
 * @brief Initialize External Intterupts Mode
 */
void MEXTI_voidInit();

/**
 * @brief It enables the interrupt of the line that is passed to it
 * 
 * @param Copy_u8Line The line number of the interrupt you want to enable.
 */
void MEXTI_voidEnableEXTI(u8 Copy_u8Line);

/**
 * @brief It disables the interrupt of the line that is passed to it
 * 
 * @param Copy_u8Line The line number of the interrupt you want to disable.
 */
void MEXTI_voidDisableEXTI(u8 Copy_u8Line);

/**
 * @brief This function is used to trigger the interrupt manually by software
 * 
 * @param Copy_u8Line The line number of the interrupt you want to trigger the interrupt by software.
 */
void MEXTI_voidSwTrigger(u8 Copy_u8Line);

/**
 * It sets the interrupt mode for the specified line
 * 
 * @param Copy_u8Line The line number of the external interrupt.
 * @param Copy_u8Mode The mode to trigger the interrupt.
 */
void MEXTI_voidSetSignalLatch(u8 Copy_u8Line,u8 Copy_u8Mode);


#endif