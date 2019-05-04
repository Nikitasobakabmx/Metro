#pragma once
#include "Task.h"
#include <iostream>
#include <string>
class Exem
{
    private:
        bool type_;//ОГЭ - 0/ ЕГЭ - 1
        int number_;// 0 for all
        int quantity_;//колличество заданий каждого типа
        bool output_;//0 - console / 1 - text file
        std::string *test_;
        float *unswers_;
        float *myUnswers_;
        std::string testFileName_;
        std::string unswerTestFileName;

    public:
        Exem(bool a, int b, int c, bool d) : type(a), number(b), quantity(c), io(d){};
        void setExem();
        /**********************************************
        * geerate test, put it to string array(test_) *
        **********************************************/
        void genetateTest();
        /*******************************************
        * generate identification num for own test *
        * return string with id num                *
        *******************************************/
        std::string generateID();
        /****************************************************************
        * generate only one task from test                              *
        * get name of file with tasks and cage of unswer array(unswer_) *
        * return string with task                                       *
        ****************************************************************/
        std::string generateTask(std::string name, float &unswer);
        /**************************************************
        * generate a certan amount specific type of tasks *
        * get name of file with tasks                     *
        * return string with tasks                        *
        **************************************************/
        std::string* generateTask(std::string name);
        /**************************************************************
        * string(test_) formats and put in file (name(testFileName_)) *
        **************************************************************/
        void writeTest();
}
Task setExem(bool flag, bool outPut);//
void writeTest(std::string *test, const Task &exem);
float* startTest(std::string *test, const Task &exem);
void chekTest(char *fileName);
int chekTest(const float *unswerArray, const std::string *test, const float *unswer, const Task &exem);
//void chekTest(float *unswerArray, std::string *test);
std::string* generateTest(const Task &exem, float *unswers);//
std::string generateNum(float *unswers);//
std::string generateTask(std::string name, float &unswer);//
std::string* generateTask(std::string name, const int &quantity, float *unswer);//
float* catchTheUnswer(std::string file, bool type);