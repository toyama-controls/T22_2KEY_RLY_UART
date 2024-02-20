################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include makefile.init

RM := rm -rf *.sni *.dbg *.lst *.lis *.lpp *.map *.x *.lbp *.bls *.libelf *.rel *.lbk *.abs *.mi *.jmp *.fsy *.ud *.udm 1st/*.abs 1st/*.jmp 1st/*.fsy

# All of the sources participating in the build are defined here
-include sources.mk
-include src/smc_gen/rm_touch_qe/src/subdir.mk
-include src/smc_gen/r_pincfg/subdir.mk
-include src/smc_gen/Config_RIIC0/subdir.mk
-include qe_gen/subdir.mk
-include src/smc_gen/Config_PORT/subdir.mk
-include src/smc_gen/r_bsp/mcu/rx130/subdir.mk
-include src/smc_gen/Config_SCI12/subdir.mk
-include src/smc_gen/rm_touch_qe/wrapper/subdir.mk
-include src/smc_gen/r_ctsu_qe/src/subdir.mk
-include src/smc_gen/general/subdir.mk
-include src/smc_gen/Config_CMT0/subdir.mk
-include src/subdir.mk
-include src/smc_gen/r_bsp/mcu/all/subdir.mk
-include src/smc_gen/r_bsp/board/generic_rx130/subdir.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif 
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif 
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif 
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif 
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif 
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif 
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif 
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif 
ifneq ($(strip $(SX_DEPS)),)
-include $(SX_DEPS)
endif 
ifneq ($(strip $(JMP_DEPS)),)
-include $(JMP_DEPS)
endif 
ifneq ($(strip $(SRC_DEPS)),)
-include $(SRC_DEPS)
endif 
ifneq ($(strip $(PP_DEPS)),)
-include $(PP_DEPS)
endif 
ifneq ($(strip $(P_DEPS)),)
-include $(P_DEPS)
endif 
ifneq ($(strip $(FSY_DEPS)),)
-include $(FSY_DEPS)
endif 
endif

ifneq ($(strip $(SRC_UPPER_SRCS)),)
ALL_ASMS += $(SRC_UPPER_SRCS) 
endif
ifneq ($(strip $(SRC_SRCS)),)
ALL_ASMS += $(SRC_SRCS) 
endif
ifneq ($(strip $(S_UPPER_SRCS)),)
ALL_ASMS += $(S_UPPER_SRCS) 
endif
ifneq ($(strip $(S_SRCS)),)
ALL_ASMS += $(S_SRCS) 
endif


-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables
LINKER_OUTPUT_OUTPUTS += \
T22_2KEY_RLY_UART.abs

LIBRARY_GENERATOR_OUTPUTTYPE_OUTPUTS += \
T22_2KEY_RLY_UART.lib

CONVERTOR_OUTPUT_OUTPUTS += \
T22_2KEY_RLY_UART.hex T22_2KEY_RLY_UART.bin

OBJS := \
$(COMPILER_OBJS) \
$(INDIVIDUAL_COMPILER_OBJS) \
$(ASSEMBLER_OBJS) \
$(CUSTOM_OBJS)

# All Target
all: $(CONVERTOR_OUTPUT_OUTPUTS) T22_2KEY_RLY_UART.x T22_2KEY_RLY_UART.udm

	@echo 'Build complete.'

%.hex %.bin: $(LINKER_OUTPUT_OUTPUTS) Converter.sub
	@echo 'Invoking: Converter'
	@echo 'Building target:'
	@echo ConverterT22_2KEY_RLY_UART.tmp=
	@sed -e "s/^/    /" "ConverterT22_2KEY_RLY_UART.tmp"
	rlink -subcommand="ConverterT22_2KEY_RLY_UART.tmp"
	@echo 'Finished building target:'
	@echo ''


T22_2KEY_RLY_UART.abs: $(OBJS)  $(ALL_ASMS) $(LIBRARY_GENERATOR_OUTPUTTYPE_OUTPUTS) 
	@echo 'Invoking: Linker'
	@echo LinkerT22_2KEY_RLY_UART.tmp=
	@sed -e "s/^/    /" "LinkerT22_2KEY_RLY_UART.tmp"
	rlink -subcommand="LinkerT22_2KEY_RLY_UART.tmp"
	@echo 'Finished building:'
	@echo ''


T22_2KEY_RLY_UART.lib: 
	@echo 'Invoking: Library Generator'
	@echo LibraryGeneratorT22_2KEY_RLY_UART.tmp=
	@sed -e "s/^/    /" "LibraryGeneratorT22_2KEY_RLY_UART.tmp"
	lbgrx -subcommand="LibraryGeneratorT22_2KEY_RLY_UART.tmp"
	@echo 'Finished building:'
	@echo ''

T22_2KEY_RLY_UART.x: T22_2KEY_RLY_UART.abs
		-C:\Users\Aishwarya\.eclipse\com.renesas.platform_26289591\Utilities\\ccrx\renesas_cc_converter T22_2KEY_RLY_UART.abs T22_2KEY_RLY_UART.x

T22_2KEY_RLY_UART.udm: $(LINKER_OUTPUT_OUTPUTS) $(CONVERTOR_OUTPUT_OUTPUTS)
	udcollector -subcommand=udSubcommand.tmp -output=T22_2KEY_RLY_UART.udm

# Other Targets
clean:
	-$(RM) $(LINKER_OUTPUT_OUTPUTS) $(LIBRARY_GENERATOR_OUTPUTTYPE_OUTPUTS) $(CONVERTOR_OUTPUT_OUTPUTS)
ifneq ($(strip $(OBJS)),)
	-$(file > clean_OBJS.tmp, $(OBJS))
	-@xargs -s 4000 -t -a clean_OBJS.tmp rm -rf
	-@rm -rf clean_OBJS.tmp
endif
ifneq ($(strip $(C_DEPS)),)
	-$(file > clean_C_DEPS.tmp, $(C_DEPS))
	-@xargs -s 4000 -t -a clean_C_DEPS.tmp rm -rf
	-@rm -rf clean_C_DEPS.tmp
endif
ifneq ($(strip $(CPP_DEPS)),)
	-$(file > clean_CPP_DEPS.tmp, $(CPP_DEPS))
	-@xargs -s 4000 -t -a clean_CPP_DEPS.tmp rm -rf
	-@rm -rf clean_CPP_DEPS.tmp
endif
ifneq ($(strip $(ASM_DEPS)),)
	-$(file > clean_ASM_DEPS.tmp, $(ASM_DEPS))
	-@xargs -s 4000 -t -a clean_ASM_DEPS.tmp rm -rf
	-@rm -rf clean_ASM_DEPS.tmp
endif
ifneq ($(strip $(DSP_DEPS)),)
	-$(file > clean_DSP_DEPS.tmp, $(DSP_DEPS))
	-@xargs -s 4000 -t -a clean_DSP_DEPS.tmp rm -rf
	-@rm -rf clean_DSP_DEPS.tmp
endif
	-rm -rf src/smc_gen/rm_touch_qe/src/*.asm src/smc_gen/rm_touch_qe/src/*.p src/smc_gen/rm_touch_qe/src/*.pp src/smc_gen/rm_touch_qe/src/*.src src/smc_gen/rm_touch_qe/src/*.jmp src/smc_gen/rm_touch_qe/src/*.lst src/smc_gen/rm_touch_qe/src/*.prn src/smc_gen/rm_touch_qe/src/*.i src/smc_gen/rm_touch_qe/src/*.ud 
	-rm -rf src/smc_gen/r_pincfg/*.asm src/smc_gen/r_pincfg/*.p src/smc_gen/r_pincfg/*.pp src/smc_gen/r_pincfg/*.src src/smc_gen/r_pincfg/*.jmp src/smc_gen/r_pincfg/*.lst src/smc_gen/r_pincfg/*.prn src/smc_gen/r_pincfg/*.i src/smc_gen/r_pincfg/*.ud 
	-rm -rf src/smc_gen/Config_RIIC0/*.asm src/smc_gen/Config_RIIC0/*.p src/smc_gen/Config_RIIC0/*.pp src/smc_gen/Config_RIIC0/*.src src/smc_gen/Config_RIIC0/*.jmp src/smc_gen/Config_RIIC0/*.lst src/smc_gen/Config_RIIC0/*.prn src/smc_gen/Config_RIIC0/*.i src/smc_gen/Config_RIIC0/*.ud 
	-rm -rf qe_gen/*.asm qe_gen/*.p qe_gen/*.pp qe_gen/*.src qe_gen/*.jmp qe_gen/*.lst qe_gen/*.prn qe_gen/*.i qe_gen/*.ud 
	-rm -rf src/smc_gen/Config_PORT/*.asm src/smc_gen/Config_PORT/*.p src/smc_gen/Config_PORT/*.pp src/smc_gen/Config_PORT/*.src src/smc_gen/Config_PORT/*.jmp src/smc_gen/Config_PORT/*.lst src/smc_gen/Config_PORT/*.prn src/smc_gen/Config_PORT/*.i src/smc_gen/Config_PORT/*.ud 
	-rm -rf src/smc_gen/r_bsp/mcu/rx130/*.asm src/smc_gen/r_bsp/mcu/rx130/*.p src/smc_gen/r_bsp/mcu/rx130/*.pp src/smc_gen/r_bsp/mcu/rx130/*.src src/smc_gen/r_bsp/mcu/rx130/*.jmp src/smc_gen/r_bsp/mcu/rx130/*.lst src/smc_gen/r_bsp/mcu/rx130/*.prn src/smc_gen/r_bsp/mcu/rx130/*.i src/smc_gen/r_bsp/mcu/rx130/*.ud 
	-rm -rf src/smc_gen/Config_SCI12/*.asm src/smc_gen/Config_SCI12/*.p src/smc_gen/Config_SCI12/*.pp src/smc_gen/Config_SCI12/*.src src/smc_gen/Config_SCI12/*.jmp src/smc_gen/Config_SCI12/*.lst src/smc_gen/Config_SCI12/*.prn src/smc_gen/Config_SCI12/*.i src/smc_gen/Config_SCI12/*.ud 
	-rm -rf src/smc_gen/rm_touch_qe/wrapper/*.asm src/smc_gen/rm_touch_qe/wrapper/*.p src/smc_gen/rm_touch_qe/wrapper/*.pp src/smc_gen/rm_touch_qe/wrapper/*.src src/smc_gen/rm_touch_qe/wrapper/*.jmp src/smc_gen/rm_touch_qe/wrapper/*.lst src/smc_gen/rm_touch_qe/wrapper/*.prn src/smc_gen/rm_touch_qe/wrapper/*.i src/smc_gen/rm_touch_qe/wrapper/*.ud 
	-rm -rf src/smc_gen/r_ctsu_qe/src/*.asm src/smc_gen/r_ctsu_qe/src/*.p src/smc_gen/r_ctsu_qe/src/*.pp src/smc_gen/r_ctsu_qe/src/*.src src/smc_gen/r_ctsu_qe/src/*.jmp src/smc_gen/r_ctsu_qe/src/*.lst src/smc_gen/r_ctsu_qe/src/*.prn src/smc_gen/r_ctsu_qe/src/*.i src/smc_gen/r_ctsu_qe/src/*.ud 
	-rm -rf src/smc_gen/general/*.asm src/smc_gen/general/*.p src/smc_gen/general/*.pp src/smc_gen/general/*.src src/smc_gen/general/*.jmp src/smc_gen/general/*.lst src/smc_gen/general/*.prn src/smc_gen/general/*.i src/smc_gen/general/*.ud 
	-rm -rf src/smc_gen/Config_CMT0/*.asm src/smc_gen/Config_CMT0/*.p src/smc_gen/Config_CMT0/*.pp src/smc_gen/Config_CMT0/*.src src/smc_gen/Config_CMT0/*.jmp src/smc_gen/Config_CMT0/*.lst src/smc_gen/Config_CMT0/*.prn src/smc_gen/Config_CMT0/*.i src/smc_gen/Config_CMT0/*.ud 
	-rm -rf src/*.asm src/*.p src/*.pp src/*.src src/*.jmp src/*.lst src/*.prn src/*.i src/*.ud 
	-rm -rf src/smc_gen/r_bsp/mcu/all/*.asm src/smc_gen/r_bsp/mcu/all/*.p src/smc_gen/r_bsp/mcu/all/*.pp src/smc_gen/r_bsp/mcu/all/*.src src/smc_gen/r_bsp/mcu/all/*.jmp src/smc_gen/r_bsp/mcu/all/*.lst src/smc_gen/r_bsp/mcu/all/*.prn src/smc_gen/r_bsp/mcu/all/*.i src/smc_gen/r_bsp/mcu/all/*.ud 
	-rm -rf src/smc_gen/r_bsp/board/generic_rx130/*.asm src/smc_gen/r_bsp/board/generic_rx130/*.p src/smc_gen/r_bsp/board/generic_rx130/*.pp src/smc_gen/r_bsp/board/generic_rx130/*.src src/smc_gen/r_bsp/board/generic_rx130/*.jmp src/smc_gen/r_bsp/board/generic_rx130/*.lst src/smc_gen/r_bsp/board/generic_rx130/*.prn src/smc_gen/r_bsp/board/generic_rx130/*.i src/smc_gen/r_bsp/board/generic_rx130/*.ud 
	@echo ''
	@echo 'Clean complete.'

.PHONY: all clean  $(LINKER_OUTPUT_OUTPUTS)  $(LIBRARY_GENERATOR_OUTPUTTYPE_OUTPUTS)  
-include ../makefile.targets