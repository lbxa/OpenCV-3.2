/*
 *
 *
 *
 *
 */

#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>

#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char **argv)
{
  
  std::string windowName = "Video Capture";

  cv::namedWindow(windowName, cv::WINDOW_AUTOSIZE);

  cv::VideoCapture cap;
  cap.open("video.mp4");

  cv::Mat frame;

  while(true)
  {
    cap >> frame;
    if (frame.empty()) break;
    cv::imshow(windowName, frame);
    if (cv::waitKey(33) >= 1) break; 
  }
  
  return 0;

}