/*****************************************************************************/
/*****************************************************************************/
/**********************    Author : Mohamed Aburehab    **********************/
/**********************    Layer  : MCAL                **********************/
/**********************    SWD    : UART                **********************/
/**********************    Version: 1.0                 **********************/
/*****************************************************************************/
/*****************************************************************************/

#ifndef UART_PRIVATE_H_
#define UART_PRIVATE_H_

typedef struct 
{
    volatile u32 SR     ;       /* Status register */
    volatile u32 DR     ;       /* Data register */
    volatile u32 BRR    ;       /* Baud rate register */
    volatile u32 CR1    ;       /* Control register 1 */
    volatile u32 CR2    ;       /* Control register 2 */
    volatile u32 CR3    ;       /* Control register 3 */
    volatile u32 GTPR   ;       /* Guard time and prescaler register */

} MUART_Type;

#define MUART1 ((volatile MUART_Type*) 0x40013800)


#endif