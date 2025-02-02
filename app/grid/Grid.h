#ifndef GRID_H
#define GRID_H

#include <vector>
#include <raylib.h>

namespace tetris
    {
        class Grid
            {
            public:
                Grid();

                // Инициализация (очистка) поля
                void initialize();

                // Отрисовка игрового поля
                void drawGrid() const;

                // Проверка, находится ли ячейка за пределами поля
                bool isCellOutside(int row, int col) const;

                // Проверка, пуста ли ячейка
                bool isCellEmpty(int row, int col) const;

                // Установка значения ячейки
                void setCell(int row, int col, int value);

                // Очистка полных строк и сдвиг оставшихся строк вниз; возвращает число очищенных строк
                int clearFullRows();

            private:
                bool isRowFull(int row) const;

                void clearRow(int row);

                void moveRowDown(int row, int numRowsToMove);

                int numRows;
                int numCols;
                int cellSize;

                std::vector<std::vector<int> > grid;
                std::vector<Color> colors;
            };
    } // namespace tetris

#endif // GRID_H
