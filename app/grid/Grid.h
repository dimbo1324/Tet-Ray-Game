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

    bool IsCellOutside(int r, int c) const;

    bool IsCellEmpty(int r, int c);
    int ClearFullRows();

    int grid[20][10];

private:
    bool IsRowFull(int r);

    void ClearRow(int r);

    void MoveRowDown(int r, int numRows);

    int numRows, numCols, cellSize;
    std::vector<Color> colors;
};
