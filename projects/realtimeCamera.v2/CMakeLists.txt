cmake_minimum_required( VERSION 2.8 )
project( RealtimeCamera_v2 )
find_package( OpenCV REQUIRED )
add_executable ( RealtimeCamera_v2 realtimeCamera.v2.cpp )
target_link_libraries( RealtimeCamera_v2 ${OpenCV_LIBS} )

