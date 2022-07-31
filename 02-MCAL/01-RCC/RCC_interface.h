/*****************************************************************************/
/*****************************************************************************/
/**********************    Author : Mohamed Aburehab    **********************/
/**********************    Layer  : MCAL                **********************/
/**********************    SWD    : RCC                 **********************/
/**********************    Version: 1.0                 **********************/
/*****************************************************************************/
/*****************************************************************************/

#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_

/* Buses Macro */
#define RCC_AHB                    0
#define RCC_APB1                   1
#define RCC_APB2                   2

/* Peripherals Bus Macro */
#define RCC_APB2_AFIO              0    // Alternate function IO clock
#define RCC_APB2_IOPA              2    // IO port A clock 
#define RCC_APB2_IOPB              3    // IO port B clock 
#define RCC_APB2_IOPC              4    // IO port C clock 

/**
 * @brief It enables the clock of a peripheral by setting the corresponding bit in the corresponding register
 * @param Copy_u8BusId The bus you want to enable the clock for.
 * @param Copy_u8PeripheralId The peripheral ID 
 */
void RCC_voidEnableClock(u8 Copy_u8BusId, u8 Copy_u8PeripheralId);

/**
 * @brief It takes a bus ID and a peripheral ID and disables the clock for that peripheral
 * @param Copy_u8BusId The bus you want to enable the clock for.
 * @param Copy_u8PeripheralId The peripheral ID.
 */
void RCC_voidDisableClock(u8 Copy_u8BusId, u8 Copy_u8PeripheralId);

/**
* @brief A function that initializes the system clock.
*/
void RCC_voidInitSysClock(void);
#endif