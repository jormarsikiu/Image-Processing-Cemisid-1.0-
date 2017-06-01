# Image Processing Cemisid 1.0 Library
# Copyright (C) 2017  Jormar S. Turizo A.
#
# This file is part of the Image Processing Cemisid 1.0 Library.
# It is provided without any warranty of fitness
# for any purpose. You can redistribute this file
# and/or modify it under the terms of the GNU
# Lesser General Public License (LGPL) as published
# by the Free Software Foundation, either version 3
# of the License or (at your option) any later version.
# (see http://www.opensource.org/licenses for more info)

CPP=g++
INC= -I../include
OPC = -g
CFLAGS=-c -Wall $(shell pkg-config --cflags opencv) -O2 -larmadillo -w
LDFLAGS = $(shell pkg-config --libs --static opencv) -O2 -larmadillo -w



all: basic_funcions gaussian_noise lost_Pixels_noise salt_pepper uniform_impulsive_noise filtering_mean filtering_median noise_remover overlap idtc_Robusta_mean idtc_Robusta_median detection_face

#mains
#---------------------------------------------------#

basic_funcions: basic_funcions.o Image_load.o
	$(CPP) $(OPC) -o $@ $^ $(LDFLAGS)

gaussian_noise:  gaussian_noise.o Four_windows_opencv.o Image_load.o 
	$(CPP) $(OPC) -o $@ $^ $(LDFLAGS)

lost_Pixels_noise:  lost_Pixels_noise.o Four_windows_opencv.o Image_load.o 
	$(CPP) $(OPC) -o $@ $^ $(LDFLAGS)

salt_pepper: salt_pepper.o Four_windows_opencv.o Image_load.o 
	$(CPP) $(OPC) -o $@ $^ $(LDFLAGS)

uniform_impulsive_noise: uniform_impulsive_noise.o Four_windows_opencv.o Image_load.o 
	$(CPP) $(OPC) -o $@ $^ $(LDFLAGS)

filtering_mean: filtering_mean.o Two_windows_opencv.o Four_windows_opencv.o Image_load.o 
	$(CPP) $(OPC) -o $@ $^ $(LDFLAGS)

filtering_median: filtering_median.o Two_windows_opencv.o Four_windows_opencv.o Image_load.o 
	$(CPP) $(OPC) -o $@ $^ $(LDFLAGS)

noise_remover: noise_remover.o Two_windows_opencv.o Image_load.o 
	$(CPP) $(OPC) -o $@ $^ $(LDFLAGS)

overlap: overlap.o  Two_windows_opencv.o Image_load.o 
	$(CPP) $(OPC) -o $@ $^ $(LDFLAGS)

idtc_Robusta_mean: idtc_Robusta_mean.o Two_windows_opencv.o Image_load.o
	$(CPP) $(OPC) -o $@ $^ $(LDFLAGS) 

idtc_Robusta_median: idtc_Robusta_median.o Two_windows_opencv.o Image_load.o
	$(CPP) $(OPC) -o $@ $^ $(LDFLAGS) 

detection_face: detection_face.o Detection_Face_opencv.o Image_load.o
	$(CPP) $(OPC) -o $@ $^ $(LDFLAGS) 

#add mains
#---------------------------------------------------#
basic_funcions.o: basic_funcions.cpp
	$(CPP) $(INC) $(CFLAGS) -c $^

gaussian_noise.o: gaussian_noise.cpp 
	$(CPP) $(INC) $(CFLAGS) -c $^

lost_Pixels_noise.o: lost_Pixels_noise.cpp 
	$(CPP) $(INC) $(CFLAGS) -c $^

salt_pepper.o: salt_pepper.cpp
	$(CPP) $(INC) $(CFLAGS) -c $^

uniform_impulsive_noise.o: uniform_impulsive_noise.cpp
	$(CPP) $(INC) $(CFLAGS) -c $^

filtering_mean.o: filtering_mean.cpp
	$(CPP) $(INC) $(CFLAGS) -c $^

filtering_median.o: filtering_median.cpp
	$(CPP) $(INC) $(CFLAGS) -c $^

noise_remover.o: noise_remover.cpp
	$(CPP) $(INC) $(CFLAGS) -c $^

overlap.o: overlap.cpp
	$(CPP) $(INC) $(CFLAGS) -c $^

idtc_Robusta_mean.o: idtc_Robusta_mean.cpp
	$(CPP) $(INC) $(CFLAGS) -c $^

idtc_Robusta_median.o: idtc_Robusta_median.cpp
	$(CPP) $(INC) $(CFLAGS) -c $^

detection_face.o: detection_face.cpp 
	$(CPP) $(INC) $(CFLAGS) -c $^

#library (Don't touch)
#---------------------------------------------------#
Four_windows_opencv.o: ../src/Four_windows_opencv.cpp 
	$(CPP) $(INC) $(CFLAGS) -c $^

Two_windows_opencv.o: ../src/Two_windows_opencv.cpp
	$(CPP) $(INC) $(CFLAGS) -c $^

Detection_Face_opencv.o: ../src/Detection_Face_opencv.cpp
	$(CPP) $(INC) $(CFLAGS) -c $^

Image_load.o: ../src/Image_load.cpp 
	$(CPP) $(INC) $(CFLAGS) -c $^

clean:
	rm -f *.o  gaussian_noise lost_Pixels_noise salt_pepper uniform_impulsive_noise filtering noise_remover overlap
