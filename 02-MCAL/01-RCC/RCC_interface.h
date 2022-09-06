/*****************************************************************************/
/*****************************************************************************/
/**********************    Author : Mohamed Aburehab    **********************/
/**********************    Layer  : MCAL                **********************/
/**********************    SWD    : RCC                 **********************/
/**********************    Version: 2.0                 **********************/
/*****************************************************************************/
/*****************************************************************************/

#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_

/* Buses Macro */
#define MRCC_AHB                    0
#define MRCC_APB1                   1
#define MRCC_APB2                   2

/* Peripherals Bus Macro */
#define MRCC_APB2_AFIO              0    // Alternate function IO clock
#define MRCC_APB2_IOPA              2    // IO port A clock 
#define MRCC_APB2_IOPB              3    // IO port B clock 
#define MRCC_APB2_IOPC              4    // IO port C clock 

/**
 * @brief It enables the clock of a peripheral by setting the corresponding bit in the corresponding register
 * @param Copy_u8BusId The bus you want to enable the clock for.
 * @param Copy_u8PeripheralId The peripheral ID 
 */
void MRCC_voidEnableClock(u8 Copy_u8BusId, u8 Copy_u8PeripheralId);

/**
 * @brief It takes a bus ID and a peripheral ID and disables the clock for that peripheral
 * @param Copy_u8BusId The bus you want to enable the clock for.
 * @param Copy_u8PeripheralId The peripheral ID.
 */
void MRCC_voidDisableClock(u8 Copy_u8BusId, u8 Copy_u8PeripheralId);

/**
* @brief A function that initializes the system clock.
*/
void MRCC_voidInitSysClock(void);
#endif