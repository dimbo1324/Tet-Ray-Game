#pragma once
#include  <vector>
#include <map>
#include "../colors/Colors.h"
#include "../positions/Position.h"


class Block
    {
    public:
        Block();

        void DrawBlock();

        int id;

        std::map<int, std::vector<Position> > cells;

    private:
        unsigned int cellSize, rotationState;
        std::vector<Color> colors;
    };
