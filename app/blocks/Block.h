#pragma once

#include  <vector>
#include <map>
#include "../colors/Colors.h"
#include "../positions/Position.h"
#include "../utils/types/Types.h"


class Block
    {
    public:
        Block();

        void DrawBlock();

        void Move(uint r, uint c);

        uint id;

        std::map<uint, std::vector<Position> > cells;

    private:
        uint cellSize, rotationState, rowOffset, colOffset;
        std::vector<Color> colors;
    };
