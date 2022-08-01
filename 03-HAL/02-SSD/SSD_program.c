/*****************************************************************************/
/*****************************************************************************/
/**********************    Author : Mohamed Aburehab    **********************/
/**********************    Layer  : HAL                 **********************/
/**********************    SWD    : LED                 **********************/
/**********************    Version: 1.0                 **********************/
/*****************************************************************************/
/*****************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "SSD_interface.h"
#include "SSD_private.h"
#include "SSD_config.h"


void SSD_voidDisplay(u8 Copy_u8Port, u8 Copy_u8StartPin,u8 SSD_u8Type, u8 Copy_u8Number){
    u8 sevenSegmentMap [10] = {
        0b00111111, 	// value of 0 on seven segment 
        0b00000110, 	// value of 1 on seven segment 
        0b01011011, 	// value of 2 on seven segment 
        0b01001111,		// value of 3 on seven segment 
        0b01100110,		// value of 4 on seven segment 
        0b01101101,		// value of 5 on seven segment 
        0b01111101,		// value of 6 on seven segment 
        0b00000111,		// value of 7 on seven segment 
        0b01111111,		// value of 8 on seven segment 
        0b01101111      // value of 9 on seven segment 
        }; 	

    MGPIO_voidSetPinDirection(Copy_u8Port, Copy_u8StartPin, OUTPUT_SPEED_10MHZ_PP);
    MGPIO_voidSetPinDirection(Copy_u8Port, (Copy_u8StartPin +1), OUTPUT_SPEED_10MHZ_PP);
    MGPIO_voidSetPinDirection(Copy_u8Port, (Copy_u8StartPin +2), OUTPUT_SPEED_10MHZ_PP);
    MGPIO_voidSetPinDirection(Copy_u8Port, (Copy_u8StartPin +3), OUTPUT_SPEED_10MHZ_PP);
    MGPIO_voidSetPinDirection(Copy_u8Port, (Copy_u8StartPin +4), OUTPUT_SPEED_10MHZ_PP);
    MGPIO_voidSetPinDirection(Copy_u8Port, (Copy_u8StartPin +5), OUTPUT_SPEED_10MHZ_PP);
    MGPIO_voidSetPinDirection(Copy_u8Port, (Copy_u8StartPin +6), OUTPUT_SPEED_10MHZ_PP);

    switch (SSD_u8Type)
    {
        case SSD_COMMON_CATHODE:
            MGPIO_voidSetPinValue(Copy_u8Port, (Copy_u8StartPin+ 0), GET_BIT(sevenSegmentMap[Copy_u8Number], 0));
            MGPIO_voidSetPinValue(Copy_u8Port, (Copy_u8StartPin+ 1), GET_BIT(sevenSegmentMap[Copy_u8Number], 1));
            MGPIO_voidSetPinValue(Copy_u8Port, (Copy_u8StartPin+ 2), GET_BIT(sevenSegmentMap[Copy_u8Number], 2));
            MGPIO_voidSetPinValue(Copy_u8Port, (Copy_u8StartPin+ 3), GET_BIT(sevenSegmentMap[Copy_u8Number], 3));
            MGPIO_voidSetPinValue(Copy_u8Port, (Copy_u8StartPin+ 4), GET_BIT(sevenSegmentMap[Copy_u8Number], 4));
            MGPIO_voidSetPinValue(Copy_u8Port, (Copy_u8StartPin+ 5), GET_BIT(sevenSegmentMap[Copy_u8Number], 5));
            MGPIO_voidSetPinValue(Copy_u8Port, (Copy_u8StartPin+ 6), GET_BIT(sevenSegmentMap[Copy_u8Number], 6));
            break;
        case SSD_COMMON_ANODE:
            MGPIO_voidSetPinValue(Copy_u8Port, (Copy_u8StartPin+ 0), ~GET_BIT(sevenSegmentMap[Copy_u8Number], 0));
            MGPIO_voidSetPinValue(Copy_u8Port, (Copy_u8StartPin+ 1), ~GET_BIT(sevenSegmentMap[Copy_u8Number], 1));
            MGPIO_voidSetPinValue(Copy_u8Port, (Copy_u8StartPin+ 2), ~GET_BIT(sevenSegmentMap[Copy_u8Number], 2));
            MGPIO_voidSetPinValue(Copy_u8Port, (Copy_u8StartPin+ 3), ~GET_BIT(sevenSegmentMap[Copy_u8Number], 3));
            MGPIO_voidSetPinValue(Copy_u8Port, (Copy_u8StartPin+ 4), ~GET_BIT(sevenSegmentMap[Copy_u8Number], 4));
            MGPIO_voidSetPinValue(Copy_u8Port, (Copy_u8StartPin+ 5), ~GET_BIT(sevenSegmentMap[Copy_u8Number], 5));
            MGPIO_voidSetPinValue(Copy_u8Port, (Copy_u8StartPin+ 6), ~GET_BIT(sevenSegmentMap[Copy_u8Number], 6));

            break;

    }
}
