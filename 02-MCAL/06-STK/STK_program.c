/*****************************************************************************/
/*****************************************************************************/
/**********************    Author : Mohamed Aburehab    **********************/
/**********************    Layer  : MCAL                **********************/
/**********************    SWD    : SysTick (STK)       **********************/
/**********************    Version: 1.0                 **********************/
/*****************************************************************************/
/*****************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "STK_interface.h"
#include "STK_private.h"
#include "STK_config.h"

/* A pointer to a function to hold the call back function. */
void (*CallBack)(void);
/* A global variable that is used to determine the interrupt mode. */
static u8 STK_gu8InterruptSource = 0;

/**
 * @brief It initializes the SysTick timer.
 */
void MSTK_voidInit(){

    #if STK_CLOCK_SOURCE == STK_CLOCK_AHB
        /* Setting the clock source to AHB. */
    STK_CTRL = 0x00000004;
	#elif  STK_CLOCK_SOURCE == STK_CLOCK_AHB_Divided_BY_8
    STK_CTRL = 0x00000000;
    #endif

}

/**
 * @brief It sets the busy wait ticks
 * @param Copy_u32Ticks The number of ticks to wait for.
 */
void MSTK_voidSetBusyWait(u32 Copy_u32Ticks){
    /* Loading the value of the ticks into the STK_LOAD register. */
    STK_LOAD = Copy_u32Ticks;
    /* Setting the bit in the STK_CTRL register that enables the SysTick timer. */
    SET_BIT(STK_CTRL, STK_CTRL_ENABLE);
    /* Checking if the counter has reached zero. */
    while(GET_BIT(STK_CTRL, STK_CTRL_COUNTFLAG) == 0);

    /* Clearing the STK_CTRL_ENABLE bit in the STK_CTRL register. */
    CLR_BIT(STK_CTRL, STK_CTRL_ENABLE);
    /* Clearing the value of the STK_LOAD register. */
    STK_LOAD = 0;
    /* Clearing the value of the STK_VAL register. */
    STK_VAL = 0;
}

/**
 * @brief It sets the SysTick timer to work in interval mode for one time only.
 * 
 * @param Copy_u32Ticks The number of ticks that the timer will count.
 * @param Copy_pvNotificationFunc The address of the function that will be called when the timer
 * finish counting.
 */
void MSTK_voidSetIntervalSingle(u32 Copy_u32Ticks, void (*Copy_pvNotificationFunc)(void)){
    /* A global variable that is used to determine the interrupt mode . */
    STK_gu8InterruptSource = STK_INTERRUPT_SOURCE_INTERVAL_SINGLE;
    /* Assigning the address of the function to the global variable `CallBack`. */
    CallBack = Copy_pvNotificationFunc;
    /* Loading the value of the ticks into the STK_LOAD register. */
    STK_LOAD = Copy_u32Ticks;
    /* Setting the bit in the STK_CTRL register that enables the interrupt. */
    SET_BIT(STK_CTRL, STK_CTRL_TICKINT);
    /* Setting the bit in the STK_CTRL register that enables the SysTick timer. */
    SET_BIT(STK_CTRL, STK_CTRL_ENABLE);

}

/**
 * @brief It sets the SysTick timer to work in interval mode .
 * 
 * @param Copy_u32Ticks The number of ticks that the timer will count.
 * @param Copy_pvNotificationFunc The address of the function that will be called when the timer
 * finish counting.
 */
void MSTK_voidSetIntervalPeriodic(u32 Copy_u32Ticks, void (*Copy_pvNotificationFunc)(void)){
    /* A global variable that is used to determine the interrupt mode . */
    STK_gu8InterruptSource = STK_INTERRUPT_SOURCE_INTERVAL_PERIODIC;
    /* Assigning the address of the function to the global variable `CallBack`. */
    CallBack = Copy_pvNotificationFunc;
    /* Loading the value of the ticks into the STK_LOAD register. */
    STK_LOAD = Copy_u32Ticks;
    /* Setting the bit in the STK_CTRL register that enables the interrupt. */
    SET_BIT(STK_CTRL, STK_CTRL_TICKINT);
    /* Setting the bit in the STK_CTRL register that enables the SysTick timer. */
    SET_BIT(STK_CTRL, STK_CTRL_ENABLE);

}

/**
 * @brief It stops the interval timer 
 */
void MSTK_voidStopInterval(void){
    /* Clearing the STK_CTRL_ENABLE bit in the STK_CTRL register. */
    CLR_BIT(STK_CTRL, STK_CTRL_ENABLE);
    /* Clearing the bit in the STK_CTRL register that enables the interrupt. */
    CLR_BIT(STK_CTRL, STK_CTRL_TICKINT);
    /* Clearing the value of the STK_LOAD register. */
    STK_LOAD = 0;
    /* Clearing the value of the STK_VAL register. */
    STK_VAL = 0;
}

/**
 * @brief It returns the value of the elapsed time.
 * 
 * @return The elapsed time.
 */
u32 MSTK_u32GetElapsedTime(void){
    /* A local variable that is used to store the elapsed time. */
	u32 Local_u32ElapsedTime;
    /* Calculating the elapsed time. */
	Local_u32ElapsedTime = STK_LOAD - STK_VAL ;
    /* Returning the value of the elapsed time. */
	return Local_u32ElapsedTime;
}

/**
 * @brief This function is used to get the remaining time of the SysTick timer
 * 
 * @return The remaining time.
 */
u32 MSTK_u32GetRemainingTime(void){
    /* A local variable that is used to store the remaining time. */
	u32 Local_u32RemainTime;
    /* Getting the value of the STK_VAL register value (remaining time). */
	Local_u32RemainTime = STK_VAL ;
    /* Returning the value of the remaining time. */
	return Local_u32RemainTime;

}



void SysTick_Handler(void){
    /* A local varible that is used to clear the flag. */
    u8 Local_u8Temporary;

    /* Used to stop the timer when interval is in single mode. */
    if (STK_gu8InterruptSource == STK_INTERRUPT_SOURCE_INTERVAL_SINGLE){
        /* Clearing the STK_CTRL_ENABLE bit in the STK_CTRL register. */
        CLR_BIT(STK_CTRL, STK_CTRL_ENABLE);
        /* Clearing the bit in the STK_CTRL register that enables the interrupt. */
        CLR_BIT(STK_CTRL, STK_CTRL_TICKINT);
        /* Clearing the value of the STK_LOAD register. */
        STK_LOAD = 0;
        /* Clearing the value of the STK_VAL register. */
        STK_VAL = 0;
    }

    /* Calling the notification function that is stored in the global variable `CallBack`. */
    CallBack();
    
    /* Clearing the flag. */
    Local_u8Temporary = GET_BIT(STK_CTRL,STK_CTRL_COUNTFLAG);

}
