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

typedef float f32;
typedef double f64;


/* define the pointer to NULL */
#define NULL ((void *)0)

/* defining Error states */
typedef enum {
    no_error,
    ERROR_nullPointer,
    ERROR_wrongChannelID,
    ERROR_wrongPortID,
    ERROR_wrongPinDirection,
    ERROR_wrongPinModeParameter,
	ERROR_wrongPinNumber

}tenuErrorStatus;


#define ROM_BASE                        (0x00000000UL)
#define RAM_BASE                        (0x20000000UL)
#define Peripherals_Alias_Base          (0x42000000UL)
#define Peripherals_BASE                (0x40000000UL)
#define Internal_Peripherals_Base       (0xE0000000UL)


#define Peripheral_BitBand(Register, Bit) (*((volatile u32*)(Peripherals_Alias_Base + (((((u32)&(Register)))-Peripherals_BASE)*(32))+ (Bit*(4)))))


#endif
