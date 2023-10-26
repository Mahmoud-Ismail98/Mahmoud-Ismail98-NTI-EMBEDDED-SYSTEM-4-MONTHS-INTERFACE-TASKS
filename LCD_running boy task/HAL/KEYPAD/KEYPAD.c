

voidKEYPAD_voidInit(void)
{
Port_setPinDirection(KEY_RAW0,PIN_OUTPUT);
Port_setPinDirection(KEY_RAW1,PIN_OUTPUT);
Port_setPinDirection(KEY_RAW2,PIN_OUTPUT);
Port_setPinDirection(KEY_RAW3,PIN_OUTPUT);
Port_SetPinMode(KEY_COL0,PIN_IN[PUT_PULLUP);
Port_SetPinMode(KEY_COL1,PIN_IN[PUT_PULLUP);
Port_SetPinMode(KEY_COL2,PIN_IN[PUT_PULLUP);
Port_SetPinMode(KEY_COL3,PIN_IN[PUT_PULLUP)

}

u8sympol[16]={0,1,2,3,
4,5,6,7,
8,9,10,11,
12,13,14,15}

u8pattern[4]={0b1111,0b01111,0b1011,0b1101,0b1110};
u8KEYPAD_u8PressedKey(u8 &Add)
{
u8Local_keypresed=0x00;
*Add=0x00;
u8temp=0x00;
for(u8i=0;i<4;i++)
{
DIO_WritrPin(TOGLE_WITHOUT_ASSIGN(PAT,i),LOW_LEVEL);
Local_keypresed=GET_BIT((KEY_COL0)<<;
DIO_READ_PIN(KEY_COL0,ADD)
switch(ADD)
{
case 0x1110:	pattern[(4*i)+0];
case 0x1110:	pattern[(4*i)+1];
case 0x1110:	pattern[(4*i)+2];
case 0x1110:	pattern[(4*i)+3]


}




}