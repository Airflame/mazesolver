cmake_minimum_required(VERSION 3.12)
project(mazesolver)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp)
add_executable(mazesolver main.cpp src/Maze.cpp include/Maze.h src/Grid.cpp include/Grid.h src/Tile.cpp include/Tile.h src/Text.cpp include/Text.h include/Scores.h src/Scores.cpp)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(mazesolver ${SFML_LIBRARIES})
endif()