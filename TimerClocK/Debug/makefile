################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
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
TimerClocK.lss \

FLASH_IMAGE += \
TimerClocK.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: TimerClocK.elf secondary-outputs

# Tool invocations
TimerClocK.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,TimerClocK.map -mmcu=atmega32 -o "TimerClocK.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

TimerClocK.lss: TimerClocK.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S TimerClocK.elf  >"TimerClocK.lss"
	@echo 'Finished building: $@'
	@echo ' '

TimerClocK.hex: TimerClocK.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex TimerClocK.elf  "TimerClocK.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: TimerClocK.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 TimerClocK.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) TimerClocK.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
