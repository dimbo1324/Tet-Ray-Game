#include "Grid.h"
#include "../colors/Colors.h"
#include <iostream>
#include <algorithm>
#include "../game property/constants.h"

Grid::Grid()
    : numRows(numRowsValue),
      numCols(numColsValue),
      cellSize(cellSizeValue)
    {
        grid.resize(numRows, std::vector<int>(numCols, 0));
        initialize();
        colors = GetCellColors();
    }

void Grid::initialize()
    {
        for (auto &row: grid)
            {
                std::fill(row.begin(), row.end(), 0);
            }
    }

void Grid::printGrid() const
    {
        for (const auto &row: grid)
            {
                for (const auto cell: row)
                    {
                        std::cout << cell << " ";
                    }
                std::cout << std::endl;
            }
    }

void Grid::drawGrid() const
    {
        for (int row = 0; row < numRows; ++row)
            {
                for (int col = 0; col < numCols; ++col)
                    {
                        int cellValue = grid[row][col];
                        DrawRectangle(col * cellSize + extraPixelsPositionValue,
                                      row * cellSize + extraPixelsPositionValue, cellSize - 1,
                                      cellSize - 1, colors[cellValue]);
                    }
            }
    }

bool Grid::isCellOutside(int row, int col) const
    {
        return (row < 0 || row >= numRows || col < 0 || col >= numCols);
    }

bool Grid::isCellEmpty(int row, int col) const
    {
        if (isCellOutside(row, col))
            {
                return false;
            }
        return (grid[row][col] == 0);
    }

int Grid::clearFullRows()
    {
        int clearedRows = 0;
        for (int row = numRows - 1; row >= 0; --row)
            {
                if (isRowFull(row))
                    {
                        clearRow(row);
                        ++clearedRows;
                    } else if (clearedRows > 0)
                    {
                        moveRowDown(row, clearedRows);
                    }
            }
        return clearedRows;
    }

bool Grid::isRowFull(int row) const
    {
        for (int col = 0; col < numCols; ++col)
            {
                if (grid[row][col] == 0)
                    {
                        return false;
                    }
            }
        return true;
    }

void Grid::clearRow(int row)
    {
        for (int col = 0; col < numCols; ++col)
            {
                grid[row][col] = 0;
            }
    }

void Grid::moveRowDown(int row, int numRowsToMove)
    {
        int targetRow = row + numRowsToMove;
        if (targetRow < numRows)
            {
                grid[targetRow] = grid[row];
                clearRow(row);
            }
    }

void Grid::setCell(int row, int col, int value)
    {
        if (!isCellOutside(row, col))
            {
                grid[row][col] = value;
            }
    }
