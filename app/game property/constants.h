#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <raylib.h>

constexpr int cellSizeValue = 30;
constexpr int rectangleHorizontalSideValue = static_cast<int>(cellSizeValue * (500.0 /
                                                                  cellSizeValue));
constexpr int rectangleVerticalSideValue = static_cast<int>(cellSizeValue * (620.0 /
                                                                cellSizeValue));
constexpr int extraPixelsPositionValue = 11;
constexpr int numColsValue = static_cast<int>(cellSizeValue / 3.0);
constexpr int numRowsValue = 2 * numColsValue;
constexpr int targetFPSValue = 60;
constexpr double gameSpeedValue = 0.3;
constexpr Color backgroundColorValue = {10, 120, 156, 124};
inline double lastUpdateTimeValue = 0.0;

#endif
