#ifndef BIT_UTILS_H
#define BIT_UTILS_H

#define SET_BIT(Reg,Bit)         	Reg|=(1<<Bit)
#define CLR_BIT(Reg,Bit)         	Reg&=~(1<<Bit)
#define GET_BIT(Reg,Bit)         	((Reg>>Bit)&(1))
#define RSHFT_REG(Reg,No)        	Reg=(Reg>>No)
#define LSHFT_REG(Reg,No)        	Reg=(Reg<<No)
#define CRSHFT_REG(Reg,No)       	Reg=((Reg<<No)|(Reg>>(sizeof((Reg)*8)-(No))))
#define CLSHFT_REG(Reg,No)       	Reg=((Reg>>No)|(Reg<<(sizeof((Reg)*8)-(No))))
#define ASSIGN_REG(Reg,Value)       Reg=Value
#define ASSIGN_BIT(Reg,BIT,Value)   Reg=Value
#define SET_REG(Reg)             	Reg=~(0)
#define CLR_REG(Reg)             	Reg=(0)
#define TGL_BIT(Reg,Bit)         	Reg^=(1<<Bit)
#define TGL_REG(Reg,Bit)         	Reg^=~(0)
#define SET_H_NIB(Reg)           	Reg|=(0xF0)
#define SET_L_NIB(Reg)           	Reg|=(0x0F)
#define CLR_H_NIB(Reg)           	Reg&=(0x0F)
#define CLR_L_NIB(Reg)           	Reg&=(0xF0)
#define GET_H_NIB(Reg)              (Reg&(0xF0))>>4
#define GET_L_NIB(Reg)           	(Reg&(0x0F))
#define ASSIGN_H_NIB(Reg, Value) (Reg = (Reg & 0x0F) | (Value << 4))
#define ASSIGN_L_NIB(Reg, Value) (Reg = (Reg & 0xF0) | (Value))   
#define TGL_H_NIB(Reg)              Reg^=(0xF0)      
#define TGL_L_NIB(Reg)              Reg^=(0x0F)      
#define SWAP_NIB(Reg)               Reg=((Reg<<4)|(Reg>>4))
#define TGLWITHOUTASSIGN_BIT(Reg,Bit)         	Reg^(1<<Bit)


#define CONC_B(B31, B30, B29, B28, B27, B26, B25, B24, B23, B22, B21, B20, B19, B18, B17, B16, B15, B14, B13, B12, B11, B10, B9, B8, B7, B6, B5, B4, B3, B2, B1, B0) \
CONC_HELPER(B31, B30, B29, B28, B27, B26, B25, B24, B23, B22, B21, B20, B19, B18, B17, B16, B15, B14, B13, B12, B11, B10, B9, B8, B7, B6, B5, B4, B3, B2, B1, B0)

#define CONC_HELPER(B31, B30, B29, B28, B27, B26, B25, B24, B23, B22, B21, B20, B19, B18, B17, B16, B15, B14, B13, B12, B11, B10, B9, B8, B7, B6, B5, B4, B3, B2, B1, B0) \
    (B31 << 31) | (B30 << 30) | (B29 << 29) | (B28 << 28) | (B27 << 27) | (B26 << 26) | (B25 << 25) | (B24 << 24) | \
    (B23 << 23) | (B22 << 22) | (B21 << 21) | (B20 << 20) | (B19 << 19) | (B18 << 18) | (B17 << 17) | (B16 << 16) | \
    (B15 << 15) | (B14 << 14) | (B13 << 13) | (B12 << 12) | (B11 << 11) | (B10 << 10) | (B9 << 9) | (B8 << 8) | \
    (B7 << 7) | (B6 << 6) | (B5 << 5) | (B4 << 4) | (B3 << 3) | (B2 << 2) | (B1 << 1) | (B0 << 0)


#endif      