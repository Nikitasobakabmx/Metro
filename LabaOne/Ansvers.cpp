#include "Ansvers.h"


void checkTest(char *fileName)
{
    Exem *exem = new Exem;
    std::ifstream file(fileName);
    std::string tmp;
    file >> tmp >> tmp >> tmp >> tmp >> tmp;
    tmp = "uns" + tmp + ".txt";
    tmp.resize(tmp.size() - 3);
    int amount = std::stoi(tmp);
    exem->myUnswers_ = catchTheUnswer(tmp, amount);
    std::getline(file, tmp);//first line complete
}

float* catchTheUnswer(std::string fileName, int amount)
{
    std::cout << fileName[0] << std::endl;
    std::ifstream unsFile(fileName);
    if(!unsFile.is_open())
        throw except("Хьюстон, у нас проблема");
    float *unswer = new float[amount];
    for(int i = 0; i < amount; i++)
        unsFile >> unswer[i];
    return unswer;
}