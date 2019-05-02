#pragma once
#include <string>
struct Task
{
    bool type;//ОГЭ - 0/ ЕГЭ - 1
    int number;// 0 for all
    int quantity;//колличество заданий каждого типа
    bool io;//0 - console / 1 - text file

    Task(bool a, int b, int c, bool d) : type(a), number(b), quantity(c), io(d){};
    Task(){};
};