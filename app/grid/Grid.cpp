#include "Grid.h"
#include "../game/constants.h"
#include "../colors/Colors.h"
#include <algorithm>

namespace tetris
    {
        Grid::Grid()
            : numRows(kNumRows),
              numCols(kNumCols),
              cellSize(kCellSize),
              grid(numRows, std::vector<int>(numCols, 0)),
              colors(GetCellColors())
            {
                initialize();
            }

        void Grid::initialize()
            {
                for (auto &row: grid)
                    {
                        std::fill(row.begin(), row.end(), 0);
                    }
            }

        void Grid::drawGrid() const
            {
                for (int row = 0; row < numRows; ++row)
                    {
                        for (int col = 0; col < numCols; ++col)
                            {
                                int cellValue = grid[row][col];
                                DrawRectangle(col * cellSize + kExtraPixels,
                                              row * cellSize + kExtraPixels,
                                              cellSize - 1,
                                              cellSize - 1,
                                              colors[cellValue]);
                            }
                    }
            }

        bool Grid::isCellOutside(int row, int col) const
            {
                return (row < 0 || row >= numRows || col < 0 || col >= numCols);
            }

        bool Grid::isCellEmpty(int row, int col) const
            {
                return !isCellOutside(row, col) && (grid[row][col] == 0);
            }

        void Grid::setCell(int row, int col, int value)
            {
                if (!isCellOutside(row, col))
                    {
                        grid[row][col] = value;
                    }
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
    } // namespace tetris
