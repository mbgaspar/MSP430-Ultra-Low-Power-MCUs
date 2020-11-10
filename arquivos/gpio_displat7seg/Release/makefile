################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include lib/subdir.mk
-include display/subdir.mk
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
gpio_displat7seg.lss \

FLASH_IMAGE += \
gpio_displat7seg.hex \

EEPROM_IMAGE += \
gpio_displat7seg.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: gpio_displat7seg.elf secondary-outputs

# Tool invocations
gpio_displat7seg.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,gpio_displat7seg.map -mmcu=atmega328p -o "gpio_displat7seg.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

gpio_displat7seg.lss: gpio_displat7seg.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S gpio_displat7seg.elf  >"gpio_displat7seg.lss"
	@echo 'Finished building: $@'
	@echo ' '

gpio_displat7seg.hex: gpio_displat7seg.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex gpio_displat7seg.elf  "gpio_displat7seg.hex"
	@echo 'Finished building: $@'
	@echo ' '

gpio_displat7seg.eep: gpio_displat7seg.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex gpio_displat7seg.elf  "gpio_displat7seg.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: gpio_displat7seg.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=berkeley -t gpio_displat7seg.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) gpio_displat7seg.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents

-include ../makefile.targets
