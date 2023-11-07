GPIO_MODE_u64_INPUT     = 1
GPIO_MODE_u64_OUTPUT_PP	= 2
GPIO_MODE_u64_OUTPUT_OD	= 3
GPIO_MODE_u64_AF_PP     = 4
GPIO_MODE_u64_AF_OD     = 5
GPIO_MODE_u64_ANALOG    = 6


GPIO_SPEED_LOW      = 0
GPIO_SPEED_MEDIUM   = 1
GPIO_SPEED_HIGH     = 2
GPIO_SPEED_VHIGH    = 3

GPIO_PUPD_u32_FLOATING  = 0
GPIO_PUPD_u32_PULL_UP   = 1
GPIO_PUPD_u32_PULL_DOWN = 2

GPIO_AF_0  = 0 
GPIO_AF_1  = 1 
GPIO_AF_2  = 2 
GPIO_AF_3  = 3 
GPIO_AF_4  = 4 
GPIO_AF_5  = 5 
GPIO_AF_6  = 6 
GPIO_AF_7  = 7 
GPIO_AF_8  = 8 
GPIO_AF_9  = 9 
GPIO_AF_10 = 10
GPIO_AF_11 = 11
GPIO_AF_12 = 12
GPIO_AF_13 = 13
GPIO_AF_14 = 14
GPIO_AF_15 = 15


#### USER CONFIGURATIONS START ####
"""
 * Set PINS mode : options:
 *                   GPIO_MODE_u64_INPUT      
 *                   GPIO_MODE_u64_OUTPUT_PP
 *                   GPIO_MODE_u64_OUTPUT_OD
 *                   GPIO_MODE_u64_AF_PP	
 *                   GPIO_MODE_u64_AF_OD	
 *                   GPIO_MODE_u64_ANALOG
"""
GPIOA_PINS_MODE = [
    GPIO_MODE_u64_OUTPUT_PP, #{i} 0 
    GPIO_MODE_u64_INPUT, #{i} 1 
    GPIO_MODE_u64_INPUT, #{i} 2 
    GPIO_MODE_u64_INPUT, #{i} 3 
    GPIO_MODE_u64_INPUT, #{i} 4 
    GPIO_MODE_u64_INPUT, #{i} 5 
    GPIO_MODE_u64_INPUT, #{i} 6 
    GPIO_MODE_u64_AF_PP, #{i} 7 
    GPIO_MODE_u64_INPUT, #{i} 8 
    GPIO_MODE_u64_INPUT, #{i} 9 
    GPIO_MODE_u64_INPUT, #{i} 10
    GPIO_MODE_u64_INPUT, #{i} 11
    GPIO_MODE_u64_INPUT, #{i} 12
    GPIO_MODE_u64_INPUT, #{i} 13
    GPIO_MODE_u64_INPUT, #{i} 14
    GPIO_MODE_u64_INPUT, #{i} 15
]

GPIOB_PINS_MODE = [
    GPIO_MODE_u64_INPUT, #{i} 0 
    GPIO_MODE_u64_INPUT, #{i} 1 
    GPIO_MODE_u64_INPUT, #{i} 2 
    GPIO_MODE_u64_INPUT, #{i} 3 
    GPIO_MODE_u64_INPUT, #{i} 4 
    GPIO_MODE_u64_INPUT, #{i} 5 
    GPIO_MODE_u64_INPUT, #{i} 6 
    GPIO_MODE_u64_INPUT, #{i} 7 
    GPIO_MODE_u64_INPUT, #{i} 8 
    GPIO_MODE_u64_INPUT, #{i} 9 
    GPIO_MODE_u64_INPUT, #{i} 10
    GPIO_MODE_u64_INPUT, #{i} 11
    GPIO_MODE_u64_INPUT, #{i} 12
    GPIO_MODE_u64_INPUT, #{i} 13
    GPIO_MODE_u64_INPUT, #{i} 14
    GPIO_MODE_u64_INPUT, #{i} 15
]

