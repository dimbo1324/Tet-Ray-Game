#include "../../Block.h"

class S_Block : public Block
    {
    public:
        S_Block()
            {
                id = 5;

                cells[0] = {Position(0, 1), Position(0, 2), Position(1, 0), Position(1,1)};
                cells[1] = {Position(0, 1), Position(1, 1), Position(1, 2), Position(2, 2)};
                cells[2] = {Position(1, 1), Position(1, 2), Position(2, 0), Position(2, 1)};
                cells[3] = {Position(0, 0), Position(1, 0), Position(1, 1), Position(2, 1)};                Move(0, 3);

            }
    };
