/*****************************************************************************/
/*****************************************************************************/
/**********************    Author : Mohamed Aburehab    **********************/
/**********************    Layer  : MCAL                **********************/
/**********************    SWD    : SPI                 **********************/
/**********************    Version: 1.0                 **********************/
/*****************************************************************************/
/*****************************************************************************/

#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_

typedef struct 
{
    volatile u32 CR1        ;
    volatile u32 CR2        ;
    volatile u32 SR         ;
    volatile u32 DR         ;
    volatile u32 CRCPR      ;
    volatile u32 RXCRCR     ;
    volatile u32 TXCRCR     ;
    volatile u32 I2SCFGR    ;
    volatile u32 I2SPR      ;

}SPI_Register;

#define MSPI1       ((SPI_Register*)0x40013000)

/* Bits names macros */
#define MSPI1_CR1_DFF                   11              // Data frame format
#define MSPI1_CR1_LSBFIRST              7               // Frame transfer format
#define MSPI1_CR1_SPE                   6               // SPI enable
#define MSPI1_CR1_BR_MASK               0xFFFFFFC7      // SPI BAUD_RATE MASK
#define MSPI1_CR1_MSTR                  2               // Master selection
#define MSPI1_CR1_CPOL                  1               // Clock polarity
#define MSPI1_CR1_CPHA                  0               // Clock phase
/* configurations macros */
#define MSPI1_8_BIT                     0
#define MSPI1_16_BIT                    1

#define MSPI1_MSB_FIRST                 0
#define MSPI1_LSB_FIRST                 1

#define MSPI1_BAUD_RATE_DIV_2           0
#define MSPI1_BAUD_RATE_DIV_4           1
#define MSPI1_BAUD_RATE_DIV_8           2
#define MSPI1_BAUD_RATE_DIV_16          3
#define MSPI1_BAUD_RATE_DIV_32          4
#define MSPI1_BAUD_RATE_DIV_64          5
#define MSPI1_BAUD_RATE_DIV_128         6
#define MSPI1_BAUD_RATE_DIV_256         7

#define MSPI1_SLAVE                     0
#define MSPI1_MASTER                    1

#define MSPI1_CLOCK_POLARITY_LOW        0
#define MSPI1_CLOCK_POLARITY_HIGH       1

#define MSPI1_CLOCK_PHASE_READ_FIRST    0
#define MSPI1_CLOCK_PHASE_WRITE_FIRST   1

#endif