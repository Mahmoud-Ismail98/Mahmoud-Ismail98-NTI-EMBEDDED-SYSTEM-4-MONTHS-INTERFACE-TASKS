/*
 * std_types.h
 *
 *  Created on: Oct 19, 2023
 *      Author: Ahmed Dwidar
 */

#ifndef STD_TYPES_H_
#define STD_TYPES_H_

/*boolen data types*/
typedef unsigned char boolen;
/*boolen false value*/
#ifndef FALSE
#define FALSE  (0)
#endif
/*boolen true value*/
#ifndef TRUE
#define TRUE  (1)
#endif

#define LOGIC_HIGH         1
#define LOGIC_LOW          0

/* define the pointer to NULL */
#define NULL   ((void*)0)

/*  Unsigned Type  */

typedef unsigned char       u8;
typedef unsigned short int  u16;
typedef unsigned long int   u32;
typedef unsigned long long  u64;


/* Signed Type */

typedef signed char         s8;
typedef signed short int    s16;
typedef signed long int     s32;
typedef signed long long    s64;
typedef float               f32;
typedef double              f64;


/*  Unsigned Type  */

typedef unsigned char*       pu8;
typedef unsigned short int*  pu16;
typedef unsigned long int*   pu32;
typedef unsigned long long*  pu64;

#endif /* STD_TYPES_H_ */
