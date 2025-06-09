cmake_minimum_required(VERSION 3.22)
project(Inheritance)

set(CMAKE_CXX_STANDARD 14)

add_executable(Inheritance main.cpp Figure.cpp Figure.h Rectangle.cpp Rectangle.h Square.cpp Square.h)
