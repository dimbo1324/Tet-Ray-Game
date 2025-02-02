#include "Block.h"

Block::Block()
{
    cellSize = 30;
    rotationState = 0;
    rowOffset = 0;
    colOffset = 0;
    colors = GetCellColors();
}

void Block::DrawBlock()
{
    std::vector<Position> titles = cells[rotationState];
    for (Position i : titles)
    {
        DrawRectangle(i.col * cellSize + 1, i.row * cellSize + 1, cellSize - 1,
                      cellSize - 1, colors[id]);
    }
}

void Block::Move(int r, int c)
{
    rowOffset += r;
    colOffset += c;
}
