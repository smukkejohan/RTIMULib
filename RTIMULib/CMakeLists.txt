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

SET(LIBRTIMU_SRCS
    ${CMAKE_CURRENT_SOURCE_DIR}/RTFusion.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/RTFusionRTQF.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/RTIMUGD20M303DLHC.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/RTIMU.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/RTIMULSM9DS0.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/RTIMUMPU9150.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/RTIMUNull.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/RTMath.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/RTFusionKalman4.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/RTIMUAccelCal.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/RTIMUGD20HM303D.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/RTIMUHal.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/RTIMUMagCal.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/RTIMUMPU9250.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/RTIMUSettings.cpp)

IF(WIN32 AND QT5)
    FIND_PACKAGE(Qt5Widgets)
    FIND_PACKAGE(Qt5Gui)
    qt5_wrap_ui(UI_HEADERS RTIMULibDemo.ui)
    ADD_LIBRARY(RTIMULib STATIC ${LIBRTIMU_SRCS})
    qt5_use_modules(RTIMULib Widgets Gui)
ENDIF(WIN32 AND QT5)

IF(WIN32 AND (NOT QT5))
    FIND_PACKAGE(Qt4 REQUIRED)
    INCLUDE(${QT_USE_FILE})
    ADD_DEFINITIONS(${QT_DEFINITIONS})
    ADD_LIBRARY(RTIMULib STATIC ${LIBRTIMU_SRCS})
    TARGET_LINK_LIBRARIES(RTIMULib ${QT_LIBRARIES})
ENDIF(WIN32 AND (NOT QT5))

IF(UNIX)
    ADD_LIBRARY(RTIMULib SHARED ${LIBRTIMU_SRCS})
    INSTALL(TARGETS RTIMULib DESTINATION lib)
ENDIF(UNIX)

