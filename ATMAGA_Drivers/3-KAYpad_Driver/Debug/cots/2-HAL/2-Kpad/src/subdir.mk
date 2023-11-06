################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../cots/2-HAL/2-Kpad/src/Kpad_Pro.c 

OBJS += \
./cots/2-HAL/2-Kpad/src/Kpad_Pro.o 

C_DEPS += \
./cots/2-HAL/2-Kpad/src/Kpad_Pro.d 


# Each subdirectory must supply rules for building sources it contributes
cots/2-HAL/2-Kpad/src/%.o: ../cots/2-HAL/2-Kpad/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


