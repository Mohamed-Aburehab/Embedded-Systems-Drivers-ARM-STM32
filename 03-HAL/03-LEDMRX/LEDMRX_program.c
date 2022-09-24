/*****************************************************************************/
/*****************************************************************************/
/**********************    Author : Mohamed Aburehab    **********************/
/**********************    Layer  : HAL                 **********************/
/**********************    SWD    : LEDMRX              **********************/
/**********************    Version: 2.0                 **********************/
/*****************************************************************************/
/*****************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "STK_interface.h"

#include "LEDMRX_interface.h"
#include "LEDMRX_private.h"
#include "LEDMRX_config.h"

/**
 * @brief It initializes the microcontroller pins configurations
 */
void HLEDMRX_voidInit(void){
    /* Rows configuration */
    MGPIO_voidSetPinDirection(LEDMRX_ROW0_PIN, MGPIO_OUTPUT_SPEED_2MHZ_PP);
    MGPIO_voidSetPinDirection(LEDMRX_ROW1_PIN, MGPIO_OUTPUT_SPEED_2MHZ_PP);
    MGPIO_voidSetPinDirection(LEDMRX_ROW2_PIN, MGPIO_OUTPUT_SPEED_2MHZ_PP);
    MGPIO_voidSetPinDirection(LEDMRX_ROW3_PIN, MGPIO_OUTPUT_SPEED_2MHZ_PP);
    MGPIO_voidSetPinDirection(LEDMRX_ROW4_PIN, MGPIO_OUTPUT_SPEED_2MHZ_PP);
    MGPIO_voidSetPinDirection(LEDMRX_ROW5_PIN, MGPIO_OUTPUT_SPEED_2MHZ_PP);
    MGPIO_voidSetPinDirection(LEDMRX_ROW6_PIN, MGPIO_OUTPUT_SPEED_2MHZ_PP);
    MGPIO_voidSetPinDirection(LEDMRX_ROW7_PIN, MGPIO_OUTPUT_SPEED_2MHZ_PP);

    /* Columns configuration */
    MGPIO_voidSetPinDirection(LEDMRX_COL0_PIN, MGPIO_OUTPUT_SPEED_2MHZ_PP);
    MGPIO_voidSetPinDirection(LEDMRX_COL1_PIN, MGPIO_OUTPUT_SPEED_2MHZ_PP);
    MGPIO_voidSetPinDirection(LEDMRX_COL2_PIN, MGPIO_OUTPUT_SPEED_2MHZ_PP);
    MGPIO_voidSetPinDirection(LEDMRX_COL3_PIN, MGPIO_OUTPUT_SPEED_2MHZ_PP);
    MGPIO_voidSetPinDirection(LEDMRX_COL4_PIN, MGPIO_OUTPUT_SPEED_2MHZ_PP);
    MGPIO_voidSetPinDirection(LEDMRX_COL5_PIN, MGPIO_OUTPUT_SPEED_2MHZ_PP);
    MGPIO_voidSetPinDirection(LEDMRX_COL6_PIN, MGPIO_OUTPUT_SPEED_2MHZ_PP);
    MGPIO_voidSetPinDirection(LEDMRX_COL7_PIN, MGPIO_OUTPUT_SPEED_2MHZ_PP);
}

/**
 * @brief For each column, set the row values, enable the column, wait 2.5ms, disable the column.
 * 
 * @param Copy_u8Data is the array of data that will be displayed on the matrix.
 * @param i is the index of the array
 */
static void HLEDMRX_voidDisplayFrame(u8 *Copy_u8Data, u8 i){
    DisableAllColumns();
    /* Set Row 0 */
    SetRowValues(Copy_u8Data[i+0]);
    /* Enable column 0 */
    MGPIO_voidSetPinValue(LEDMRX_COL0_PIN, MGPIO_VALUE_LOW);
    MSTK_voidSetBusyWait(2500); // 2.5 MSEC delay
    /* Disable column 0 */
    MGPIO_voidSetPinValue(LEDMRX_COL0_PIN, MGPIO_VALUE_HIGH);

    /* Set Row 1 */
    SetRowValues(Copy_u8Data[i+1]);
    /* Enable column 1 */
    MGPIO_voidSetPinValue(LEDMRX_COL1_PIN, MGPIO_VALUE_LOW);
    MSTK_voidSetBusyWait(2500); // 2.5 MSEC delay
    /* Disable column 1 */
    MGPIO_voidSetPinValue(LEDMRX_COL1_PIN, MGPIO_VALUE_HIGH);

    /* Set Row 2 */
    SetRowValues(Copy_u8Data[i+2]);
    /* Enable column 2 */
    MGPIO_voidSetPinValue(LEDMRX_COL2_PIN, MGPIO_VALUE_LOW);
    MSTK_voidSetBusyWait(2500); // 2.5 MSEC delay
    /* Disable column 2 */
    MGPIO_voidSetPinValue(LEDMRX_COL2_PIN, MGPIO_VALUE_HIGH);

    /* Set Row 3 */
    SetRowValues(Copy_u8Data[i+3]);
    /* Enable column 3 */
    MGPIO_voidSetPinValue(LEDMRX_COL3_PIN, MGPIO_VALUE_LOW);
    MSTK_voidSetBusyWait(2500); // 2.5 MSEC delay
    /* Disable column 3 */
    MGPIO_voidSetPinValue(LEDMRX_COL3_PIN, MGPIO_VALUE_HIGH);

    /* Set Row 4 */
    SetRowValues(Copy_u8Data[i+4]);
    /* Enable column 4 */
    MGPIO_voidSetPinValue(LEDMRX_COL4_PIN, MGPIO_VALUE_LOW);
    MSTK_voidSetBusyWait(2500); // 2.5 MSEC delay
    /* Disable column 4 */
    MGPIO_voidSetPinValue(LEDMRX_COL4_PIN, MGPIO_VALUE_HIGH);

    /* Set Row 5 */
    SetRowValues(Copy_u8Data[i+5]);
    /* Enable column 5 */
    MGPIO_voidSetPinValue(LEDMRX_COL5_PIN, MGPIO_VALUE_LOW);
    MSTK_voidSetBusyWait(2500); // 2.5 MSEC delay
    /* Disable column 5 */
    MGPIO_voidSetPinValue(LEDMRX_COL5_PIN, MGPIO_VALUE_HIGH);

    /* Set Row 6 */
    SetRowValues(Copy_u8Data[i+6]);
    /* Enable column 6 */
    MGPIO_voidSetPinValue(LEDMRX_COL6_PIN, MGPIO_VALUE_LOW);
    MSTK_voidSetBusyWait(2500); // 2.5 MSEC delay
    /* Disable column 6 */
    MGPIO_voidSetPinValue(LEDMRX_COL6_PIN, MGPIO_VALUE_HIGH);

    /* Set Row 7 */
    SetRowValues(Copy_u8Data[i+7]);
    /* Enable column 7 */
    MGPIO_voidSetPinValue(LEDMRX_COL7_PIN, MGPIO_VALUE_LOW);
    MSTK_voidSetBusyWait(2500); // 2.5 MSEC delay
    /* Disable column 7 */
    MGPIO_voidSetPinValue(LEDMRX_COL7_PIN, MGPIO_VALUE_HIGH);
}