GPIOC_PINS_MODE = [
    GPIO_MODE_u64_INPUT, #{i} 0 
    GPIO_MODE_u64_INPUT, #{i} 1 
    GPIO_MODE_u64_INPUT, #{i} 2 
    GPIO_MODE_u64_INPUT, #{i} 3 
    GPIO_MODE_u64_INPUT, #{i} 4 
    GPIO_MODE_u64_INPUT, #{i} 5 
    GPIO_MODE_u64_INPUT, #{i} 6 
    GPIO_MODE_u64_INPUT, #{i} 7 
    GPIO_MODE_u64_INPUT, #{i} 8 
    GPIO_MODE_u64_INPUT, #{i} 9 
    GPIO_MODE_u64_INPUT, #{i} 10
    GPIO_MODE_u64_INPUT, #{i} 11
    GPIO_MODE_u64_INPUT, #{i} 12
    GPIO_MODE_u64_INPUT, #{i} 13
    GPIO_MODE_u64_INPUT, #{i} 14
    GPIO_MODE_u64_INPUT, #{i} 15
]

GPIOD_PINS_MODE = [
    GPIO_MODE_u64_INPUT, #{i} 0 
    GPIO_MODE_u64_INPUT, #{i} 1 
    GPIO_MODE_u64_INPUT, #{i} 2 
    GPIO_MODE_u64_INPUT, #{i} 3 
    GPIO_MODE_u64_INPUT, #{i} 4 
    GPIO_MODE_u64_INPUT, #{i} 5 
    GPIO_MODE_u64_INPUT, #{i} 6 
    GPIO_MODE_u64_INPUT, #{i} 7 
    GPIO_MODE_u64_INPUT, #{i} 8 
    GPIO_MODE_u64_INPUT, #{i} 9 
    GPIO_MODE_u64_INPUT, #{i} 10
    GPIO_MODE_u64_INPUT, #{i} 11
    GPIO_MODE_u64_INPUT, #{i} 12
    GPIO_MODE_u64_INPUT, #{i} 13
    GPIO_MODE_u64_INPUT, #{i} 14
    GPIO_MODE_u64_INPUT, #{i} 15
]

GPIOE_PINS_MODE = [
    GPIO_MODE_u64_INPUT, #{i} 0 
    GPIO_MODE_u64_INPUT, #{i} 1 
    GPIO_MODE_u64_INPUT, #{i} 2 
    GPIO_MODE_u64_INPUT, #{i} 3 
    GPIO_MODE_u64_INPUT, #{i} 4 
    GPIO_MODE_u64_INPUT, #{i} 5 
    GPIO_MODE_u64_INPUT, #{i} 6 
    GPIO_MODE_u64_INPUT, #{i} 7 
    GPIO_MODE_u64_INPUT, #{i} 8 
    GPIO_MODE_u64_INPUT, #{i} 9 
    GPIO_MODE_u64_INPUT, #{i} 10
    GPIO_MODE_u64_INPUT, #{i} 11
    GPIO_MODE_u64_INPUT, #{i} 12
    GPIO_MODE_u64_INPUT, #{i} 13
    GPIO_MODE_u64_INPUT, #{i} 14
    GPIO_MODE_u64_INPUT, #{i} 15
]

GPIOH_PINS_MODE = [
    GPIO_MODE_u64_INPUT, #{i} 0 
    GPIO_MODE_u64_INPUT, #{i} 1 
    GPIO_MODE_u64_INPUT, #{i} 2 
    GPIO_MODE_u64_INPUT, #{i} 3 
    GPIO_MODE_u64_INPUT, #{i} 4 
    GPIO_MODE_u64_INPUT, #{i} 5 
    GPIO_MODE_u64_INPUT, #{i} 6 
    GPIO_MODE_u64_INPUT, #{i} 7 
    GPIO_MODE_u64_INPUT, #{i} 8 
    GPIO_MODE_u64_INPUT, #{i} 9 
    GPIO_MODE_u64_INPUT, #{i} 10
    GPIO_MODE_u64_INPUT, #{i} 11
    GPIO_MODE_u64_INPUT, #{i} 12
    GPIO_MODE_u64_INPUT, #{i} 13
    GPIO_MODE_u64_INPUT, #{i} 14
    GPIO_MODE_u64_INPUT, #{i} 15
]

