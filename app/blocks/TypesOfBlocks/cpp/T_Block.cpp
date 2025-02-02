#include "../../Block.h"

class T_Block : public Block
    {
    public:
        T_Block()
            {
                id = 6;

                cells[0] = {Position(0, 1), Position(1, 0), Position(1, 1), Position(1,2)};
                cells[1] = {Position(0, 1), Position(1, 1), Position(1, 2), Position(2, 1)};
                cells[2] = {Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 1)};
                cells[3] = {Position(0, 1), Position(1, 0), Position(1, 1), Position(2, 1)};                Move(0, 3);

            }
    };
