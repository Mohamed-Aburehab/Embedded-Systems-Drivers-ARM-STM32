/*****************************************************************************/
/*****************************************************************************/
/**********************    Author : Mohamed Aburehab    **********************/
/**********************    Layer  : MCAL                **********************/
/**********************    SWD    : DMA                 **********************/
/**********************    Version: 1.0                 **********************/
/*****************************************************************************/
/*****************************************************************************/

#ifndef DMA_PRIVATE_H_
#define DMA_PRIVATE_H_

typedef struct
{
    volatile u32 CCR;           /* DMA channel x configuration register */
    volatile u32 CNDTR;         /* DMA channel x number of data register */
    volatile u32 CPAR;          /* DMA channel x peripheral address register */
    volatile u32 CMAR;          /* DMA channel x memory address register */
    volatile u32 RESERVED;      /* Reserved memory location */
} DMA_Channel;



typedef struct
{
    volatile u32 ISR;           /* DMA interrupt status register */
    volatile u32 IFCR;          /* DMA interrupt flag clear register */
    DMA_Channel Channel[7];
}DMA_t;


#define DMA         ((volatile DMA_t *) 0x40020000)


#endif