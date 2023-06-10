################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables
C_SRCS += \
../qe_gen/qe_touch_config.c \
../qe_gen/qe_touch_sample.c 

COMPILER_OBJS += \
qe_gen/qe_touch_config.obj \
qe_gen/qe_touch_sample.obj 

C_DEPS += \
qe_gen/qe_touch_config.d \
qe_gen/qe_touch_sample.d 

# Each subdirectory must supply rules for building sources it contributes
qe_gen/%.obj: ../qe_gen/%.c 
	@echo 'Scanning and building file: $<'
	@echo 'Invoking: Scanner and Compiler'
	@echo qe_gen\cDepSubCommand.tmp=
	@sed -e "s/^/ /" "qe_gen\cDepSubCommand.tmp"
	ccrx -subcommand="qe_gen\cDepSubCommand.tmp" -output=dep="$(@:%.obj=%.d)"  -MT="$(@:%.d=%.obj)"  -MT="$(@:%.obj=%.d)" "$<"
	@echo qe_gen\cSubCommand.tmp=
	@sed -e "s/^/ /" "qe_gen\cSubCommand.tmp"
	ccrx -subcommand="qe_gen\cSubCommand.tmp" "$<"
	@echo 'Finished Scanning and building: $<'
	@echo ''

