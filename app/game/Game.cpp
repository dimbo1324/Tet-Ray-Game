#include <random>
#include "Game.h"
#include "../utils/types/Types.h"
#include "../blocks/TypesOfBlocks/cpp/L_Block.cpp"
#include "../blocks/TypesOfBlocks/cpp/J_Block.cpp"
#include "../blocks/TypesOfBlocks/cpp/I_Block.cpp"
#include "../blocks/TypesOfBlocks/cpp/O_Block.cpp"
#include "../blocks/TypesOfBlocks/cpp/S_Block.cpp"
#include "../blocks/TypesOfBlocks/cpp/T_Block.cpp"
#include "../blocks/TypesOfBlocks/cpp/Z_Block.cpp"

Game::Game()
    {
        grid = Grid();
        blocks = GetAllBlocks();
        currentBlock = GetRandomBlock();
        nextBlock = GetRandomBlock();
    }


Block Game::GetRandomBlock()
    {
        if (blocks.empty())
            {
                blocks = GetAllBlocks();
            }
        uint randomValue = rand() % blocks.size();
        Block block = blocks[randomValue];
        blocks.erase(blocks.begin() + randomValue);
        return block;
    }

std::vector<Block> Game::GetAllBlocks()
    {
        return {I_Block(), J_Block(), L_Block(), O_Block(), S_Block(), T_Block(), Z_Block()};
    }


void Game::DrawBlock()
    {
        grid.DrawGrid();
        currentBlock.DrawBlock();
    }


void Game::HandleInput()
    {
        int key = GetKeyPressed();

        switch (key)
            {
                case KEY_LEFT:
                    MoveBlockLeft();
                    break;
                case KEY_RIGHT:
                    MoveBlockRight();
                    break;
                case KEY_DOWN:
                    MoveBlockDown();
                    break;
                case KEY_UP:
                    RotateBlock();
                    break;
            }
    }


void Game::MoveBlockLeft()
    {
        currentBlock.Move(0, -1);

        if (IsBlockOutside() || BlockFits() == false) currentBlock.Move(0, 1);
    }

void Game::MoveBlockRight()
    {
        currentBlock.Move(0, 1);
        if (IsBlockOutside() || BlockFits() == false) currentBlock.Move(0, -1);
    }

void Game::MoveBlockDown()
    {
        currentBlock.Move(1, 0);
        if (IsBlockOutside() || BlockFits() == false)
            {
                currentBlock.Move(-1, 0);
                LockBlock();
            }
    }

bool Game::IsBlockOutside()
    {
        std::vector<Position> tiles = currentBlock.GetCellsPositions();
        for (Position i: tiles)
            {
                if (grid.IsCellOutside(i.row, i.col)) return true;
            }
        return false;
    }

void Game::RotateBlock()
    {
        currentBlock.Rotate();

        if (IsBlockOutside() || BlockFits() == false) currentBlock.UndoRotation();
    }

void Game::LockBlock()
    {
        std::vector<Position> tiles = currentBlock.GetCellsPositions();
        for (Position i: tiles)
            {
                grid.grid[i.row][i.col] = currentBlock.id;
            }
        currentBlock = nextBlock;
        nextBlock = GetRandomBlock();
    }

bool Game::BlockFits()
    {
        std::vector<Position> tiles = currentBlock.GetCellsPositions();
        for (Position i: tiles)
            {
                if (grid.IsCellEmpty(i.row, i.col) == false) return false;
            }
        return true;
    }
