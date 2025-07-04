#include "calculator.h"
#include "utils/colors.h"
#include "utils/constants_file.h"
#include <iostream>
using namespace std;

//int buttonBoxInitial = (screenHeigth + 50) - screenHeigth + 160;

int main()
{
    Calculator c1;
    std::vector<Color> allColors = GetAllColors();

    InitWindow(c1.screenWidth, c1.screenHeigth, "Calculator");
    SetTargetFPS(60);
    while(!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(allColors[0]);
        c1.DrawOutputBox();
        c1.DrawButtons();

        //DrawText("Hi", 50, 230, 32, RED);
        //DrawRectangle((c1.screenWidth + 25) - c1.screenWidth, buttonBoxInitial + 25, 550, 540, RED);
        //c1.DrawButtons();

        EndDrawing();
    }
    CloseWindow();
}
