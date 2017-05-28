/*
**  SandBox
**
**  OpenCV sandbox for testing projects out and playing with data types 
**  and structures. This is purely made to have fun. 
**
**  27.05.2017 | Lucas Barbosa (C) | Open source software 
*/

// OpenCV
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>

// STL
#include <iostream>
#include <vector>
#include <cmath>

// Auxilary
#include "aux.h"

using namespace std;
using namespace cv;
using namespace aux;

#define ESC_ASCII 27

#define X 0
#define Y 1
#define Z 2
#define A 3

std::string mainWindowName = "SandBox";

int main (int agrc, char **argv) {

  /*
  **  @Point()
  **
  **  Can be treated as primitive class, just like any point on the cartesian plane
  **  Tests with the Point class...
  */

  double xCoo = 5.7654;
  double yCoo = 6.43;
  double zCoo = 56.7;
  double aCoo = 4.65678;
  cv::Point(xCoo, yCoo);  // Using constructor syntax

  // Display of @Point() in integer format
  std::cout << "Point(" << aux::itostr(static_cast<int>(xCoo)) << ","
	    << aux::itostr(static_cast<int>(yCoo)) << ")" << std::endl;

  cv::Point MappedPoint;  // Appreciating the actual class syntax...
  MappedPoint.x = xCoo;
  MappedPoint.y = yCoo;

  /*
  **  @Scalar()
  **  
  **  Scalar -> 4 Dimensional point comprised of double floating precision points
  **  Tests with the Scalar() class.. 
  */

  cv::Scalar ScalarCoo; 
  ScalarCoo[X] = xCoo;
  ScalarCoo[Y] = yCoo;
  ScalarCoo[Z] = zCoo;
  ScalarCoo[A] = aCoo;

  // Scalar should compile.
  std::cout << "Scalar(" << ScalarCoo[X] << "," << ScalarCoo[Y]
	    << "," << ScalarCoo[Z] << "," << ScalarCoo[A] << ")" <<  std::endl;
  
  return 0;
  
}