"""
 * Set PINS SPEED : options:
 *                   GPIO_SPEED_LOW      
 *                   GPIO_SPEED_MEDIUM
 *                   GPIO_SPEED_HIGH
 *                   GPIO_SPEED_VHIGH	
"""
GPIOA_PINS_SPEED = [
    GPIO_SPEED_LOW, #{i} 0 
    GPIO_SPEED_LOW, #{i} 1 
    GPIO_SPEED_LOW, #{i} 2 
    GPIO_SPEED_LOW, #{i} 3 
    GPIO_SPEED_LOW, #{i} 4 
    GPIO_SPEED_LOW, #{i} 5 
    GPIO_SPEED_LOW, #{i} 6 
    GPIO_SPEED_LOW, #{i} 7 
    GPIO_SPEED_LOW, #{i} 8 
    GPIO_SPEED_LOW, #{i} 9 
    GPIO_SPEED_LOW, #{i} 10
    GPIO_SPEED_LOW, #{i} 11
    GPIO_SPEED_LOW, #{i} 12
    GPIO_SPEED_LOW, #{i} 13
    GPIO_SPEED_LOW, #{i} 14
    GPIO_SPEED_LOW, #{i} 15
]

GPIOB_PINS_SPEED = [
    GPIO_SPEED_LOW, #{i} 0 
    GPIO_SPEED_LOW, #{i} 1 
    GPIO_SPEED_LOW, #{i} 2 
    GPIO_SPEED_LOW, #{i} 3 
    GPIO_SPEED_LOW, #{i} 4 
    GPIO_SPEED_LOW, #{i} 5 
    GPIO_SPEED_LOW, #{i} 6 
    GPIO_SPEED_LOW, #{i} 7 
    GPIO_SPEED_LOW, #{i} 8 
    GPIO_SPEED_LOW, #{i} 9 
    GPIO_SPEED_LOW, #{i} 10
    GPIO_SPEED_LOW, #{i} 11
    GPIO_SPEED_LOW, #{i} 12
    GPIO_SPEED_LOW, #{i} 13
    GPIO_SPEED_LOW, #{i} 14
    GPIO_SPEED_LOW, #{i} 15
]

GPIOC_PINS_SPEED = [
    GPIO_SPEED_LOW, #{i} 0 
    GPIO_SPEED_LOW, #{i} 1 
    GPIO_SPEED_LOW, #{i} 2 
    GPIO_SPEED_LOW, #{i} 3 
    GPIO_SPEED_LOW, #{i} 4 
    GPIO_SPEED_LOW, #{i} 5 
    GPIO_SPEED_LOW, #{i} 6 
    GPIO_SPEED_LOW, #{i} 7 
    GPIO_SPEED_LOW, #{i} 8 
    GPIO_SPEED_LOW, #{i} 9 
    GPIO_SPEED_LOW, #{i} 10
    GPIO_SPEED_LOW, #{i} 11
    GPIO_SPEED_LOW, #{i} 12
    GPIO_SPEED_LOW, #{i} 13
    GPIO_SPEED_LOW, #{i} 14
    GPIO_SPEED_LOW, #{i} 15
]

GPIOD_PINS_SPEED = [
    GPIO_SPEED_LOW, #{i} 0 
    GPIO_SPEED_LOW, #{i} 1 
    GPIO_SPEED_LOW, #{i} 2 
    GPIO_SPEED_LOW, #{i} 3 
    GPIO_SPEED_LOW, #{i} 4 
    GPIO_SPEED_LOW, #{i} 5 
    GPIO_SPEED_LOW, #{i} 6 
    GPIO_SPEED_LOW, #{i} 7 
    GPIO_SPEED_LOW, #{i} 8 
    GPIO_SPEED_LOW, #{i} 9 
    GPIO_SPEED_LOW, #{i} 10
    GPIO_SPEED_LOW, #{i} 11
    GPIO_SPEED_LOW, #{i} 12
    GPIO_SPEED_LOW, #{i} 13
    GPIO_SPEED_LOW, #{i} 14
    GPIO_SPEED_LOW, #{i} 15
]

