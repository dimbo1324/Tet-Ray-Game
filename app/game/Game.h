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

        // Метод, возвращающий случайный блок.
        Block getRandomBlock();

        // Метод возвращает все типы блоков. Объявлен как static, так как не зависит от состояния объекта.
        static std::vector<Block> getAllBlocks();

        // Отрисовка игры.
        void draw();

        // Обработка ввода пользователя.
        void handleInput();

        // Перемещение блоков.
        void moveBlockLeft();

        void moveBlockRight();

        void moveBlockDown();

    private:
        // Проверяет, выходит ли текущий блок за пределы игрового поля.
        bool isBlockOutside() const;

        // Поворачивает текущий блок.
        void rotateBlock();

        // "Закрепляет" блок на сетке и обновляет игровое состояние.
        void lockBlock();

        // Проверяет, свободны ли ячейки под текущим блоком.
        bool blockFits() const;

        Grid grid;
        std::vector<Block> blocks;
        Block currentBlock, nextBlock;
        std::mt19937 randomEngine;
    };
