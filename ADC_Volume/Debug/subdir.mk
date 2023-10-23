################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ADC_prg.c \
../DIO.c \
../EXTI_prg.c \
../GIE_prg.c \
../LCD.c \
../PORT.c \
../main.c 

OBJS += \
./ADC_prg.o \
./DIO.o \
./EXTI_prg.o \
./GIE_prg.o \
./LCD.o \
./PORT.o \
./main.o 

C_DEPS += \
./ADC_prg.d \
./DIO.d \
./EXTI_prg.d \
./GIE_prg.d \
./LCD.d \
./PORT.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