GPIOE_PINS_SPEED = [
    GPIO_SPEED_LOW, #{i} 0 
    GPIO_SPEED_LOW, #{i} 1 
    GPIO_SPEED_LOW, #{i} 2 
    GPIO_SPEED_LOW, #{i} 3 
    GPIO_SPEED_LOW, #{i} 4 
    GPIO_SPEED_LOW, #{i} 5 
    GPIO_SPEED_LOW, #{i} 6 
    GPIO_SPEED_LOW, #{i} 7 
    GPIO_SPEED_LOW, #{i} 8 
    GPIO_SPEED_LOW, #{i} 9 
    GPIO_SPEED_LOW, #{i} 10
    GPIO_SPEED_LOW, #{i} 11
    GPIO_SPEED_LOW, #{i} 12
    GPIO_SPEED_LOW, #{i} 13
    GPIO_SPEED_LOW, #{i} 14
    GPIO_SPEED_LOW, #{i} 15
]

GPIOH_PINS_SPEED = [
    GPIO_SPEED_LOW, #{i} 0 
    GPIO_SPEED_LOW, #{i} 1 
    GPIO_SPEED_LOW, #{i} 2 
    GPIO_SPEED_LOW, #{i} 3 
    GPIO_SPEED_LOW, #{i} 4 
    GPIO_SPEED_LOW, #{i} 5 
    GPIO_SPEED_LOW, #{i} 6 
    GPIO_SPEED_LOW, #{i} 7 
    GPIO_SPEED_LOW, #{i} 8 
    GPIO_SPEED_LOW, #{i} 9 
    GPIO_SPEED_LOW, #{i} 10
    GPIO_SPEED_LOW, #{i} 11
    GPIO_SPEED_LOW, #{i} 12
    GPIO_SPEED_LOW, #{i} 13
    GPIO_SPEED_LOW, #{i} 14
    GPIO_SPEED_LOW, #{i} 15
]

"""
 * Set PINS VALUE : options:
 *      GPIO_PUPD_u32_FLOATING  
 *      GPIO_PUPD_u32_PULL_UP   
 *      GPIO_PUPD_u32_PULL_DOWN 
"""
GPIOA_PINS_VALUE = [
    GPIO_PUPD_u32_PULL_DOWN, #{i} 0 
    GPIO_PUPD_u32_PULL_DOWN, #{i} 1 
    GPIO_PUPD_u32_PULL_DOWN, #{i} 2 
    GPIO_PUPD_u32_PULL_DOWN, #{i} 3 
    GPIO_PUPD_u32_PULL_DOWN, #{i} 4 
    GPIO_PUPD_u32_PULL_DOWN, #{i} 5 
    GPIO_PUPD_u32_PULL_DOWN, #{i} 6 
    GPIO_PUPD_u32_PULL_DOWN, #{i} 7 
    GPIO_PUPD_u32_PULL_DOWN, #{i} 8 
    GPIO_PUPD_u32_PULL_DOWN, #{i} 9 
    GPIO_PUPD_u32_PULL_DOWN, #{i} 10
    GPIO_PUPD_u32_PULL_DOWN, #{i} 11
    GPIO_PUPD_u32_PULL_DOWN, #{i} 12
    GPIO_PUPD_u32_PULL_DOWN, #{i} 13
    GPIO_PUPD_u32_PULL_DOWN, #{i} 14
    GPIO_PUPD_u32_PULL_DOWN, #{i} 15
]

