#include <iostream>
#include <raylib.h>
#include "grid/Grid.h"
#include "blocks/TypesOfBlocks/cpp/L_Block.cpp"
#include "blocks/TypesOfBlocks/cpp/J_Block.cpp"
#include "blocks/TypesOfBlocks/cpp/I_Block.cpp"
#include "blocks/TypesOfBlocks/cpp/O_Block.cpp"
#include "blocks/TypesOfBlocks/cpp/S_Block.cpp"
#include "blocks/TypesOfBlocks/cpp/T_Block.cpp"
#include "blocks/TypesOfBlocks/cpp/Z_Block.cpp"
#include "utils/types/Types.h"


int main()
    {
        // int a = 0;
        // std::cout << a << std::endl;

        Color backgroundColor = {10, 120, 156, 124};
        sint rectangleSide = 300;
        InitWindow(rectangleSide, rectangleSide * 2, "Tetris by C++");
        SetTargetFPS(60);
        Grid grid = Grid();
        grid.PrintGrid();

        L_Block block_L = L_Block();
        J_Block block_J = J_Block();
        I_Block block_I = I_Block();
        O_Block block_O = O_Block();
        S_Block block_S = S_Block();
        T_Block block_T = T_Block();
        Z_Block block_Z = Z_Block();


        while (WindowShouldClose() == false)
            {
                BeginDrawing();
                ClearBackground(backgroundColor);
                grid.DrawGrid();
                block_Z.DrawBlock();

                EndDrawing();
            }
        CloseWindow();
    }
