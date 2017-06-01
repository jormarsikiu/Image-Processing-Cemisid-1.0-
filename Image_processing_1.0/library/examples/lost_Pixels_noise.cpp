/* Image Processing Cemisid 1.0 Library
 * Copyright (C) 2017  Jormar S. Turizo A.
 *
 * This file is part of the Image Processing Cemisid 1.0 Library.
 * It is provided without any warranty of fitness
 * for any purpose. You can redistribute this file
 * and/or modify it under the terms of the GNU
 * Lesser General Public License (LGPL) as published
 * by the Free Software Foundation, either version 3
 * of the License or (at your option) any later version.
 * (see http://www.opensource.org/licenses for more info)
*/

#include <iostream>
#include <armadillo>
#include "Image.hpp"
using namespace arma;
using namespace std;

int main(){

	mat R, D;
	Image Img;
	R = Img.Image_load(D, "../Resources/images/house.256.pgm");
	Image I (R);
	mat LA, LB, LC, LD;
	int nivel1=0.1, nivel2=1, nivel3=10, nivel4=50 ;
	LA = I.Lost_pixels_noise(nivel1);
	LB = I.Lost_pixels_noise(nivel2);
	LC = I.Lost_pixels_noise(nivel3);
	LD = I.Lost_pixels_noise(nivel4);
	const char* L1 = "Images/Lost_Pixels_noise/Image_0_1.pgm";
	const char* L2 = "Images/Lost_Pixels_noise/Image_1.pgm";
	const char* L3 = "Images/Lost_Pixels_noise/Image_10.pgm";
	const char* L4 = "Images/Lost_Pixels_noise/Image_50.pgm";
	I.SaveImage(LA,L1);
	I.SaveImage(LB,L2);
	I.SaveImage(LC,L3);
	I.SaveImage(LD,L4);
	const char* label1 = "Lost Pixels Noise: 0.1";
	const char* label2 = "Lost Pixels Noise: 1";
	const char* label3 = "Lost Pixels Noise: 10";
	const char* label4 = "Lost Pixels Noise: 50";
	I.Four_windows_opencv(L1, L2, L3, L4, label1, label2, label3, label4);


return 0;
}
