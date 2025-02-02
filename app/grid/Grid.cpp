#include <iostream>
#include "Grid.h"
#include "../colors/Colors.h"

Grid::Grid()
{
    numRows = 20;
    numCols = 10;
    cellSize = 30;
    Initialize();
    colors = GetCellColors();
}

void Grid::Initialize()
{
    for (int r = 0; r < numRows; r++)
    {
        for (int c = 0; c < numCols; c++)
        {
            grid[r][c] = 0;
        }
    }
}

void Grid::PrintGrid()
{
    for (int r = 0; r < numRows; r++)
    {
        for (int c = 0; c < numCols; c++)
        {
            std::cout << grid[r][c] << " ";
        }
        std::cout << std::endl;
    }
}

void Grid::DrawGrid()
{
    for (int r = 0; r < numRows; r++)
    {
        for (int c = 0; c < numCols; c++)
        {
            int cellValue = grid[r][c];
            DrawRectangle(c * cellSize + 1, r * cellSize + 1, cellSize - 1,
                          cellSize - 1,
                          colors[cellValue]);
        }
    }
}

bool Grid::IsCellOutside(int r, int c) const
{
    if (r >= 0 && r < numRows && c >= 0 && c < numCols)
        return false;
    return true;
}

bool Grid::IsCellEmpty(int r, int c)
{
    if (grid[r][c] == 0)
        return true;
    return false;
}

int Grid::ClearFullRows()
{
    int completed = 0;
    for (int r = numRows - 1; r >= 0; r--)
    {
        if (IsRowFull(r))
        {
            ClearRow(r);
            completed++;
        }
        else if (completed > 0)
        {
            MoveRowDown(r, completed);
        }
    }
    return completed;
}

bool Grid::IsRowFull(int r)
{
    for (int c = 0; c < numCols; c++)
    {
        if (grid[r][c] == 0)
            return false;
    }
    return true;
}

void Grid::ClearRow(int r)
{
    for (int c = 0; c < numCols; c++)
    {
        grid[r][c] = 0;
    }
}

void Grid::MoveRowDown(int r, int numRows)
{
    for (int c = 0; c < numCols; c++)
    {
        grid[r + numRows][c] = grid[r][c];
        grid[r][c] = 0;
    }
}
