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

/*! Descripcion: Permite cargar dos imagenes en una ventana de opencv con sus respectivas etiquetas (label).
 *  \fn void Image::Two_windows_opencv(const char* imag1, const char* imag2, string label1, string label2)
 *  \brief Carga dos imagenes en una ventana de opencv
 *  \param imag1 es la ruta o ubicación de la imagen1.
 *  \param imag2 es la ruta o ubicación de la imagen2.
 *  \param label1 es el nombre de la imagen1.
 *  \param label2 es el nombre de la imagen2.
 *  \return  Abre la ventana opencv con dos imagenes.
 *  \test main.cpp
 *  \n const char* imag1= "src/Resources/images_salt_and_pepper/lady_256_0_1.pgm";
 *  \n const char* imag2= "src/Resources/images_salt_and_pepper/lady_256_1.pgm";
 *  \n string label1 = "Imagen1";
 *  \n string label2 = "Imagen2";
 *  \n Two_windows_opencv(imag1, imag2, label1, label2);
 */

void Image::Two_windows_opencv(const char* imag1, const char* imag2, string label1, string label2)
{
    Mat im1 = imread(imag1);
    Mat im2 = imread(imag2);
    Size sz1 = im1.size();
    Size sz2 = im2.size();
 
   /*LABEL*/
    String text1 = label1;
    String text2 = label2;
    putText(im1,text1, Point(10,240), FONT_HERSHEY_COMPLEX, 0.3 , (0,0,0), 0.1);
    putText(im2,text2, Point(10,240), FONT_HERSHEY_COMPLEX, 0.3, (0,0,0), 0.1);

    /*LABEL*/
    Mat im3(sz1.height, sz1.width+sz2.width, CV_8UC3);
    im1.copyTo(im3(Rect(0, 0, sz1.width, sz1.height)));
    im2.copyTo(im3(Rect(sz1.width, 0, sz2.width, sz2.height)));
    namedWindow("Two images OPENCV", 0);

    // show the image on window
    imshow("Two images OPENCV", im3);
    waitKey(0);

}










