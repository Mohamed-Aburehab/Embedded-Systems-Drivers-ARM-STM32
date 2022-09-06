/*****************************************************************************/
/*****************************************************************************/
/**********************    Author : Mohamed Aburehab    **********************/
/**********************    Layer  : MCAL                **********************/
/**********************    SWD    : AFIO                **********************/
/**********************    Version: 1.0                 **********************/
/*****************************************************************************/
/*****************************************************************************/

#ifndef AFIO_INTERFACE_H_
#define AFIO_INTERFACE_H_

/*AFIO EXTI Port Map Configuration*/
#define MAFIO_EXTI_PORTA_CONFIG             0
#define MAFIO_EXTI_PORTB_CONFIG             1
#define MAFIO_EXTI_PORTC_CONFIG             2

/**
 * It takes a line number and a port map and sets the port map for that line in the
 * EXTI configuration register
 * 
 * @param Copy_u8Line The line number of the interrupt.
 * @param Copy_u8PortMap The port you want to map to the EXTI line.
 */
void MAFIO_voidSetEXTIConfiguration(u8 Copy_u8Line, u8 Copy_u8PortMap);

#endif