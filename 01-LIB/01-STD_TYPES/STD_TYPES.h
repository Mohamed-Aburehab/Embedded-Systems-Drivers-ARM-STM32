/*****************************************************************************/
/*****************************************************************************/
/**********************    Author : Mohamed Aburehab    **********************/
/**********************    Layer  : LIB                 **********************/
/**********************    SWD    : STD TYPES           **********************/
/**********************    Version: 2.0                 **********************/
/*****************************************************************************/
/*****************************************************************************/

#ifndef STD_TYPES_H_
#define STD_TYPES_H_

// Standard Types
typedef unsigned char           u8;
typedef unsigned short int      u16;
typedef unsigned long int       u32;

typedef signed char             s8;
typedef signed short int        s16;
typedef signed long int         s32;

// Error States
#define NO_ERROR 1
#define ERROR_WRONG_FUNCTION_ARGUMENTS 2
#define ERROR_NULL_POINTER 3
#define ERROR_TIMEOUT 4
#define BUSY_FUNCTION 5 

#define NULL 0

#endif