#include "utils/constants_file.h"

const int screenHeigth = 800;
const int screenWidth = 600;

std::vector<int> GetConstants()
{
    return {screenWidth, screenHeigth};
}