set(CMAKE_CXX_STANDARD 14)

set(LIB_SRC Action.cpp Puzzle.cpp Board.cpp AStar.cpp TilesSolver.cpp)

add_library(astar_lib SHARED ${LIB_SRC})