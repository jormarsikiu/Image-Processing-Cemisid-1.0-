################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../library/examples/basic_funcions.cpp \
../library/examples/filtering_mean.cpp \
../library/examples/filtering_median.cpp \
../library/examples/gaussian_noise.cpp \
../library/examples/lost_Pixels_noise.cpp \
../library/examples/noise_remover.cpp \
../library/examples/overlap.cpp \
../library/examples/salt_pepper.cpp \
../library/examples/uniform_impulsive_noise.cpp 

O_SRCS += \
../library/examples/Four_windows_opencv.o \
../library/examples/Image_load.o \
../library/examples/Two_windows_opencv.o \
../library/examples/basic_funcions.o \
../library/examples/filtering_mean.o \
../library/examples/filtering_median.o \
../library/examples/gaussian_noise.o \
../library/examples/lost_Pixels_noise.o \
../library/examples/noise_remover.o \
../library/examples/overlap.o \
../library/examples/salt_pepper.o \
../library/examples/uniform_impulsive_noise.o 

OBJS += \
./library/examples/basic_funcions.o \
./library/examples/filtering_mean.o \
./library/examples/filtering_median.o \
./library/examples/gaussian_noise.o \
./library/examples/lost_Pixels_noise.o \
./library/examples/noise_remover.o \
./library/examples/overlap.o \
./library/examples/salt_pepper.o \
./library/examples/uniform_impulsive_noise.o 

CPP_DEPS += \
./library/examples/basic_funcions.d \
./library/examples/filtering_mean.d \
./library/examples/filtering_median.d \
./library/examples/gaussian_noise.d \
./library/examples/lost_Pixels_noise.d \
./library/examples/noise_remover.d \
./library/examples/overlap.d \
./library/examples/salt_pepper.d \
./library/examples/uniform_impulsive_noise.d 


# Each subdirectory must supply rules for building sources it contributes
library/examples/%.o: ../library/examples/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/include/opencv -I/usr/lib -I/usr/local/include -include/usr/include/armadillo -O2 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


