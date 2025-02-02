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

        bool IsCellOutside(int r, int c) const;

        bool IsCellEmpty(int r, int c);
        int ClearFullRows();

        uint grid[20][10];

    private:
        bool IsRowFull(uint r);

        void ClearRow(uint r);

        void MoveRowDown(uint r, int numRows);

        uint numRows, numCols, cellSize;
        std::vector<Color> colors;
    };
