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

#include "../include/Image.hpp"
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/utility.hpp>
#include <iostream>
using namespace cv;
using namespace std;


/*! Descripcion: Permite cargar cuatro imagenes en una ventana de opencv
 *  \fn void Image::Four_windows_opencv(const char* imag1, const char* imag2, const char* imag3, const char* imag4, string label1, string label2, string label3, string label4)
 *  \brief Carga cuatro imagenes en una ventana de opencv
 *  \param imag1 es la ruta o ubicación de la imagen1
 *  \param imag2 es la ruta o ubicación de la imagen2 ....Imag3 ... Imag4
 *  \param label1 es el nombre de la imagen1
 *  \param label2 es el nombre de la imagen2 ....Imag3 ... Imag4
 *  \return  Abre la ventana opencv con cuatro imagenes
 *  \test main.cpp
 *  \n const char* imag1= "src/Resources/images_salt_and_pepper/lady_256_0_1.pgm";
 *  \n const char* imag2= "src/Resources/images_salt_and_pepper/lady_256_1.pgm";
 *  \n const char* imag3= "src/Resources/images_salt_and_pepper/lady_256_10.pgm";
	\n const char* imag4= "src/Resources/images_salt_and_pepper/lady_256_100.pgm";
 *  \n Four_windows_opencv(imag1, imag2, imag3, imag4, label1, label2, label3, label4);
 */
void Image::Four_windows_opencv(const char* imag1, const char* imag2, const char* imag3, const char* imag4, const char*  label1, const char* label2, const char* label3, const char* label4)
{

	//Image Reading
	IplImage* img1 = cvLoadImage( imag1 );
	IplImage* img2 = cvLoadImage( imag2 );
	IplImage* img3 = cvLoadImage( imag3 );
	IplImage* img4 = cvLoadImage( imag4 );

	int dstWidth=img1->width+img1->width;
	int dstHeight=img1->height+img1->height;

	/*IplImage* cvCreateImage(CvSize size, int depth, int channels)
    size - Image width and height
	IPL_DEPTH_8U - unsigned 8-bit integer. Equivalent to CV_8U in matrix types.
	*/

	IplImage* dst=cvCreateImage(cvSize(dstWidth,dstHeight),IPL_DEPTH_8U,3);

	/*Label first image*/
	const char*  text1 = label1;
	CvFont font;
	double hScale=0.4;
	double vScale=0.4;
	int    lineWidth=1;
	cvInitFont(&font,CV_FONT_HERSHEY_COMPLEX, hScale,vScale,0,lineWidth);
	cvPutText (img1, text1, cvPoint(10,240), &font, cvScalar(0,0,0));


	// Copy first image to dst
	cvSetImageROI(dst, cvRect(0, 0,img1->width,img1->height) );
	cvCopy(img1,dst,NULL);
	cvResetImageROI(dst);


	/*Label second image*/
	const char*  text2 = label2;
	cvInitFont(&font,CV_FONT_HERSHEY_COMPLEX, hScale,vScale,0,lineWidth);
	cvPutText (img2, text2, cvPoint(10,240), &font, cvScalar(0,0,0));

	// Copy second image to dst
	cvSetImageROI(dst, cvRect(img2->width, 0,img2->width,img2->height) );
	cvCopy(img2,dst,NULL);
	cvResetImageROI(dst);


	/*Label third image*/
	const char*  text3 = label3;
	cvInitFont(&font,CV_FONT_HERSHEY_COMPLEX, hScale,vScale,0,lineWidth);
	cvPutText (img3, text3, cvPoint(10,240), &font, cvScalar(0,0,0));


	// Copy third image to dst
	cvSetImageROI(dst, cvRect(0, img3->height,img3->width,img3->height) );
	cvCopy(img3,dst,NULL);
	cvResetImageROI(dst);


	/*Label fourth image*/
	const char*  text4 = label4;
	cvInitFont(&font,CV_FONT_HERSHEY_COMPLEX, hScale,vScale,0,lineWidth);
	cvPutText (img4, text4, cvPoint(10,240), &font, cvScalar(255,0,0));


	// Copy fourth image to dst
	cvSetImageROI(dst, cvRect(img4->width, img4->height,img4->width,img4->height) );
	cvCopy(img4,dst,NULL);
	cvResetImageROI(dst);


	//show all in a single window
	//CV_WINDOW_AUTOSIZE
	//CV_WINDOW_NORMAL
	namedWindow( "Four windows OPENCV", 0);
	cvShowImage( "Four windows OPENCV", dst );
	waitKey(0);

}

