#ifndef RCC_PRV_H
#define RCC_PRV_H


#define MRCC_BASE_ADDRESS     0x40023800




#define CSSON   19U


typedef struct
{
  volatile u32 CR;             
  volatile u32 PLLCFGR;       
  volatile u32 CFGR;          
  volatile u32 CIR;           
  volatile u32 AHB1RSTR;      
  volatile u32 AHB2RSTR;      
  volatile u32 RESERVED0;      
  volatile u32 RESERVED1;     
  volatile u32 APB1RSTR;      
  volatile u32 APB2RSTR;      
  volatile u32 RESERVED2[2];  
  volatile u32 AHB1ENR;       
  volatile u32 AHB2ENR;       
  volatile u32 RESERVED3;        
  volatile u32 RESERVED4;     
  volatile u32 APB1ENR;       
  volatile u32 APB2ENR;       
  volatile u32 RESERVED5[2];  
  volatile u32 AHB1LPENR;     
  volatile u32 AHB2LPENR;     
  volatile u32 RESERVED6;      
  volatile u32 RESERVED7;     
  volatile u32 APB1LPENR;     
  volatile u32 APB2LPENR;     
  volatile u32 RESERVED8[2];  
  volatile u32 BDCR;          
  volatile u32 CSR;           
  volatile u32 RESERVED9[2];  
  volatile u32 SSCGR;         
  volatile u32 PLLI2SCFGR;    
  volatile u32 RESERVED10[1];  
  volatile u32 DCKCFGR;       
}RCC_T;


#define    MRCC     ((volatile RCC_T *) (MRCC_BASE_ADDRESS))



#endif