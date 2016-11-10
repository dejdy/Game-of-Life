cmake_minimum_required(VERSION 3.6)
project(Game_of_Life)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Board.cpp Board.h Cell.cpp Cell.h Game.cpp Game.h)
add_executable(Game_of_Life ${SOURCE_FILES})