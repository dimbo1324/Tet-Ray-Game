#pragma once
#include <vector>
#include <raylib.h>


class Grid
    {
    public:
        Grid();

        void Initialize();

        void PrintGrid();

        void DrawGrid();

        int grid[20][10];

    private:
        unsigned int numRows, numCols, cellSize;
        std::vector<Color> colors;
    };
