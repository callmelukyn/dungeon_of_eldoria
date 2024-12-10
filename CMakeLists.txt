cmake_minimum_required(VERSION 3.29)
project(zoo_project)

set(CMAKE_CXX_STANDARD 20)

add_executable(zoo_project src/main.cpp
        src/domain/entities/player.cpp
        src/domain/entities/player.h
        src/map/map.cpp
        src/map/map.h
        src/map/levels.cpp
        src/map/levels.h
        src/domain/value_objects/potion.h
        src/UI/menu.cpp
        src/UI/menu.h
        src/application.cpp
        src/application.h
        src/domain/value_objects/role.h
        src/domain/entities/position.h
        src/game.cpp
        src/game.h
        src/domain/value_objects/Screen.h
        src/domain/value_objects/doorPosition.h
        src/UI/Scenes.cpp
        src/UI/Scenes.h
        src/Tools/GlobalSettings.cpp
        src/Tools/GlobalSettings.h
)
