/*****************************************************************************/
/*****************************************************************************/
/**********************    Author : Mohamed Aburehab    **********************/
/**********************    Layer  : HAL                 **********************/
/**********************    SWD    : IR                  **********************/
/**********************    Version: 1.0                 **********************/
/*****************************************************************************/
/*****************************************************************************/

#ifndef IR_PRIVATE_H_
#define IR_PRIVATE_H_

/**
 * @brief It starts a timer, and when the timer expires, it stores the time elapsed since the timer started in
 * an array, and then starts the timer again.
 */
static void callBack_voidGetIRframe(void);

/**
 * @brief It takes the data from the IR receiver and converts it into a byte and then calls the 
 * notification function if the frame is valid.
 */
static void callBack_voidTakeAction();

#endif