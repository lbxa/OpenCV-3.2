cmake_minimum_required(VERSION 2.8)

project( DisplayImage1 )
find_package( OpenCV REQUIRED )

add_executable( DisplayImage1 displayImage1.cpp )
target_link_libraries( DisplayImage1 ${OpenCV_LIBS} )