cmake_minimum_required(VERSION 3.0)

set(CMAKE_BUILD_TYPE debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

project(MiniMaxAIWithTicTacToe)

add_executable(
TicTacToe

GameStart.cpp
MoveCoords.cpp
TicTacToe.cpp
)