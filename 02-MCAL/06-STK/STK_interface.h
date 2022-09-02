/*****************************************************************************/
/*****************************************************************************/
/**********************    Author : Mohamed Aburehab    **********************/
/**********************    Layer  : MCAL                **********************/
/**********************    SWD    : SysTick (STK)       **********************/
/**********************    Version: 1.0                 **********************/
/*****************************************************************************/
/*****************************************************************************/

#ifndef STK_INTERFACE_H_
#define STK_INTERFACE_H_

/**
 * It initializes the SysTick timer.
 */
void MSTK_voidInit(void);

/**
 * @brief It sets the busy wait ticks (delay function)
 * @param Copy_u32Ticks The number of ticks to wait for.
 */
void MSTK_voidSetBusyWait(u32 Copy_u32Ticks);

/**
 * @brief It sets the SysTick timer to work in interval mode for one time only.
 * 
 * @param Copy_u32Ticks The number of ticks that the timer will count.
 * @param Copy_pvNotificationFunc The address of the function that will be called when the timer
 * finish counting.
 */
void MSTK_voidSetIntervalSingle(u32 Copy_u32Ticks, void (*Copy_pvNotificationFunc)(void));

/**
 * @brief It sets the SysTick timer to work in interval mode .
 * 
 * @param Copy_u32Ticks The number of ticks that the timer will count.
 * @param Copy_pvNotificationFunc The address of the function that will be called when the timer
 * finish counting.
 */
void MSTK_voidSetIntervalPeriodic(u32 Copy_u32Ticks, void (*Copy_pvNotificationFunc)(void));

/**
 * @brief It stops the interval timer 
 */
void MSTK_voidStopInterval(void);

/**
 * @brief It returns the value of the elapsed time.
 * 
 * @return The elapsed time.
 */
u32 MSTK_u32GetElapsedTime(void);

/**
 * @brief This function is used to get the remaining time of the SysTick timer
 * 
 * @return The remaining time.
 */
u32 MSTK_u32GetRemainingTime(void);

#endif