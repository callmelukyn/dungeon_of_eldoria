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
        src/map/position.h
        src/domain/value_objects/potion.h
        src/ui/menu.cpp
        src/ui/menu.h
        src/application.cpp
        src/application.h
        src/domain/value_objects/role.h
        src/game.cpp
        src/game.h
        src/domain/value_objects/Screen.h
        src/domain/value_objects/doorPosition.h
        src/ui/scenes.cpp
        src/ui/scenes.h
        src/tools/GlobalSettings.cpp
        src/tools/GlobalSettings.h
)
