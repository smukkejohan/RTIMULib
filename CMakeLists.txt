#////////////////////////////////////////////////////////////////////////////
#//
#//  This file is part of RTIMULib
#//
#//  Copyright (c) 2014, richards-tech
#//
#//  Permission is hereby granted, free of charge, to any person obtaining a copy of
#//  this software and associated documentation files (the "Software"), to deal in
#//  the Software without restriction, including without limitation the rights to use,
#//  copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the
#//  Software, and to permit persons to whom the Software is furnished to do so,
#//  subject to the following conditions:
#//
#//  The above copyright notice and this permission notice shall be included in all
#//  copies or substantial portions of the Software.
#//
#//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
#//  INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
#//  PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
#//  HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
#//  OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
#//  SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#// The cmake support was based on work by Moritz Fischer at ettus.com.
#// Original copyright notice:
#
# Copyright 2014 Ettus Research LLC
#

########################################################################
IF(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
    MESSAGE(FATAL_ERROR "Prevented in-tree built. This is bad practice.")
ENDIF(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})

########################################################################
# Project setup
########################################################################
CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
PROJECT(RTIMULib CXX)
ENABLE_TESTING()

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/RTIMULib)
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/RTArduLinkHost)
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/RTHostIMUCommon)
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/RTSerialPort/src)

ADD_SUBDIRECTORY(RTIMULib)
ADD_SUBDIRECTORY(RTIMULibDrive)
ADD_SUBDIRECTORY(RTIMULibCal)
ADD_SUBDIRECTORY(RTIMULibDemo)
ADD_SUBDIRECTORY(RTSerialPort)
ADD_SUBDIRECTORY(RTArduLinkHost)
ADD_SUBDIRECTORY(RTHostIMUCommon)
ADD_SUBDIRECTORY(RTHostIMU)
ADD_SUBDIRECTORY(RTHostIMUGL)

MESSAGE(STATUS "Using install prefix: ${CMAKE_INSTALL_PREFIX}")
