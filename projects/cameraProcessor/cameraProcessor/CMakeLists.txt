cmake_minimum_required(VERSION 2.8)

project( CameraProcessor )
find_package( OpenCV REQUIRED )

add_executable( CameraProcessor cameraProcessor.cpp )
target_link_libraries( CameraProcessor ${OpenCV_LIBS} )