GPIOB_PINS_VALUE = [
    GPIO_PUPD_u32_PULL_DOWN, #{i} 0 
    GPIO_PUPD_u32_PULL_DOWN, #{i} 1 
    GPIO_PUPD_u32_PULL_DOWN, #{i} 2 
    GPIO_PUPD_u32_PULL_DOWN, #{i} 3 
    GPIO_PUPD_u32_PULL_DOWN, #{i} 4 
    GPIO_PUPD_u32_PULL_DOWN, #{i} 5 
    GPIO_PUPD_u32_PULL_DOWN, #{i} 6 
    GPIO_PUPD_u32_PULL_DOWN, #{i} 7 
    GPIO_PUPD_u32_PULL_DOWN, #{i} 8 
    GPIO_PUPD_u32_PULL_DOWN, #{i} 9 
    GPIO_PUPD_u32_PULL_DOWN, #{i} 10
    GPIO_PUPD_u32_PULL_DOWN, #{i} 11
    GPIO_PUPD_u32_PULL_DOWN, #{i} 12
    GPIO_PUPD_u32_PULL_DOWN, #{i} 13
    GPIO_PUPD_u32_PULL_DOWN, #{i} 14
    GPIO_PUPD_u32_PULL_DOWN, #{i} 15
]

GPIOC_PINS_VALUE = [
    GPIO_PUPD_u32_PULL_DOWN, #{i} 0 
    GPIO_PUPD_u32_PULL_DOWN, #{i} 1 
    GPIO_PUPD_u32_PULL_DOWN, #{i} 2 
    GPIO_PUPD_u32_PULL_DOWN, #{i} 3 
    GPIO_PUPD_u32_PULL_DOWN, #{i} 4 
    GPIO_PUPD_u32_PULL_DOWN, #{i} 5 
    GPIO_PUPD_u32_PULL_DOWN, #{i} 6 
    GPIO_PUPD_u32_PULL_DOWN, #{i} 7 
    GPIO_PUPD_u32_PULL_DOWN, #{i} 8 
    GPIO_PUPD_u32_PULL_DOWN, #{i} 9 
    GPIO_PUPD_u32_PULL_DOWN, #{i} 10
    GPIO_PUPD_u32_PULL_DOWN, #{i} 11
    GPIO_PUPD_u32_PULL_DOWN, #{i} 12
    GPIO_PUPD_u32_PULL_DOWN, #{i} 13
    GPIO_PUPD_u32_PULL_DOWN, #{i} 14
    GPIO_PUPD_u32_PULL_DOWN, #{i} 15
]

GPIOD_PINS_VALUE = [
    GPIO_PUPD_u32_PULL_DOWN, #{i} 0 
    GPIO_PUPD_u32_PULL_DOWN, #{i} 1 
    GPIO_PUPD_u32_PULL_DOWN, #{i} 2 
    GPIO_PUPD_u32_PULL_DOWN, #{i} 3 
    GPIO_PUPD_u32_PULL_DOWN, #{i} 4 
    GPIO_PUPD_u32_PULL_DOWN, #{i} 5 
    GPIO_PUPD_u32_PULL_DOWN, #{i} 6 
    GPIO_PUPD_u32_PULL_DOWN, #{i} 7 
    GPIO_PUPD_u32_PULL_DOWN, #{i} 8 
    GPIO_PUPD_u32_PULL_DOWN, #{i} 9 
    GPIO_PUPD_u32_PULL_DOWN, #{i} 10
    GPIO_PUPD_u32_PULL_DOWN, #{i} 11
    GPIO_PUPD_u32_PULL_DOWN, #{i} 12
    GPIO_PUPD_u32_PULL_DOWN, #{i} 13
    GPIO_PUPD_u32_PULL_DOWN, #{i} 14
    GPIO_PUPD_u32_PULL_DOWN, #{i} 15
]

