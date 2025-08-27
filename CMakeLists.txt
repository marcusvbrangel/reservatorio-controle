cmake_minimum_required(VERSION 3.10)
project(reservatorio_01)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)

add_executable(reservatorio_01 main.cpp)

find_package(Qt5 COMPONENTS Widgets Charts Svg REQUIRED)
target_link_libraries(reservatorio_01 Qt5::Widgets Qt5::Charts Qt5::Svg)