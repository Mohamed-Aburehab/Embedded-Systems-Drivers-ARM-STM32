/*****************************************************************************/
/*****************************************************************************/
/**********************    Author : Mohamed Aburehab    **********************/
/**********************    Layer  : LIB                 **********************/
/**********************    SWD    : STD TYPES           **********************/
/**********************    Version: 1.0                 **********************/
/*****************************************************************************/
/*****************************************************************************/

#ifndef STD_TYPES_H_
#define STD_TYPES_H_

// Standard Types
typedef unsigned char           u8;
typedef unsigned short int      u16;
typedef unsigned long int       u32;

typedef signed char             s8;

// Error States
#define NO_ERROR 1
#define ERROR_WRONG_FUNCTION_ARGUMENTS 2
#define ERROR_NULL_POINTER 3
#define ERROR_TIMEOUT 4
#define BUSY_FUNCTION 5 

#endif