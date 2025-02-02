#pragma once
#include "../blocks/Block.h"
#include "../grid/Grid.h"

class Game
    {
    public:
        Game();


        Block GetRandomBlock();

        std::vector<Block> GetAllBlocks();

        void DrawBlock();

        void HandleInput();

        void MoveBlockLeft();

        void MoveBlockRight();

        void MoveBlockDown();

        Grid grid;

    private:
        bool IsBlockOutside();

        void RotateBlock();

        std::vector<Block> blocks;
        Block currentBlock, nextBlock;
    };
