/*****************************************************************************/
/*****************************************************************************/
/**********************    Author : Mohamed Aburehab    **********************/
/**********************    Layer  : MCAL                **********************/
/**********************    SWD    : RCC                 **********************/
/**********************    Version: 1.0                 **********************/
/*****************************************************************************/
/*****************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"

/**
 * It enables the clock of a peripheral by setting the corresponding bit in the corresponding register
 * 
 * @param Copy_u8BusId The bus you want to enable the clock for.
 * @param Copy_u8PeripheralId The peripheral ID 
 */
void RCC_voidEnableClock(u8 Copy_u8BusId, u8 Copy_u8PeripheralId){
    if(Copy_u8PeripheralId <= 31){

        switch(Copy_u8BusId){
            case RCC_AHB : SET_BIT(RCC_AHBENR,  Copy_u8PeripheralId);   break; 
            case RCC_APB1: SET_BIT(RCC_APB1ENR, Copy_u8PeripheralId);   break;
            case RCC_APB2: SET_BIT(RCC_APB2ENR, Copy_u8PeripheralId);   break;
            // default      : /* Return Error */ break;
        }

    }else {
        /* return error */
    }
}


/**
 * It takes a bus ID and a peripheral ID and disables the clock for that peripheral
 * 
 * @param Copy_u8BusId The bus you want to enable the clock for.
 * @param Copy_u8PeripheralId The peripheral ID.
 */
void RCC_voidDisableClock(u8 Copy_u8BusId, u8 Copy_u8PeripheralId){
    if(Copy_u8PeripheralId <= 31){

        switch(Copy_u8BusId){
            case RCC_AHB : CLR_BIT(RCC_AHBENR,  Copy_u8PeripheralId);   break; 
            case RCC_APB1: CLR_BIT(RCC_APB1ENR, Copy_u8PeripheralId);   break;
            case RCC_APB2: CLR_BIT(RCC_APB2ENR, Copy_u8PeripheralId);   break;
            // default      : /* Return Error */ break;
        }

    }else {
        /* return error */
    }
}

void RCC_voidInitSysClock(void){
    #if RCC_CLOCK_TYPE   == RCC_HSE_CRYSTAL
        RCC_CR   = 0x00010000; /* Enable HSI with no bypass (crystal)  */
        RCC_CFGR = 0x00000001; /* Select System clock as HSE */
    #elif RCC_CLOCK_TYPE == RCC_HSE_RC
        RCC_CR   = 0x00050000; /* Enable HSI with bypass (RC) */
        RCC_CFGR = 0x00000001; /* Select System clock as HSE */
    #elif RCC_CLOCK_TYPE == RCC_HSI
        RCC_CR   = 0x00000081; /* Enable HSI + Trimming = 0 */
        RCC_CFGR = 0x00000000; /* Select System clock as HSI */
    #elif RCC_CLOCK_TYPE == RCC_PLL
        RCC_CFGR &= 0xFFC3FFFF ; /* Masking multiplication factor bits */
        RCC_CFGR |= RCC_PLL_MUL_VAL << 18; /* Setting Multiplication factor */
        #if   RCC_PLL_INPUT == RCC_PLL_IN_HSI_DIV_2
            CLR_BIT(RCC_CFGR, RCC_CFGR_PLLSRC); /* Selecting HSI clock/2 as source clock */
            SET_BIT(RCC_CR, RCC_CR_PLLON); /* Enabling PLL */
        #elif RCC_PLL_INPUT == RCC_PLL_IN_HSE_DIV_2
            SET_BIT(RCC_CFGR, RCC_CFGR_PLLSRC); /* Selecting HSE as source clock */
            SET_BIT(RCC_CFGR, RCC_CFGR_PLLXTPRE); /* Dividing HSE Clock By 2 */
            SET_BIT(RCC_CR, RCC_CR_PLLON); /* Enabling PLL */
        #elif RCC_PLL_INPUT == RCC_PLL_IN_HSE
            SET_BIT(RCC_CFGR, RCC_CFGR_PLLSRC); /* Selecting HSE as source clock */
            CLR_BIT(RCC_CFGR, RCC_CFGR_PLLXTPRE); /* Selecting not to divide HSE clock */
            SET_BIT(RCC_CR, RCC_CR_PLLON); /* Enabling PLL */
        #endif
    #else 
        #error("You choosed Wrong Clock Type")
    #endif
}
