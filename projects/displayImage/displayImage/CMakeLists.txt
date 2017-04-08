cmake_minimum_required(VERSION 2.8)
set("OpenCV_DIR" "C:/OpenCV-3.2/opencv/build")

project( displayImage )
find_package( OpenCV REQUIRED )

add_executable( displayImage.exe displayImage.cpp )
target_link_libraries( displayImage ${OpenCV_LIBS} )