/*****************************************************************************/
/*****************************************************************************/
/**********************    Author : Mohamed Aburehab    **********************/
/**********************    Layer  : MCAL                **********************/
/**********************    SWD    : UART                **********************/
/**********************    Version: 1.0                 **********************/
/*****************************************************************************/
/*****************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "UART_interface.h"
#include "UART_private.h"
#include "UART_config.h"

void MUART1_voidInit(void){
	/*	baud rate = 9600 */
	MUART1->BRR = 0x341;

	SET_BIT((MUART1->CR1), 3);			/* Enabling Transmitter */
	SET_BIT((MUART1->CR1), 2);			/* Enabling Receiver */
	SET_BIT((MUART1->CR1), 13);			/* Enabling USART */
	
	MUART1->SR = 0;						/* Clearing status register */

}

void MUART1_voidTransmit(u8 arr[]){
	u8 i = 0;
	while(arr[i] != '\0'){
		MUART1->DR = arr[i];
		while( GET_BIT(MUART1->SR, 6) == 0);
		i++;
		CLR_BIT(MUART1->SR, 6);
	}

}

u8 MUART1_u8Receive(void){
	u8 Loc_u8ReceivedData = 0;
	while((GET_BIT((MUART1->SR), 5)) == 0);
	Loc_u8ReceivedData = MUART1->DR;
	return (Loc_u8ReceivedData);

}