/**
 * @brief It takes a pointer to an array of 8 bytes, and displays the contents of that array on the LED
 * matrix.
 * 
 * @param Copy_u8Data The data to be displayed.
 */
void HLEDMRX_voidDisplay(u8 *Copy_u8Data){
    while (1){
        HLEDMRX_voidDisplayFrame(Copy_u8Data, 0);
    }
}

/**
 * @brief It takes a pointer to an array of 64 bytes, and displays the first 8 bytes on the first row, then
 * the next 8 bytes on the second row, and so on. 
 * 
 * @param Copy_u8Data is the array of the animation frames
 */
void HLEDMRX_voidDisplayAnimation(u8 *Copy_u8Data){
    DisableAllColumns();
    u8 i = 0 ;
    u32 Local_u32FrameDuration ;
    while (1){
		for (i = 0 ; i+7 < 64 ; i ++){
			Local_u32FrameDuration = 0;
			while (Local_u32FrameDuration < 10){
                HLEDMRX_voidDisplayFrame(Copy_u8Data, i);
                Local_u32FrameDuration ++;
			}
		}
    }
}


/**
 * @brief It disables all columns by setting all the columns to high.
 */
static void DisableAllColumns(void){
    /* disable all columns */
    MGPIO_voidSetPinValue(LEDMRX_COL0_PIN, MGPIO_VALUE_HIGH);
    MGPIO_voidSetPinValue(LEDMRX_COL1_PIN, MGPIO_VALUE_HIGH);
    MGPIO_voidSetPinValue(LEDMRX_COL2_PIN, MGPIO_VALUE_HIGH);
    MGPIO_voidSetPinValue(LEDMRX_COL3_PIN, MGPIO_VALUE_HIGH);
    MGPIO_voidSetPinValue(LEDMRX_COL4_PIN, MGPIO_VALUE_HIGH);
    MGPIO_voidSetPinValue(LEDMRX_COL5_PIN, MGPIO_VALUE_HIGH);
    MGPIO_voidSetPinValue(LEDMRX_COL6_PIN, MGPIO_VALUE_HIGH);
    MGPIO_voidSetPinValue(LEDMRX_COL7_PIN, MGPIO_VALUE_HIGH);
}

/**
 * @brief sets the value of the rows of the LED matrix to the value of the passed argument. 
 *
 * @param Copy_u8Value the value to be set on the rows
 */
static void SetRowValues(u8 Copy_u8Value){
    /* set rows data */
    MGPIO_voidSetPinValue(LEDMRX_ROW0_PIN, (GET_BIT(Copy_u8Value, 0)) );
    MGPIO_voidSetPinValue(LEDMRX_ROW1_PIN, (GET_BIT(Copy_u8Value, 1)) );
    MGPIO_voidSetPinValue(LEDMRX_ROW2_PIN, (GET_BIT(Copy_u8Value, 2)) );
    MGPIO_voidSetPinValue(LEDMRX_ROW3_PIN, (GET_BIT(Copy_u8Value, 3)) );
    MGPIO_voidSetPinValue(LEDMRX_ROW4_PIN, (GET_BIT(Copy_u8Value, 4)) );
    MGPIO_voidSetPinValue(LEDMRX_ROW5_PIN, (GET_BIT(Copy_u8Value, 5)) );
    MGPIO_voidSetPinValue(LEDMRX_ROW6_PIN, (GET_BIT(Copy_u8Value, 6)) );
    MGPIO_voidSetPinValue(LEDMRX_ROW7_PIN, (GET_BIT(Copy_u8Value, 7)) );

}
