################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Four_windows_opencv.cpp \
../src/Image_load.cpp \
../src/Two_windows_opencv.cpp \
../src/main.cpp \
../src/main_Gaussian_noise.cpp \
../src/main_Lost_pixels_noise.cpp \
../src/main_Salt_and_pepper_noise.cpp 

OBJS += \
./src/Four_windows_opencv.o \
./src/Image_load.o \
./src/Two_windows_opencv.o \
./src/main.o \
./src/main_Gaussian_noise.o \
./src/main_Lost_pixels_noise.o \
./src/main_Salt_and_pepper_noise.o 

CPP_DEPS += \
./src/Four_windows_opencv.d \
./src/Image_load.d \
./src/Two_windows_opencv.d \
./src/main.d \
./src/main_Gaussian_noise.d \
./src/main_Lost_pixels_noise.d \
./src/main_Salt_and_pepper_noise.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/include/opencv -I/usr/lib -I/usr/local/include -include/usr/include/armadillo -O2 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


