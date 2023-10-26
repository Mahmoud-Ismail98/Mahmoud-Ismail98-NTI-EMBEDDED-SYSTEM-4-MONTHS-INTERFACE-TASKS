################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../includes/Mcal/dio.c \
../includes/Mcal/exInterrupt.c \
../includes/Mcal/port.c 

OBJS += \
./includes/Mcal/dio.o \
./includes/Mcal/exInterrupt.o \
./includes/Mcal/port.o 

C_DEPS += \
./includes/Mcal/dio.d \
./includes/Mcal/exInterrupt.d \
./includes/Mcal/port.d 


# Each subdirectory must supply rules for building sources it contributes
includes/Mcal/%.o: ../includes/Mcal/%.c includes/Mcal/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


