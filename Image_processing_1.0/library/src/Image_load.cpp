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

/*
 * Image_load.cpp
 *  	Descripcion: Implementación de funciones que permiten manipular las imagenes en forma de matrices
 */

#include "../include/Image.hpp"
#include <iostream>
#include <armadillo>


using namespace arma;
using namespace std;


/*! Descripcion: Permite cargar la imagen en formato pgm a mat
 *  \fn mat Image::Image_load(mat matrix, string ruta)
 *  \brief Carga de Imagen pgm a mat.
 *  \param matrix es la matriz que contine los pixeles de la imagen.
 *  \param ruta es la ubicacion o localizacion de la imagen.
 *  \return  Retorna si la matriz fue cargada o si hubo problemas en la carga.
 *  \test basic_funcions.cpp
 *  \n mat matrix;
 *  \n string ruta = "src/Resources/images/house.256.pgm";
 *  \n Image_load(matrix, ruta);
 */

mat Image::Image_load(mat matrix, string ruta){

	bool status = matrix.load(ruta, pgm_binary);

	if(status == true)
	  {
	  cout << "Loaded okay" << endl;
	  cout << "Size of matrix: " << size(matrix) << endl;
	  }
	else
	  {
	  cout << "Problem with loading" << endl;
	  }

	return matrix;
}


/*! Descripcion: Constructor de la clase Image para acceder a sus metodos internos
 *  \fn Image::Image()
 *  \brief Constructor  de la clase
 *  \test basic_funcions.cpp
 *  \n Image I;
 *  \n I.Dimension();
 */
Image::Image(){
	rows = 0;
	cols = 0;

}
/*! Descripcion: Constructor  de la clase Image, carga en la estructura la matriz de la imagen y
 *  el tamaño de las filas y de las columnas.
 *  \fn Image::Image(mat matrix)
 *  \brief Constructor parametrizado de la clase
 *  \param matrix es la matriz que contiene los pixeles de la imagen.
 *  \param rows guarda el valor de las filas (private)
 *  \param cols guarda el valor de las columnas (private)
 *  \test basic_funcions.cpp
 *  \n mat A;
 *  \n Image(A);
 */
Image::Image(mat matrix_original){
	matrix = matrix_original;
	rows = matrix_original.n_rows;
	cols = matrix_original.n_cols;

}

/*! Descripcion: Destructor  de la clase Image donde guarda el tamaño de las filas y columnas.
 *  \fn Image::Image::~Image(arma::mat)
 *  \brief Destructor  de la clase
 *  \test basic_funcions.cpp
 */
Image::~Image(){
	rows=cols=0;

}

/*! Descripcion: Permite obtener la dimension nxn de la matriz.
 *  \fn void Image::Dimension()
 *  \brief Obtiene las dimensiones de la matriz.
 *  \return Retorna la dimension de la imagen nxn.
 *  \test basic_funcions.cpp
 *  \n Image I;
 *  \n I.Dimension();
 */
void Image::Dimension(){


	cout << "Class Image: Size of matriz: "<<rows <<"x"<<cols <<endl;

}

/*! Descripcion: Permite obtener el valor de un pixel de la matriz de la imagen original
 *  \fn int Image::Get_pixel(int row, int col)
 *  \brief Obtiene el valor de un pixel
 *  \param row es el numero de filas de la matriz
 *  \param col es el numero de columnas de la matriz
 *  \return Retorna el valor (value) de un pixel
 *  \test basic_funcions.cpp
 *  \n Image I;
 *  \n int row=5;
 *  \n int col=5;
 *  \n I.Get_pixel(row, col);
 */
int Image::Get_pixel(int row, int col){
	int value;
	value = matrix(row,col);
	return value;

}

/*! Descripcion: Permite obtener e imprimir todos los pixeles de la imagen.
 *  \fn void Image::Get_pixels()
 *  \brief Imprime todos los pixeles de la matriz imagen.
 *  \return value: Retorna todos los pixeles.
 *  \test basic_funcions.cpp
 *  \n Image I;
 *  \n I.Get_pixels();
 */
