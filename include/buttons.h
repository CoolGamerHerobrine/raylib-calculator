#pragma once
#include <raylib.h>
#include "utils/constants_file.h"


class Buttons{
private:
    int numRows;
    int numCols;
    int ScreenSizeVertical;
    int ScreenSizeHorizontal;
    std::vector<int> coordinates;

    int initialScreenPositionX;
    int initialScreenPositionY;

    int eachBoxHeigth;
    int eachBoxWidth;

    bool isMouseInsideRectangle(Rectangle &);
    int board[5][3];

public:
    Buttons();
    void Initialize();
    int DrawButtons();
};