cmake_minimum_required(VERSION 3.16)
project(AKNN)

set(CMAKE_CXX_STANDARD 14)

add_executable(AKNN main.cpp include/load.h source/load.cpp include/AKNN.h source/AKNN.cpp include/config.h include/mem_check.h source/AKNN_with_mmap.cpp include/AKNN_with_mmap.h)