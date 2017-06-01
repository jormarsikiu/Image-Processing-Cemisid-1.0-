/* Copyright (C) 2017  Jormar S. Turizo A.
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
haarcascade_eye_tree_eyeglasses.xml		//Reconoce los ojos
haarcascade_eye.xml 				//Reconoce los ojos 
haarcascade_frontalcatface_extended.xml
haarcascade_frontalcatface.xml
haarcascade_frontalface_alt2.xml
haarcascade_frontalface_alt_tree.xml
haarcascade_frontalface_alt.xml  		//Reconoce el rostro
haarcascade_frontalface_default.xml
haarcascade_fullbody.xml
haarcascade_lefteye_2splits.xml
haarcascade_licence_plate_rus_16stages.xml
haarcascade_lowerbody.xml
haarcascade_profileface.xml
haarcascade_righteye_2splits.xml
haarcascade_russian_plate_number.xml
haarcascade_smile.xml
haarcascade_upperbody.xml
*/
#include "../include/Image.hpp"
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/utility.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

CascadeClassifier face_cascade;

void Image::Detection_Face(string ruta){

vector<Rect> faces; // Vector para las caras detectadas
	// Carga el archivo xml para detectar caras:

	if (!face_cascade.load("/usr/local/share/OpenCV/haarcascades/haarcascade_frontalface_alt.xml")){
    		cout << "Cannot load face xml!" << endl; }


	Mat src = imread(ruta); // Almacena en la matriz scr la imagen
	if (src.empty()){
	    	cout << "Cannot load image!" << endl; }

	// Pasamos a escala de grises la imagen
	Mat gray;
	cvtColor(src, gray, CV_BGR2GRAY);
	equalizeHist(gray, gray);


	//imshow("Gray", gray);
	face_cascade.detectMultiScale(gray, faces, 1.2, 3); // Detectamos las caras presentes en la imagen
   
	// Caras
	// Repetimos tantas veces como caras detectadas:
	for (int i = 0; i < int(faces.size()); i++){ 
		Rect r = faces[i];
		rectangle(src, Point(r.x, r.y), Point(r.x + r.width, r.y + r.height), CV_RGB(0,255,0)); // Marcamos la cara
	}
	namedWindow("Detection Face", 0);
	imshow("Detection Face", src); // Mostramos la imagen con las caras marcadas
	waitKey(0);
}



