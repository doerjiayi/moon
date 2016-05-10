################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include x64/Debug/subdir.mk
-include net/netGate/win/wsa/subdir.mk
-include net/netGate/win/iocp/subdir.mk
-include net/netGate/select/subdir.mk
-include net/netGate/linux/epoll/subdir.mk
-include net/netGate/dataProcess/subdir.mk
-include net/netGate/base/subdir.mk
-include net/netGate/subdir.mk
-include logic/units/team/subdir.mk
-include logic/units/skill/subdir.mk
-include logic/units/doerUnit/subdir.mk
-include logic/units/command/subdir.mk
-include logic/server/subdir.mk
-include logic/scriptSystem/luaInterface/subdir.mk
-include logic/scriptSystem/subdir.mk
-include logic/memory/subdir.mk
-include logic/map/subdir.mk
-include logic/event/subdir.mk
-include logic/engine/monsterEngine/subdir.mk
-include logic/engine/logicEngine/subdir.mk
-include logic/doer/subdir.mk
-include dbClient/gameLog/subdir.mk
-include dbClient/dbm/subdir.mk
-include dbClient/account/subdir.mk
-include config/subdir.mk
-include accessor/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: moon

# Tool invocations
moon: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: GCC C++ Linker'
	g++ -L../../../moonLib/Debug -L/usr/lib64/mysql/ -L../../../libs/linux -o "moon" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C++_DEPS)$(C_DEPS)$(CC_DEPS)$(CPP_DEPS)$(EXECUTABLES)$(CXX_DEPS)$(C_UPPER_DEPS) moon
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
