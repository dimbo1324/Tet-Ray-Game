#ifndef CONSTANTS_H
#define CONSTANTS_H


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
constexpr int xUiTextPosition = static_cast<int>(cellSizeValue * (350.0 /
                                                     cellSizeValue));
constexpr int yUiTextPosition = static_cast<int>(cellSizeValue * (15.0 /
                                                     cellSizeValue));
constexpr int fontSizeUiText = static_cast<int>(cellSizeValue / 1.5);

inline double lastUpdateTimeValue = 0.0;

#endif
