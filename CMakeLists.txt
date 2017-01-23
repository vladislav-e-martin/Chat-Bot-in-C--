cmake_minimum_required(VERSION 3.6)
project(Weekend_Marathon__1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Lexeme.cpp Lexeme.h Bot.cpp Bot.h ResponseHandler.cpp ResponseHandler.h)
add_executable(Weekend_Marathon__1 ${SOURCE_FILES})