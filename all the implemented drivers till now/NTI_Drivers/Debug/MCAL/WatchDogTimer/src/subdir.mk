################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/WatchDogTimer/src/WatchDogTimer.c 

OBJS += \
./MCAL/WatchDogTimer/src/WatchDogTimer.o 

C_DEPS += \
./MCAL/WatchDogTimer/src/WatchDogTimer.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/WatchDogTimer/src/%.o: ../MCAL/WatchDogTimer/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


