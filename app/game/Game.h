#pragma once

#include <vector>
#include <raylib.h>
#include <random>
#include "../blocks/Block.h"
#include "../grid/Grid.h"

class Game
    {
    public:
        Game();

        Block getRandomBlock();

        static std::vector<Block> getAllBlocks();

        void draw();

        void handleInput();

        void moveBlockLeft();

        void moveBlockRight();

        void moveBlockDown();

        bool gameOver;

    private:
        bool isBlockOutside() const;

        void rotateBlock();

        void lockBlock();

        bool blockFits() const;

        void Reset();

        Grid grid;
        std::vector<Block> blocks;
        Block currentBlock, nextBlock;
        std::mt19937 randomEngine;
    };
