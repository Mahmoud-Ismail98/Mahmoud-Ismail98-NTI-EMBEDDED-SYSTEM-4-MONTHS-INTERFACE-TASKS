################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include cots/3-APP/subdir.mk
-include cots/2-HAL/2-Kpad/src/subdir.mk
-include cots/1-MCAL/01-DIO/subdir.mk
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
KAYpad_Driver.lss \

FLASH_IMAGE += \
KAYpad_Driver.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: KAYpad_Driver.elf secondary-outputs

# Tool invocations
KAYpad_Driver.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,KAYpad_Driver.map -mmcu=atmega32 -o "KAYpad_Driver.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

KAYpad_Driver.lss: KAYpad_Driver.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S KAYpad_Driver.elf  >"KAYpad_Driver.lss"
	@echo 'Finished building: $@'
	@echo ' '

KAYpad_Driver.hex: KAYpad_Driver.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex KAYpad_Driver.elf  "KAYpad_Driver.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: KAYpad_Driver.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 KAYpad_Driver.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) KAYpad_Driver.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
