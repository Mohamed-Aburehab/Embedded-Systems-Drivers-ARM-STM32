/*****************************************************************************/
/*****************************************************************************/
/**********************    Author : Mohamed Aburehab    **********************/
/**********************    Layer  : HAL                 **********************/
/**********************    SWD    : TFT                 **********************/
/**********************    Version: 2.0                 **********************/
/*****************************************************************************/
/*****************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "STK_interface.h"
#include "SPI_interface.h"

#include "TFT_interface.h"
#include "TFT_private.h"
#include "TFT_config.h"

void HTFT_voidInitialize(void){
    /* Reset Pulse */
    MGPIO_voidSetPinValue(TFT_RST_PIN, MGPIO_VALUE_HIGH);
    MSTK_voidSetBusyWait(100);
    MGPIO_voidSetPinValue(TFT_RST_PIN, MGPIO_VALUE_LOW);
    MSTK_voidSetBusyWait(1);
    MGPIO_voidSetPinValue(TFT_RST_PIN, MGPIO_VALUE_HIGH);
    MSTK_voidSetBusyWait(100);
    MGPIO_voidSetPinValue(TFT_RST_PIN, MGPIO_VALUE_LOW);
    MSTK_voidSetBusyWait(100);
    MGPIO_voidSetPinValue(TFT_RST_PIN, MGPIO_VALUE_HIGH);
    MSTK_voidSetBusyWait(120000);

    /* Sleep out command */
    voidWriteCommand(0x11);

    /* Delay for 150ms */
    MSTK_voidSetBusyWait(150000);

    /* Color mode command */
    voidWriteCommand(0x3A);
    voidWriteData(0x05);

    /* Display out */
    voidWriteCommand(0x29);

}

void HTFT_voidDisplayImage(const u16* Copy_Image){
	u16 Local_u8Counter;
	u8 Local_u8Data;

	/* Set X Address */
	voidWriteCommand(0x2A);
	voidWriteData(0);
	voidWriteData(0);
	voidWriteData(0);
	voidWriteData(127);
	
	/* Set Y Address */
	voidWriteCommand(0x2B);
	voidWriteData(0);
	voidWriteData(0);
	voidWriteData(0);
	voidWriteData(159);

	/* RAM Write */
	voidWriteCommand(0x2C);

	for(Local_u8Counter = 0; Local_u8Counter < NUMBER_OF_PIXLES ;Local_u8Counter++)
	{
		Local_u8Data = Copy_Image[Local_u8Counter] >> 8;

		/* Write the high byte */
		voidWriteData(Local_u8Data);
		/* Write the low byte */
		Local_u8Data = Copy_Image[Local_u8Counter] & 0x00ff;
		voidWriteData(Local_u8Data);
	}

}

void HTFT_voidFillColor(u16 Copy_u16Color){
	u16 Local_u8Counter;
	u8 Local_u8Data;

	/* Set X Address */
	voidWriteCommand(0x2A);
	voidWriteData(0);
	voidWriteData(0);
	voidWriteData(0);
	voidWriteData(127);
	
	/* Set Y Address */
	voidWriteCommand(0x2B);
	voidWriteData(0);
	voidWriteData(0);
	voidWriteData(0);
	voidWriteData(159);

	/* RAM Write */
	voidWriteCommand(0x2C);

	for(Local_u8Counter = 0; Local_u8Counter < NUMBER_OF_PIXLES ;Local_u8Counter++)
	{
		Local_u8Data = Copy_u16Color >> 8;

		/* Write the high byte */
		voidWriteData(Local_u8Data);
		/* Write the low byte */
		Local_u8Data = Copy_u16Color & 0x00ff;
		voidWriteData(Local_u8Data);
	}

}

void HTFT_voidDrawRect(u8 x1, u8 x2, u8 y1, u8 y2, u16 Copy_u16Color){
	u16 Local_u8Counter;
	u8 Local_u8Data;

	/* Set X Address */
	voidWriteCommand(0x2A);
	voidWriteData(0);
	voidWriteData(x1);
	voidWriteData(0);
	voidWriteData(x2);
	
	/* Set Y Address */
	voidWriteCommand(0x2B);
	voidWriteData(0);
	voidWriteData(y1);
	voidWriteData(0);
	voidWriteData(y2);

	/* RAM Write */
	voidWriteCommand(0x2C);
	u16 Local_u16Size = (x2 - x1)* (y2 - y1);
	for(Local_u8Counter = 0; Local_u8Counter < Local_u16Size ;Local_u8Counter++)
	{
		Local_u8Data = Copy_u16Color >> 8;

		/* Write the high byte */
		voidWriteData(Local_u8Data);
		/* Write the low byte */
		Local_u8Data = Copy_u16Color & 0x00ff;
		voidWriteData(Local_u8Data);
	}

}


static void voidWriteCommand(u8 Copy_u8Command){
    /* Set A0 to low */ 
    u8 Local_u8Temp;
    MGPIO_voidSetPinValue(TFT_A0_PIN, MGPIO_VALUE_LOW);
    MSPI1_voidSendReceiveSynch(Copy_u8Command, &Local_u8Temp);
}

static void voidWriteData(u8 Copy_u8Data){
    /* Set A0 to high */ 
    u8 Local_u8Temp;
    MGPIO_voidSetPinValue(TFT_A0_PIN, MGPIO_VALUE_HIGH);
    MSPI1_voidSendReceiveSynch(Copy_u8Data, &Local_u8Temp);
}