cmake_minimum_required(VERSION 3.12)
project(mazesolver)

## If you want to link SFML statically
# set(SFML_STATIC_LIBRARIES TRUE)

## In most cases better set in the CMake cache
# set(SFML_DIR "<sfml root prefix>/lib/cmake/SFML")

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)
add_executable(mazesolver main.cpp src/Maze.cpp include/Maze.h src/Grid.cpp include/Grid.h src/Tile.cpp include/Tile.h src/Text.cpp include/Text.h include/Scores.h src/Scores.cpp src/Bonus.cpp include/Bonus.h src/BonusLeft.cpp include/BonusLeft.h src/BonusRight.cpp include/BonusRight.h src/BonusUp.cpp include/BonusUp.h src/BonusDown.cpp include/BonusDown.h src/BonusBomb.cpp include/BonusBomb.h include/Bonuses.h)
target_link_libraries(mazesolver sfml-graphics sfml-window sfml-system)