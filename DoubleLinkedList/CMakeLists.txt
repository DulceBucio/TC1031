cmake_minimum_required(VERSION 3.23)
project(DoubleLinkedList)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(DoubleLinkedList
        main.cpp
        Node.h
        DoubleLinkList.h)
