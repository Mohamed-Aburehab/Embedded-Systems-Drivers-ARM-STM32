/*****************************************************************************/
/*****************************************************************************/
/**********************    Author : Mohamed Aburehab    **********************/
/**********************    Layer  : HAL                 **********************/
/**********************    SWD    : IR                  **********************/
/**********************    Version: 1.0                 **********************/
/*****************************************************************************/
/*****************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "NVIC_interface.h"
#include "STK_interface.h"
#include "EXTI_interface.h"
#include "AFIO_interface.h"

#include "IR_interface.h"
#include "IR_private.h"
#include "IR_config.h"


volatile u8 		u8StartFlag 		= 0;
volatile u32 		u32FrameData[50] 	= {0};
volatile u8 		u8EdgeCounter 		= 0;
volatile u8 		u8data 				= 0;

static void (*HIR_pvNotificationFunc)(u8 Copy_u8FrameData) = NULL;

/**
 * @brief It initializes the IR required functions
 */
void HIR_voidInit(){
    #if HIR_INPUT_PIN > MGPIO_PIN_4
    #error "wrong configurations"
    #else
    MGPIO_voidSetPinDirection(HIR_INPUT_PORT, HIR_INPUT_PIN, MGPIO_INPUT_FLOATING);
    MAFIO_voidSetEXTIConfiguration(HIR_INPUT_PIN, HIR_INPUT_PORT);
	MEXTI_voidSetCallBack(HIR_INPUT_PIN, callBack_voidGetIRframe);
	MEXTI_voidSetSignalLatch(HIR_INPUT_PIN,MEXTI_MODE_FALLING);
	MEXTI_voidEnableEXTI(HIR_INPUT_PIN);
    MNVIC_voidInit();
    MNVIC_voidEnableInterrupt((MNVIC_PERIPHERAL_EXTI0 + HIR_INPUT_PIN));
	MSTK_voidInit();
    #endif
}

/**
 * @brief It takes a pointer to a function as an argument, this function will be run whin a valid IR NEC
 * frame is recieved.
 * 
 * @param Copy_pvNotificationFunc is a pointer to a function that takes a u8 parameter and returns
 * void.
 */
void HIR_voidSetCallBackFunction(void (*Copy_pvNotificationFunc)(u8 Copy_u8FrameData)){
    HIR_pvNotificationFunc = Copy_pvNotificationFunc;
}


/**
 * @brief It starts a timer, and when the timer expires, it stores the time elapsed since the timer started in
 * an array, and then starts the timer again.
 */
static void callBack_voidGetIRframe(void){

	if(u8StartFlag == 0){
		// start timer
		MSTK_voidSetIntervalSingle(1000000, callBack_voidTakeAction);
		u8StartFlag = 1;
	}else {
		u32FrameData[u8EdgeCounter] = MSTK_u32GetElapsedTime();
		MSTK_voidSetIntervalSingle(1000000, callBack_voidTakeAction);
		u8EdgeCounter ++;
	}
}

/**
 * @brief It takes the data from the IR receiver and converts it into a byte and then calls the 
 * notification function if the frame is valid.
 */
static void callBack_voidTakeAction(){
	u8 i ;
	u8data = 0;
	if ( (u32FrameData[0] >= 10000) && (u32FrameData[0] <= 14000 )){
		for (i = 0 ; i<8 ; i++){
			if((u32FrameData[17+i] >= 2000) && (u32FrameData[17+i] <=2300)){
				SET_BIT(u8data, i);
			}else {
				CLR_BIT(u8data, i);
			}
		}
        if (HIR_pvNotificationFunc != NULL){
            HIR_pvNotificationFunc(u8data);
        }
	}
	else {
		//invaled frame
	}
	u8EdgeCounter = 0;
	u8StartFlag = 0;
	u32FrameData[0] = 0;
}

/* void voidPlay(void)
{
	switch (u8data)
	{
		case 19: MGPIO_voidSetPinValue(MGPIO_PORT_A,MGPIO_PIN_1,MGPIO_VALUE_HIGH); break;
		case 20: MGPIO_voidSetPinValue(MGPIO_PORT_A,MGPIO_PIN_1,MGPIO_VALUE_LOW);  break;
	}
} */
