/*Guard File*/

#ifndef STD_TYPES_H_
#define STD_TYPES_H_


/* Unsigned Types */
typedef unsigned char       u8;
typedef unsigned short int  u16;
typedef unsigned long int   u32;
typedef unsigned long long  u64;

/* Signed Types */
typedef signed char         s8;
typedef signed short int    s16;
typedef signed long int     s32;
typedef signed long long    s64;

/* Pointer Types for Unsigned Types */
typedef unsigned char*       pu8;
typedef unsigned short int*  pu16;
typedef unsigned long int*   pu32;
typedef unsigned long long*  pu64;

/* Define the Pointer to NULL */
#define NULL ((void *)0)



#endif