void Image::Get_pixels(){


	int & _row = rows;
	int & _col = cols;
	mat & _matrix = matrix;

	for(int i = 0; i < _col ; i++)
	{
	    for(int j = 0; j < _row ; j++)
	    {

	     cout <<_matrix(i,j) << " ";
	    }
	cout << endl;
	}
}

/*! Descripcion: Permite aplicarle Ruido Gaussiano a una matriz.
 * El Ruido Gaussiano es una matriz de media 0 y con una desviacion estandar variable.
 *  \fn mat Image::Gaussian_noise(double nivel)
 *  \brief Aplica Ruido Gaussiano a una matriz
 *  \param nivel es el nivel de varianza variable
 *  \n
 *  \n Parametros Internos:
 *  \n A es una matriz gaussiana de dimensiones iguales a la matriz y de media 0 y varianza 1
 *  \n B es una matriz donde se almacena la matriz gaussiana de media 0 y el calculo de una varianza determinada
 *  \n std es la desviacion estandar
 *  \return value: Retorna la matriz con el ruido aplicado
 *  \test gaussian_noise.cpp
 *  \n int nivel=0.1;
 *  \n Gaussian_noise(nivel1);
 */
mat Image::Gaussian_noise(double nivel){

	double varianza = pow (nivel, 2);
	int & _row = rows;
	int & _col = cols;
	mat & _matrix = matrix;

	// Semilla del random --->  arma_rng::set_seed(value) or arma_rng::set_seed_random()
	arma_rng::set_seed_random();

	// Matriz gausiana de dimensiones iguales a la matriz y de media 0 y varianza 1
	mat A =randn<mat>(_row, _col);

	// Matriz donde se almacenará la matriz gausiana de media 0 y varianza nueva
	mat B;

	// La Desviacion estandar de la matriz gausiana nueva que es la raiz de la varianza
	double std = sqrt(varianza);

	// Matriz gausiana de media cero y varianza nueva;
	B = std * A;

	// Matriz que almacene que añade el filtro a la imagen
	mat RG = _matrix + B;

	cout << "Success Gauss complete" << endl;

	return RG;
}

/*! Descripcion: Permite aplicarle Perdida de Pixeles a una matriz
 *  \fn mat Image::Lost_pixels_noise(int nivel)
 *  \brief Aplica Perdida de pixeles a una matriz
 *  \param nivel es el porcentaje de ruido
 *  \return value: Retorna la matriz con el ruido aplicado
 *  \test lost_Pixels_noise.cpp
 *  \n double nivel=0.1;
 *  \n Lost_pixels_noise(nivel);
 */
mat Image::Lost_pixels_noise(double nivel){

	int & _row = rows;
	int & _col = cols;
	mat & _matrix = matrix;

	double n2;
	n2=nivel/100.0;

	//Matriz de valores aleatorios de distribucion 0 a 1
	mat U =randu<mat>(_row, _col);
	mat RG (_row, _col);

	//Generacion de perdida de pixels
	for(int i = 0; i < _col ; i++)
	{
	    for(int j = 0; j < _row; j++)
	    {
	    	if(U(i,j) < n2)
	    	{
	    		RG(i,j)=0;
	    	}
	    	else
	    	{
	    		RG(i,j)= _matrix(i,j);
	    	}
	    }

	}
	cout << "Success lost pixel complete" << endl;
	return RG;
}

/*! Descripcion: Permite aplicarle Ruido Sal y Pimienta a una matriz
 *  \fn mat Image::Salt_and_pepper_noise(int nivel)
 *  \brief Aplica Ruido Sal y Pimienta a una matriz
 *  \param nivel es el porcentaje de ruido
 *  \return Retorna la matriz con el ruido (RG)
 *  \test salt_pepper.cpp
 *  \n double nivel=0.1;
 *  \n Salt_and_pepper_noise(nivel);
 */
