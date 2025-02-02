#include "../../Block.h"

class O_Block : public Block
    {
    public:
        O_Block()
            {
                id = 4;

                cells[0] = {Position(0, 0), Position(0, 1), Position(1, 0), Position(1,1)};
                Move(0, 3);

            }
    };
