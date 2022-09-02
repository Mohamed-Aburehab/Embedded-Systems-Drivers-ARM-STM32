/*****************************************************************************/
/*****************************************************************************/
/**********************    Author : Mohamed Aburehab    **********************/
/**********************    Layer  : LIB                 **********************/
/**********************    SWD    : BIT MATH            **********************/
/**********************    Version: 2.0                 **********************/
/*****************************************************************************/
/*****************************************************************************/

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

/* Setting the bit to 1. */
#define SET_BIT(VAR,BIT)        ((VAR) |=  (1 << (BIT)))
/* Clearing the bit. */
#define CLR_BIT(VAR,BIT)        ((VAR) &= ~(1 << (BIT)))
/* Getting the value of the bit in the variable VAR at the position BIT. */
#define GET_BIT(VAR,BIT)        (((VAR) >> (BIT)) & 1)
/* Toggling the bit. */
#define TOG_BIT(VAR,BIT)        ((VAR) ^=  (1 << (BIT)))

#endif