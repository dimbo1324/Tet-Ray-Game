#ifndef GRID_H
#define GRID_H

#include <vector>
#include <raylib.h>

namespace tetris
    {
        class Grid
            {
            public:
                Grid();

                void initialize();

                void drawGrid() const;

                bool isCellOutside(int row, int col) const;

                bool isCellEmpty(int row, int col) const;

                void setCell(int row, int col, int value);

                int clearFullRows();

            private:
                bool isRowFull(int row) const;

                void clearRow(int row);

                void moveRowDown(int row, int numRowsToMove);

                int numRows;
                int numCols;
                int cellSize;

                std::vector<std::vector<int> > grid;
                std::vector<Color> colors;
            };
    }

#endif
