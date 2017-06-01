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

	/*PRUEBA Remocion de Ruido: Gaussiano 10

	/*Guardamos la imagen con ruido*/
	const char* G1 = "Images/Overlap/Image_R.pgm";
	I.SaveImage(G,G1);

	/*Remocion de Ruido(SOLAPADO)*/
	mat O = zeros<mat>(256,256);
	O = I.Overlap(G);	
	
	/*Guardamos la imagen*/
	const char* O1 = "Images/Overlap/Image_F.pgm";
	I.SaveImage(O,O1);

	/*PSNR*/
	cout<<"Metrica Relacion Señal a ruido: PSNR[dB]: "<<I.PSNR(G, O)<<endl;

	/*Ventana Opencv*/
	string label1 = "Gaussian noise: 10";
	string label2 = "Overlap (Solapado)";
	I.Two_windows_opencv(G1, O1, label1, label2);

	

return 0;
}


