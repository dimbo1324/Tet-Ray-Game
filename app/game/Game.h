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

        ~Game();

        static std::vector<Block> getAllBlocks();

        void draw();

        void handleInput();

        void moveBlockDown();

        bool gameOver;

        int gameScore;

        Music music;

    private:
        void moveBlockLeft();

        void moveBlockRight();

        bool isBlockOutside() const;

        void rotateBlock();

        void lockBlock();

        bool blockFits() const;

        void reset();

        void updateScore(int linesCleared, int moveDownPoints);

        Block getRandomBlock();

        Grid grid;
        std::vector<Block> blocks;
        Block currentBlock, nextBlock;
        std::mt19937 randomEngine;
        Sound rotateSound, clearSound;
    };
