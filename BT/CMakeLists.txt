cmake_minimum_required(VERSION 3.23)
project(BT)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(BT
        BST.h
        main.cpp
        TreeNode.h)
