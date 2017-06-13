/*
 *  Camera Processor
 *
 *  OpenCV project which reads frames from default camera on
 *  computer and displays frames with a Guassian blurred canny
 *  edge image.
 *
 *  Lucas Barbosa | 07.04.2017 | All Rights Reserved (R)
 */

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

#define ESC_ASCII 27
#define WEBCAM 1

int main(int argc, char **argv)
{
  
  // choose default camera
  cv::VideoCapture cam_cap(WEBCAM);
  std::string windowName = "Smile for the camera";
  char check_for_esc_key = 0;

  if (!cam_cap.isOpened()) return -1;

  cv::Mat img_edges;
  cv::namedWindow(windowName, cv::WINDOW_NORMAL);

  while (check_for_esc_key != ESC_ASCII)
  {
    cv::Mat img_frame;
    cam_cap >> img_frame;   // get a new frame from camera

    if (img_frame.empty()) break;

    cv::imshow( windowName, img_frame );

    // wait for esc key to be pressed
    check_for_esc_key = cv::waitKey(30);

  }

  cv::destroyWindow( windowName );

  return 0;

}
