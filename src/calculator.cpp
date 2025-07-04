#include "calculator.h"
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;


Calculator ::Calculator()
{
    std::vector<int> screen_coordinates = GetConstants();
    screenWidth = screen_coordinates[0];
    screenHeigth = screen_coordinates[1];
    Buttons b = Buttons();
    count = -1;
    retrievedNumbers = {};
    nextNumber = 0;
    isOperatorSelected = false;

    strcpy(numberText, "");
    strcpy(operatorChar, "");
    strcpy(resultText, "");
    strcpy(cStyleCharacters, "");


    allCharaterString = "";

    ResetCountVectorEtc();
}

void Calculator ::ResetCountVectorEtc()
{
    if(isOperatorSelected == true)
    {
        count = -1;
        retrievedNumbers.clear();
    }
}

void Calculator ::DrawOutputBox()
{
    Rectangle outputBox = {40, 50, 520, 160};
    DrawRectangleRounded(outputBox, 0.2, 10, RAYWHITE);

    // Draw expression string near top-right inside box
    int fontSize = 30;
    int expressionWidth = MeasureText(cStyleCharacters, fontSize);
    int exprX = outputBox.x + outputBox.width - expressionWidth - 20;
    int exprY = outputBox.y + 10;

    // Draw result string below expression
    int resultWidth = MeasureText(resultText, fontSize);
    int resultX = outputBox.x + outputBox.width - resultWidth - 20;
    int resultY = outputBox.y + fontSize + 30;

    strcpy(cStyleCharacters, allCharaterString.c_str());

    DrawText(cStyleCharacters, exprX, exprY, fontSize, DARKGRAY);
    DrawText(resultText, resultX, resultY, fontSize, RED);
}

void Calculator ::DrawButtons()
{
    int checkNum = b.DrawButtons();
    if(checkNum != -1)
    {
        if (resultJustCalculated)
        {
            // Start fresh after last result
            currentNumber = 0;
            nextNumber = 0;
            retrievedNumbers.clear();
            allCharaterString = "";
            resultJustCalculated = false;
            isOperatorSelected = false;
            count = -1;
        }

        if(checkNum >= 0 && checkNum <= 9)
        {
            snprintf(numberText, sizeof(numberText), "%d", checkNum);
            allCharaterString.append(numberText);

            cout << "ALL STRINGS: " << allCharaterString << endl;
            int currNum = atoi(numberText);
            
            if(!isOperatorSelected)
            {
                retrievedNumbers.push_back(currNum);
                count++;

                if(retrievedNumbers.size() == 1)
                {
                    currentNumber = retrievedNumbers[0];
                }

                if(retrievedNumbers.size() > 1){
                    currentNumber = (currentNumber * 10) + retrievedNumbers[count];
                }
            }

            if(isOperatorSelected)
            {
                retrievedNumbers.push_back(currNum);
                count++;
                if(retrievedNumbers.size() == 1)
                {
                    nextNumber = retrievedNumbers[0];
                }

                if(retrievedNumbers.size() > 1){
                    nextNumber = (nextNumber * 10) + retrievedNumbers[count];
                }
            }
        }

        else
        {

            snprintf(numberText, sizeof(numberText), "%c", char(checkNum));
            allCharaterString.append(numberText);
            switch(numberText[0])
            {
                case '+':{
                    snprintf(operatorChar, sizeof(operatorChar), "%c", char(checkNum));
                    isOperatorSelected = true;
                }break;
                case '-':{
                    snprintf(operatorChar, sizeof(operatorChar), "%c", char(checkNum));
                    isOperatorSelected = true;
                }break;
                case 'X':{
                    snprintf(operatorChar, sizeof(operatorChar), "%c", char(checkNum));
                    isOperatorSelected = true;
                }break;
                case '/':{
                    snprintf(operatorChar, sizeof(operatorChar), "%c", char(checkNum));
                    isOperatorSelected = true;
                }break;
                case '=':{
                    strcpy(resultText, "");
                    Evaluate(operatorChar);
                }break;
            }
        }
    }
}

void Calculator ::Evaluate(char *operatorChar)
{
    switch(operatorChar[0])
    {
        case '+':
            {
                int sum = currentNumber + nextNumber;
                snprintf(resultText, sizeof(resultText), "%d", char(sum));
                allCharaterString = "";
            }
        break;

        case '-':
            {
                int result = currentNumber - nextNumber;
                snprintf(resultText, sizeof(resultText), "%d", char(result));
                allCharaterString = "";
            }
        break;

        case 'X':
            {
                int result = currentNumber * nextNumber;
                snprintf(resultText, sizeof(resultText), "%d", char(result));
                allCharaterString = "";
            }
        break;

        case '/':
            {
                int result = currentNumber / nextNumber;
                snprintf(resultText, sizeof(resultText), "%d", char(result));
                allCharaterString = "";
            }
        break;
    }
    resultJustCalculated = true;

    return;
}