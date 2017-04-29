cmake_minimum_required( VERSION 2.8 )
project( CannyWebcam )
find_package( OpenCV REQUIRED )
add_executable( CannyWebcam CannyWebcam.cpp )
target_link_libraries( CannyWebcam ${OpenCV_LIBS} )

