#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
MACRO1=__SUPPRESS_PLIB_WARNING
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/FloodIt.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/FloodIt.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS

else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=porta_in.c portb_out.c main.c debounce.c timer.c adc_intf.c glcdfont.c tft_gfx.c tft_master.c draw_screen.c fillsquares.c floodit_fsm.c Adafruit_DotStar.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/porta_in.o ${OBJECTDIR}/portb_out.o ${OBJECTDIR}/main.o ${OBJECTDIR}/debounce.o ${OBJECTDIR}/timer.o ${OBJECTDIR}/adc_intf.o ${OBJECTDIR}/glcdfont.o ${OBJECTDIR}/tft_gfx.o ${OBJECTDIR}/tft_master.o ${OBJECTDIR}/draw_screen.o ${OBJECTDIR}/fillsquares.o ${OBJECTDIR}/floodit_fsm.o ${OBJECTDIR}/Adafruit_DotStar.o
POSSIBLE_DEPFILES=${OBJECTDIR}/porta_in.o.d ${OBJECTDIR}/portb_out.o.d ${OBJECTDIR}/main.o.d ${OBJECTDIR}/debounce.o.d ${OBJECTDIR}/timer.o.d ${OBJECTDIR}/adc_intf.o.d ${OBJECTDIR}/glcdfont.o.d ${OBJECTDIR}/tft_gfx.o.d ${OBJECTDIR}/tft_master.o.d ${OBJECTDIR}/draw_screen.o.d ${OBJECTDIR}/fillsquares.o.d ${OBJECTDIR}/floodit_fsm.o.d ${OBJECTDIR}/Adafruit_DotStar.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/porta_in.o ${OBJECTDIR}/portb_out.o ${OBJECTDIR}/main.o ${OBJECTDIR}/debounce.o ${OBJECTDIR}/timer.o ${OBJECTDIR}/adc_intf.o ${OBJECTDIR}/glcdfont.o ${OBJECTDIR}/tft_gfx.o ${OBJECTDIR}/tft_master.o ${OBJECTDIR}/draw_screen.o ${OBJECTDIR}/fillsquares.o ${OBJECTDIR}/floodit_fsm.o ${OBJECTDIR}/Adafruit_DotStar.o

