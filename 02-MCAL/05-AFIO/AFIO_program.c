/*****************************************************************************/
/*****************************************************************************/
/**********************    Author : Mohamed Aburehab    **********************/
/**********************    Layer  : MCAL                **********************/
/**********************    SWD    : AFIO                **********************/
/**********************    Version: 1.0                 **********************/
/*****************************************************************************/
/*****************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "AFIO_interface.h"
#include "AFIO_private.h"
#include "AFIO_config.h"

/**
 * It takes a line number and a port map and sets the port map for that line in the
 * EXTI configuration register
 * 
 * @param Copy_u8Line The line number of the interrupt.
 * @param Copy_u8PortMap The port you want to map to the EXTI line.
 */
void MAFIO_voidSetEXTIConfiguration(u8 Copy_u8Line, u8 Copy_u8PortMap){
    u8 Local_u8RegIndex = Copy_u8Line/4;
    Copy_u8Line = Copy_u8Line%4;

    AFIO->EXTICR[Local_u8RegIndex] &= ~((0b1111) << (Copy_u8Line * 4));
    AFIO->EXTICR[Local_u8RegIndex] |= ((Copy_u8PortMap) << (Copy_u8Line * 4));

}
