#include "Block.h"
#include "../utils/types/Types.h"

Block::Block() : id(0)
    {
        cellSize = 30;
        rotationState = 0;
        rowOffset = 0;
        colOffset = 0;
        colors = GetCellColors();
    }

void Block::DrawBlock()
    {
        std::vector<Position> tiles = GetCellsPositions();
        for (Position i: tiles)
            {
                DrawRectangle(static_cast<int>(i.col) * static_cast<int>(cellSize) + 1,
                              static_cast<int>(i.row) * static_cast<int>(cellSize) + 1,
                              static_cast<int>(cellSize) - 1,
                              static_cast<int>(cellSize) - 1,
                              colors[id]);
            }
    }

void Block::Move(uint r, uint c)
    {
        rowOffset += r;
        colOffset += c;
    }

std::vector<Position> Block::GetCellsPositions()
    {
        std::vector<Position> tiles = cells[rotationState];
        std::vector<Position> movedTiles;
        for (Position i: tiles)
            {
                Position newPosition = Position(i.row + rowOffset, i.col + colOffset);
                movedTiles.push_back(newPosition);
            }
        return movedTiles;
    }
