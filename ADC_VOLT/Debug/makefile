################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/PORT/Source/subdir.mk
-include MCAL/GIE/Source/subdir.mk
-include MCAL/EXTI/Source/subdir.mk
-include MCAL/DIO/Source/subdir.mk
-include MCAL/ADC/Source/subdir.mk
-include HAL/LCD/Source/subdir.mk
-include APP/subdir.mk
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
ADC_VOLT.lss \

FLASH_IMAGE += \
ADC_VOLT.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: ADC_VOLT.elf secondary-outputs

# Tool invocations
ADC_VOLT.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,ADC_VOLT.map -mmcu=atmega32 -o "ADC_VOLT.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

ADC_VOLT.lss: ADC_VOLT.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S ADC_VOLT.elf  >"ADC_VOLT.lss"
	@echo 'Finished building: $@'
	@echo ' '

ADC_VOLT.hex: ADC_VOLT.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex ADC_VOLT.elf  "ADC_VOLT.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: ADC_VOLT.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 ADC_VOLT.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) ADC_VOLT.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
