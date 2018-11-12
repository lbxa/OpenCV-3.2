/*
 *  Canny Edges
 *  -----------------------
 *
 *  Experimenting with the canny edges functionality of OpenCV
 *  making sure to understand all the arguments which are passed
 *  into the fuctions and how to incorportate a 'scroll bar' too.
 *
 *  Lucas Barbosa | 12.06/2018 | Open Source Software (C)
 */

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/imgcodecs/imgcodecs.hpp>
#include <opencv2/core/utility.hpp>

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;
using namespace cv;

#define ESC_ASCII 27 
#define DEFAULT_CAMERA 0

int edgeThresh = 1;
int edgeThreshScharr=1;
Mat image, gray, blurImage, edge1, edge2, cedge;
const char* window_name1 = "Edge map : Canny default (Sobel gradient)";
const char* window_name2 = "Edge map : Canny with custom gradient (Scharr)";

// define a trackbar callback
static void onTrackbar(int, void*) {
    blur(gray, blurImage, Size(3,3));
    // Run the edge detector on grayscale
    Canny(blurImage, edge1, edgeThresh, edgeThresh*3, 3);
    cedge = Scalar::all(0);
    image.copyTo(cedge, edge1);
    imshow(window_name1, cedge);
    Mat dx,dy;
    Scharr(blurImage,dx,CV_16S,1,0);
    Scharr(blurImage,dy,CV_16S,0,1);
    Canny( dx,dy, edge2, edgeThreshScharr, edgeThreshScharr*3 );
    cedge = Scalar::all(0);
    image.copyTo(cedge, edge2);
    imshow(window_name2, cedge);
}

static void help() {
    printf("\nThis sample demonstrates Canny edge detection\n"
           "Call:\n"
           "    /.edge [image_name -- Default is ../data/fruits.jpg]\n\n");
}

const char* keys = {
    "{help h||}{@image |../data/fruits.jpg|input image name}"
};

int main( int argc, const char** argv ) {
    CommandLineParser parser(argc, argv, keys);
    if (parser.has("help")) {
        help();
        return 0;
    }

    string filename = parser.get<string>(0);
    image = imread(filename, 1);
    if(image.empty()) {
        printf("Cannot read image file: %s\n", filename.c_str());
        help();
        return -1;
    }

    cedge.create(image.size(), image.type());
    cvtColor(image, gray, COLOR_BGR2GRAY);
    // Create a window
    namedWindow(window_name1, cv::WINDOW_AUTOSIZE);
    namedWindow(window_name2, cv::WINDOW_AUTOSIZE);
    // create a toolbar
    createTrackbar("Canny threshold default", window_name1, &edgeThresh, 100, onTrackbar);
    createTrackbar("Canny threshold Scharr", window_name2, &edgeThreshScharr, 400, onTrackbar);
    // Show the image
    onTrackbar(0, 0);
    // Wait for a key stroke; the same function arranges events processing
    waitKey(0);
    return 0;

}
