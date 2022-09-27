/*****************************************************************************/
/*****************************************************************************/
/**********************    Author : Mohamed Aburehab    **********************/
/**********************    Layer  : SERVICES            **********************/
/**********************    SWD    : OS                  **********************/
/**********************    Version: 1.0                 **********************/
/*****************************************************************************/
/*****************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "STK_interface.h"

#include "OS_interface.h"
#include "OS_private.h"
#include "OS_config.h"

/* Declaring an array of type Task and initializing it with NULL. */
Task OS_Tasks[SOS_NUMBER_OF_TASKS] = {{NULL}};

/**
 * It initializes the SysTick timer and sets it to call the Scheduler every 1000 micro second
 */
void SOS_voidStart(void){
    /* Initializing the SysTick timer. */
    MSTK_voidInit();
    /* Setting the SysTick timer to call the Scheduler every 1000 micro second. */
    MSTK_voidSetIntervalPeriodic(1000,Scheduler);
}

/**
 * @brief It takes a task ID, a task periodicity, and a pointer to a function, and then it assigns the
 * periodicity and the function pointer to the task ID.
 * 
 * @param Copy_u8ID The ID of the task.
 * @param Copy_u16Priodicity The time between each task execution.
 * @param Copy_u16FirstDelay The delay before the task starts executing.
 * @param Fptr is a pointer to a function that takes no parameters and returns void.
 */
void SOS_voidCreateTask(u8 Copy_u8ID, u16 Copy_u16Priodicity, u16 Copy_u16FirstDelay, u8 Copy_u8TaskState,void (*Fptr)(void) ){
    OS_Tasks[Copy_u8ID].priodicity = Copy_u16Priodicity;
    OS_Tasks[Copy_u8ID].FirstDelay = Copy_u16FirstDelay;
    OS_Tasks[Copy_u8ID].TaskState = Copy_u8TaskState;
    OS_Tasks[Copy_u8ID].TaskFunc = Fptr;

}

/**
 * The function loops through all the tasks in the array and checks if the task is ready and 
 * the first delay is zero, then it executes the task function and resets the first delay to the
 * priodicity.
 */
static void Scheduler(void){
    u8 Local_u8TaskCounter ;
    for(Local_u8TaskCounter = 0; Local_u8TaskCounter < SOS_NUMBER_OF_TASKS; Local_u8TaskCounter++){
    	if (OS_Tasks[Local_u8TaskCounter].TaskFunc != NULL){
			if(OS_Tasks[Local_u8TaskCounter].TaskState == SOS_TASK_STATE_READY ){
				if(OS_Tasks[Local_u8TaskCounter].FirstDelay == 0){
					OS_Tasks[Local_u8TaskCounter].TaskFunc();
					OS_Tasks[Local_u8TaskCounter].FirstDelay = OS_Tasks[Local_u8TaskCounter].priodicity;
				}else {
					OS_Tasks[Local_u8TaskCounter].FirstDelay --;
				}
			}
		}
    }
}
