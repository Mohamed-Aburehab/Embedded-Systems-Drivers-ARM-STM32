/*****************************************************************************/
/*****************************************************************************/
/**********************    Author : Mohamed Aburehab    **********************/
/**********************    Layer  : HAL                 **********************/
/**********************    SWD    : IR                  **********************/
/**********************    Version: 1.0                 **********************/
/*****************************************************************************/
/*****************************************************************************/

#ifndef IR_INTERFACE_H_
#define IR_INTERFACE_H_

#define HIR_BUTTON_UP_ARROW             19
#define HIR_BUTTON_DOWN_ARROW           20
#define HIR_BUTTON_RIGHT_ARROW          21
#define HIR_BUTTON_LEFT_ARROW           22
#define HIR_BUTTON_OK                   23
#define HIR_BUTTON_POWER_ON_OFF         2
#define HIR_BUTTON_VOLUME_UP            7
#define HIR_BUTTON_VOLUME_DOWN          10


/**
 * @brief It initializes the IR required functions
 */
void HIR_voidInit();

/**
 * @brief It takes a pointer to a function as an argument, this function will be run whin a valid IR NEC
 * frame is recieved.
 * 
 * @param Copy_pvNotificationFunc is a pointer to a function that takes a u8 parameter and returns
 * void.
 */
void HIR_voidSetCallBackFunction(void (*Copy_pvNotificationFunc)(u8 Copy_u8FrameData));

#endif