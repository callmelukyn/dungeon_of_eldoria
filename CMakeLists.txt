cmake_minimum_required(VERSION 3.29)
project(zoo_project)

set(CMAKE_CXX_STANDARD 20)

add_executable(zoo_project src/main.cpp
        src/domain/entities/player.cpp
        src/domain/entities/player.h
        src/map/map.cpp
        src/map/map.h
        src/map/tile.cpp
        src/map/tile.h
        src/domain/value_objects/potion.h
        src/Menu.cpp
        src/Menu.h
        src/application.cpp
        src/application.h
        src/domain/value_objects/role.h
        src/domain/entities/position.h
)
