#pragma once
#include "Task.h"
#include <iostream>
#include <string>

Task setExem(bool flag, bool outPut);//
void writeTest(std::string *test, const Task &exem);//
float* startTest(std::string *test, const Task &exem);//
void chekTest(char *fileName);//
int chekTest(const float *unswerArray, const std::string *test, const float *unswer, const Task &exem);//
//void chekTest(float *unswerArray, std::string *test);
std::string* generateTest(const Task &exem, float *unswers);//
std::string generateNum(float *unswers);//
std::string generateTask(std::string name, float &unswer);//
std::string* generateTask(std::string name, const int &quantity, float *unswer);//
float* catchTheUnswer(std::string file, bool type);