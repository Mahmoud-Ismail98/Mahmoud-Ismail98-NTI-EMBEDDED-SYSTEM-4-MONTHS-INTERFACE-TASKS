################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/ADC_prg.c \
../src/DIO.c \
../src/EXTI_prg.c \
../src/GIE_prg.c \
../src/KEYPAD_prg.c \
../src/LCD.c \
../src/PORT.c \
../src/TIMER0_prg.c \
../src/WDT.c \
../src/main.c 

OBJS += \
./src/ADC_prg.o \
./src/DIO.o \
./src/EXTI_prg.o \
./src/GIE_prg.o \
./src/KEYPAD_prg.o \
./src/LCD.o \
./src/PORT.o \
./src/TIMER0_prg.o \
./src/WDT.o \
./src/main.o 

C_DEPS += \
./src/ADC_prg.d \
./src/DIO.d \
./src/EXTI_prg.d \
./src/GIE_prg.d \
./src/KEYPAD_prg.d \
./src/LCD.d \
./src/PORT.d \
./src/TIMER0_prg.d \
./src/WDT.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


