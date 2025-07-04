#include "buttons.h"
#include <iostream>
#include <iomanip>
using namespace std;


Buttons ::Buttons(){
    std::vector<int> coordinates = GetConstants();
    numRows = 5;
    numCols = 3;

    initialScreenPositionX = 40;
    initialScreenPositionY = 230;

    ScreenSizeVertical = coordinates[1] - 230;      // heigth   550
    ScreenSizeHorizontal = coordinates[0] - 80;    // horizontal 520

    eachBoxHeigth = ScreenSizeVertical / 5;
    eachBoxWidth = ScreenSizeHorizontal / 3;

    Initialize();
}

void Buttons ::Initialize()
{
    int start = 9, end = 1;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            board[i][j] = start--;
        }
    }
    board[3][0] = 0;
    board[3][1] = '+';
    board[3][2] = '-';

    board[4][0] = 'X';
    board[4][1] = '/';
    board[4][2] = '=';
}

int Buttons ::DrawButtons()
{
    //DrawRectangle(initialScreenPositionY, initialScreenPositionX, ScreenSizeHorizontal, ScreenSizeVertical, RED);
    int currentX = initialScreenPositionX;
    int currentY = initialScreenPositionY;
    int valueClicked = -1;
    for(int rows = 0; rows < numRows; rows++)
    {
        for(int cols = 0; cols < numCols; cols++)
        {
            Rectangle rec = {float(currentX), float(currentY), float(eachBoxWidth), float(eachBoxHeigth)};
            if(isMouseInsideRectangle(rec))
            {
                DrawRectangleRounded({float(currentX), float(currentY), float(eachBoxWidth - 15), float(eachBoxHeigth - 15)}, 0.2, 10, YELLOW);
            }
            else
            {
                DrawRectangleRounded({float(currentX), float(currentY), float(eachBoxWidth - 25), float(eachBoxHeigth - 25)}, 0.2, 10, BLUE);   
            }

            if(isMouseInsideRectangle(rec) && IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
            {
                valueClicked = board[rows][cols];
            }

            char text[2] = "";
            int currentBoardValue = board[rows][cols];

            if(currentBoardValue >= 0 && currentBoardValue <= 9)
                snprintf(text, sizeof(text), "%d", currentBoardValue);
            else
                snprintf(text, sizeof(text), "%c", char(currentBoardValue));
            
            int textWidth = MeasureText(text, 30);
            int textX = currentX + (eachBoxWidth - 15 - textWidth) / 2;
            int textY = currentY + (eachBoxHeigth - 15 - 30) / 2;
            DrawText(text, textX, textY, 30, WHITE);

            currentX += eachBoxWidth;
            
        }
        currentY += eachBoxHeigth;
        currentX = initialScreenPositionX;
    }

    return valueClicked;        // -1
}

bool Buttons ::isMouseInsideRectangle(Rectangle &rec)
{
    Vector2 mousePosition = GetMousePosition();
    bool isMouseInside = CheckCollisionPointRec(mousePosition, rec);
    return isMouseInside;
}