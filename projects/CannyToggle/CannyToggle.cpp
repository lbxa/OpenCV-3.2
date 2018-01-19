/*
 *  Canny Toggle Project
 *
 *  Incorporating <highgui>'s trackbar with a Canny 
 *  edge, regulated image to test the effects of noise
 *  reduction in images and video.
 *
 *  29.04.2017 | Lucas Barbosa | Open source software
 */

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <cv.h>

#include <iostream>
#include <vector>

using namespace std;
using namespace cv;

#define ESC_ASCII 27

cv::Mat src, src_gray;
cv::Mat dst, detected_edges;

int edgeThresh = 1;
int lowThreshold;
int const max_lowThreshold = 100;
int ratio = 3;
int kernel_size = 3;
std::string window_name = "Edge Map";
std::string trackbar_name = "Min Threshold:";
int sigmaX = 4;

/*
 *  @function ToggelCanny
 *  @brief Trackbar Callback - Canny Threshold is reponsive to this
 *  active trackbar
 */

void ToggleCanny (int, void *);

/** @function main  */
int main (int agrc, char **argv){

  src = cv::imread( argv[1] );

  if (src.empty()) {
    std::cout << "Image was empty." << std::endl;
    return -1;
  }

  cv::cvtColor(src, src_gray, cv::COLOR_BGR2GRAY);
  cv::namedWindow(window_name, cv::WINDOW_AUTOSIZE);

  cv::createTrackbar(trackbar_name, window_name, &lowThreshold,
		     max_lowThreshold, ToggleCanny);

  ToggleCanny(0, 0);

  cv::waitKey(0);

  cv::destroyWindow(window_name);
  
  return 0;
  
}

void ToggleCanny (int, void *) {
  /// Reduce noise with a kernel 3x3
  cv::GaussianBlur(src_gray, detected_edges, cv::Size(3, 3), sigmaX);
  /// Canny detector
  cv::Canny(detected_edges, detected_edges, lowThreshold,
	    lowThreshold * ratio, kernel_size);
  /// Using Canny's output as a mask display the result
  dst = cv::Scalar::all(0);
  src.copyTo( dst, detected_edges );
  cv::imshow( window_name, dst );
}