mat Image::Salt_and_pepper_noise(double nivel){

	int & _row = rows;
	int & _col = cols;
	mat & _matrix = matrix;

	double nivel1=nivel/(100.0*2);
	double nivel2=nivel/100.0;
	mat RG (_row, _col);

	//Matriz de valores aleatorios de distribucion 0 a 1
	mat U =randu<mat>(_row, _col);
	//Generacion del ruido sal y pimienta
	for(int i = 0; i < _col ; i++)
	{
	    for(int j = 0; j < _row; j++)
	    {
	    	if(U(i,j) < nivel1)
	    	{
	    		RG(i,j)=0;
	    	}
	    	else if ((nivel1 <= U(i,j)) && (U(i,j) < nivel2))
	    	{
	    		RG(i,j)=255;
	    	}
	    	else {
	    		RG(i,j)= _matrix(i,j);
	    	}
	    }
	}
	cout << "Success salt and pepper complete" << endl;
	return RG;
}
/*! Descripcion: Permite aplicarle Ruido Impulsivo Uniforme a una matriz
 *  \fn mat Image::Impulsive_uniform_noise(int nivel)
 *  \brief Aplica Ruido Impulsivo Uniforme a una matriz.
 *  \param nivel es el porcentaje de ruido.
 *  \return value: Retorna la matriz con el ruido aplicado.
 *  \test uniform_impulsive_noise.cpp
 *  \n double nivel=0.1;
 *  \n Impulsive_uniform_noise(nivel);
 */
mat Image::Impulsive_uniform_noise(double nivel){

	int & _row = rows;
	int & _col = cols;
	mat & _matrix = matrix;

	mat RI (_row, _col);
	double n2;
	n2=nivel/100.0;

	//Matriz de valores aleatorios de distribucion 0 a 1
	mat U =randu<mat>(_row, _col);

	//Generacion del ruido uniforme impusivo
	for(int i = 0; i < _col ; i++)
	{
	    for(int j = 0; j < _row; j++)
	    {
	    	if(U(i,j) < n2)
	    	{
	    		RI(i,j)=rand()%256;
	    	}
	    	else {
	    		RI(i,j)= _matrix(i,j);
	    	}
	    }
	}
	cout << "Success impulsive noise complete" << endl;
	return RI;
}
/*! Descripcion: Permite guardar una matriz mat en formato pgm
 *  \fn void Image::SaveImage(mat matrix, string ruta)
 *  \brief Guarda la matriz en formato pgm.
 *  \param matrix matriz que contine los pixeles de la imagen.
 *  \param ruta ubicacion o localizacion de la imagen.
 *  \return  Retorna si la matriz fue guardada o si hubo problemas al guardar.
 *  \test gaussian_noise.cpp
 *  \n mat matrix;
 *  \n string ruta= "src/Resources/images/house.256.pgm";
 *  \n SaveImage(matrix, ruta);
 */
void Image::SaveImage(mat matrix, string ruta){
	bool status = matrix.save(ruta, pgm_binary);

	if(status == true)
	  {
	 // cout << "Save okay: " << ruta << endl;
	  }
	else
	  {
	  cout << "Problem with save" << endl;
	  }

}

/*! Descripcion: Permite calcular el promedio y la mediana.
 *  \fn double Image::Average_Median(vec vector, int flag)
 *  \brief Calcula el promedio y la mediana
 *  \param vector es el vector al cual se le calculará el promedio o la mediana
 *  \param flag cuando flag = 0 se calcula el promedio y cuando flag = 1 se calcula la mediana
 *  \return value: Retorna la matriz con el ruido
 *  \n vec B;
 *  \n Average_Median(B, 0); //Promedio-Media
 *  \n Average_Median(B, 1); //Mediana
 */

double Average_Median(vec vector, int flag){

	if (flag == 0){  //Promedio-Media
		double average  = mean(vector);
		return average;
	}
	else if (flag == 1){ //Mediana
		double median1 = median(vector);
		return median1;
	}

	return 0.0;
}
/*! Descripcion: Permite aplicar un filtrado a una matriz, utilizando el sparse.
 * Se selecciona una ventana de lxl a la cual se le aplica un promedio o la mediana para restaurar la imagen.
 * Se calcula utilizando el tamaño de la ventana l y el pixel central de la ventana,
 * luego se aplica el promedio o mediana de los pixels adyacentes al central.
 *  \fn mat Image::Filtering(mat matrix, int l)
 *  \brief Aplica un filtrado usando el promedio o la mediana para remover ruido.
 *  \param matrix es la matriz con ruido a la cual se le aplicara el filtrado.
 *  \param l es el tamaño de la ventana
 *  \param flag es la bandera que indica si se efectua el promedio o la mediana. Donde el promedio es igual 0 y la mediana igual a 1
 *  \return filt_matrix: Retorna la matriz con el filtrado.
 *  \test filtering_median.cpp filtering_mean.cpp
 *  \n mat matrix;
 *  \n int l = 5;
 *  \n int flag = 0;
 *  \n Filtering(matrix, l, flag);
 */
