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

/*Archivo prueba para probar la Funcion del Ruido Impulsivo Uniforme(Impulsive_uniform_noise)
 * Descripcion:
 *
 *	mat R, D;
 *
 *	Constructor por defecto de la clase Imagen
 *	Image Img;
 *
 *	Cargamos una imagen (.pgm) a la matriz de armadillo (D)
 *	R = Img.Image_load(D, "src/Images/house.256.pgm");
 *
 *	Cargamos la matriz (imagen) en el constructor de la clase
 *	Image I (R);
 *
 *	Ruido Impulsivo Uniforme
 *	mat UA;
 *	double nivel1=0.1;
 *	UA = I.Impulsive_uniform_noise(nivel1);
 *
 *	Guardamos la imagen
 *	const char* U1 = "src/Images/Image_10.pgm";
 *	I.SaveImage(UA,U1);
 *
 * 	Abrimos la ventana y etiquetamos las imagenes
 * 	const char* label1 = "Ruido 0.1";
 * 	I.Four_windows_opencv(U1, U2, U3, U4, label1, label2, label3, label4);
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

	mat UA, UB, UC, UD;
	double nivel1=0.1, nivel2=1, nivel3=10, nivel4=50;
	UA = I.Impulsive_uniform_noise(nivel1);
	UB = I.Impulsive_uniform_noise(nivel2);
	UC = I.Impulsive_uniform_noise(nivel3);
	UD = I.Impulsive_uniform_noise(nivel4);
	const char* U1 = "Images/Uniform_noise/Image_0_1.pgm";
	const char* U2 = "Images/Uniform_noise/Image_1.pgm";
	const char* U3 = "Images/Uniform_noise/Image_10.pgm";
	const char* U4 = "Images/Uniform_noise/Image_50.pgm";
	I.SaveImage(UA,U1);
	I.SaveImage(UB,U2);
	I.SaveImage(UC,U3);
	I.SaveImage(UD,U4);
	const char* label1 = "Uniform Impulsive Noise: 0.1";
	const char* label2 = "Uniform Impulsive Noise: 1";
	const char* label3 = "Uniform Impulsive Noise: 10";
	const char* label4 = "Uniform Impulsive Noise: 50";
	I.Four_windows_opencv(U1, U2, U3, U4, label1, label2, label3, label4);


return 0;
}
