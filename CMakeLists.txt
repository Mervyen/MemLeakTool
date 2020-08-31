cmake_minimum_required(VERSION 3.17)
project(Memleak)

set(CMAKE_CXX_STANDARD 11)

add_executable(MemLeak main.cpp MemRecord.cpp MemRecordMap.cpp)
#add_executable(MemLeak main.cpp)