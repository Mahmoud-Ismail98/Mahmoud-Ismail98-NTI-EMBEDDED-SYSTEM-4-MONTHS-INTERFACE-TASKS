################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/WatchDogTimer/src/subdir.mk
-include MCAL/USART/src/subdir.mk
-include MCAL/TIMER2/src/subdir.mk
-include MCAL/TIMER1/src/subdir.mk
-include MCAL/TIMER0/src/subdir.mk
-include MCAL/SPI/src/subdir.mk
-include MCAL/PORT/src/subdir.mk
-include MCAL/I2C/src/subdir.mk
-include MCAL/GIE/src/subdir.mk
-include MCAL/EXIT/src/subdir.mk
-include MCAL/DIO/src/subdir.mk
-include MCAL/ADC/src/subdir.mk
-include HAL/SevenSegment/src/subdir.mk
-include HAL/LCD/src/subdir.mk
-include HAL/KeyPad/src/subdir.mk
-include HAL/EEPROM/src/subdir.mk
-include Application/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
NTI_Drivers.lss \

SIZEDUMMY += \
sizedummy \


# All Target
all: NTI_Drivers.elf secondary-outputs

# Tool invocations
NTI_Drivers.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,NTI_Drivers.map -mmcu=atmega32 -o "NTI_Drivers.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

NTI_Drivers.lss: NTI_Drivers.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S NTI_Drivers.elf  >"NTI_Drivers.lss"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: NTI_Drivers.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 NTI_Drivers.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) NTI_Drivers.elf
	-@echo ' '

secondary-outputs: $(LSS) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