mat Image::Filtering(mat matrix, int l, int flag){

	mat windows(l,l);
	int l2 = l/2;
	int rows = matrix.n_rows;
	int cols = matrix.n_cols;
	vec vector;
	mat filt_matrix(rows, cols); //Es necesario

	for (int i=l2; i<rows-l2; i++){
		for (int j=l2; j<cols-l2; j++){
				windows = matrix(span(i-l2 , i+l2),span(j-l2 , j+l2));
				vector = vectorise(windows);
				filt_matrix(i,j) = Average_Median(vector, flag);
		}
	}
	cout << "Filtered complete" << endl;
	return filt_matrix;
}



/*! Descripcion: Permite remover ruido mediante el uso de una ventana 8x8 no solapado
 *  \fn mat Image::Noise_remover(mat matrix, int image_tam)
 *  \brief Aproximación Robusta por bloques No solpados (ventana 8x8) 
 *  \param matrix es la matriz que se le removerá el ruido.
 *  \param image_tam es el tamaño de la imagen.
 *  \return removermatrix: Retorna la matriz sin ruido.
 *  \test noise_remover.cpp
 *  \n mat matrix;
 *  \n int image_tam = 256;
 *  \n Noise_remover(matrix, image_tam);
 */

mat Image::Noise_remover(mat matrix, int image_tam){

	//fft2(): 2D fast Fourier transform of a matrix (real or complex)
	mat windows(8,8), magDFTV(8,8), magDFTV2(8,8);
	cx_mat DFTwindows(8,8), A(8,8), B(8,8), C(8,8);
	vec magvector, magvectororder;
	int umbral;
	int rows = matrix.n_rows;
	int cols = matrix.n_cols;
	mat removermatrix(rows,cols);

	for(int i=0; i<=image_tam-8; i+=8) {
		for(int j=0; j<=image_tam-8; j+=8) {
			windows = matrix(span(i , i+7),span(j , j+7));
			DFTwindows =fft2(windows);
			magDFTV = abs(DFTwindows);
			magvector = vectorise(magDFTV);
			magvectororder=sort(magvector, "descend");
			umbral = magvectororder(15);
			A = (magDFTV>=umbral) % DFTwindows;
			B = ifft2(A);
			magDFTV2=abs(B);
			removermatrix(span(i , i+7),span(j , j+7))=magDFTV2;
		}
	}


		cout << "Noise_remover complete" << endl;
		return removermatrix;

}
/*! Descripcion: Permite remover ruido mediante el uso de una ventana 8x8 solapado
 *  \fn mat Image::Overlap(mat matrix)
 *  \brief Aproximación por bloques solpados (ventana 8x8) 
 *  \param matrix es la matriz que se le removerá el ruido.
 *  \return removermatrix: Retorna la matriz sin ruido.
 *  \test overlap.cpp
 *  \n mat matrix;
 *  \n Overlap(matrix);
 */

