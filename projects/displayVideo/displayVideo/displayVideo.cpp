/*
 *  Display Video
 *
 *  Mimicking a media player much like the countless ones 
 *  which already exist.
 *
 *  Lucas Barbosa | 08.04.2017 | All Rights Reserved (R)
 */

#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>

#include <iostream>
#include <fstream>

using namespace cv;
using namespace std;

#define ESC_ASCII 27

// global variables contain g_ prefix
int g_slider_position = 0;
int g_run = 1, g_dontset = 0;  // start out in single step mode
cv::VideoCapture g_cap;

void onTrackBarSlide(int pos, void *)
{ 
  /*s
   *  cv::CAP_PROP_POS_FRAMES = 1
   *
   *  Based index of the frame to be captured or decoded next.
   */
  g_cap.set( cv::CAP_PROP_POS_FRAMES, pos );

  if (!g_dontset)
  {
    g_run = 1;
    g_dontset = 0;
  }

}

int main(int argc, char **argv)
{

  char check_for_esc_key = 0;
  cv::VideoCapture my_video;

  std::string windowName = "Exmaple 2";
  std::string trackbarName = "Trackbar";
  my_video.open("video.mp4");

  int total_frames = static_cast<int>(my_video.get( cv::CAP_PROP_FRAME_COUNT ));
  int width        = static_cast<int>(my_video.get( cv::CAP_PROP_FRAME_WIDTH ));
  int height       = static_cast<int>(my_video.get( cv::CAP_PROP_FRAME_HEIGHT ));

  std::cout << "Video contains " << total_frames << " frames with dimensions: " <<
    "[" << width << "x" << height << "]" << std::endl;

  namedWindow(windowName, cv::WINDOW_NORMAL);
  cv::createTrackbar(trackbarName, windowName, &g_slider_position, total_frames, onTrackBarSlide);

  cv::Mat curr_frame;

  while (check_for_esc_key != ESC_ASCII)
  {
   
    my_video >> curr_frame;
    if (curr_frame.empty()) break;

    int active_frame = static_cast<int>(my_video.get(cv::CAP_PROP_POS_FRAMES));
    std::cout << "Current frame: " << active_frame << std::endl;

    // update the trackbar
    cv::setTrackbarPos(trackbarName, windowName, active_frame);
    cv::imshow(windowName, curr_frame);

    check_for_esc_key = cv::waitKey(1);
    
  }

  cv::destroyWindow( windowName );
  
  return 0;

}