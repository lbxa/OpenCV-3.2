/*
 *  Image Pyramid
 *
 *  Using Gaussian blur to down sample images creating
 *  the next image half the width and height of the original
 *  image. Now you can see where the whole pyramid idea comes 
 *  from.
 *
 *  This can be good in computer vision for analysing changing
 *  scales in an image during observation cycles.
 *
 *  Lucas Barbosa | 11.04.2017 | All Rights Reserved (R)
 */

#include <opencv2\imgproc\imgproc.hpp>
#include <opencv2\highgui\highgui.hpp>

#include <iostream>

#define ESC_ASCII 27

using namespace std;
using namespace cv;

int main(int argc, char *argv)
{
  
  cv::Mat img1, img2, img3, img4;
  img1 = cv::imread("image.jpg");
  if (img1.empty())
  {
    std::cout << "Image was empty." << std::endl;
    return -1;
  }

  std::string win1 = "Image 1";
  std::string win2 = "Image 2";
  std::string win3 = "Image 3";
  std::string win4 = "Image 4";

  cv::namedWindow( win1, cv::WINDOW_AUTOSIZE );
  cv::namedWindow( win2, cv::WINDOW_AUTOSIZE );
  cv::namedWindow( win3, cv::WINDOW_AUTOSIZE );
  cv::namedWindow( win4, cv::WINDOW_AUTOSIZE );

  /*
   *  cv::pyrDown( <inputArray>, <outputArray> );
   *
   *  Downsamples signals so that the outputArray has frames 
   *  which are exactly half the width and the height of the
   *  input arrays. This can be a continuous process to produce
   *  and image pyramid. This function uses Gaussian blur to process
   *  the smaller image output(s). 
   */

  cv::imshow ( win1, img1 );
  cv::pyrDown( img1, img2 );
  cv::imshow ( win2, img2 );
  cv::pyrDown( img2, img3 );
  cv::imshow ( win3, img3 );
  cv::pyrDown( img3, img4 );
  cv::imshow ( win4, img4 );

  cv::waitKey(0);
  cv::destroyAllWindows();

  return 0;

}