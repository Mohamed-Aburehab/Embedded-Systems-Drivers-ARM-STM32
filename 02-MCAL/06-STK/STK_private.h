/*****************************************************************************/
/*****************************************************************************/
/**********************    Author : Mohamed Aburehab    **********************/
/**********************    Layer  : MCAL                **********************/
/**********************    SWD    : SysTick (STK)       **********************/
/**********************    Version: 1.0                 **********************/
/*****************************************************************************/
/*****************************************************************************/

#ifndef STK_PRIVATE_H_
#define STK_PRIVATE_H_

                            /* Register Definitions */
/*control and status register*/
#define STK_CTRL                *((volatile u32*) 0xE000E010)
#define STK_CTRL_COUNTFLAG      16  // Returns 1 when under flow happens.
#define STK_CTRL_CLKSOURCE      2   // Clock source selection.
#define STK_CTRL_TICKINT        1   // SysTick interrupt enable.
#define STK_CTRL_ENABLE         0   // Enable Peripheral.
/*reload value register*/
#define STK_LOAD                *((volatile u32*) 0xE000E014)
/*current value register*/
#define STK_VAL                 *((volatile u32*) 0xE000E018)
/*calibration value register*/
#define STK_CALIB               *((volatile u32*) 0xE000E01C)


                            /* Configurations MACROS */
/*STK CLOCK SOURCE*/
#define STK_CLOCK_AHB                           0
#define STK_CLOCK_AHB_Divided_BY_8              1

/*STK INTERRUPT OPTION*/
#define STK_INTERRUPT_DISABLE                   0
#define STK_INTERRUPT_ENABLE                    1

#define STK_INTERRUPT_SOURCE_INTERVAL_SINGLE    1
#define STK_INTERRUPT_SOURCE_INTERVAL_PERIODIC  2


#endif