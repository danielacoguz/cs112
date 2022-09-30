################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../CongaLine.cpp \
../main\ (1).cpp 

OBJS += \
./CongaLine.o \
./main\ (1).o 

CPP_DEPS += \
./CongaLine.d \
./main\ (1).d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

main\ (1).o: ../main\ (1).cpp subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"main (1).d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


