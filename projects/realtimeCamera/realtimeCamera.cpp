/*
 *  Displaying realtime footage with first available camera
 *
 *  19.04.17 | Lucas Barbosa | Open source software
 */

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <iostream>

using namespace std;
using namespace cv;

#define ESC_ASCII      27
#define DEFAULT_CAMERA 0

int main (void) {
  
  // choose default camera
  cv::VideoCapture cam_cap(DEFAULT_CAMERA);
  std::string windowName = "Smile for the camera";
  char check_for_esc_key = 0;

  if (!cam_cap.isOpened()) {
    std::cout << "No camera input." << std::endl;
    return -1;
  }

  cv::Mat img_edges;
  namedWindow(windowName, cv::WINDOW_AUTOSIZE);

  while (check_for_esc_key != ESC_ASCII)
  {
    cv::Mat img_frame;
    cam_cap >> img_frame;   // get a new frame from camera

    if (img_frame.empty()) {
      std::cout << "Current frame is empty." << std::endl;
      break;
    }

    cv::imshow( windowName, img_frame );

    // wait for esc key to be pressed
    check_for_esc_key = cv::waitKey(1);

  }

  return 0;
}