# Source Files
SOURCEFILES=porta_in.c portb_out.c main.c debounce.c timer.c adc_intf.c glcdfont.c tft_gfx.c tft_master.c draw_screen.c fillsquares.c floodit_fsm.c Adafruit_DotStar.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/FloodIt.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=32MX250F128B
MP_LINKER_FILE_OPTION=
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/porta_in.o: porta_in.c  .generated_files/flags/default/d46b547db5b6b29e920bf30702efea418135ee49 .generated_files/flags/default/fa77e48c5d6b209b0dbc904325b3870195f7a677
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/porta_in.o.d 
	@${RM} ${OBJECTDIR}/porta_in.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/porta_in.o.d" -o ${OBJECTDIR}/porta_in.o porta_in.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/portb_out.o: portb_out.c  .generated_files/flags/default/1c3b7eee65ade0aa4ed79808d57f1210a163d04b .generated_files/flags/default/fa77e48c5d6b209b0dbc904325b3870195f7a677
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/portb_out.o.d 
	@${RM} ${OBJECTDIR}/portb_out.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/portb_out.o.d" -o ${OBJECTDIR}/portb_out.o portb_out.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/main.o: main.c  .generated_files/flags/default/80abc17fbc16b4a2adb57274f25a61a0abc3211b .generated_files/flags/default/fa77e48c5d6b209b0dbc904325b3870195f7a677
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/main.o.d" -o ${OBJECTDIR}/main.o main.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/debounce.o: debounce.c  .generated_files/flags/default/4c6e102dbdf782c8b55dc89aa806b3d5f763f7cd .generated_files/flags/default/fa77e48c5d6b209b0dbc904325b3870195f7a677
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/debounce.o.d 
	@${RM} ${OBJECTDIR}/debounce.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/debounce.o.d" -o ${OBJECTDIR}/debounce.o debounce.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/timer.o: timer.c  .generated_files/flags/default/6aee89954f597da548a8586e98aae4a059f3ddd4 .generated_files/flags/default/fa77e48c5d6b209b0dbc904325b3870195f7a677
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/timer.o.d 
	@${RM} ${OBJECTDIR}/timer.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/timer.o.d" -o ${OBJECTDIR}/timer.o timer.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/adc_intf.o: adc_intf.c  .generated_files/flags/default/938b8e71de348580c697d727e78578982de4d6a5 .generated_files/flags/default/fa77e48c5d6b209b0dbc904325b3870195f7a677
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/adc_intf.o.d 
	@${RM} ${OBJECTDIR}/adc_intf.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/adc_intf.o.d" -o ${OBJECTDIR}/adc_intf.o adc_intf.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/glcdfont.o: glcdfont.c  .generated_files/flags/default/f067a563f170db4855e5cdc20fc3cac6d2c3507c .generated_files/flags/default/fa77e48c5d6b209b0dbc904325b3870195f7a677
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/glcdfont.o.d 
	@${RM} ${OBJECTDIR}/glcdfont.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/glcdfont.o.d" -o ${OBJECTDIR}/glcdfont.o glcdfont.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/tft_gfx.o: tft_gfx.c  .generated_files/flags/default/39de69dfb96fdfc756c0f308e9744310fa251593 .generated_files/flags/default/fa77e48c5d6b209b0dbc904325b3870195f7a677
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/tft_gfx.o.d 
	@${RM} ${OBJECTDIR}/tft_gfx.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/tft_gfx.o.d" -o ${OBJECTDIR}/tft_gfx.o tft_gfx.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/tft_master.o: tft_master.c  .generated_files/flags/default/d681c0499bf07a8452e6ba240d4707113fdd7981 .generated_files/flags/default/fa77e48c5d6b209b0dbc904325b3870195f7a677
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/tft_master.o.d 
	@${RM} ${OBJECTDIR}/tft_master.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/tft_master.o.d" -o ${OBJECTDIR}/tft_master.o tft_master.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/draw_screen.o: draw_screen.c  .generated_files/flags/default/e06e7e31ff61db2a7a3e1c55d29514f813e6eb3c .generated_files/flags/default/fa77e48c5d6b209b0dbc904325b3870195f7a677
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/draw_screen.o.d 
	@${RM} ${OBJECTDIR}/draw_screen.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/draw_screen.o.d" -o ${OBJECTDIR}/draw_screen.o draw_screen.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/fillsquares.o: fillsquares.c  .generated_files/flags/default/e5cd6a5fc12781a165bb1dd408811b19472ce7bb .generated_files/flags/default/fa77e48c5d6b209b0dbc904325b3870195f7a677
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/fillsquares.o.d 
	@${RM} ${OBJECTDIR}/fillsquares.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/fillsquares.o.d" -o ${OBJECTDIR}/fillsquares.o fillsquares.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/floodit_fsm.o: floodit_fsm.c  .generated_files/flags/default/53b629cd8cdc14f2bb8fe3b8fda442d02176a2f6 .generated_files/flags/default/fa77e48c5d6b209b0dbc904325b3870195f7a677
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/floodit_fsm.o.d 
	@${RM} ${OBJECTDIR}/floodit_fsm.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/floodit_fsm.o.d" -o ${OBJECTDIR}/floodit_fsm.o floodit_fsm.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/Adafruit_DotStar.o: Adafruit_DotStar.c  .generated_files/flags/default/c759dfca12759fe9d43f6e97c3b5c8f1ac7c324a .generated_files/flags/default/fa77e48c5d6b209b0dbc904325b3870195f7a677
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Adafruit_DotStar.o.d 
	@${RM} ${OBJECTDIR}/Adafruit_DotStar.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Adafruit_DotStar.o.d" -o ${OBJECTDIR}/Adafruit_DotStar.o Adafruit_DotStar.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)    
	
