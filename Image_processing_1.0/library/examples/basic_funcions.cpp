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


/*Funciones Basicas: Cargar imagen, Dimension de la matriz, Obtencion de un pixel, Obtencion de todos los pixeles, Generar un histrograma de la imagen, Obtener el PSNR */
#include "../include/Image.hpp"
#include <iostream>
#include <armadillo>
//#include <math.h>


using namespace arma;
using namespace std;

int main(){

	mat D, R;
	int pixel;
	Image Img;

	/*Cargar la imagen en la matriz*/
	R = Img.Image_load(D, "../Resources/images/house.256.pgm");

	/*Cargamos la imagen en el constructor*/
	Image I (R);

	/*Dimensión de la matriz*/
	I.Dimension();

	/*Imprimir un pixel*/
	pixel= I.Get_pixel(254, 254);
	cout << "Pixel (256, 256): "<< pixel<<endl;

	/*Imprimir varios pixeles*/
	I.Get_pixels();

	/*PSNR*/
	mat A = R;
	mat B = R+9;
	cout<<"Metrica Relacion Señal a ruido: PSNR[dB]: "<<I.PSNR(A, B)<<endl;
	
	cout<<I.Diccionary() <<endl;

	mat A1(5, 5, fill::randu);
	vec D1(5, fill::randu);
	mat C1 = A1 * A1;
	vec E1 = A1 * D1;

	return 0;

}


