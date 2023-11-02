################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/TIMER/Source/subdir.mk
-include MCAL/PORT/Source/subdir.mk
-include MCAL/GIE/Source/subdir.mk
-include MCAL/DIO/Source/subdir.mk
-include HAL/LCD/Source/subdir.mk
-include HAL/KPD/Source/subdir.mk
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
TIMER_TASK.lss \

FLASH_IMAGE += \
TIMER_TASK.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: TIMER_TASK.elf secondary-outputs

# Tool invocations
TIMER_TASK.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,TIMER_TASK.map -mmcu=atmega32 -o "TIMER_TASK.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

TIMER_TASK.lss: TIMER_TASK.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S TIMER_TASK.elf  >"TIMER_TASK.lss"
	@echo 'Finished building: $@'
	@echo ' '

TIMER_TASK.hex: TIMER_TASK.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex TIMER_TASK.elf  "TIMER_TASK.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: TIMER_TASK.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 TIMER_TASK.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) TIMER_TASK.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
