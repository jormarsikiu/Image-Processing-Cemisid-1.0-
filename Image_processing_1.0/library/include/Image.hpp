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
 * Image.h
 *  	Descripcion: Implementación de funciones que permiten manipular las imagenes en forma de matrices
 */

#ifndef IMAGE_H_
#define IMAGE_H_

#include <iostream>
#include <armadillo>

/**
  \class Image.h "src/Image.h"
*/

class Image {

public:

	arma::mat Image_load(arma::mat, std::string);
	Image();
	Image(arma::mat);
	void Dimension();	
	int Get_pixel(int, int);
	void Get_pixels();
	arma::mat Gaussian_noise(double);
	arma::mat Lost_pixels_noise(int);
	arma::mat Salt_and_pepper_noise(int);
	arma::mat Impulsive_uniform_noise(int);
	void SaveImage(arma::mat, std::string);
	double PSNR(arma::mat, arma::mat);
	double MAE(arma::mat, arma::mat);
	double MSE(arma::mat, arma::mat);
	arma::mat Filtering(arma::mat, int, int);
	void Detection_Face(std::string);
	void Four_windows_opencv(const char*, const char*, const char*, const char*, const char*,const char*,const char*,const char*);
	void Two_windows_opencv(const char*, const char*, std::string, std::string);
	arma::mat Noise_remover(arma::mat, int);
	arma::mat Overlap(arma::mat);
	arma::mat Idtc_Robusta(arma::mat, int);
	double wmedianf(arma::vec&, arma::vec&);
	arma::mat Diccionary();
	arma::vec Fast_awmr(arma::vec& y, arma::mat& A, int sparsity, int itmax, double beta, double tol, double epsilon, int numcoefperiter, double Kpar);

	 ~Image();

private:

	int cols, rows;
	arma::mat matrix;
};

#endif /* IMAGE_H_ */

