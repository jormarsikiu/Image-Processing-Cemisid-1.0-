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
#include <iostream>
#include <armadillo>



using namespace arma;
using namespace std;

int main(){

	Image Img;

	
	string ruta = "../Resources/images/friends2.jpg";
	Img.Detection_Face(ruta);


	return 0;

}



