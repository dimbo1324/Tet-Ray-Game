#pragma once
#include <vector>
#include <raylib.h>
#include "../utils/types/Types.h"


class Grid
    {
    public:
        Grid();

        void Initialize();

        void PrintGrid();

        void DrawGrid();


        uint grid[20][10];

    private:
        uint numRows, numCols, cellSize;
        std::vector<Color> colors;
    };
