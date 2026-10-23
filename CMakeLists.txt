cmake_minimum_required(VERSION 3.10)
project(test_2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(test_2 src/main.cpp)

target_link_libraries(test_2 ${OpenCV_LIBS})