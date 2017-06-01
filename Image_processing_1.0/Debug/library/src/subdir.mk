################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../library/src/Four_windows_opencv.cpp \
../library/src/Image_load.cpp \
../library/src/Two_windows_opencv.cpp \
../library/src/main.cpp 

O_SRCS += \
../library/src/Four_windows_opencv.o \
../library/src/Image_load.o \
../library/src/Two_windows_opencv.o \
../library/src/main.o 

OBJS += \
./library/src/Four_windows_opencv.o \
./library/src/Image_load.o \
./library/src/Two_windows_opencv.o \
./library/src/main.o 

CPP_DEPS += \
./library/src/Four_windows_opencv.d \
./library/src/Image_load.d \
./library/src/Two_windows_opencv.d \
./library/src/main.d 


# Each subdirectory must supply rules for building sources it contributes
library/src/%.o: ../library/src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/include/opencv -I/usr/lib -I/usr/local/include -include/usr/include/armadillo -O2 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


