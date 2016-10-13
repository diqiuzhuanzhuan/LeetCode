cmake_minimum_required(VERSION 3.6)
project(LeetCode)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp AddTwoNumbers.cpp MissingNumber.cpp DeleteNodeInALinkedList.cpp ContainsDuplicateIII.cpp "KthSmallestElementInABST.cpp")
add_executable(LeetCode ${SOURCE_FILES})