################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables
C_SRCS += \
../src/smc_gen/Config_RIIC0/Config_RIIC0.c \
../src/smc_gen/Config_RIIC0/Config_RIIC0_user.c 

COMPILER_OBJS += \
src/smc_gen/Config_RIIC0/Config_RIIC0.obj \
src/smc_gen/Config_RIIC0/Config_RIIC0_user.obj 

C_DEPS += \
src/smc_gen/Config_RIIC0/Config_RIIC0.d \
src/smc_gen/Config_RIIC0/Config_RIIC0_user.d 

# Each subdirectory must supply rules for building sources it contributes
src/smc_gen/Config_RIIC0/%.obj: ../src/smc_gen/Config_RIIC0/%.c src/smc_gen/Config_RIIC0/Compiler.sub
	@echo 'Scanning and building file: $<'
	@echo 'Invoking: Scanner and Compiler'
	@echo src\smc_gen\Config_RIIC0\cDepSubCommand.tmp=
	@sed -e "s/^/ /" "src\smc_gen\Config_RIIC0\cDepSubCommand.tmp"
	ccrx -subcommand="src\smc_gen\Config_RIIC0\cDepSubCommand.tmp" -output=dep="$(@:%.obj=%.d)"  -MT="$(@:%.d=%.obj)"  -MT="$(@:%.obj=%.d)" "$<"
	@echo src\smc_gen\Config_RIIC0\cSubCommand.tmp=
	@sed -e "s/^/ /" "src\smc_gen\Config_RIIC0\cSubCommand.tmp"
	ccrx -subcommand="src\smc_gen\Config_RIIC0\cSubCommand.tmp" "$<"
	@echo 'Finished Scanning and building: $<'
	@echo ''

