/*
 *  Writting to an AVI file
 *
 *  Recording video, then writting to a classic AVI (Audio, Video, Interleave)
 *  file, testing OpenCV's video recording capabilities with non comproessing
 *  AVI codecs in log polar format.
 * 
 *  30.04.2017 | Lucas Barbosa | Open source software
 */

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <iostream>
#include <vector>

using namespace std;
using namespace cv;

#define ESC_ASCII 27
#define MAX_POLAR_SCALE 40

int main(int argc, char **argv) {

  std::string window1_name = "Original Example";
  std::string window2_name = "Log Polar";

  cv::namedWindow(window1_name, cv::WINDOW_AUTOSIZE);
  cv::namedWindow(window2_name, cv::WINDOW_AUTOSIZE);

  cv::VideoCapture cam_cap(1);

  if (! cam_cap.isOpened()) {
    std::cout << "Camera not feeding input." << std::endl;
    return -1;
  }

  /// retrieve the frame per second of the video
  double FPS = cam_cap.get( cv::CAP_PROP_FPS );
  auto input_codec = cam_cap.get( cv::CAP_PROP_FOURCC );
  cv::Size size(static_cast<int>( cam_cap.get( cv::CAP_PROP_FRAME_WIDTH ) ),
		static_cast<int>( cam_cap.get( cv::CAP_PROP_FRAME_HEIGHT )));

  /**
   *  @VideoWriter data type
   *
   *
   *
   */

  cv::VideoWriter video_writer( argv[1], CV_FOURCC('P','I','M','1'),
				FPS, size );

  cv::Mat logpolar_frame, BGR_frame;
  char check_for_esc_key;

  while (check_for_esc_key != ESC_ASCII) {

    cam_cap >> BGR_frame;
    
    if (BGR_frame.empty()) {
      std::cout << "AVI frame was empty." << std::endl;
      return -1;
    }

    cv::imshow(window1_name, BGR_frame);

    cv::logPolar(BGR_frame,
		 logpolar_frame,
		 cv::Point2f(BGR_frame.cols / 2,  // x
			     BGR_frame.rows / 2), // y
		 MAX_POLAR_SCALE, // Magnitude (scale parameter) 
		 cv::WARP_FILL_OUTLIERS); // fill outliers with 0

    cv::imshow(window2_name, logpolar_frame);

    video_writer << logpolar_frame;
    
    check_for_esc_key = cv::waitKey(30);
    
  }

  cam_cap.release();

  cv::destroyAllWindows();

  return 0;
  
}
