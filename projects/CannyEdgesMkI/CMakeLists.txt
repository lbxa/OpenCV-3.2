cmake_minimum_required(VERSION 2.8)
project(CannyEdgesMkI)
find_package(OpenCV REQUIRED)
add_executable(CannyEdgesMkI main.cpp)
target_link_libraries(CannyEdgesMkI ${OpenCV_LIBS})

