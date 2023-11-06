################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include cots/3-APP/subdir.mk
-include cots/2-HAL/3-ICU_Driver/src/subdir.mk
-include cots/1-MCAL/6-Watch_DogDriver/Source/subdir.mk
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
WATDOG_Driver.lss \

SIZEDUMMY += \
sizedummy \


# All Target
all: WATDOG_Driver.elf secondary-outputs

# Tool invocations
WATDOG_Driver.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,WATDOG_Driver.map -mmcu=atmega32 -o "WATDOG_Driver.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

WATDOG_Driver.lss: WATDOG_Driver.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S WATDOG_Driver.elf  >"WATDOG_Driver.lss"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: WATDOG_Driver.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 WATDOG_Driver.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) WATDOG_Driver.elf
	-@echo ' '

secondary-outputs: $(LSS) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
