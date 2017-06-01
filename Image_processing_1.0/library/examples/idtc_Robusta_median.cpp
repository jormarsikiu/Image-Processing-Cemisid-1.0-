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

	/*Cargar la imagen en la matriz*/
	mat R, D;
	Image Img;
	R = Img.Image_load(D, "../Resources/images/house.256.pgm");
	Image I (R);

	/*Uso de un ruido para el filtrado*/
	mat G, S, L, U;
	G = I.Gaussian_noise(10);
	S = I.Salt_and_pepper_noise(10);
	L = I.Lost_pixels_noise(10);
	U = I.Impulsive_uniform_noise(10);

	/*Guardamos la imagen con ruido*/
	const char* S1 = "Images/Idtc_Robusta/Image_R_Median.pgm";
	I.SaveImage(S,S1);
	mat O = zeros<mat>(256,256);
	O = I.Idtc_Robusta(S, 1); //median = 1
	const char* O1 = "Images/Idtc_Robusta/Image_F_Median.pgm";
	I.SaveImage(O,O1);

	/*Ventana Opencv*/
	string label1 = "Salt and Pepper noise: 10";
	string label2 = "Idtc Robusta Median";
	I.Two_windows_opencv(S1, O1, label1, label2);

	

return 0;
}

