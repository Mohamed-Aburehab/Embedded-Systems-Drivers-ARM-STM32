/*****************************************************************************/
/*****************************************************************************/
/**********************    Author : Mohamed Aburehab    **********************/
/**********************    Layer  : MCAL                **********************/
/**********************    SWD    : RCC                 **********************/
/**********************    Version: 1.0                 **********************/
/*****************************************************************************/
/*****************************************************************************/

#ifndef RCC_CONFIG_H_
#define RCC_CONFIG_H_
/*Options : 
                RCC_HSE_CRYSTAL
                RCC_HSE_RC
                RCC_HSI
                RCC_PLL
*/
#define RCC_CLOCK_TYPE              RCC_HSE_CRYSTAL

//! Select value only if you have RCC_PLL as input clock
#if RCC_CLOCK_TYPE == RCC_PLL
/*Options : 
                RCC_PLL_IN_HSI_DIV_2
                RCC_PLL_IN_HSE_DIV_2
                RCC_PLL_IN_HSE
*/
#define RCC_PLL_INPUT               RCC_PLL_IN_HSE_DIV_2

/*Options : [2 to 16]
*/
#define RCC_PLL_MUL_VAL             4
#endif



#endif