GPIOE_PINS_VALUE = [
    GPIO_PUPD_u32_PULL_DOWN, #{i} 0 
    GPIO_PUPD_u32_PULL_DOWN, #{i} 1 
    GPIO_PUPD_u32_PULL_DOWN, #{i} 2 
    GPIO_PUPD_u32_PULL_DOWN, #{i} 3 
    GPIO_PUPD_u32_PULL_DOWN, #{i} 4 
    GPIO_PUPD_u32_PULL_DOWN, #{i} 5 
    GPIO_PUPD_u32_PULL_DOWN, #{i} 6 
    GPIO_PUPD_u32_PULL_DOWN, #{i} 7 
    GPIO_PUPD_u32_PULL_DOWN, #{i} 8 
    GPIO_PUPD_u32_PULL_DOWN, #{i} 9 
    GPIO_PUPD_u32_PULL_DOWN, #{i} 10
    GPIO_PUPD_u32_PULL_DOWN, #{i} 11
    GPIO_PUPD_u32_PULL_DOWN, #{i} 12
    GPIO_PUPD_u32_PULL_DOWN, #{i} 13
    GPIO_PUPD_u32_PULL_DOWN, #{i} 14
    GPIO_PUPD_u32_PULL_DOWN, #{i} 15
]

GPIOH_PINS_VALUE = [
    GPIO_PUPD_u32_PULL_DOWN, #{i} 0 
    GPIO_PUPD_u32_PULL_DOWN, #{i} 1 
    GPIO_PUPD_u32_PULL_DOWN, #{i} 2 
    GPIO_PUPD_u32_PULL_DOWN, #{i} 3 
    GPIO_PUPD_u32_PULL_DOWN, #{i} 4 
    GPIO_PUPD_u32_PULL_DOWN, #{i} 5 
    GPIO_PUPD_u32_PULL_DOWN, #{i} 6 
    GPIO_PUPD_u32_PULL_DOWN, #{i} 7 
    GPIO_PUPD_u32_PULL_DOWN, #{i} 8 
    GPIO_PUPD_u32_PULL_DOWN, #{i} 9 
    GPIO_PUPD_u32_PULL_DOWN, #{i} 10
    GPIO_PUPD_u32_PULL_DOWN, #{i} 11
    GPIO_PUPD_u32_PULL_DOWN, #{i} 12
    GPIO_PUPD_u32_PULL_DOWN, #{i} 13
    GPIO_PUPD_u32_PULL_DOWN, #{i} 14
    GPIO_PUPD_u32_PULL_DOWN, #{i} 15
]

"""
 * Set PINS AF : options:
 *                   GPIO_AF_0      
 *                   GPIO_AF_1
 *                   GPIO_AF_2      
 *                   GPIO_AF_3
 *                   GPIO_AF_4      
 *                   GPIO_AF_5
 *                   GPIO_AF_6      
 *                   GPIO_AF_7
 *                   GPIO_AF_8      
 *                   GPIO_AF_9
 *                   GPIO_AF_10      
 *                   GPIO_AF_11
 *                   GPIO_AF_12      
 *                   GPIO_AF_13
 *                   GPIO_AF_14      
 *                   GPIO_AF_15
"""
GPIOA_PINS_AF = [
    GPIO_AF_0, #{i} 0 
    GPIO_AF_0, #{i} 1 
    GPIO_AF_0, #{i} 2 
    GPIO_AF_0, #{i} 3 
    GPIO_AF_0, #{i} 4 
    GPIO_AF_0, #{i} 5 
    GPIO_AF_0, #{i} 6 
    GPIO_AF_0, #{i} 7 
    GPIO_AF_0, #{i} 8 
    GPIO_AF_0, #{i} 9 
    GPIO_AF_0, #{i} 10
    GPIO_AF_0, #{i} 11
    GPIO_AF_0, #{i} 12
    GPIO_AF_0, #{i} 13
    GPIO_AF_0, #{i} 14
    GPIO_AF_0, #{i} 15
]

GPIOB_PINS_AF = [
    GPIO_AF_0, #{i} 0 
    GPIO_AF_0, #{i} 1 
    GPIO_AF_0, #{i} 2 
    GPIO_AF_0, #{i} 3 
    GPIO_AF_0, #{i} 4 
    GPIO_AF_0, #{i} 5 
    GPIO_AF_0, #{i} 6 
    GPIO_AF_0, #{i} 7 
    GPIO_AF_0, #{i} 8 
    GPIO_AF_0, #{i} 9 
    GPIO_AF_0, #{i} 10
    GPIO_AF_0, #{i} 11
    GPIO_AF_0, #{i} 12
    GPIO_AF_0, #{i} 13
    GPIO_AF_0, #{i} 14
    GPIO_AF_0, #{i} 15
]

