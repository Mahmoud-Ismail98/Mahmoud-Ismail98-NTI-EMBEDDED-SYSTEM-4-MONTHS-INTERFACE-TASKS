
# NTI EMBEDDED SYSTEM 4 MONTHS TASK
## TASKS under supervise ENG/MAHMOUD-ELIMBABI
## TASK1 SEVEN SEGMENT COUNTER TASK
###  TASK  Features:
1.	**four seven segment able to count from 0 to 9999**
2.	**external push putton when pressed number pn seven segment increased by 1 with each putton pressed until reash to 9999**
## task1 simulation on Proteus


https://github.com/MAHMOUD-ELIMBABI/NTI_Interfacing/assets/63348980/1deac126-253b-406a-bab7-55d9fd6303fe


## TASK2 FOUR SEVEN SEGMENT STOP WATCH 
### TASK features
1.	**four seven segment able to count from 0 to 9999**
2.  **there are three push putton control the stow watch**
     #### a. **start button start count until clear or stop putton pressed**
     #### b. **stop button is stop count on seven segment** 
     #### c. **clear button is clear the counter on stop watch to zero**   
## task2 simulation on Proteus


https://github.com/MAHMOUD-ELIMBABI/NTI_Interfacing/assets/63348980/a2fbdf02-6f0b-49de-86e6-be12f2659be1


## TASK3 LCD RUNNING BOY TASK 
###  TASK  Features:
**there are three object face a boy hole ,ramp and wall and there are three senatio faced aboy**

 1. **if aboy found ahole in the raw he dropped from ahole to next raw**
 2. **if aboy faced a ramp and above the ramp there is ahole he jump through the ramp and the hole to upper raw** 
 3. **if aboy faced the wall and there is no holes or ramp on his way he crashed and the game end and print game over on lcd** 
## task3 simulation on Proteus

https://github.com/MAHMOUD-ELIMBABI/NTI_Interfacing/assets/63348980/95d956bc-fdb0-45d2-a1c0-6d1e41898ac3

## TASK4 ADC SHOW VOLT LCD
###  TASK  Features:
1.	**analog to digital converter sense the analog volt from 0 to 5 volt**
2.	**lcd that show the voltage in volt or mvolt**
3.	**push putton control the showing value in volt or mvolt on lcd**
## task4 simulation on Proteus

https://github.com/MAHMOUD-ELIMBABI/NTI_Interfacing/assets/63348980/fa1a7616-dd4e-4c15-8840-c2bcb637a2dc

## TASK5 ADC volume show lcd
###  TASK  Features:
1.	**potenshowmeter to control the required volume** 
2.  **analog to digital converter sense the range of value indicated to the required volume**
3.	**lcd show the indicated volume**
## task5 simulation on Proteus

https://github.com/MAHMOUD-ELIMBABI/NTI_Interfacing/assets/63348980/6d7ae0db-4b98-4f2b-958d-12d8b6fb21fe

## task6 Calculator program that supports 4 operations (+,-,*,/)

###  TASK  Features:
1.	**The program starts with initializing the LCD and keypad and initializing the calculator to start accepting inputs for the first operand**

2.   **Every operand can consist of 5 digits and have a maximum of 65,535 because the variable is an unsigned 16-bit integer**

3.   **The program doesn't support floats or negative values. If you make a subtraction operation, the program checks which operand is bigger and calculates the difference between them, avoiding negative values**
## task6 simulation on Proteus

https://github.com/MAHMOUD-ELIMBABI/NTI_Interfacing/assets/63348980/a44b9100-a129-4a59-a579-f253d97ee512

##  TASK7 ALARM WITH SELECTED TIME

## task7 simulation on Proteus
https://github.com/MAHMOUD-ELIMBABI/NTI_Interfacing/assets/63348980/62b2c6df-6f00-4d11-83a0-a74441d53a45



##  TASK8 STOP WATCH ON  LCD

## task8 simulation on Proteus


https://github.com/MAHMOUD-ELIMBABI/NTI_Interfacing/assets/63348980/6d1bd510-6aa1-4e01-adfe-7f5e543567ea


<h1 align="center" style="font-size:2em;">STM32F401_DRIVERS_TEST_ON_KEIL</h1>

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


# 3)SysTick timer (STK)
SysTick is a simple timer that is part of the NVIC controller in the Cortex-M microprocessor. Its intended purpose is to provide a periodic interrupt 

## the SysTick function  debuging on keil 

**The systick a 24-bit system timer, SysTick, that counts down from the reload value to zero, reloads the value in the STK_LOAD register on the next clock edge, then counts down on subsequent clocks**

![Screenshot_46](https://github.com/MAHMOUD-ELIMBABI/NTI_Interfacing/assets/63348980/fdecbc4a-e6ee-45cd-873d-19a40255d2dc)

### 1.Systick_Init(1000);

    working on AHP/8 prescaller so we need cont 2000 to reach 1 ms so i made counter for COUNTER_MS variable that every ISR for SYSTICK decressed and when this var reach to zero that mean reach the required
    ms timing and we can take action  

![Screenshot_47](https://github.com/MAHMOUD-ELIMBABI/NTI_Interfacing/assets/63348980/e8d67da3-d108-49ee-a45b-15b816f74c09)

### 2.Systick_Start();
    Enables the counter. When ENABLE the counter loads the RELOAD value from the LOAD register and then counts down. On reaching 0, it sets the COUNTFLAG to 1 and optionally asserts the SysTick depending on the value of TICKINT. It then loads the RELOAD
    value again, and begins counting.

![Screenshot_48](https://github.com/MAHMOUD-ELIMBABI/NTI_Interfacing/assets/63348980/20578c48-5208-4a1c-9ac9-d5b1770bbf03)

### 3.Systick_RegisterCbf(ISR_SYSTICK);	
    ISR_SYSTICK is excuted after COUNTER_MS reached to zero after excuted the output pin2 in PORTB become HIGH 

![Screenshot_49](https://github.com/MAHMOUD-ELIMBABI/NTI_Interfacing/assets/63348980/436f5b49-5f49-4914-806c-debc474c643c)

![Screenshot_50](https://github.com/MAHMOUD-ELIMBABI/NTI_Interfacing/assets/63348980/05ba6927-b1f4-42ca-90c8-afa26d51aaab)

### 4.void SysTick_Handler (void)
    tacking another action when  COUNTER_MS become zero and after excuted the callBack function i   Disable STK Interrupt  and Stop Timer 

![Screenshot_52](https://github.com/MAHMOUD-ELIMBABI/NTI_Interfacing/assets/63348980/cd50b01b-aae4-4565-8dd2-13db2c9deae5)



