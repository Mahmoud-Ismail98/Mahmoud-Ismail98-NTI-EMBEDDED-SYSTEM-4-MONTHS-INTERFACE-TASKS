################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/KeyPad/src/KeyPad.c 

OBJS += \
./HAL/KeyPad/src/KeyPad.o 

C_DEPS += \
./HAL/KeyPad/src/KeyPad.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/KeyPad/src/%.o: ../HAL/KeyPad/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