GPIOC_PINS_AF = [
    GPIO_AF_0, #{i} 0 
    GPIO_AF_0, #{i} 1 
    GPIO_AF_0, #{i} 2 
    GPIO_AF_0, #{i} 3 
    GPIO_AF_0, #{i} 4 
    GPIO_AF_0, #{i} 5 
    GPIO_AF_0, #{i} 6 
    GPIO_AF_0, #{i} 7 
    GPIO_AF_0, #{i} 8 
    GPIO_AF_0, #{i} 9 
    GPIO_AF_0, #{i} 10
    GPIO_AF_0, #{i} 11
    GPIO_AF_0, #{i} 12
    GPIO_AF_0, #{i} 13
    GPIO_AF_0, #{i} 14
    GPIO_AF_0, #{i} 15
]

GPIOD_PINS_AF = [
    GPIO_AF_0, #{i} 0 
    GPIO_AF_0, #{i} 1 
    GPIO_AF_0, #{i} 2 
    GPIO_AF_0, #{i} 3 
    GPIO_AF_0, #{i} 4 
    GPIO_AF_0, #{i} 5 
    GPIO_AF_0, #{i} 6 
    GPIO_AF_0, #{i} 7 
    GPIO_AF_0, #{i} 8 
    GPIO_AF_0, #{i} 9 
    GPIO_AF_0, #{i} 10
    GPIO_AF_0, #{i} 11
    GPIO_AF_0, #{i} 12
    GPIO_AF_0, #{i} 13
    GPIO_AF_0, #{i} 14
    GPIO_AF_0, #{i} 15
]

GPIOE_PINS_AF = [
    GPIO_AF_0, #{i} 0 
    GPIO_AF_0, #{i} 1 
    GPIO_AF_0, #{i} 2 
    GPIO_AF_0, #{i} 3 
    GPIO_AF_0, #{i} 4 
    GPIO_AF_0, #{i} 5 
    GPIO_AF_0, #{i} 6 
    GPIO_AF_15, #{i} 7 
    GPIO_AF_0, #{i} 8 
    GPIO_AF_0, #{i} 9 
    GPIO_AF_0, #{i} 10
    GPIO_AF_0, #{i} 11
    GPIO_AF_0, #{i} 12
    GPIO_AF_0, #{i} 13
    GPIO_AF_0, #{i} 14
    GPIO_AF_0, #{i} 15
]

GPIOH_PINS_AF = [
    GPIO_AF_0, #{i} 0 
    GPIO_AF_0, #{i} 1 
    GPIO_AF_0, #{i} 2 
    GPIO_AF_0, #{i} 3 
    GPIO_AF_0, #{i} 4 
    GPIO_AF_0, #{i} 5 
    GPIO_AF_0, #{i} 6 
    GPIO_AF_0, #{i} 7 
    GPIO_AF_0, #{i} 8 
    GPIO_AF_0, #{i} 9 
    GPIO_AF_0, #{i} 10
    GPIO_AF_0, #{i} 11
    GPIO_AF_0, #{i} 12
    GPIO_AF_0, #{i} 13
    GPIO_AF_0, #{i} 14
    GPIO_AF_0, #{i} 15
]

#### USER CONFIGURATIONS END ####



def set_bit(value, bit):
    return value | (1<<bit)

