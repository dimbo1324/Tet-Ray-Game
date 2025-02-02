#ifndef GAME_H
#define GAME_H

#include <vector>
#include <random>
#include "../blocks/Block.h"
#include "../grid/Grid.h"
#include <raylib.h>

namespace tetris
    {
        class Game
            {
            public:
                Game();

                ~Game();

                void draw();

                void handleInput();

                void moveBlockDown();

                bool gameOver;
                int gameScore;
                Music music;

            private:
                void moveBlockLeft();

                void moveBlockRight();

                void rotateBlock();

                bool isBlockOutside() const;

                bool blockFits() const;

                void lockBlock();

                void reset();

                void updateScore(int linesCleared, int moveDownPoints);

                Block getRandomBlock();

                std::vector<Block> getAllBlocks();

                Grid grid;
                std::vector<Block> blocks;
                Block currentBlock, nextBlock;
                std::mt19937 randomEngine;
                Sound rotateSound, clearSound;
            };
    }

#endif
