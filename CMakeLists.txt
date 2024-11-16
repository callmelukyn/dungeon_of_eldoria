cmake_minimum_required(VERSION 3.29)
project(zoo_project)

set(CMAKE_CXX_STANDARD 20)

add_executable(zoo_project src/main.cpp
        src/domain/entities/player.cpp
        src/domain/entities/player.h
        src/map/map.cpp
        src/map/map.h
        src/domain/value_objects/potion.cpp
        src/domain/value_objects/potion.h)
