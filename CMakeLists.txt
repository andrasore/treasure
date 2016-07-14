cmake_minimum_required(VERSION 2.6)
project(treasure)

add_definitions(-std=c++14)

set(CMAKE_BUILD_TYPE Debug)

set (GAME_SOURCES GameClass.cpp GameObject.cpp Level.cpp GameClassInstances.cpp GameController.cpp GameCommands.cpp LevelCreator.cpp Console.cpp)

add_executable(treasure main.cpp ${GAME_SOURCES})
