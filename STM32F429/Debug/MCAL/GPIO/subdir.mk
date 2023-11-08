################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/GPIO/GPIO.c 

OBJS += \
./MCAL/GPIO/GPIO.o 

C_DEPS += \
./MCAL/GPIO/GPIO.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/GPIO/%.o MCAL/GPIO/%.su MCAL/GPIO/%.cyclo: ../MCAL/GPIO/%.c MCAL/GPIO/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F429I_DISC1 -DSTM32 -DSTM32F429ZITx -DSTM32F4 -c -I"/home/muhammad/Desktop/embedded/NTI TASK/STM32F429I/STM32F429/ECUL" -I"/home/muhammad/Desktop/embedded/NTI TASK/STM32F429I/STM32F429/APP" -I"/home/muhammad/Desktop/embedded/NTI TASK/STM32F429I/STM32F429/SERVICES" -I"/home/muhammad/Desktop/embedded/NTI TASK/STM32F429I/STM32F429/MCAL" -I"/home/muhammad/Desktop/embedded/NTI TASK/STM32F429I/STM32F429/MCAL/GPIO" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-MCAL-2f-GPIO

clean-MCAL-2f-GPIO:
	-$(RM) ./MCAL/GPIO/GPIO.cyclo ./MCAL/GPIO/GPIO.d ./MCAL/GPIO/GPIO.o ./MCAL/GPIO/GPIO.su

.PHONY: clean-MCAL-2f-GPIO