mat Image::Overlap(mat matrix){

	    //fft2(): 2D fast Fourier transform of a matrix (real or complex)
	    mat windows(8,8), magDFTV(8,8), magDFTV2(8,8);
	    cx_mat DFTwindows(8,8), A(8,8), B(8,8), C(8,8);
	    vec magvector(64), magvectororder(64), pixelvec(64);
	    double umbral;
	    int rows = matrix.n_rows;
	    int cols = matrix.n_cols;
	    mat removermatrix = zeros<mat>(rows,cols);
	    mat matpixel(64, (rows-7)*(cols-7));

	    for(int i=0; i<=rows-8; i+=1) {
	        for(int j=0; j<=cols-8; j+=1) {
	            windows = matrix(span(i, i+7),span(j, j+7));
	            DFTwindows =fft2(windows);
	            magDFTV = abs(DFTwindows);
	            magvector = vectorise(magDFTV);
	            magvectororder=sort(magvector, "descend");
	            umbral = magvectororder(15);
	            A = (magDFTV>=umbral) % DFTwindows;
	            B = ifft2(A);
	            magDFTV2=abs(B);
	            pixelvec = vectorise(magDFTV2);
	            matpixel.col(i*(rows-7) + j) = pixelvec;
	        }
	    }

	    int ia, ja, u, w;
	    vec v(64);
	    for (int i=7; i<=rows-8; i++) {
	        for (int j=7; j<=cols-8; j++) {
	                ia=i-7;
	                ja=j-7;
	            for (int k=0; k < 8; k++) {
	                for (int l=0; l < 8; l++) {
	                    u = 63 - l*8 - k;
	                    w = (ja + ia*(rows - 7)) + l + k*(cols - 7);
	                    v(l + 8*k) = matpixel(u,w);
	                    }
	                }

	            removermatrix(i, j) = mean(v);
	            }

	    }
	        cout << "Noise_remover complete" << endl;
	        return removermatrix;

	}

/*! Descripcion: Permite calcular el PSNR de una imagen con ruido y una imagen filtrada 
 *  \fn double Image::PSNR(mat matrix_r, mat matriz_f)
 *  \brief Calculo del PSNR
 *  \param matrix_r es la matriz con ruido.
 *  \param matriz_f es la matriz filtrada o recuperada
 *  \return Retorna el valor del PSNR
 *  \test filtering_mean.cpp
 *  \n mat matrix_r;
 *  \n mat matriz_f;
 *  \n PSNR(matrix_r, matriz_f);
 */
double Image::PSNR(mat matrix_r, mat matrix_f){
	double PSNR, numerator, denominator, division;
	mat subtraction, elev;
	Image I;

	mat matrix_orig = matrix_r(span(2, 253),span(2, 253));
	mat matrix_fil = matrix_f(span(2, 253),span(2, 253));

	if (size(matrix_orig)==size(matrix_fil))
	{
		
		numerator = pow(255.0, 2.0);
		subtraction = matrix_orig - matrix_fil;
		elev = pow(subtraction, 2.0);
		denominator = mean(mean(elev));
		division = numerator / denominator;
		PSNR = 10.0 * log10(abs(division));
	}
	else
		cout<<"No se puede calcular el PSNR"<<endl;
	
	return PSNR;
}


/*! Descripcion: Permite calcular el MSE (Error cuadratico medio) de una imagen con ruido y una imagen filtrada 
 *  \fn double Image::MSE(mat matrix_r, mat matriz_f)
 *  \brief Calculo del MSE
 *  \param matrix_r es la matriz con ruido.
 *  \param matriz_f es la matriz filtrada o recuperada
 *  \return Retorna el valor del MSE
 *  \test filtering_mean.cpp
 *  \n mat matrix_r;
 *  \n mat matriz_f;
 *  \n MSE(matrix_r, matriz_f);
 */

double Image::MSE(mat matrix_r, mat matrix_f){
	double mse; 
	mat subtraction, elev;
	Image I;

	mat matrix_orig = matrix_r(span(2, 253),span(2, 253));
	mat matrix_fil = matrix_f(span(2, 253),span(2, 253));

	if (size(matrix_orig)==size(matrix_fil))
	{

	subtraction = matrix_orig - matrix_fil;
	elev = pow(subtraction, 2.0);
	mse = mean(mean(elev)); //--->OJO REVISAR  
	}
	else
		cout<<"No se puede calcular el MSE"<<endl;
	
	return mse;
}

