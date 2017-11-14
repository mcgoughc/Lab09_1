cmake_minimum_required(VERSION 3.8)
project(Lab09_1)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES Lab9Tester.cpp ListTests.cpp ArrayLib.cpp ArrayList.cpp IntLinkedList.cpp LinkedNode.cpp)
add_executable(Lab09_1 ${SOURCE_FILES})