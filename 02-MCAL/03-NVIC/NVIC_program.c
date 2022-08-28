/*****************************************************************************/
/*****************************************************************************/
/**********************    Author : Mohamed Aburehab    **********************/
/**********************    Layer  : MCAL                **********************/
/**********************    SWD    : NVIC                **********************/
/**********************    Version: 1.0                 **********************/
/*****************************************************************************/
/*****************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"

/**
 * @brief it initializes the NVIC.
 */
void MNVIC_voidInit(){
    /* Application interrupt and reset control register */
    #define SCB_AIRCR *((u32*) 0xE000ED0C)
    SCB_AIRCR = MNVIC_GROUP_SUB_DISTRIBUTION;
}

/**
 * @brief It enables the interrupt number that is passed to it
 * 
 * @param Copy_u8IntNumber The number of the interrupt you want to enable.
 * 
 */
void MNVIC_voidEnableInterrupt(u8 Copy_u8IntNumber){
    if (Copy_u8IntNumber <= 31){
        NVIC_ISER0 = (1 << Copy_u8IntNumber);
    }else if (Copy_u8IntNumber <= 59){
        Copy_u8IntNumber -= 32;
        NVIC_ISER1 = (1<< Copy_u8IntNumber);
    }
}

/**
 * @brief It disables the interrupt number that is passed to it
 * 
 * @param Copy_u8IntNumber The number of the interrupt you want to disable.
 * 
 */
void MNVIC_voidDisableInterrupt(u8 Copy_u8IntNumber){
    if (Copy_u8IntNumber <= 31){
        NVIC_ICER0 = (1 << Copy_u8IntNumber);
    }else if (Copy_u8IntNumber <= 59){
        Copy_u8IntNumber -= 32;
        NVIC_ICER1 = (1<< Copy_u8IntNumber);
        }
}

/**
 * @brief It sets the pending flag of the interrupt number that is passed to it.
 * 
 * @param Copy_u8IntNumber The number of the interrupt you want to set pending flag for.
 */
void MNVIC_voidSetPendingFlag(u8 Copy_u8IntNumber){
    if (Copy_u8IntNumber <= 31){
        NVIC_ISPR0 = (1 << Copy_u8IntNumber);
    }else if (Copy_u8IntNumber <= 59){
        Copy_u8IntNumber -= 32;
        NVIC_ISPR1 = (1<< Copy_u8IntNumber);
        }
}

/**
 * @brief It clears the pending flag of the interrupt number passed to it
 * 
 * @param Copy_u8IntNumber The number of the interrupt you want to clear its pending flag.
 */
void MNVIC_voidClearPendingFlag(u8 Copy_u8IntNumber){
    if (Copy_u8IntNumber <= 31){
        NVIC_ICPR0 = (1 << Copy_u8IntNumber);
    }else if (Copy_u8IntNumber <= 59){
        Copy_u8IntNumber -= 32;
        NVIC_ICPR1 = (1<< Copy_u8IntNumber);
        }
}

/**
 * @brief It returns the state of the active flag of the interrupt number passed to it
 * 
 * @param Copy_u8IntNumber The number of the interrupt you want to get its active flag value.
 * 
 * @return Active flag value for the passed interrupt number
 */
u8 MNVIC_u8GetActiveFlag(u8 Copy_u8IntNumber){
    u8 Local_u8Result ;
    if (Copy_u8IntNumber <= 31){
        Local_u8Result = GET_BIT(NVIC_IABR0, Copy_u8IntNumber);
    }else if (Copy_u8IntNumber <= 59){
        Copy_u8IntNumber -= 32;
        Local_u8Result = GET_BIT(NVIC_IABR1, Copy_u8IntNumber);
        }
    return Local_u8Result;
}

/**
 * @brief It sets group priority and the subgroup priority by taking the takes the interrupt ID, 
 * the group priority and the subgroup priority and writes them to the appropriate register
 * 
 * @param Copy_u8InterruptID The interrupt number you want to set the priority for.
 * @param Copy_u8GroupPriority The priority of the group.
 * @param Copy_u8SubGroupPriority The priority of the interrupt within the group.
 */
void MNVIC_voidSetPriority(u8 Copy_u8InterruptID,u8 Copy_u8GroupPriority,u8 Copy_u8SubGroupPriority){
    if (Copy_u8InterruptID < 60){
        #if MNVIC_GROUP_SUB_DISTRIBUTION   == MNVIC_GROUP_4_SUB_0
            NVIC_IPR[Copy_u8InterruptID] = Copy_u8GroupPriority;
        #elif MNVIC_GROUP_SUB_DISTRIBUTION == MNVIC_GROUP_3_SUB_1
            NVIC_IPR[Copy_u8InterruptID] = (Copy_u8GroupPriority<<1) | Copy_u8SubGroupPriority;
        #elif MNVIC_GROUP_SUB_DISTRIBUTION == MNVIC_GROUP_2_SUB_2
            NVIC_IPR[Copy_u8InterruptID] = (Copy_u8GroupPriority<<2) | Copy_u8SubGroupPriority;
        #elif MNVIC_GROUP_SUB_DISTRIBUTION == MNVIC_GROUP_1_SUB_3
            NVIC_IPR[Copy_u8InterruptID] = (Copy_u8GroupPriority<<3) | Copy_u8SubGroupPriority;
        #elif MNVIC_GROUP_SUB_DISTRIBUTION == MNVIC_GROUP_0_SUB_4
            NVIC_IPR[Copy_u8InterruptID] = Copy_u8SubGroupPriority;
        #endif
    }else {
        // todo: return error state
    }
}