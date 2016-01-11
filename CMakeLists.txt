cmake_minimum_required(VERSION 3.3)
set(CMAKE_CXX_COMPILER "/usr/bin/g++-4.2")
project(assigment3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})

find_package(Boost 1.57.0)

if(NOT Boost_FOUND)
    message(FATAL_ERROR "Could not find boost!")
endif()

INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR})


set(SOURCE_FILES client/connectionHandler.cpp protocol/msgParser.cpp client/listeners.cpp client/clientMain.cpp )
add_executable(client ${SOURCE_FILES})