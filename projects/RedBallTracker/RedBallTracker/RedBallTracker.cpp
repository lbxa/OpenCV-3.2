// RedBallTracker.cpp | Lucas Barbosa (C)

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <iostream>

#define ESC_ASCII 27

using namespace cv;
using namespace std;

//////////////////////////////////////////////////////////////////////////////

int main() {
    cv::VideoCapture capWebcam(0);
    // declare a VideoCapture object and associate to webcam, 0 => use 1st webcam

    // check if VideoCapture object was associated to webcam successfully
    if (capWebcam.isOpened() == false) {        
        // if not, print error message to std out
        std::cout << "error: capWebcam not accessed successfully\n\n"; 
        // and exit program
        return 0;
    }

    cv::Mat imgOriginal;    // input image
    cv::Mat imgHSV;
    cv::Mat imgThreshLow;
    cv::Mat imgThreshHigh;
    cv::Mat imgThresh;

    // 3 element vector of floats, this will be the pass by reference output of 
    // HoughCircles()
    std::vector<cv::Vec3f> v3fCircles;    
    char charCheckForEscKey = 0;
    
    // until the Esc key is pressed or webcam connection is lost
    while (charCheckForEscKey != ESC_ASCII && capWebcam.isOpened()) {
        // get next frame
        bool blnFrameReadSuccessfully = capWebcam.read(imgOriginal);
            // if frame not read successfully
            if (!blnFrameReadSuccessfully || imgOriginal.empty()) {              
                // print error message to std out
                std::cout << "error: frame not read from webcam\n"; 
                // and jump out of while loop
                break;    
            }

        cv::cvtColor(imgOriginal, imgHSV, CV_BGR2HSV);
        cv::inRange(imgHSV, cv::Scalar(0, 155, 155),
        cv::Scalar(18, 255, 255), imgThreshLow);
        cv::inRange(imgHSV, cv::Scalar(165, 155, 155), 
        cv::Scalar(179, 255, 255), imgThreshHigh);
        cv::add(imgThreshLow, imgThreshHigh, imgThresh);
        cv::GaussianBlur(imgThresh, imgThresh, cv::Size(3, 3), 0);
        cv::Mat structuringElement = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3));
        cv::dilate(imgThresh, imgThresh, structuringElement);
        cv::erode(imgThresh, imgThresh, structuringElement);

        // fill circles vector with all circles in processed image
        cv::HoughCircles(imgThresh,             // input image
                         // function output (must be a standard template library vector
                         v3fCircles,
                         // two-pass algorithm for detecting circles, this is the only choice available
                         CV_HOUGH_GRADIENT,
                         // size of image / this value = "accumulator resolution", 
                         // i.e. accum res = size of image / 2
                         2, 
                         // min distance in pixels between the centers of the detected circles
                         imgThresh.rows / 4,
                         // high threshold of Canny edge detector (called by cvHoughCircles)	
                         100,
                         // low threshold of Canny edge detector (set at 1/2 previous value)
                         50, 
                         // min circle radius (any circles with smaller radius will not be returned)
                         50,
                         // max circle radius (any circles with larger radius will not be returned)
                         200);

        for (int i = 0; i < v3fCircles.size(); i++) {   // for each circle . . .
            // x position of center point of circle
            std::cout << "ball position x = " << v3fCircles[i][0] 
            // y position of center point of circle
            << ", y = " << v3fCircles[i][1] 
            // radius of circle
            << ", radius = " << v3fCircles[i][2] << "\n";
                                                                                                                            // draw small green circle at center of detected object
            cv::circle(imgOriginal, 
            // draw on original image
            cv::Point((int)v3fCircles[i][0], (int)v3fCircles[i][1]),    // center point of circle
                      3,  // radius of circle in pixels
                      cv::Scalar(0, 255, 0),            // draw pure green (remember, its BGR, not RGB)
                      CV_FILLED);                       // thickness, fill in the circle
                      cv::circle(imgOriginal,           // draw on original image
                      // center point of circle
                      cv::Point((int)v3fCircles[i][0], (int)v3fCircles[i][1]),
                                (int)v3fCircles[i][2],  // radius of circle in pixels
                                cv::Scalar(255, 0, 0),  // draw pure red (remember, its BGR, not RGB)
                                2);                     // thickness of circle in pixels
        }   // end for

        // note: you <can use CV_WINDOW_NORMAL which allows resizing the window
        cv::namedWindow("imgOriginal", CV_WINDOW_NORMAL);
        cv::namedWindow("imgThresh", CV_WINDOW_NORMAL);
        // or CV_WINDOW_AUTOSIZE for a fixed size window matching the resolution of the image
        // CV_WINDOW_AUTOSIZE is the default

        cv::imshow("imgOriginal", imgOriginal); // show windows
        cv::imshow("imgThresh", imgThresh);

        // delay (in ms) and get key press, if any
        charCheckForEscKey = cv::waitKey(1);
    } // end while

    return(0);
}