else
${OBJECTDIR}/porta_in.o: porta_in.c  .generated_files/flags/default/6b09305678deac13832d0e94b95b16338f96bdcc .generated_files/flags/default/fa77e48c5d6b209b0dbc904325b3870195f7a677
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/porta_in.o.d 
	@${RM} ${OBJECTDIR}/porta_in.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/porta_in.o.d" -o ${OBJECTDIR}/porta_in.o porta_in.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/portb_out.o: portb_out.c  .generated_files/flags/default/b9ae1c9570b17e6569002d113340480f6bf5c309 .generated_files/flags/default/fa77e48c5d6b209b0dbc904325b3870195f7a677
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/portb_out.o.d 
	@${RM} ${OBJECTDIR}/portb_out.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/portb_out.o.d" -o ${OBJECTDIR}/portb_out.o portb_out.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/main.o: main.c  .generated_files/flags/default/47e6c7a714c774b11762767a055341f36e682fcc .generated_files/flags/default/fa77e48c5d6b209b0dbc904325b3870195f7a677
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/main.o.d" -o ${OBJECTDIR}/main.o main.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/debounce.o: debounce.c  .generated_files/flags/default/bf2fd6d4597af7fb8f4a20f50b56523790187eae .generated_files/flags/default/fa77e48c5d6b209b0dbc904325b3870195f7a677
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/debounce.o.d 
	@${RM} ${OBJECTDIR}/debounce.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/debounce.o.d" -o ${OBJECTDIR}/debounce.o debounce.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/timer.o: timer.c  .generated_files/flags/default/e3f2fbeef94c75abb0ad1908dcd4dcf4747f779c .generated_files/flags/default/fa77e48c5d6b209b0dbc904325b3870195f7a677
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/timer.o.d 
	@${RM} ${OBJECTDIR}/timer.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/timer.o.d" -o ${OBJECTDIR}/timer.o timer.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/adc_intf.o: adc_intf.c  .generated_files/flags/default/4fe03084f02c1054ebe2c068f4302e6ee4b4fc7e .generated_files/flags/default/fa77e48c5d6b209b0dbc904325b3870195f7a677
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/adc_intf.o.d 
	@${RM} ${OBJECTDIR}/adc_intf.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/adc_intf.o.d" -o ${OBJECTDIR}/adc_intf.o adc_intf.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/glcdfont.o: glcdfont.c  .generated_files/flags/default/17916bed826546a563129930ca27d435d633047e .generated_files/flags/default/fa77e48c5d6b209b0dbc904325b3870195f7a677
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/glcdfont.o.d 
	@${RM} ${OBJECTDIR}/glcdfont.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/glcdfont.o.d" -o ${OBJECTDIR}/glcdfont.o glcdfont.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/tft_gfx.o: tft_gfx.c  .generated_files/flags/default/5282a7dfe16e495a74d1091b7d598f9cdcd02c81 .generated_files/flags/default/fa77e48c5d6b209b0dbc904325b3870195f7a677
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/tft_gfx.o.d 
	@${RM} ${OBJECTDIR}/tft_gfx.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/tft_gfx.o.d" -o ${OBJECTDIR}/tft_gfx.o tft_gfx.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/tft_master.o: tft_master.c  .generated_files/flags/default/74ad10aa17c5ccaee1861abe3d3d8ad7e4d033ce .generated_files/flags/default/fa77e48c5d6b209b0dbc904325b3870195f7a677
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/tft_master.o.d 
	@${RM} ${OBJECTDIR}/tft_master.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/tft_master.o.d" -o ${OBJECTDIR}/tft_master.o tft_master.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/draw_screen.o: draw_screen.c  .generated_files/flags/default/72ed6f56927215392c328c16176708f2dfc67c1e .generated_files/flags/default/fa77e48c5d6b209b0dbc904325b3870195f7a677
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/draw_screen.o.d 
	@${RM} ${OBJECTDIR}/draw_screen.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/draw_screen.o.d" -o ${OBJECTDIR}/draw_screen.o draw_screen.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/fillsquares.o: fillsquares.c  .generated_files/flags/default/1a9752db4a0a6494d5df452a52eccd3cfb3b9ed7 .generated_files/flags/default/fa77e48c5d6b209b0dbc904325b3870195f7a677
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/fillsquares.o.d 
	@${RM} ${OBJECTDIR}/fillsquares.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/fillsquares.o.d" -o ${OBJECTDIR}/fillsquares.o fillsquares.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/floodit_fsm.o: floodit_fsm.c  .generated_files/flags/default/a161e9b1acc812ba7aecf354d1aaa0d029a791eb .generated_files/flags/default/fa77e48c5d6b209b0dbc904325b3870195f7a677
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/floodit_fsm.o.d 
	@${RM} ${OBJECTDIR}/floodit_fsm.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/floodit_fsm.o.d" -o ${OBJECTDIR}/floodit_fsm.o floodit_fsm.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/Adafruit_DotStar.o: Adafruit_DotStar.c  .generated_files/flags/default/43284666bfd5a6a78d8cad68277a596d0d20157d .generated_files/flags/default/fa77e48c5d6b209b0dbc904325b3870195f7a677
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Adafruit_DotStar.o.d 
	@${RM} ${OBJECTDIR}/Adafruit_DotStar.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Adafruit_DotStar.o.d" -o ${OBJECTDIR}/Adafruit_DotStar.o Adafruit_DotStar.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)    
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/FloodIt.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -g -mdebugger -D__MPLAB_DEBUGGER_PK3=1 -mprocessor=$(MP_PROCESSOR_OPTION)  -o ${DISTDIR}/FloodIt.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)   -mreserve=data@0x0:0x1FC -mreserve=boot@0x1FC00490:0x1FC00BEF  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D=__DEBUG_D,--defsym=__MPLAB_DEBUGGER_PK3=1,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,${DISTDIR}/memoryfile.xml 
	
else
${DISTDIR}/FloodIt.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION)  -o ${DISTDIR}/FloodIt.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,${DISTDIR}/memoryfile.xml 
	${MP_CC_DIR}\\xc32-bin2hex ${DISTDIR}/FloodIt.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} 
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${OBJECTDIR}
	${RM} -r ${DISTDIR}

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
