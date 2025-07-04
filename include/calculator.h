#pragma once
#include "utils/colors.h"
#include "utils/constants_file.h"
#include "buttons.h"
#include <string>


class Calculator {
public:
    Calculator();
    void DrawOutputBox();
    void DrawButtons();
    char text[32];

    std::vector<int> screen_coordinates;
    int screenWidth;
    int screenHeigth;
    Buttons b;

    int currentNumber;
    int nextNumber;
    char numberText[32];
    bool isOperatorSelected;
    char operatorChar[2];
    std::vector<int> retrievedNumbers;
    int count;
    void Evaluate(char *);
    char resultText[10];

    std::string allCharaterString;
    char cStyleCharacters[32];\

    bool resultJustCalculated = false;

    void ResetCountVectorEtc();
};
