cmake_minimum_required(VERSION 3.8)
project(astar_ver2)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        astar/graph.h
        astar/node.h
        astar/nodelist.h
        astar/test_astar.cpp)

add_executable(astar_ver2 ${SOURCE_FILES})