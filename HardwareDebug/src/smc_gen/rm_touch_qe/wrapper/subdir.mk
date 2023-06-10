################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables
C_SRCS += \
../src/smc_gen/rm_touch_qe/wrapper/r_touch_wrapper_qe.c 

COMPILER_OBJS += \
src/smc_gen/rm_touch_qe/wrapper/r_touch_wrapper_qe.obj 

C_DEPS += \
src/smc_gen/rm_touch_qe/wrapper/r_touch_wrapper_qe.d 

# Each subdirectory must supply rules for building sources it contributes
src/smc_gen/rm_touch_qe/wrapper/%.obj: ../src/smc_gen/rm_touch_qe/wrapper/%.c 
	@echo 'Scanning and building file: $<'
	@echo 'Invoking: Scanner and Compiler'
	@echo src\smc_gen\rm_touch_qe\wrapper\cDepSubCommand.tmp=
	@sed -e "s/^/ /" "src\smc_gen\rm_touch_qe\wrapper\cDepSubCommand.tmp"
	ccrx -subcommand="src\smc_gen\rm_touch_qe\wrapper\cDepSubCommand.tmp" -output=dep="$(@:%.obj=%.d)"  -MT="$(@:%.d=%.obj)"  -MT="$(@:%.obj=%.d)" "$<"
	@echo src\smc_gen\rm_touch_qe\wrapper\cSubCommand.tmp=
	@sed -e "s/^/ /" "src\smc_gen\rm_touch_qe\wrapper\cSubCommand.tmp"
	ccrx -subcommand="src\smc_gen\rm_touch_qe\wrapper\cSubCommand.tmp" "$<"
	@echo 'Finished Scanning and building: $<'
	@echo ''

