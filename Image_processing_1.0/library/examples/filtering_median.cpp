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
	mat IO, D;
	Image Img;
	IO = Img.Image_load(D, "../Resources/images/house.256.pgm");
	Image I (IO);

	/*Uso de un ruido para el filtrado*/
	mat G, S, L, U;
	G = I.Gaussian_noise(10);
	S = I.Salt_and_pepper_noise(5);
	L = I.Lost_pixels_noise(5);
	U = I.Impulsive_uniform_noise(5);

	/*Guardamos la imagen con ruido*/
	const char* S1 = "Images/Filtering/Image_R.pgm";
	I.SaveImage(S,S1);  //<---Para cambiarar el ruido

	/*Filtrado*/
	mat F;
	int median = 1;
	F = I.Filtering(S, 5, median);   //<---Para cambiarar el ruido

	/*Guardamos el filtrado*/
	const char* F1 = "Images/Filtering/Image_F.pgm";
	I.SaveImage(F,F1);


	cout<<"********************Metricas********************"<<endl;
	cout<<"*                   (IO, R)       (IO, F)     "<<endl;
	cout<<"*       PSNR        "<<I.PSNR(IO,S) <<"       "<<I.PSNR(IO, F)<<endl; //<---Para cambiarar el ruido
	cout<<"*       MSE         "<<I.MSE(IO, S) <<"       "<<I.MSE(IO, F)<<endl;
	cout<<"*       MAE         "<<I.MAE(IO, S) <<"       "<<I.MAE(IO, F)<<endl;
	cout<<"************************************************"<<endl;
	cout<<"IO:       Imagen Original"<<endl;
	cout<<"R:        Imagen con Ruido"<<endl;
	cout<<"F:        Imagen Filtrada"<<endl;
	cout<<"PSNR[dB]: Metrica Relacion Señal a ruido"<<endl;  
	cout<<"MSE:      Metrica del Error Cuadratico Medio"<<endl;
	cout<<"MAE:      Metrica del Error Promedio Absoluto"<<endl;



	/*Mostramos la imagen recortada*/
	mat IO1 = IO(span(2, 253),span(2, 253));
	mat SS1 = S(span(2, 253),span(2, 253)); //<---Para cambiarar el ruido
	mat FF1 = F(span(2, 253),span(2, 253));
	const char* R0 = "Images/Recorte_Median/Recorte_Original.pgm";
	const char* R1 = "Images/Recorte_Median/Recorte_Ruido.pgm";
	const char* R2 = "Images/Recorte_Median/Recorte_Filtrado.pgm";
	I.SaveImage(IO1,R0);
	I.SaveImage(SS1,R1);
	I.SaveImage(FF1,R2);
	
	/*Ventana Opencv*/
	const char* label1 = "Imagen Original";
	const char* label2 = "Ruido: Sal y Pimienta: 5%";
	const char* label3 = "Original Imagen";
	const char* label4 = "Filtering Median";
	I.Four_windows_opencv(R0, R1, R0, R2, label1, label2, label3, label4);

return 0;
}