PORTS = ["GPIOA","GPIOB","GPIOC","GPIOD","GPIOE","GPIOH"]
MODES = [GPIOA_PINS_MODE, GPIOB_PINS_MODE, GPIOC_PINS_MODE, GPIOD_PINS_MODE, GPIOE_PINS_MODE, GPIOH_PINS_MODE]
SPEEDS = [GPIOA_PINS_SPEED, GPIOB_PINS_SPEED, GPIOC_PINS_SPEED, GPIOD_PINS_SPEED, GPIOE_PINS_SPEED, GPIOH_PINS_SPEED]
VALUES = [GPIOA_PINS_VALUE, GPIOB_PINS_VALUE, GPIOC_PINS_VALUE, GPIOD_PINS_VALUE, GPIOE_PINS_VALUE, GPIOH_PINS_VALUE]
AF = [GPIOA_PINS_AF, GPIOB_PINS_AF, GPIOC_PINS_AF, GPIOD_PINS_AF, GPIOE_PINS_AF, GPIOH_PINS_AF]
print("Gpio_tenuErrorStatus Gpio_initAll(){")
print("    Gpio_tenuErrorStatus local_errorState = Gpio_enuOk\n")
for p in range(6):
    MODER_VAL   = 0
    OTYPER_VAL  = 0
    OSPEEDR_VAL = 0
    PUPDR_VAL   = 0 
    AFRL_VAL    = 0
    AFRH_VAL    = 0
    for i in range(16) :
        if MODES[p][i] ==  GPIO_MODE_u64_OUTPUT_PP:
            MODER_VAL = set_bit(MODER_VAL, i*2)
        if MODES[p][i] ==  GPIO_MODE_u64_OUTPUT_OD:
            MODER_VAL = set_bit(MODER_VAL, i*2)
            OTYPER_VAL = set_bit(OTYPER_VAL, i) 
        if MODES[p][i] ==  GPIO_MODE_u64_AF_PP:
            MODER_VAL = set_bit(MODER_VAL, i*2 +1)
        if MODES[p][i] ==  GPIO_MODE_u64_AF_OD:
            MODER_VAL = set_bit(MODER_VAL, i*2 +1)
        if MODES[p][i] ==  GPIO_MODE_u64_ANALOG:
            MODER_VAL = set_bit(MODER_VAL, i*2)
            MODER_VAL = set_bit(MODER_VAL, i*2 +1)
        if SPEEDS[p][i] == GPIO_SPEED_MEDIUM :
            OSPEEDR_VAL = set_bit(OSPEEDR_VAL, i*2)
        if SPEEDS[p][i] == GPIO_SPEED_HIGH :
            OSPEEDR_VAL = set_bit(OSPEEDR_VAL, i*2 +1)
        if SPEEDS[p][i] == GPIO_SPEED_VHIGH :
            OSPEEDR_VAL = set_bit(OSPEEDR_VAL, i*2)
            OSPEEDR_VAL = set_bit(OSPEEDR_VAL, i*2 +1)
        if VALUES[p][i] ==  GPIO_PUPD_u32_PULL_UP :
            PUPDR_VAL = set_bit(PUPDR_VAL, i*2)
        if VALUES[p][i] ==   GPIO_PUPD_u32_PULL_DOWN :
            PUPDR_VAL = set_bit(PUPDR_VAL, i*2 +1)
        if i < 8:
            pin = i
            local_u32_mask  = 0xF << pin*4;
            local_u32_value = AF[p][i] << pin*4 ;
            AFRL_VAL  &= ~local_u32_mask;
            AFRL_VAL  |= local_u32_value;
        elif i < 16:
            pin = i
            pin -= 8;
            local_u32_mask  = 0xF << pin*4;
            local_u32_value = AF[p][i] << pin*4 ;
            AFRH_VAL  &= ~local_u32_mask;
            AFRH_VAL  |= local_u32_value;
    print(f'    {PORTS[p]}->MODER   = {MODER_VAL};')
    print(f'    {PORTS[p]}->OTYPER  = {OTYPER_VAL};')
    print(f'    {PORTS[p]}->OSPEEDR = {OSPEEDR_VAL};')
    print(f'    {PORTS[p]}->PUPDR   = {PUPDR_VAL};')
    print(f'    {PORTS[p]}->AFRL    = {AFRL_VAL};')
    print(f'    {PORTS[p]}->AFRH    = {AFRH_VAL};\n')

print("    return local_errorState;")
print("}")