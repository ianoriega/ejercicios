################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Empleado.c \
../src/arr.c \
../src/clase18_05.c \
../src/matOp.c \
../src/utn.c 

OBJS += \
./src/Empleado.o \
./src/arr.o \
./src/clase18_05.o \
./src/matOp.o \
./src/utn.o 

C_DEPS += \
./src/Empleado.d \
./src/arr.d \
./src/clase18_05.d \
./src/matOp.d \
./src/utn.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


