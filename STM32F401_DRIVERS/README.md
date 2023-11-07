
# 1)Reset and clock control (RCC) peripheral 
is used to control the internal peripherals, as well as the reset signals and clock distribution.
The RCC gets several internal (LSI, HSI and CSI) and external (LSE and HSE) clocks. They are used as clock sources for the hardware blocks, either directly or indirectly, via the PLL that allow to achieve high frequencies.
There are three
## clock sources can be used to drive the system clock 
1.   **HSI oscillator clock**
2.   **HSE oscillator clock**
3.   **PLL clock**

## the RCC function  debuging on keil 
## 1.Rcc_enuSelectSysCLk(RCC_CLK_HSE,RCC_HSI_disable);
    a. first argument enable selected clock through RCC clock control register (RCC_CR) and configuar th first argument as the system clock through (RCC_CFGR)
    b.second argumen disable selected clock through RCC clock control register (RCC_CR) 

![select clock fun](https://github.com/MAHMOUD-ELIMBABI/NTI_Interfacing/assets/63348980/e2e4148e-8fec-42b1-9f33-9a7e261195f9)

## 2.Rcc_enuCheckCLk(RCC_CLK_HSE,&check_clk_on_flag);
    a.this function check if passed clock in argument is enabled or not if enabled return 1 in check_clk_on_flag argument and vise versa

![check clock](https://github.com/MAHMOUD-ELIMBABI/NTI_Interfacing/assets/63348980/df1b8a82-f773-4699-b8b2-d82d5e3a9b21)


## 3.Rcc_enuControlCLk(RCC_CNTROL_HSION,RCC_CNTROL_HSEON,RCC_CNTROL_PLLON);	
    a.enable clock through RCC clock control register (RCC_CR) for HEI,HSE and PLL  but not configuar the system clock

![control HSE-HSI-PLL on off fun](https://github.com/MAHMOUD-ELIMBABI/NTI_Interfacing/assets/63348980/c2bff25a-3228-4fd3-aa0c-8fe6348f4659)

## 4.Rcc_enuCnfgrPll(u8 COPY_u8M , u16 Copy_u16N , u8 Copy_u8P , u8 Copy_u8SrcPll , u8 Copy_u8Q);
### Rcc_enuCnfgrPll(8,192,1,0,0);
### this function set system clock as 81MHZ not exceeded max freq 84MHZ
    PLL_VCO = (HSE_VALUE or HSI_VALUE / PLL_M) * PLL_N 	
    COPY_u8M=16 : PLL_M division to 16 to get the comparison frequency1 MHz 
    Copy_u16N =192   PLL_N 192*1MHZ (192),
    Copy_u8SrcPll=0 ---0: HSI clock selected as PLL
    SYSCLK = PLL_VCO / PLL_P 	
    Copy_u8P=1 (VCO/ PLLP(2))

![Screenshot_30](https://github.com/MAHMOUD-ELIMBABI/NTI_Interfacing/assets/63348980/44122596-9998-4e98-9474-280ce599cfa0)

## 5.Rcc_enuEnablePeriphral(RCC_REGISTER_AHB1 , AHB1_GPIOA_EN);
    this function enable clock on selected bus in the first argument
    and the preioheral we want enable clock on it in the second argument 

![enable prephieral clock fun](https://github.com/MAHMOUD-ELIMBABI/NTI_Interfacing/assets/63348980/0c2e3aa6-6503-4f22-9cbf-65ecaf0f8493)

### 6.Rcc_enuDiablePeriphral(RCC_REGISTER_AHB1 , AHB1_GPIOA_EN);
    this function disable clock on selected bus in the first argument
    and the preioheral we want disable clock on it in the second argument
    
![Screenshot_31](https://github.com/MAHMOUD-ELIMBABI/NTI_Interfacing/assets/63348980/b3e69b86-2ba3-4506-9f60-f4c4de6a0727) 

### 7.Rcc_enuCfgBusPrescalers(RCC_AHB_DIV4);
    The clocks are divided with the new prescaler factor from 1 to 16 AHB cycles after HPRE write.

![Screenshot_33](https://github.com/MAHMOUD-ELIMBABI/NTI_Interfacing/assets/63348980/d438cd9d-5a60-43ab-9660-22abb5d51a14)

# 2)the general-purpose I/O ports(GPIO)
is a pin on an IC (Integrated Circuit). It can be used for driving loads, reading digital and analog signals, controlling external components, generating triggers for external devices etc. Each of the general-purpose I/O ports has two 32-bit configuration registers, two 32-bit data registers, a 32-bit set/reset register , a 16-bit reset register and a 32-bit locking register.

**Input floating**

**Input pull-up**

**Input-pull-down**
**Analog**

**Output open-drain**

**Output push-pull**

**Alternate function push-pull**

**Alternate function open-drain**

## the GPIO function  debuging on keil 

### 1.Gpio_init(&led_configuraion);
    GpioPinCfg_t led_configuraion={GPIO_MODE_u64_OUTPUT_PP,GPIO_PUPD_u32_FLOATING,GPIO_SPEED_LOW,GPIO_PIN_01,GPIO_PORT_B};

![Screenshot_39](https://github.com/MAHMOUD-ELIMBABI/NTI_Interfacing/assets/63348980/7f03f5d1-7298-4e1d-89c6-732c9412004b)

### 2.Gpio_setPinValue(&led_configuraion,GPIO_ODR_HIGH);

![Screenshot_36](https://github.com/MAHMOUD-ELIMBABI/NTI_Interfacing/assets/63348980/84cf9e0a-4b20-46ca-ac66-b9438a87b9da)

![Screenshot_38](https://github.com/MAHMOUD-ELIMBABI/NTI_Interfacing/assets/63348980/e5a1eafe-2ce6-4b9e-b187-e096344b6afb)

### 3.Gpio_readPinValue(&led_configuraion,&PIN_STATUS);
    GpioPinCfg_t led_configuraion={GPIO_MODE_u64_INPUT,GPIO_PUPD_u32_PULL_UP,GPIO_SPEED_MEDIUM,GPIO_PIN_00,GPIO_PORT_B};
when i set pin1 in portB as input pullup we notice the regesters are changed except IDR that suppose it deected high as he connected on pullup but the regester value and passed argument not channged i thought that KEIL no support directly changed in hardware pullup input mode 

![Screenshot_40](https://github.com/MAHMOUD-ELIMBABI/NTI_Interfacing/assets/63348980/16c14d2c-730f-4930-8fc1-8d2642f1b060)






