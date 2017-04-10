/*
*  Gaussian Blur
*
*  Aims to understand OpenCV filters and static image
*  manipulations with the Gaussian Blur effect and 
*  further explorations of multiple windows with HighGUI.
*
*  Lucas Barbosa | 08.04.2017 | All Rights Reserved (R)
*/

#include <opencv2\imgproc\imgproc.hpp>
#include <opencv2\highgui\highgui.hpp>

#include <iostream>

using namespace cv;
using namespace std;

#define ESC_ASCII 27

void displayGuassian(const cv::Mat &img_in, int blur_size);

int main(int argc, char **argv)
{

  std::string gBlur_size;
  std::cout << "Input blur size: ";
  std::getline(cin, gBlur_size);
  int blur_size_int = std::stoi(gBlur_size);

  cv::Mat og_img = cv::imread("image.jpg");
  std::string ogImgWindowName = "Original Image";

  if (og_img.empty())
  {
    std::cout << "Image was empty." << std::endl;
    return -1;
  }

  cv::namedWindow(ogImgWindowName, cv::WINDOW_NORMAL);
  cv::imshow(ogImgWindowName, og_img);
  displayGuassian(og_img, blur_size_int);

  // awaits any key press
  cv::waitKey(0);
  // destroys all window instances
  cv::destroyAllWindows();

  return 0;

}

void displayGuassian(const cv::Mat &img_in, int blur_size)
{
  std::string windowName = "Double Gaussian Blur";
  cv::Mat img_out;

  if (blur_size > 7)
  {
    blur_size = 7;
  }

  /*
  *  cv::GaussianBlur(<cv::InputArray>, <outputArray>, <blurSize>, <sigmaX>, <sigmaY>)
  *
  *  Filters image's frame into a blurred version according to the pixel blur size
  *  which is denoted as a Size(width, height) struct. Size() arguments should always
  *  be odd numbers as the Gaussian Kernel is computed at the CENTER pixel.
  */
  cv::GaussianBlur(img_in, img_out, cv::Size(blur_size, blur_size), 4, 4);  // image is filtered twice
  cv::GaussianBlur(img_out, img_out, cv::Size(blur_size, blur_size), 4, 4);

  cv::namedWindow(windowName, cv::WINDOW_NORMAL);
  cv::imshow(windowName, img_out);

}