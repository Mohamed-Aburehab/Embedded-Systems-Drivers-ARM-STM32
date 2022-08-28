/*****************************************************************************/
/*****************************************************************************/
/**********************    Author : Mohamed Aburehab    **********************/
/**********************    Layer  : MCAL                **********************/
/**********************    SWD    : EXTI                **********************/
/**********************    Version: 1.0                 **********************/
/*****************************************************************************/
/*****************************************************************************/

#ifndef EXTI_CONFIG_H_
#define EXTI_CONFIG_H_

/* Choose the line for the external intterupt
* Options :     0  - EXTI_LINE_0
*               1  - EXTI_LINE_1
*               2  - EXTI_LINE_2
*               3  - EXTI_LINE_3
*               4  - EXTI_LINE_4
*               5  - EXTI_LINE_5
*               6  - EXTI_LINE_6
*               7  - EXTI_LINE_7
*               8  - EXTI_LINE_8
*               9  - EXTI_LINE_9
*               10 - EXTI_LINE_10
*               11 - EXTI_LINE_11
*               12 - EXTI_LINE_12
*               13 - EXTI_LINE_13
*               14 - EXTI_LINE_14
*               15 - EXTI_LINE_15
*/
#define         EXTI_LINE               EXTI_LINE_0

/* Choose the mode for the external intterupt
* Options :     0  - EXTI_MODE_RISING
*               1  - EXTI_MODE_FALLING
*               2  - EXTI_MODE_ON_CHANGE
*/
#define         EXTI_MODE               EXTI_MODE_RISING

#endif