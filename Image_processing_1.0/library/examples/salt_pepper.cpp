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

/*Archivo prueba para probar la Funcion de Ruido Sal y Pimienta(Salt_and_pepper_noise)
 * Descripcion:
 *
 *	mat R, D;
 *
 *	Constructor por defecto de la clase Imagen
 *	Image Img;
 *
 *	Cargamos una imagen (.pgm) a la matriz de armadillo (D)
 *	R = Img.Image_load(D, "src/Resources/images/house.256.pgm");
 *
 *	Cargamos la matriz (imagen) en el constructor de la clase
 *	Image I (R);
 *
 *	Ruido Sal y Pimienta
 *	mat SP;
 *	double nivel=10;
 *	SP = I.Salt_and_pepper_noise(nivel);
 *
 *	Guardamos la imagen
 * 	const char* S1 = "src/Pruebas/images_salt_and_pepper/Image_10.pgm";
 *	I.SaveImage(SP,S1);
 *
 * 	Abrimos la ventana y etiquetamos las imagenes
 * 	const char* label1 = "Ruido 0.1";
 * 	I.Four_windows_opencv(S1, S2, S3, S4, label1, label2, label3, label4);
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
	mat SA, SB, SC, SD, SE;
	double nivel1=0.1, nivel2=1, nivel3=10, nivel4=50 ;
	SA = I.Salt_and_pepper_noise(nivel1);
	SB = I.Salt_and_pepper_noise(nivel2);
	SC = I.Salt_and_pepper_noise(nivel3);
	SD = I.Salt_and_pepper_noise(nivel4);
	const char* S1 = "Images/Salt_pepper/Image_0_1.pgm";
	const char* S2 = "Images/Salt_pepper/Image_1.pgm";
	const char* S3 = "Images/Salt_pepper/Image_10.pgm";
	const char* S4 = "Images/Salt_pepper/Image_50.pgm";
	I.SaveImage(SA,S1);
	I.SaveImage(SB,S2);
	I.SaveImage(SC,S3);
	I.SaveImage(SD,S4);
	const char* label1 = "Salt and Pepper Noise: 0.1";
	const char* label2 = "Salt and Pepper Noise: 1";
	const char* label3 = "Salt and Pepper Noise: 10";
	const char* label4 = "Salt and Pepper Noise: 50";
	I.Four_windows_opencv(S1, S2, S3, S4, label1, label2, label3, label4);


return 0;
}