/*! Descripcion: Permite calcular el MAE (Error promedio absoluto) de una imagen con ruido y una imagen filtrada 
 *  \fn double Image::MAE(mat matrix_r, mat matriz_f)
 *  \brief Calculo del MAE
 *  \param matrix_r es la matriz con ruido.
 *  \param matriz_f es la matriz filtrada o recuperada
 *  \return Retorna el valor del MAE
 *  \test filtering_mean.cpp
 *  \n mat matrix_r;
 *  \n mat matriz_f;
 *  \n MAE(matrix_r, matriz_f);
 */
double Image::MAE(mat matrix_r, mat matrix_f){
	double mae; 
	mat subtraction, elev;
	Image I;

	mat matrix_orig = matrix_r(span(2, 253),span(2, 253));
	mat matrix_fil = matrix_f(span(2, 253),span(2, 253));

	if (size(matrix_orig)==size(matrix_fil))
	{

	subtraction = matrix_orig - matrix_fil;
	elev = abs(subtraction);
	mae = mean(mean(elev)); //--->OJO REVISAR  
	}
	else
		cout<<"No se puede calcular el MSE"<<endl;
	
	return mae;
}


/*! Descripcion: Funcion necesaria para idt_Robusta()
 * 
 * Basado en los Articulos:
 * 
 * Ramírez J. y Paredes J. (2014). Robust Sparse Recovery Base On Weighted Median Operator. IEEE International Conference on Acoustic, Speech
 * and Signal Processing (ICASSP). Department of Electrical Engineering, Universidad de Los Andes, Mérida, Venezuela.  
 * Doi: 978-1-4799-2893-4/14/$31.00. 
 * Recuperado de: http://www.mirlab.org/conference_papers/International_Conference/ICASSP%202014/papers/p1050-ramirez.pdf
 * 
 * Ramírez J. y Paredes J. (2015). Robust Transforms Based on the Weighted Median Operator. IEEE Signal Processing Letters, 22(1), pp. 120 – 124. 
 * doi: 10.1109/LSP.2014.2349351. Recuperado de: http://ieeexplore.ieee.org/document/6880779/
 *
 *  \brief Calculo de la mediana 
 */
double Image::wmedianf(vec& samples, vec& weights)
{
	int i, N;
	N = samples.n_elem;
	uvec sortind(N);
	double threshold;
	double sum_temp;

	double pivote = mean(samples);
	threshold = sum(weights)/2;
	double w1 = sum((samples > pivote) % weights);
	double w2 = sum((samples <= pivote) % weights);
	int N1 =  sum((samples > pivote));
       //cout << w1 << " " << w2 << " "<< N1 << " " << N2 << " " << threshold <<endl;
	double wmedian_output;

		sortind = sort_index(samples,1);
		if (w1 > w2)
		{
			i = N1 - 1;
			sum_temp = w1;
			while (sum_temp >= threshold){
				sum_temp += -weights(sortind(i));
				i--;
			}
			wmedian_output = samples(sortind(i+1));
		}
		else
		{
			i = N1;
			sum_temp = w2;
			while (sum_temp >= threshold){
				sum_temp += -weights(sortind(i));
				i++;
			}
			wmedian_output = samples(sortind(i-1));
		}

	return wmedian_output;
}

/*! Descripcion: Funcion necesaria para idt_Robusta()
 * 
 * Basado en los Articulos:
 * 
 * Ramírez J. y Paredes J. (2014). Robust Sparse Recovery Base On Weighted Median Operator. IEEE International Conference on Acoustic, Speech
 * and Signal Processing (ICASSP). Department of Electrical Engineering, Universidad de Los Andes, Mérida, Venezuela.  
 * Doi: 978-1-4799-2893-4/14/$31.00. 
 * Recuperado de: http://www.mirlab.org/conference_papers/International_Conference/ICASSP%202014/papers/p1050-ramirez.pdf
 * 
 * Ramírez J. y Paredes J. (2015). Robust Transforms Based on the Weighted Median Operator. IEEE Signal Processing Letters, 22(1), pp. 120 – 124. 
 * doi: 10.1109/LSP.2014.2349351. Recuperado de: http://ieeexplore.ieee.org/document/6880779/
 *
 *  \brief Diccionario de la transformada del Coseno
 */
