################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables
C_SRCS += \
../src/EEPROM.c \
../src/T22_2KEY_RLY_UART.c \
../src/TOUCH_LED.c \
../src/UART.c 

COMPILER_OBJS += \
src/EEPROM.obj \
src/T22_2KEY_RLY_UART.obj \
src/TOUCH_LED.obj \
src/UART.obj 

C_DEPS += \
src/EEPROM.d \
src/T22_2KEY_RLY_UART.d \
src/TOUCH_LED.d \
src/UART.d 

# Each subdirectory must supply rules for building sources it contributes
src/%.obj: ../src/%.c src/Compiler.sub
	@echo 'Scanning and building file: $<'
	@echo 'Invoking: Scanner and Compiler'
	@echo src\cDepSubCommand.tmp=
	@sed -e "s/^/ /" "src\cDepSubCommand.tmp"
	ccrx -subcommand="src\cDepSubCommand.tmp" -output=dep="$(@:%.obj=%.d)"  -MT="$(@:%.d=%.obj)"  -MT="$(@:%.obj=%.d)" "$<"
	@echo src\cSubCommand.tmp=
	@sed -e "s/^/ /" "src\cSubCommand.tmp"
	ccrx -subcommand="src\cSubCommand.tmp" "$<"
	@echo 'Finished Scanning and building: $<'
	@echo ''

