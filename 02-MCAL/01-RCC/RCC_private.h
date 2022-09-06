/*****************************************************************************/
/*****************************************************************************/
/**********************    Author : Mohamed Aburehab    **********************/
/**********************    Layer  : MCAL                **********************/
/**********************    SWD    : RCC                 **********************/
/**********************    Version: 2.0                 **********************/
/*****************************************************************************/
/*****************************************************************************/

#ifndef RCC_PRIVATE_H_
#define RCC_PRIVATE_H_

/* Register Definitions */
#define MRCC_CR                      *((volatile u32*) 0x40021000)
#define MRCC_CR_PLLON                24
#define MRCC_CR_CSSON                19
#define MRCC_CR_HSEON                16
#define MRCC_CR_HSION                0

#define MRCC_CFGR                    *((volatile u32*) 0x40021004)
#define MRCC_CFGR_PLLXTPRE           17
#define MRCC_CFGR_PLLSRC             16

#define MRCC_CIR                     *((volatile u32*) 0x40021008)
#define MRCC_APB2RSTR                *((volatile u32*) 0x4002100C)
#define MRCC_APB1RSTR                *((volatile u32*) 0x40021010)
#define MRCC_AHBENR                  *((volatile u32*) 0x40021014)
#define MRCC_APB2ENR                 *((volatile u32*) 0x40021018)
#define MRCC_APB1ENR                 *((volatile u32*) 0x4002101C)
#define MRCC_BDCR                    *((volatile u32*) 0x40021020)
#define MRCC_CSR                     *((volatile u32*) 0x40021024)


/* config macros */
#define MRCC_ENABLE                      1
#define MRCC_DISABLE                     0

/* Clock Types */
#define MRCC_HSE_CRYSTAL                 0
#define MRCC_HSE_RC                      1
#define MRCC_HSI                         2
#define MRCC_PLL                         3

/* PLL Options */
#define MRCC_PLL_IN_HSI_DIV_2            0
#define MRCC_PLL_IN_HSE_DIV_2            1
#define MRCC_PLL_IN_HSE                  2

#endif