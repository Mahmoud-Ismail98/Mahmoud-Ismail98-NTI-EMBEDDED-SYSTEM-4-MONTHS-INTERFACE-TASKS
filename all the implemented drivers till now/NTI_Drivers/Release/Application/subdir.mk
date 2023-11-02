################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Application/App.c \
../Application/Calculator.c \
../Application/spi.c \
../Application/twi.c 

OBJS += \
./Application/App.o \
./Application/Calculator.o \
./Application/spi.o \
./Application/twi.o 

C_DEPS += \
./Application/App.d \
./Application/Calculator.d \
./Application/spi.d \
./Application/twi.d 


# Each subdirectory must supply rules for building sources it contributes
Application/%.o: ../Application/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


