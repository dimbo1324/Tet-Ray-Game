#include "Game.h"
#include "../blocks/StorageOfBlocks.cpp"
#include <stdexcept>
#include <algorithm>
#include "../game property/constants.h"

Game::Game()
    : grid(),
      randomEngine(std::random_device{}())
    {
        blocks = getAllBlocks();
        currentBlock = getRandomBlock();
        nextBlock = getRandomBlock();
        gameOver = false;
        gameScore = 0;
        InitAudioDevice();
        music = LoadMusicStream("../../../Tetris/sounds/music.mp3");
        PlayMusicStream(music);
        rotateSound = LoadSound("../../../Tetris/sounds/rotate.mp3");
        clearSound = LoadSound("../../../Tetris/sounds/clear.mp3");
    }

Game::~Game()
    {
        UnloadSound(rotateSound);
        UnloadSound(clearSound);
        UnloadMusicStream(music);
        CloseAudioDevice();
    }

Block Game::getRandomBlock()
    {
        if (blocks.empty())
            {
                blocks = getAllBlocks();
            }
        std::uniform_int_distribution<> dist(0, static_cast<int>(blocks.size()) - 1);
        int randomIndex = dist(randomEngine);
        Block block = blocks[randomIndex];
        blocks.erase(blocks.begin() + randomIndex);
        return block;
    }

std::vector<Block> Game::getAllBlocks()
    {
        return {I_Block(), J_Block(), L_Block(), O_Block(), S_Block(), T_Block(), Z_Block()};
    }

void Game::draw()
    {
        grid.drawGrid();
        currentBlock.draw(extraPixelsPositionValue, extraPixelsPositionValue);
        switch (nextBlock.id)
            {
                case 3:
                    nextBlock.draw(255, 290);
                    break;
                case 4:
                    nextBlock.draw(255, 280);
                    break;
                default:
                    nextBlock.draw(270, 270);
                    break;
            }
    }

void Game::handleInput()
    {
        int key = GetKeyPressed();
        if (gameOver && (key == KEY_SPACE || key == KEY_ENTER))
            {
                gameOver = false;
                reset();
            }

        switch (key)
            {
                case KEY_LEFT:
                    moveBlockLeft();
                    break;
                case KEY_RIGHT:
                    moveBlockRight();
                    break;
                case KEY_DOWN:
                    moveBlockDown();
                    updateScore(0, 1);
                    break;
                case KEY_UP:
                    rotateBlock();
                    break;
                default:
                    break;
            }
    }

void Game::moveBlockLeft()
    {
        if (!gameOver)
            {
                currentBlock.move(0, -1);
                if (isBlockOutside() || !blockFits())
                    {
                        currentBlock.move(0, 1);
                    }
            }
    }

void Game::moveBlockRight()
    {
        if (!gameOver)
            {
                currentBlock.move(0, 1);
                if (isBlockOutside() || !blockFits())
                    {
                        currentBlock.move(0, -1);
                    }
            }
    }

void Game::moveBlockDown()
    {
        if (!gameOver)
            {
                currentBlock.move(1, 0);
                if (isBlockOutside() || !blockFits())
                    {
                        currentBlock.move(-1, 0);
                        lockBlock();
                    }
            }
    }


bool Game::isBlockOutside() const
    {
        const std::vector<Position> tiles = currentBlock.getCellsPositions();
        return std::any_of(tiles.begin(), tiles.end(),
                           [this](const Position &pos)
                               {
                                   return grid.isCellOutside(pos.row, pos.col);
                               });
    }

void Game::rotateBlock()
    {
        if (!gameOver)
            {
                currentBlock.rotate();
                if (isBlockOutside() || !blockFits())
                    {
                        currentBlock.undoRotation();
                    } else
                    {
                        PlaySound(rotateSound);
                    }
            }
    }

void Game::lockBlock()
    {
        const std::vector<Position> tiles = currentBlock.getCellsPositions();
        for (const auto &pos: tiles)
            {
                grid.setCell(pos.row, pos.col, currentBlock.id);
            }
        currentBlock = nextBlock;
        if (blockFits() == false)
            {
                gameOver = true;
            }
        nextBlock = getRandomBlock();
        int rowCleared = grid.clearFullRows();
        if (rowCleared > 0)
            {
                PlaySound(clearSound);
                updateScore(rowCleared, 0);
            }
    }


bool Game::blockFits() const
    {
        const std::vector<Position> tiles = currentBlock.getCellsPositions();
        return std::all_of(tiles.begin(), tiles.end(),
                           [this](const Position &pos)
                               {
                                   return grid.isCellEmpty(pos.row, pos.col);
                               });
    }

void Game::reset()
    {
        grid.initialize();
        blocks = getAllBlocks();
        currentBlock = getRandomBlock();
        nextBlock = getRandomBlock();
        gameScore = 0;
    }

void Game::updateScore(int linesCleared, int moveDownPoints)
    {
        switch (linesCleared)
            {
                case 1:
                    gameScore += 100;
                    break;
                case 2:
                    gameScore += 300;
                    break;
                case 3:
                    gameScore += 500;
                    break;
                default:
                    break;
            }
        gameScore += moveDownPoints;
    }
