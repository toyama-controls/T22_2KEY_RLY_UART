################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables
C_SRCS += \
../src/smc_gen/r_ctsu_qe/src/r_ctsu_qe.c 

COMPILER_OBJS += \
src/smc_gen/r_ctsu_qe/src/r_ctsu_qe.obj 

C_DEPS += \
src/smc_gen/r_ctsu_qe/src/r_ctsu_qe.d 

# Each subdirectory must supply rules for building sources it contributes
src/smc_gen/r_ctsu_qe/src/%.obj: ../src/smc_gen/r_ctsu_qe/src/%.c 
	@echo 'Scanning and building file: $<'
	@echo 'Invoking: Scanner and Compiler'
	@echo src\smc_gen\r_ctsu_qe\src\cDepSubCommand.tmp=
	@sed -e "s/^/ /" "src\smc_gen\r_ctsu_qe\src\cDepSubCommand.tmp"
	ccrx -subcommand="src\smc_gen\r_ctsu_qe\src\cDepSubCommand.tmp" -output=dep="$(@:%.obj=%.d)"  -MT="$(@:%.d=%.obj)"  -MT="$(@:%.obj=%.d)" "$<"
	@echo src\smc_gen\r_ctsu_qe\src\cSubCommand.tmp=
	@sed -e "s/^/ /" "src\smc_gen\r_ctsu_qe\src\cSubCommand.tmp"
	ccrx -subcommand="src\smc_gen\r_ctsu_qe\src\cSubCommand.tmp" "$<"
	@echo 'Finished Scanning and building: $<'
	@echo ''

