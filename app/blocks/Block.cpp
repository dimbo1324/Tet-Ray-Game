#include "Block.h"
#include <stdexcept>
#include "../game property/constants.h"


Block::Block()
    : id(0),
      cellSize(cellSizeValue),
      rotationState(0),
      rowOffset(0),
      colOffset(0),
      colors(GetCellColors())
    {}

void Block::draw(int offsetX, int offsetY) const
    {
        std::vector<Position> tiles = getCellsPositions();

        for (const auto &pos: tiles)
            {
                DrawRectangle(static_cast<int>(pos.col) * cellSize + offsetX,
                              static_cast<int>(pos.row) * cellSize + offsetY,
                              cellSize - 1,
                              cellSize - 1,
                              colors.at(id));
            }
    }

void Block::move(int rowDelta, int colDelta)
    {
        rowOffset += rowDelta;
        colOffset += colDelta;
    }

std::vector<Position> Block::getCellsPositions() const
    {
        auto it = cells.find(rotationState);
        if (it == cells.end())
            {
                throw std::out_of_range("Invalid rotation state in Block::getCellsPositions()");
            }

        const std::vector<Position> &baseTiles = it->second;
        std::vector<Position> movedTiles;
        movedTiles.reserve(baseTiles.size());

        for (const auto &pos: baseTiles)
            {
                movedTiles.emplace_back(pos.row + rowOffset, pos.col + colOffset);
            }

        return movedTiles;
    }

void Block::rotate()
    {
        if (cells.empty())
            {
                throw std::runtime_error("Block cells are empty");
            }
        rotationState = (rotationState + 1) % cells.size();
    }

void Block::undoRotation()
    {
        if (cells.empty())
            {
                throw std::runtime_error("Block cells are empty");
            }
        if (rotationState == 0)
            {
                rotationState = cells.size() - 1;
            } else
            {
                --rotationState;
            }
    }
