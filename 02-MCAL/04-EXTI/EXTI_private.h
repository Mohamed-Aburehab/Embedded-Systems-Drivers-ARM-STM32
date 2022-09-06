/*****************************************************************************/
/*****************************************************************************/
/**********************    Author : Mohamed Aburehab    **********************/
/**********************    Layer  : MCAL                **********************/
/**********************    SWD    : EXTI                **********************/
/**********************    Version: 1.0                 **********************/
/*****************************************************************************/
/*****************************************************************************/

#ifndef EXTI_PRIVATE_H_
#define EXTI_PRIVATE_H_

                            /* Register Definitions */
typedef struct 
{
    volatile u32 IMR;   /* Interrupt mask register */
    volatile u32 EMR;   /* Event mask register */
    volatile u32 RTSR;  /* Rising trigger selection register */
    volatile u32 FTSR;  /* Falling trigger selection register  */
    volatile u32 SWIER; /* Software interrupt event register */
    volatile u32 PR;    /* Pending register */
}EXTI_t;

#define EXTI        ((volatile EXTI_t*) 0x40010400)

/*EXTI Intial states*/
#define EXTI_DISABLE        0
#define EXTI_ENABLE         1

#endif