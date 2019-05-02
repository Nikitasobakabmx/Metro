#pragma once
#include "Task.h"
#include <iostream>
#include <string>

Task setExem(bool flag, bool outPut);
void writeTest(std::string *test);
float* startTest(std::string *test);
void chekTest(char *fileName);
void chekTest(float *unswerArray, std::string *test);
std::string* generateTest(Task &exem);
std::string generateNum(float *unswers);
std::string generateTask(std::string name, float &unswer);
std::string* generateTask(std::string name, int quantity, float *unswer);