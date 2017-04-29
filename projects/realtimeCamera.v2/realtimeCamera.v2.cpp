/* 
 *  Realtime Camera Version 2
 * 
 *  This is an overall improvement of the original realtime
 *  camera project. Targeting linux distros specifically
 *
 *  24.04.17 | Lucas Barbosa | Open source software
 */

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <iostream>
#include <vector>

using namespace cv;
using namespace std;

#define ESC_ASCII 27

int thresh_ratio = 3;
int low_thresh = 5;
const int kernel_size = 3;

int main (int argc, char **argv)
{

  // Capture sigma x values
  std::string user_in;
  std::cout << "Input Gaussian Sigmax: ";
  getline(cin, user_in);
  int sigma_int = std::stoi(user_in);
  double gaussian_sigmax = static_cast<double>( sigma_int );
  /////////////

  cv::VideoCapture web_cam(1);
  std::string windowName = "Simle for the camera.";
  std::string trackbarName = "Blur Index";
  char check_for_esc = 0;
  
  if (!web_cam.isOpened())
  {
    std::cout << "Webcam is not capturing video." << std::endl;
    return 1;
  }
  
  cv::namedWindow(windowName, cv::WINDOW_NORMAL);
  cv::Mat single_frame;
  cv::Mat edged_frame;
  
  while (check_for_esc != ESC_ASCII)
  {
    web_cam >> single_frame;
    if (single_frame.empty())
    {
      std::cout << "Frame is empty." << std::endl;
      return 1;
    }

  cv::GaussianBlur( single_frame, edged_frame, Size(5, 5),
                      gaussian_sigmax );
  cv::GaussianBlur( edged_frame, edged_frame, Size(5, 5),
                    gaussian_sigmax );

  cv::cvtColor( edged_frame, edged_frame, cv::COLOR_BGR2GRAY );
  
  cv::Canny( edged_frame, edged_frame, low_thresh,
             low_thresh * thresh_ratio,
             kernel_size);

  cv::putText( edged_frame, "Smile for the camera", Point(10, 40),
	       cv::FONT_HERSHEY_SIMPLEX, 1, Scalar(255, 255, 0), 2);

  cv::imshow( windowName, edged_frame);

    check_for_esc = cv::waitKey(30);
  }

  cv::destroyWindow(windowName);
  
  return 0;
  
}
