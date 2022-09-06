/*****************************************************************************/
/*****************************************************************************/
/**********************    Author : Mohamed Aburehab    **********************/
/**********************    Layer  : MCAL                **********************/
/**********************    SWD    : RCC                 **********************/
/**********************    Version: 2.0                 **********************/
/*****************************************************************************/
/*****************************************************************************/

#ifndef RCC_CONFIG_H_
#define RCC_CONFIG_H_
/*Options : 
                MRCC_HSE_CRYSTAL
                MRCC_HSE_RC
                MRCC_HSI
                MRCC_PLL
*/
#define MRCC_CLOCK_TYPE              MRCC_HSE_CRYSTAL

//! Select value only if you have MRCC_PLL as input clock
#if MRCC_CLOCK_TYPE == MRCC_PLL
/*Options : 
                MRCC_PLL_IN_HSI_DIV_2
                MRCC_PLL_IN_HSE_DIV_2
                MRCC_PLL_IN_HSE
*/
#define MRCC_PLL_INPUT               MRCC_PLL_IN_HSE_DIV_2

/*Options : [2 to 16]
*/
#define MRCC_PLL_MUL_VAL             4
#endif



#endif