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
 * It sets the row values, enables the column, waits 2.5ms, disables the column, and repeats for all
 * columns
 * 
 * @param Copy_u8Data is a pointer to an array of 8 bytes, each byte represents a row in the matrix.
 */
void HLEDMRX_voidDisplay(u8 *Copy_u8Data){
    DisableAllColumns();
    
        /* Set Row 0 */
        SetRowValues(Copy_u8Data[0]);
        /* Enable column 0 */
        MGPIO_voidSetPinValue(LEDMRX_COL0_PIN, MGPIO_VALUE_LOW);
        MSTK_voidSetBusyWait(2500); // 2.5 MSEC delay
        /* Disable column 0 */
        MGPIO_voidSetPinValue(LEDMRX_COL0_PIN, MGPIO_VALUE_HIGH);

        /* Set Row 1 */
        SetRowValues(Copy_u8Data[1]);
        /* Enable column 1 */
        MGPIO_voidSetPinValue(LEDMRX_COL1_PIN, MGPIO_VALUE_LOW);
        MSTK_voidSetBusyWait(2500); // 2.5 MSEC delay
        /* Disable column 1 */
        MGPIO_voidSetPinValue(LEDMRX_COL1_PIN, MGPIO_VALUE_HIGH);

        /* Set Row 2 */
        SetRowValues(Copy_u8Data[2]);
        /* Enable column 2 */
        MGPIO_voidSetPinValue(LEDMRX_COL2_PIN, MGPIO_VALUE_LOW);
        MSTK_voidSetBusyWait(2500); // 2.5 MSEC delay
        /* Disable column 2 */
        MGPIO_voidSetPinValue(LEDMRX_COL2_PIN, MGPIO_VALUE_HIGH);

        /* Set Row 3 */
        SetRowValues(Copy_u8Data[3]);
        /* Enable column 3 */
        MGPIO_voidSetPinValue(LEDMRX_COL3_PIN, MGPIO_VALUE_LOW);
        MSTK_voidSetBusyWait(2500); // 2.5 MSEC delay
        /* Disable column 3 */
        MGPIO_voidSetPinValue(LEDMRX_COL3_PIN, MGPIO_VALUE_HIGH);

        /* Set Row 4 */
        SetRowValues(Copy_u8Data[4]);
        /* Enable column 4 */
        MGPIO_voidSetPinValue(LEDMRX_COL4_PIN, MGPIO_VALUE_LOW);
        MSTK_voidSetBusyWait(2500); // 2.5 MSEC delay
        /* Disable column 4 */
        MGPIO_voidSetPinValue(LEDMRX_COL4_PIN, MGPIO_VALUE_HIGH);

        /* Set Row 5 */
        SetRowValues(Copy_u8Data[5]);
        /* Enable column 5 */
        MGPIO_voidSetPinValue(LEDMRX_COL5_PIN, MGPIO_VALUE_LOW);
        MSTK_voidSetBusyWait(2500); // 2.5 MSEC delay
        /* Disable column 5 */
        MGPIO_voidSetPinValue(LEDMRX_COL5_PIN, MGPIO_VALUE_HIGH);

        /* Set Row 6 */
        SetRowValues(Copy_u8Data[6]);
        /* Enable column 6 */
        MGPIO_voidSetPinValue(LEDMRX_COL6_PIN, MGPIO_VALUE_LOW);
        MSTK_voidSetBusyWait(2500); // 2.5 MSEC delay
        /* Disable column 6 */
        MGPIO_voidSetPinValue(LEDMRX_COL6_PIN, MGPIO_VALUE_HIGH);

        /* Set Row 7 */
        SetRowValues(Copy_u8Data[7]);
        /* Enable column 7 */
        MGPIO_voidSetPinValue(LEDMRX_COL7_PIN, MGPIO_VALUE_LOW);
        MSTK_voidSetBusyWait(2500); // 2.5 MSEC delay
        /* Disable column 7 */
        MGPIO_voidSetPinValue(LEDMRX_COL7_PIN, MGPIO_VALUE_HIGH);
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