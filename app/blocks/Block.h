#pragma once

#include <vector>
#include <map>
#include "../colors/Colors.h"
#include "../positions/Position.h"

std::vector<Color> GetCellColors();

void DrawRectangle(int posX, int posY, int width, int height, Color color);

class Block
    {
    public:
        Block();

        void draw() const;

        void move(int rowDelta, int colDelta);

        std::vector<Position> getCellsPositions() const;

        void rotate();

        void undoRotation();

        int id;

        std::map<int, std::vector<Position> > cells;

    private:
        int cellSize;
        int rotationState;
        int rowOffset;
        int colOffset;

        std::vector<Color> colors;
    };
