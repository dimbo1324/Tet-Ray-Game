#pragma once

#include <vector>
#include <raylib.h>

class Grid
    {
    public:
        Grid();

        void initialize();

        void printGrid() const;

        void drawGrid() const;

        bool isCellOutside(int row, int col) const;

        bool isCellEmpty(int row, int col) const;

        int clearFullRows();

        void setCell(int row, int col, int value); // Добавленный метод

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
