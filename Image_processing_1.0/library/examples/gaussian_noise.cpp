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

/*Archivo prueba para probar la Funcion de Ruido Gaussiano(Gaussian_Noise)
 * Descripcion:
 * 	Cargamos una imagen (.pgm) a la matriz de armadillo (D)
 * 	R = Img.Image_load(D, "src/Images/house.256.pgm");
 *
 * 	Cargamos la matriz (imagen) en el constructor de la clase
 * 	Image I (R);
 *
 * 	Ruido Gaussiano
 * 	mat RG;
 * 	double desviacion1 = pow (0.1, 2);
 * 	RG = I.Gaussian_noise(desviacion1);
 *
 * 	Guardamos la imagen
 * 	const char* G1 = "src/Images/Image_0_1.pgm";
 * 	I.SaveImage(RG,G1);
 *
 * 	Abrimos la ventana y etiquetamos las imagenes
 * 	const char* label1 = "Gaussian 0.1";
 * 	I.Four_windows_opencv(G1, G2, G3, G4, label1, label2, label3, label4);
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
	mat GA, GB, GC, GD;
	double nivel1=0.1, nivel2=1, nivel3=10, nivel4=50;
	GA = I.Gaussian_noise(nivel1);
	GB = I.Gaussian_noise(nivel2);
	GC = I.Gaussian_noise(nivel3);
	GD = I.Gaussian_noise(nivel4);
	const char* G1 = "Images/Gaussian_noise/Image_0_1.pgm";
	const char* G2 = "Images/Gaussian_noise/Image_1.pgm";
	const char* G3 = "Images/Gaussian_noise/Image_10.pgm";
	const char* G4 = "Images/Gaussian_noise/Image_50.pgm";
	I.SaveImage(GA,G1);
	I.SaveImage(GB,G2);
	I.SaveImage(GC,G3);
	I.SaveImage(GD,G4);
	const char* label1 = "Gaussian Noise: 0.1";
	const char* label2 = "Gaussian Noise: 1";
	const char* label3 = "Gaussian Noise: 10";
	const char* label4 = "Gaussian Noise: 50";
	I.Four_windows_opencv(G1, G2, G3, G4, label1, label2, label3, label4);


return 0;
}
