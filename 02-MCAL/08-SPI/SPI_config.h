/*****************************************************************************/
/*****************************************************************************/
/**********************    Author : Mohamed Aburehab    **********************/
/**********************    Layer  : MCAL                **********************/
/**********************    SWD    : SPI                 **********************/
/**********************    Version: 1.0                 **********************/
/*****************************************************************************/
/*****************************************************************************/

#ifndef SPI_CONFIG_H_
#define SPI_CONFIG_H_

#define MSPI1_CONNECTION_CONFIGURATION  MSPI1_MASTER
#define MSPI1_DATA_FRAME_FORMAT         MSPI1_8_BIT
#define MSPI1_DATA_TRANSFER_FORMAT      MSPI1_MSB_FIRST
#define MSPI1_BAUD_RATE                 MSPI1_BAUD_RATE_DIV_2
#define MSPI1_CLOCK_POLARITY            MSPI1_CLOCK_POLARITY_HIGH
#define MSPI1_CLOCK_PHASE               MSPI1_CLOCK_PHASE_WRITE_FIRST

#define MSPI1_SLAVE_PORT_AND_PIN        MGPIO_PORT_A,MGPIO_PIN_0

#endif