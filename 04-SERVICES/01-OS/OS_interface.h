/*****************************************************************************/
/*****************************************************************************/
/**********************    Author : Mohamed Aburehab    **********************/
/**********************    Layer  : SERVICES            **********************/
/**********************    SWD    : OS                  **********************/
/**********************    Version: 1.0                 **********************/
/*****************************************************************************/
/*****************************************************************************/

#ifndef OS_INTERFACE_H_
#define OS_INTERFACE_H_

#define SOS_TASK_STATE_READY          1
#define SOS_TASK_STATE_STOPPED        2


/**
 * It initializes the SysTick timer and sets it to call the Scheduler every 1000 micro second
 */
void SOS_voidStart(void);

/**
 * @brief It takes a task ID, a task periodicity, and a pointer to a function, and then it assigns the
 * periodicity and the function pointer to the task ID.
 * 
 * @param Copy_u8ID The ID of the task.
 * @param Copy_u16Priodicity The time between each task execution.
 * @param Copy_u16FirstDelay The delay before the task starts executing.
 * @param Fptr is a pointer to a function that takes no parameters and returns void.
 */
void SOS_voidCreateTask(u8 Copy_u8ID, u16 Copy_u16Priodicity, u16 Copy_u16FirstDelay, u8 Copy_u8TaskState,void (*Fptr)(void) );


#endif
