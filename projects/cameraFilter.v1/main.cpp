/*
**  Camera Filter: Mark I
**
**
**
**
**
**
**
**
**
**
**
*/

#include <iostream>
#include <list>
#include <vector>
#include <string>

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;

#define ESC_ASCII 27
#define DEFAULT_WEBCAM 0
#define DEFAULT_WAIT_PERIOD 1

int main(int argc, char **argv) {
    
    cv::VideoCapture webcam(DEFAULT_WEBCAM);

    if (webcam.isOpened() == false) {
        std::cout << "ERROR: Webcam was not connected properly." << std::endl;
        return -1;
    }
    std::string mainWindowName = "Say Hello!";
    cv::namedWindow(mainWindowName, cv::WINDOW_NORMAL);
    char escFlag = 0;

    while (escFlag != ESC_ASCII) {
        cv::Mat img_frame;
        webcam >> img_frame;
        if (img_frame.empty()) break;

        cv::imshow(mainWindowName, img_frame);
        // wait for the esc key to be pressed
        escFlag = cv::waitKey(DEFAULT_WAIT_PERIOD);
    }

    cv::destroyWindow(mainWindowName);
    
    return 0;

}
