/*****************************************************************************/
/*****************************************************************************/
/**********************    Author : Mohamed Aburehab    **********************/
/**********************    Layer  : HAL                 **********************/
/**********************    SWD    : DAC                 **********************/
/**********************    Version: 1.0                 **********************/
/*****************************************************************************/
/*****************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "STK_interface.h"

#include "DAC_interface.h"
#include "DAC_config.h"
#include "DAC_private.h"

/**
 * @brief It sets the direction of the pins to output and sets the speed to 2MHz 
 * and initializes SysTick.
 */
void HDAC_voidInit(){
	MGPIO_voidSetPinDirection(HDAC_BIT_0_PORT_AND_PIN,MGPIO_OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(HDAC_BIT_1_PORT_AND_PIN,MGPIO_OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(HDAC_BIT_2_PORT_AND_PIN,MGPIO_OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(HDAC_BIT_3_PORT_AND_PIN,MGPIO_OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(HDAC_BIT_4_PORT_AND_PIN,MGPIO_OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(HDAC_BIT_5_PORT_AND_PIN,MGPIO_OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(HDAC_BIT_6_PORT_AND_PIN,MGPIO_OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(HDAC_BIT_7_PORT_AND_PIN,MGPIO_OUTPUT_SPEED_2MHZ_PP);
    MSTK_voidInit();
}

/**
 * @brief It takes a number between 0 and 255 and sets the value of the DAC to that number
 * 
 * @param Copy_u8DacValue The value you want to set the DAC to.
 */
void HDAC_voidSetDacValue(u8 Copy_u8DacValue){
	MGPIO_voidSetPinValue(HDAC_BIT_0_PORT_AND_PIN,(GET_BIT(Copy_u8DacValue,0)));
	MGPIO_voidSetPinValue(HDAC_BIT_1_PORT_AND_PIN,(GET_BIT(Copy_u8DacValue,1)));
	MGPIO_voidSetPinValue(HDAC_BIT_2_PORT_AND_PIN,(GET_BIT(Copy_u8DacValue,2)));
	MGPIO_voidSetPinValue(HDAC_BIT_3_PORT_AND_PIN,(GET_BIT(Copy_u8DacValue,3)));
	MGPIO_voidSetPinValue(HDAC_BIT_4_PORT_AND_PIN,(GET_BIT(Copy_u8DacValue,4)));
	MGPIO_voidSetPinValue(HDAC_BIT_5_PORT_AND_PIN,(GET_BIT(Copy_u8DacValue,5)));
	MGPIO_voidSetPinValue(HDAC_BIT_6_PORT_AND_PIN,(GET_BIT(Copy_u8DacValue,6)));
	MGPIO_voidSetPinValue(HDAC_BIT_7_PORT_AND_PIN,(GET_BIT(Copy_u8DacValue,7)));
}