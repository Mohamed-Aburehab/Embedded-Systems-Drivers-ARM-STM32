/*****************************************************************************/
/*****************************************************************************/
/**********************    Author : Mohamed Aburehab    **********************/
/**********************    Layer  : MCAL                **********************/
/**********************    SWD    : SPI                 **********************/
/**********************    Version: 1.0                 **********************/
/*****************************************************************************/
/*****************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_config.h"

void MSPI1_voidInit(void){

    MSPI1->CR1 = MSPI1->CR1 & MSPI1_CR1_BR_MASK;
    MSPI1->CR1 = MSPI1->CR1 | MSPI1_BAUD_RATE;

    #if MSPI1_CONNECTION_CONFIGURATION == MSPI1_MASTER
        SET_BIT(MSPI1->CR1, MSPI1_CR1_MSTR);
    #elif MSPI1_CONNECTION_CONFIGURATION == MSPI1_SLAVE
        CLR_BIT(MSPI1->CR1, MSPI1_CR1_MSTR);
    #else
        #error wrong configuration parameter
    #endif

    #if MSPI1_DATA_FRAME_FORMAT        == MSPI1_8_BIT
        CLR_BIT(MSPI1->CR1, MSPI1_CR1_DFF);
    #elif   MSPI1_DATA_FRAME_FORMAT    == MSPI1_16_BIT
        SET_BIT(MSPI1->CR1, MSPI1_CR1_DFF);
    #else
        #error wrong configuration parameter
    #endif

    #if MSPI1_DATA_TRANSFER_FORMAT     == MSPI1_MSB_FIRST
        CLR_BIT(MSPI1->CR1, MSPI1_CR1_LSBFIRST);
    #elif
        SET_BIT(MSPI1->CR1, MSPI1_CR1_LSBFIRST);
    #else
        #error wrong configuration parameter
    #endif

    #if MSPI1_CLOCK_POLARITY           == MSPI1_CLOCK_POLARITY_HIGH
        SET_BIT(MSPI1->CR1, MSPI1_CR1_CPOL);
    #elif
        CLR_BIT(MSPI1->CR1, MSPI1_CR1_CPOL);
    #else
        #error wrong configuration parameter
    #endif

    #if MSPI1_CLOCK_PHASE              == MSPI1_CLOCK_PHASE_WRITE_FIRST
        SET_BIT(MSPI1->CR1, MSPI1_CR1_CPHA);
    #elif
        CLR_BIT(MSPI1->CR1, MSPI1_CR1_CPHA);
    #else
        #error wrong configuration parameter
    #endif
    SET_BIT(MSPI1->CR1, MSPI1_CR1_SPE);
    SET_BIT(MSPI1->CR1, 8);
    SET_BIT(MSPI1->CR1, 9);

}

/**
 * @brief This function is used to send and receive data using SPI1 peripheral.
 * 
 * @param Copy_u8DataToTransmit The data to be transmitted.
 * @param Copy_u8DataToReceive a pointer to u8 to save the received data into it.
 */
void MSPI1_voidSendReceiveSynch(u8 Copy_u8DataToTransmit, u8 * Copy_u8DataToReceive){

	/* Clear For Slave Select Pin */
	MGPIO_voidSetPinValue(MSPI1_SLAVE_PORT_AND_PIN,MGPIO_VALUE_LOW);
    /* Send data */
    MSPI1->DR = Copy_u8DataToTransmit;
    /* Wait busy flag to finish */
    while(( GET_BIT(MSPI1->SR, 7) ==1 )) ;

    /* Return to received data */
    *Copy_u8DataToReceive = MSPI1->DR;
    
	/* Set Salve Select Pin */
	MGPIO_voidSetPinValue(MSPI1_SLAVE_PORT_AND_PIN,MGPIO_VALUE_HIGH);

}
