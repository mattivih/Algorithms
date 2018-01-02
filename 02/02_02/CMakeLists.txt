cmake_minimum_required(VERSION 3.8)
project(02_02)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp MY_BOT.h bot_interface.h)
add_executable(02_02 ${SOURCE_FILES})