/************************************************************************************/
/*  Author  : Ahmed Mohey                                                           */
/*  Version : v01                                                                   */
/*  Date    : 20 Oct 2023                                                           */
/************************************************************************************/
#ifndef STD_TYPES_H
#define STD_TYPES_H

typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned long  int u32;

typedef signed char s8;
typedef signed short int s16;
typedef signed long  int s32;

typedef float  f32;
typedef double f64;

typedef unsigned char* pu8;
typedef unsigned short int* pu16;
typedef unsigned long  int* pu32;

#define STD_TYPES_OK   1
#define STD_TYPES_NOK  0

#define NULL      ((void*)0)   

#endif