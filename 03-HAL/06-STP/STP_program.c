/*****************************************************************************/
/*****************************************************************************/
/**********************    Author : Mohamed Aburehab    **********************/
/**********************    Layer  : HAL                 **********************/
/**********************    SWD    : STP                 **********************/
/**********************    Version: 1.0                 **********************/
/*****************************************************************************/
/*****************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "STK_interface.h"

#include "STP_interface.h"
#include "STP_config.h"
#include "STP_private.h"

void HSTP_voidSendSynchronus(u8 Copy_u8DataToSend){
    s8 Local_s8Counter;
    u8 Local_u8Bit;
    for (Local_s8Counter = 7 ; Local_s8Counter >= 0 ; Local_s8Counter--){
        /* Send bit by bit starting from MSb */
        Local_u8Bit = GET_BIT(Copy_u8DataToSend, Local_s8Counter);
        MGPIO_voidSetPinValue(HSTP_SERIAL_DATA, Local_u8Bit);

        /* Send Pulse to Shift Clock */
        MGPIO_voidSetPinValue(HSTP_SHIFT_CLOCK, MGPIO_VALUE_HIGH);
        MSTK_voidSetBusyWait(1);
        MGPIO_voidSetPinValue(HSTP_SHIFT_CLOCK, MGPIO_VALUE_LOW);
        MSTK_voidSetBusyWait(1);

    }
    /* Send Pulse to store Clock */
    MGPIO_voidSetPinValue(HSTP_STORE_CLOCK, MGPIO_VALUE_HIGH);
    MSTK_voidSetBusyWait(1);
    MGPIO_voidSetPinValue(HSTP_STORE_CLOCK, MGPIO_VALUE_LOW);
    MSTK_voidSetBusyWait(1);
}