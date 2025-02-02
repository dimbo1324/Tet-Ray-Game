#pragma once

#include <vector>
#include <map>
#include "../colors/Colors.h"
#include "../positions/Position.h"

class Block
{
public:
    int id;

    Block();

    void DrawBlock();

    void Move(int r, int c);

    std::vector<Position> GetCellsPositions();

    void Rotate();

    void UndoRotation();

    std::map<int, std::vector<Position>> cells;

private:
    int cellSize, rotationState, rowOffset, colOffset;
    std::vector<Color> colors;
};
