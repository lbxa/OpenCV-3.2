/*
 *  Simple OpenCV project which outputs an image to the screen.
 *
 *  <opencv2/opencv.hpp>:
 *  Contains all OpenCV supported functions
 *
 *  Lucas Barbosa | 08.04.2017 | All Rights Reserved (R)
 */

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char **argv)
{
	
  // class cv::Mat is what will hold single and multi-channel arrays (images etc.)
  cv::Mat img = cv::imread("image.jpg");

  std::string windowName = "Image Display";

  if (img.empty())
  {
    std::cout << "Image was not found." << std::endl;
    return 0;
  }

  // creates a window which can be used as a placeholder for images

  /*
   *  cv::namedWindow(<cv::String winname>, <int Flags = 1>)
   *  
   *  <cv::String winname>:
   *  Name of the window being displayed, also concidered as an indentifier
   *
   *  <int Flags = 1>:
   *  Flags include support for window re-sizing capabilities
   *    <cv::WINDOW_AUTOSIZE = 1>: 
   *      Makes window's size relative to image size, not user re-sizable
   *    <cv::WINDOW_NORMAL = 0>:
   *      Makes window's and image's size relative to user ajustable size
   *
   */
  cv::namedWindow(windowName, cv::WINDOW_AUTOSIZE );

  // displays and image in the specified window
  cv::imshow( windowName, img );

  // holds window open until user presses any key
  cv::waitKey(0);

  cv::destroyWindow( windowName );

  return 0;

}