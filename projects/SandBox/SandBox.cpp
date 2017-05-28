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
  std::cout << std::endl;
  /*
  **  @Point()
  **
  **  Can be treated as primitive class, just like any point on the cartesian plane
  **  Point classes are implemented on a template basis, therefore they can be points
  **  of any basic types: int, float, double, long long etc..
  **  Member accessing is via dot notation (Point.x, Point.y, Point.z)  
  **
  **  -- -- -- -- 
  **  typedef Point<int, 2>    Point2i;
  **  typedef Point<int, 3>    Point3i;
  **  typedef Point<float, 2>  Point2f;
  **  typedef Point<float, 3>  Point3f;
  **  typedef Point<double, 2> Point2d;
  **  typedef Point<double, 3> Point3d;
  */

  double xCoo = 5.74;
  double yCoo = 6.43;
  double zCoo = 5.57;
  double aCoo = 4.68;
  cv::Point2d(xCoo, yCoo);  // Using constructor syntax

  // Display of @Point() in integer format
  std::cout << bold_on << blackBG_on << "Point(" << aux::itostr(static_cast<int>(xCoo))
	    << "," << aux::itostr(static_cast<int>(yCoo)) << ")" << color_off << std::endl
            << "------"  << std::endl;

  cv::Point2d MappedPoint;  // Appreciating the actual class syntax...
  MappedPoint.x = xCoo;
  MappedPoint.y = yCoo;

  /*
  **  @Size()
  **
  **  Size is extremly similar to the cv::Point() class, in fact each can be cast
  **  to another. The main difference between both is the method of member accessing.
  **  Size uses width and height whilst Point uses x and y (which is pretty self-
  **  explanatory). Also Size is only 2 dimensional
  */

  cv::Size myRect;  // Hmmmmmm, well whats a good shape to play with?
  myRect.width  = 500;
  myRect.height = 200;

  std::cout << bold_on << blackBG_on << "Size(" << myRect.width << "," << myRect.height
	    << ")" << color_off << std::endl << "------" << std::endl;

  /*
  **  @Scalar()
  **  
  **  Scalar -> 4 Dimensional point comprised of double floating precision point.
  */

  cv::Scalar ScalarCoo; 
  ScalarCoo[X] = xCoo;
  ScalarCoo[Y] = yCoo;
  ScalarCoo[Z] = zCoo;
  ScalarCoo[A] = aCoo;

  // Scalar should compile.
  std::cout << bold_on << blackBG_on << "Scalar(" << ScalarCoo[X] << "," << ScalarCoo[Y]
	    << "," << ScalarCoo[Z] << "," << ScalarCoo[A] << ")" << color_off << std::endl
            << std::endl;
  
  return 0;
  
}
