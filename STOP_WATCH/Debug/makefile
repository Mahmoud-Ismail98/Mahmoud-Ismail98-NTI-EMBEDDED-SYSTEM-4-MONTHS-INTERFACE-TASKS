################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/PORT/Source/subdir.mk
-include MCAL/DIO/Source/subdir.mk
-include HAL/SSD/Source/subdir.mk
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
STOP_WATCH.lss \

FLASH_IMAGE += \
STOP_WATCH.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: STOP_WATCH.elf secondary-outputs

# Tool invocations
STOP_WATCH.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,STOP_WATCH.map -mmcu=atmega32 -o "STOP_WATCH.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

STOP_WATCH.lss: STOP_WATCH.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S STOP_WATCH.elf  >"STOP_WATCH.lss"
	@echo 'Finished building: $@'
	@echo ' '

STOP_WATCH.hex: STOP_WATCH.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex STOP_WATCH.elf  "STOP_WATCH.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: STOP_WATCH.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 STOP_WATCH.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) STOP_WATCH.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
