################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../includes/Hal/buzzer.c \
../includes/Hal/keyPad.c \
../includes/Hal/lcd.c 

OBJS += \
./includes/Hal/buzzer.o \
./includes/Hal/keyPad.o \
./includes/Hal/lcd.o 

C_DEPS += \
./includes/Hal/buzzer.d \
./includes/Hal/keyPad.d \
./includes/Hal/lcd.d 


# Each subdirectory must supply rules for building sources it contributes
includes/Hal/%.o: ../includes/Hal/%.c includes/Hal/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


