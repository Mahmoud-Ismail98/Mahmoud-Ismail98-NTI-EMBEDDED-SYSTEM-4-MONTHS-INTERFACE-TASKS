/*Guard File*/

#ifndef STD_TYPES_H_
#define STD_TYPES_H_


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



/*  Unsigned Type  */

typedef unsigned char*       pu8;
typedef unsigned short int*  pu16;
typedef unsigned long int*   pu32;
typedef unsigned long long*  pu64;

typedef double f32;

/* define the pointer to NULL */
#define NULL ((void *)0)

/*The ISR*/
#define ISR(x)  void x (void) __attribute__((signal)); \
void x (void)

# define GIE()  __asm__ __volatile__ ("sei" ::)
# define GID()  __asm__ __volatile__ ("cli" ::)


#endif