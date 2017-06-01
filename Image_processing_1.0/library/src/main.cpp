#include <iostream>
#include <armadillo>
using namespace arma;
using namespace std;

//clave del repositorio: informatica 5

#include "../include/Image.hpp"

//! Titulo: Funcion de Inicio.
/*! Descripcion: Comienzo de codigo. */
int main(){


	mat D, R;
	int pixel;
	double desviacion1 = 0.1;
	double desviacion2 = 1;
	double desviacion3 = 10;
	double desviacion4 = 100;
	Image Img;

	/*Cargar la imagen en la matriz*/
	R = Img.Image_load(D, "Resources/images/house.256.pgm");
	const char* R1= "Resources/images/Image.pgm";

	/*Cargamos la imagen en el constructor*/
	Image I (R);

	//R.print();
	//I.Dimension();

	/*Imprimir un pixel*/
	pixel= I.Get_pixel(254, 254);
	cout << "Pixel (256, 256): "<< pixel<<endl;

	/*Imprimir varios pixeles*/
	//I.Get_pixels();


	//Ruido Gausseano
	mat GA, GB, GC, GD;
	GA = I.Gaussian_noise(desviacion1);
	GB = I.Gaussian_noise(desviacion2);
	GC = I.Gaussian_noise(desviacion3);
	GD = I.Gaussian_noise(desviacion4);
	const char* G1 = "src/Resources/images_gaussian/Image_0_1.pgm";
	const char* G2 = "src/Resources/images_gaussian/Image_1.pgm";
	const char* G3 = "src/Resources/images_gaussian/Image_10.pgm";
	const char* G4 = "src/Resources/images_gaussian/Image_100.pgm";
	I.SaveImage(GA,G1);
	I.SaveImage(GB,G2);
	I.SaveImage(GC,G3);
	I.SaveImage(GD,G4);

	//Perdida de pixeles
	mat LA, LB, LC, LD;
	int nivel1=0.1, nivel2=1, nivel3=10, nivel4=100 ;
	LA = I.Lost_pixels_noise(nivel1);
	LB = I.Lost_pixels_noise(nivel2);
	LC = I.Lost_pixels_noise(nivel3);
	LD = I.Lost_pixels_noise(nivel4);
	const char* L1 = "src/Resources/images_lost_pixels/Image_0_1.pgm";
	const char* L2 = "src/Resources/images_lost_pixels/Image_1.pgm";
	const char* L3 = "src/Resources/images_lost_pixels/Image_10.pgm";
	const char* L4 = "src/Resources/images_lost_pixels/Image_100.pgm";
	I.SaveImage(LA,L1);
	I.SaveImage(LB,L2);
	I.SaveImage(LC,L3);
	I.SaveImage(LD,L4);

	//Ruido sal y pimienta
	mat SA, SB, SC, SD, SE;
	SA = I.Salt_and_pepper_noise(nivel1);
	SB = I.Salt_and_pepper_noise(nivel2);
	SC = I.Salt_and_pepper_noise(nivel3);
	SD = I.Salt_and_pepper_noise(nivel4);
	SE = I.Salt_and_pepper_noise(5);
	const char* S1 = "src/Resources/images_salt_and_pepper/Image_0_1.pgm";
	const char* S2 = "src/Resources/images_salt_and_pepper/Image_1.pgm";
	const char* S3 = "src/Resources/images_salt_and_pepper/Image_10.pgm";
	const char* S4 = "src/Resources/images_salt_and_pepper/Image_100.pgm";
	const char* S5 = "src/Resources/images_salt_and_pepper/Image_5.pgm";
	I.SaveImage(SA,S1);
	I.SaveImage(SB,S2);
	I.SaveImage(SC,S3);
	I.SaveImage(SD,S4);
	I.SaveImage(SE,S5);

	//Ruido uniforme impulsivo
	mat UA, UB, UC, UD;
	UA = I.Impulsive_uniform_noise(nivel1);
	UB = I.Impulsive_uniform_noise(nivel2);
	UC = I.Impulsive_uniform_noise(nivel3);
	UD = I.Impulsive_uniform_noise(nivel4);
	const char* U1 = "src/Resources/images_impulsive_noise/Image_0_1.pgm";
	const char* U2 = "src/Resources/images_impulsive_noise/Image_1.pgm";
	const char* U3 = "src/Resources/images_impulsive_noise/Image_10.pgm";
	const char* U4 = "src/Resources/images_impulsive_noise/Image_100.pgm";
	I.SaveImage(UA,U1);
	I.SaveImage(UB,U2);
	I.SaveImage(UC,U3);
	I.SaveImage(UD,U4);

	//Histograma para el ruido gauseano de 0.1
	//cout<< I.Histgram(GA) << endl;

	//Ventana Opencv = Sal y pimienta
	const char* slabel1 = "";
	const char* slabel2 = "";
	const char* slabel3 = "";
	const char* slabel4 = "";
	I.Four_windows_opencv(L1, L2, L3, L4, slabel1, slabel2, slabel3, slabel4);

	//Filtrado
	mat FA;
	///FA = I.Filtering(SC, 5);
	const char* F1 = "src/Resources/filtered/filtered_Image_10.pgm";
	I.SaveImage(FA,F1);

	//Ventana Opencv = filtrado
	//I.Two_windows_opencv(S3, F1);
	//I.Two_windows_opencv(R1, F1);

	//Remocion de Ruido: Gausiana 10
	mat NA;
	//NA = I.Noise_remover(LC, 256);
	const char* N1 = "src/Resources/filtered/noise_remover_Image_10.pgm";
	I.SaveImage(NA, N1);
	string glabel3 = "Ruido Perdida de Pixeles: 10";
	string rlabel4 = "Remocion de Ruido: No Solapado";
	//I.Two_windows_opencv(L3, N1, glabel3, rlabel4);

	cout<<"Metrica Relacion Señal a ruido: PSNR[dB]: "<<I.PSNR(R, GC)<<endl;

	//Remocion de Ruido: Gausiana 10
	mat OA = zeros<mat>(256,256);
	/*DESCOMENTAR*/
	OA = I.Overlap(UC);
	const char* O1 = "src/Resources/filtered/overlap_Image_10.pgm";
	I.SaveImage(OA, O1);
	string glabel1 = "Ruido Impulsivo Uniforme: 10";
	string rlabel2 = "Remocion de Ruido: Solapado";
	//I.Two_windows_opencv(U3, O1, glabel1, rlabel2);

	//I.Four_windows_opencv(U1, U2, U3, U4)

	mat A(5, 5, fill::randu);
vec D1(5, fill::randu);
mat C = A * A;
vec E = A * D1;

	/* Leyenda:
	 * Gauseano G, Perdida L, Sal-Pimienta S, Impulsivo U
	 * A1: 0.1 B2=1, C3=10, D4=100
	*/
	return 0;

}

