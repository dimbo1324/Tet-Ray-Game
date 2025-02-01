cmake_minimum_required(VERSION 3.30)
project(Tetris)

set(CMAKE_CXX_STANDARD 17)


set(RAYLIB_INCLUDE_DIR "P:/1.From Git/_LIBS/raylib-master/build/raylib/include")
set(RAYLIB_LIB_DIR "P:/1.From Git/_LIBS/raylib-master/build/raylib")

include_directories(${RAYLIB_INCLUDE_DIR})
link_directories(${RAYLIB_LIB_DIR})


add_executable(Tetris app/main.cpp
        app/grid/grid.cpp
        app/grid/grid.h
        app/blocks/Block.h
        app/positions/Position.cpp
        app/positions/Position.h
        app/colors/Colors.cpp
        app/colors/Colors.h
        app/blocks/Block.cpp
        app/blocks/TypesOfBlocks/cpp/L_Block.cpp
        app/blocks/TypesOfBlocks/cpp/J_Block.cpp
        app/blocks/TypesOfBlocks/cpp/I_Block.cpp
        app/blocks/TypesOfBlocks/cpp/O_Block.cpp
        app/blocks/TypesOfBlocks/cpp/S_Block.cpp
        app/blocks/TypesOfBlocks/cpp/T_Block.cpp
        app/blocks/TypesOfBlocks/cpp/Z_Block.cpp

)


target_link_libraries(Tetris ${RAYLIB_LIB_DIR}/libraylib.a -lopengl32 -lgdi32 -lwinmm)
