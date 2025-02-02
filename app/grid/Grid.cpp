#include <iostream>
#include "Grid.h"
#include "../colors/Colors.h"
#include "../utils/types/Types.h"

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
        for (uint r = 0; r < numRows; r++)
            {
                for (uint c = 0; c < numCols; c++)
                    {
                        grid[r][c] = 0;
                    }
            }
    }

void Grid::PrintGrid()
    {
        for (uint r = 0; r < numRows; r++)
            {
                for (uint c = 0; c < numCols; c++)
                    {
                        std::cout << grid[r][c] << " ";
                    }
                std::cout << std::endl;
            }
    }


void Grid::DrawGrid()
    {
        for (uint r = 0; r < numRows; r++)
            {
                for (uint c = 0; c < numCols; c++)
                    {
                        uint cellValue = grid[r][c];
                        DrawRectangle(c * cellSize + 1, r * cellSize + 1, cellSize - 1,
                                      cellSize - 1,
                                      colors[cellValue]);
                    }
            }
    }


bool Grid::IsCellOutside(int r, int c) const
    {
        if (r >= 0 && r < numRows && c >= 0 && c < numCols) return false;
        return true;
    }