mat Image::Diccionary(){
    double pi = acos(-1.0);
    int width_patch = 8;
    int length_patch;
    length_patch = pow(width_patch,2);
    mat DCT1D(width_patch,width_patch);
    mat DCT2D(length_patch,length_patch);
    vec phi = linspace<vec>(0,width_patch-1,width_patch);
    vec V(width_patch), V1(width_patch);
    double arg, mV, nV, V2;
    for (int i = 0; i < width_patch; i++)
    {
        arg = double(i)*pi/double(width_patch);
        V = cos(arg*phi);
        if (i > 0)
        {
            mV = mean(V);
            V = V - mV;
        }
        V1 = pow(V,2);
	V2 = sum(V1);
	nV = sqrt(V2);
        DCT1D.col(i) = (1.0/nV) * V;
    }
    DCT2D = kron(DCT1D,DCT1D);
    return DCT2D;


}



/*!  \brief Funcion necesaria para idt_Robusta()
 * 
 * Basado en los Articulos:
 * 
 * Ramírez J. y Paredes J. (2014). Robust Sparse Recovery Base On Weighted Median Operator. IEEE International Conference on Acoustic, Speech
 * and Signal Processing (ICASSP). Department of Electrical Engineering, Universidad de Los Andes, Mérida, Venezuela.  
 * Doi: 978-1-4799-2893-4/14/$31.00. 
 * Recuperado de: http://www.mirlab.org/conference_papers/International_Conference/ICASSP%202014/papers/p1050-ramirez.pdf
 * 
 * Ramírez J. y Paredes J. (2015). Robust Transforms Based on the Weighted Median Operator. IEEE Signal Processing Letters, 22(1), pp. 120 – 124. 
 * doi: 10.1109/LSP.2014.2349351. Recuperado de: http://ieeexplore.ieee.org/document/6880779/
 *
 */
vec Image::Fast_awmr(vec& y, mat& A, int sparsity, int itmax, double beta, double tol, double epsilon, int numcoefperiter, double Kpar)
{
	
	int N, M, P;
	N = A.n_cols;
	M = A.n_rows;
	vec x(N);
	mat absA(M,N);
	mat AT(N,M);
	AT = A.t();
	absA = abs(A);

	//lambda inicial
	mat lambda_m(1,N);
	lambda_m = sum(absA);
	vec lambda_v(N);
	lambda_v = lambda_m.t();
	double lambda;
	lambda = 0.5*epsilon*max(lambda_v);

	//Numero de iteraciones de busqueda de soporte
	int Ts;
	Ts = int((sparsity/numcoefperiter)+1);

	//Declaracion de variables requeridas
	vec ye(M), r(M), rn(M), ai(M);
	vec samples(M+1), weights(M+1);
	x.zeros();
	ye.zeros();
	rn.zeros();
	double yn, acc, x_temp;
	yn = norm(y,2);
	acc = tol + 1;
	double er;

	r = y;
	vec r1;
	
	int i, j, k, l, iter, iteration;
	iteration = 0;
	vec ATfr(N);
	uvec index_ATfr(N);
	uvec soporte_temp, sp(numcoefperiter);
	uvec soporte;

	while (iteration < itmax && acc > tol)
	{
		r1 = (2*r)/(pow(r,2) + pow(Kpar,2));		
		if (P < sparsity)
		{
			ATfr = abs(AT * r1);
			index_ATfr = sort_index(ATfr,1);
		
			for(j = 0; j < numcoefperiter; j++)
			{
				sp(j) = index_ATfr(j);
			}
			soporte_temp = join_cols(soporte_temp, sp);		
		}
		soporte = unique(soporte_temp);
		P = soporte.n_elem;
		Image I;

		for (k = 0; k < P; k++)
		{
			l = soporte(k);
			x_temp = x(l);
			ai = A.col(l);
			rn = y - ye + (x(l) * ai);
			for (j = 0; j < M; j++)
			{
				samples(j) = rn(j)/ai(j);
				weights(j) = abs(ai(j));
			}
			weights(M) = lambda/(epsilon + abs(x(l)));
			samples(M) = 0;
			x(l) = I.wmedianf(samples, weights);
			ye = ye + (x(l) - x_temp)*A.col(l);
		}
		r = y - ye;
		er = norm(r,2);
		acc = er/yn;
		iteration++;
		lambda = lambda*beta;
	}
return x;
}




