################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../APP/main.c \
../APP/syscalls.c \
../APP/sysmem.c 

OBJS += \
./APP/main.o \
./APP/syscalls.o \
./APP/sysmem.o 

C_DEPS += \
./APP/main.d \
./APP/syscalls.d \
./APP/sysmem.d 


# Each subdirectory must supply rules for building sources it contributes
APP/%.o APP/%.su APP/%.cyclo: ../APP/%.c APP/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F429I_DISC1 -DSTM32 -DSTM32F429ZITx -DSTM32F4 -c -I"/home/muhammad/Desktop/embedded/NTI TASK/STM32F429I/STM32F429/ECUL" -I"/home/muhammad/Desktop/embedded/NTI TASK/STM32F429I/STM32F429/APP" -I"/home/muhammad/Desktop/embedded/NTI TASK/STM32F429I/STM32F429/SERVICES" -I"/home/muhammad/Desktop/embedded/NTI TASK/STM32F429I/STM32F429/MCAL" -I"/home/muhammad/Desktop/embedded/NTI TASK/STM32F429I/STM32F429/MCAL/GPIO" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-APP

clean-APP:
	-$(RM) ./APP/main.cyclo ./APP/main.d ./APP/main.o ./APP/main.su ./APP/syscalls.cyclo ./APP/syscalls.d ./APP/syscalls.o ./APP/syscalls.su ./APP/sysmem.cyclo ./APP/sysmem.d ./APP/sysmem.o ./APP/sysmem.su

.PHONY: clean-APP

