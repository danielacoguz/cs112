################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Matrix.cpp \
../MatrixTester.cpp \
../Vec.cpp \
../VecTester.cpp \
../tester.cpp 

OBJS += \
./Matrix.o \
./MatrixTester.o \
./Vec.o \
./VecTester.o \
./tester.o 

CPP_DEPS += \
./Matrix.d \
./MatrixTester.d \
./Vec.d \
./VecTester.d \
./tester.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