/*! Descripcion: Permite remover ruido mediante el uso de una ventana 8x8 solapado por media (0) y mediana ponderada (1). 
 * 
 * Basado en los Articulos:
 * 
 * Ramírez J. y Paredes J. (2014). Robust Sparse Recovery Base On Weighted Median Operator. IEEE International Conference on Acoustic, Speech
 * and Signal Processing (ICASSP). Department of Electrical Engineering, Universidad de Los Andes, Mérida, Venezuela.  
 * Doi: 978-1-4799-2893-4/14/$31.00. 
 * Recuperado de: http://www.mirlab.org/conference_papers/International_Conference/ICASSP%202014/papers/p1050-ramirez.pdf
 * 
 * Ramírez J. y Paredes J. (2015). Robust Transforms Based on the Weighted Median Operator. IEEE Signal Processing Letters, 22(1), pp. 120 – 124. 
 * doi: 10.1109/LSP.2014.2349351. Recuperado de: http://ieeexplore.ieee.org/document/6880779/
 *
 *  \fn mat Image::Idtc_Robusta(mat matrix, int flag)
 *  \brief Aproximación Robusta por bloques solpados (ventana 8x8)
 *  \param matrix es la matriz con ruido.
 *  \param flag es la bandera que indica si se efectua el promedio o la mediana. Donde el promedio es igual 0 y la mediana igual a 1
 *  \return Retorna la matriz sin ruido.
 *  \test idtc_Robusta_median.cpp idtc_Robusta_mean.cpp
 *  \n mat matrix;
 *  \n int flag = 0;
 *  \n Idtc_Robusta(matrix, flag);
 */
mat Image::Idtc_Robusta(mat matrix, int flag){

	    //Declaraciones
		int sparsity = 6;
	    int itmax = 8;
	    double beta = 0.95;
	    double tol = 1*pow(10, -6);
	    double epsilon  = 1*pow(10,-3);
	    int numcoefperiter = 2;
	    double Kpar = 0.25;
	    mat windows(8,8), magDFTV(8,8), magDFTV2(8,8);
	    cx_mat DFTwindows(8,8), A(8,8), B(8,8), C(8,8);
	    vec magvector(64), magvectororder(64), pixelvec(64);
	    double umbral;
	    int rows = matrix.n_rows;
	    int cols = matrix.n_cols;
	    mat removermatrix = zeros<mat>(rows,cols);
	    mat matpixel(64, (rows-7)*(cols-7));
	    Image I;	   
	    mat dic;
	    dic = I.Diccionary();
	    mat xmat(64,1);
	    mat idct(64,1);
	    vec x(64);
	   

	   //Funcion
	    for(int i=0; i<=rows-8; i+=1) {
	        for(int j=0; j<=cols-8; j+=1) {
	            windows = matrix(span(i, i+7),span(j, j+7));

	            //Vectorizacion de la matriz
	            magvector = vectorise(windows);

	            //Fast_awmr y Diccionary son sus codigos profe
	            x = I.Fast_awmr(magvector, dic, sparsity, itmax, beta, tol, epsilon, numcoefperiter, Kpar);

	            idct = dic * x;
	            matpixel.col(i*(rows-7) + j) = idct;
	        }
	    }

	    int ia, ja, u, w;
	    vec v(64);
	    for (int i=7; i<=rows-8; i++) {
	        for (int j=7; j<=cols-8; j++) {
	                ia=i-7;
	                ja=j-7;
	            for (int k=0; k < 8; k++) {
	                for (int l=0; l < 8; l++) {
	                    u = 63 - l*8 - k;
	                    w = (ja + ia*(rows - 7)) + l + k*(cols - 7);
	                    v(l + 8*k) = matpixel(u,w);
	                    }
	                }

	            removermatrix(i, j) = Average_Median(v, flag);
	            }

	    }
	        cout << "Noise_remover complete" << endl;

	        return removermatrix;

	}

