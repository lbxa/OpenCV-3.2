/*
 *  Test Driver for displaying a simple image
 *  
 *  Lucas Barbosa | 18/04/17 | Open source code
 */

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <iostream>

using namespace std;
using namespace cv;

cv::Mat img_in;
std::string windowName = "Mandelbrot Art";

int main (void) {

  img_in = cv::imread("image.png");

  if (img_in.empty()) {
    std::cout << "Empty image." << std::endl;
    return 1;
  }

  cv::namedWindow(windowName, cv::WINDOW_AUTOSIZE);
  cv::imshow(windowName, img_in);

  cv::waitKey(0);
  cv::destroyWindow(windowName);

  return 0;

}

