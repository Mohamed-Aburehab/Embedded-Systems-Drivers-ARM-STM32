/*****************************************************************************/
/*****************************************************************************/
/**********************    Author : Mohamed Aburehab    **********************/
/**********************    Layer  : MCAL                **********************/
/**********************    SWD    : NVIC                **********************/
/**********************    Version: 1.0                 **********************/
/*****************************************************************************/
/*****************************************************************************/

#ifndef NVIC_PRIVATE_H_
#define NVIC_PRIVATE_H_

                            /* Register Definitions */
/* Enable External Interrupts from 0 to 31 register */
#define NVIC_ISER0                      *((volatile u32*) 0xE000E100) 

/* Enable External Interrupts from 32 to 63 register */
#define NVIC_ISER1                      *((volatile u32*) 0xE000E104) 

/* Disable External Interrupts from 0 to 31 register */
#define NVIC_ICER0                      *((volatile u32*) 0xE000E180) 

/* Disable External Interrupts from 32 to 63 register */
#define NVIC_ICER1                      *((volatile u32*) 0xE000E184) 

/* Set Pending Flag for Interrupts from 0 to 31 register */
#define NVIC_ISPR0                      *((volatile u32*) 0xE000E200) 

/* Set Pending Flag for Interrupts from 32 to 63 register */
#define NVIC_ISPR1                      *((volatile u32*) 0xE000E204) 

/* Clear Pending Flag for Interrupts from 0 to 31 register */
#define NVIC_ICPR0                      *((volatile u32*) 0xE000E280) 

/* Clear Pending Flag for Interrupts from 32 to 63 register */
#define NVIC_ICPR1                      *((volatile u32*) 0xE000E284)

/* Active Bit Flag for Interrupts from 0 to 31 register */
#define NVIC_IABR0                      *((volatile u32*) 0xE000E300) 

/* Active Bit Flag for Interrupts from 32 to 63 register */
#define NVIC_IABR1                      *((volatile u32*) 0xE000E304) 

/* Interrupt priority registers */
#define NVIC_IPR                        ((volatile u8*) 0xE000E400)

#endif