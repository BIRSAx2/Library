cmake_minimum_required(VERSION 3.10)
project(Library)

set(CMAKE_CXX_STANDARD 11)

include_directories(include src)

add_library(ISBN STATIC src/ISBN.cpp include/ISBN.h)
add_library(Date STATIC src/Date.cpp include/Date.h)
add_library(Book STATIC src/Book.cpp include/Book.h)
add_library(Utility STATIC src/Utility.cpp include/Utility.h)

add_executable(${PROJECT_NAME} src/main.cpp)

target_link_libraries(${PROJECT_NAME} ISBN Date Book Utility)

