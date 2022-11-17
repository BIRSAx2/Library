cmake_minimum_required(VERSION 3.10)
project(Library)

set(CMAKE_CXX_STANDARD 17)
include_directories(include)
add_executable(Library src/main.cpp include/ISBN.h include/Date.h include/Book.h src/Date.cpp src/Book.cpp src/ISBN.cpp src/Utility.cpp include/Utility.h)
