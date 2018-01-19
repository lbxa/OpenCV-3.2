<<<<<<< HEAD
# Install script for directory: /Users/lucasbarbosa/Documents/MainDrive/Programming/OpenCV/projects/cameraProcessor/cameraProcessor
=======
# Install script for directory: /home/lucas/Documents/MainDrive/Programming/OpenCV-3.2/projects/cameraProcessor/cameraProcessor
>>>>>>> 95362959d291264918c3365cd0f5afb6bb3c5c0b

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

<<<<<<< HEAD
# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
=======
# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "0")
>>>>>>> 95362959d291264918c3365cd0f5afb6bb3c5c0b
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
<<<<<<< HEAD
file(WRITE "/Users/lucasbarbosa/Documents/MainDrive/Programming/OpenCV/projects/cameraProcessor/cameraProcessor/${CMAKE_INSTALL_MANIFEST}"
=======
file(WRITE "/home/lucas/Documents/MainDrive/Programming/OpenCV-3.2/projects/cameraProcessor/cameraProcessor/${CMAKE_INSTALL_MANIFEST}"
>>>>>>> 95362959d291264918c3365cd0f5afb6bb3c5c0b
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
