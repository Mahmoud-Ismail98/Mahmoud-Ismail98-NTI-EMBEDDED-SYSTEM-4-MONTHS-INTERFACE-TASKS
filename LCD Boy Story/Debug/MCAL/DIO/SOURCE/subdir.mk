################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/DIO/SOURCE/dio.c 

OBJS += \
./MCAL/DIO/SOURCE/dio.o 

C_DEPS += \
./MCAL/DIO/SOURCE/dio.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/DIO/SOURCE/%.o: ../MCAL/DIO/SOURCE/%.c MCAL/DIO/SOURCE/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


