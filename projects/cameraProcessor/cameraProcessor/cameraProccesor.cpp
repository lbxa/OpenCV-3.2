/*
 *  Camera Processor
 *
 *  OpenCV project which reads frames from default camera on
 *  computer and displays frames with a Guassian blur.
 *
 *  Lucas Barbosa | 07.04.2017 | All Rights Reserved (R)
 */

#include <opencv2\opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

#define ESC_ASCII 27

int main(int argc, char **argv)
{
  
  // choose default camera
  cv::VideoCapture cam_cap(0);
  std::string windowName = "Example1";
  char check_for_esc_key = 0;

  if (!cam_cap.isOpened()) return -1;

  cv::Mat img_edges;
  namedWindow(windowName, cv::WINDOW_AUTOSIZE);

  while (check_for_esc_key != ESC_ASCII)
  {
    cv::Mat img_frame;
    cam_cap >> img_frame;   // get a new frame from camera

    if (img_frame.empty()) break;

    cvtColor(img_frame, img_edges, cv::COLOR_BGR2GRAY);
    GaussianBlur(img_edges, img_edges, cv::Size(7, 7), 1.5, 1.5);

    cv::Canny( img_edges, img_edges, 0, 30, 3, true );
    cv::imshow( windowName, img_edges );


    // wait for esc key to be pressed
    check_for_esc_key = cv::waitKey(1);

  }


  return 0;

}
