#include "Test.h"
#include "Task.h"
#include <iostream>
#include <string>
#include "stdio.h"
#include <fstream>
#include "except.h"


Task setExem(bool flag, bool outPut)
{
    int tasks[] = {20, 12};
    std::string tmp;
    while(true)
    {
        std::cout << "Веберите конкретное задание или тест" << std::endl;
        std::cin >> tmp;
        if(tmp == "задание" || tmp == "конкретное задание")
        {
            int Num;
            std::cout << "Выберите номер задания" << std::endl;
            std::cin >> Num;
            if(Num > tasks[flag] || Num <= 0)
            {
                std::cout << "Вы ввели что то не то" << std::endl;
                continue;
            }
            std::cout << "Выберите колличество задания данного номера" << std::endl;
            int quan; //quantity
            std::cin >> quan;
            if(quan <= 0)
            {
                std::cout << "Вы ввели что то не то" << std::endl;
                continue;
            }
            Task exem(flag, Num, quan, outPut); 
            return exem;
        }
        if(tmp == "тест")
        {
            Task exem(flag, 0, 1, outPut); 
            return exem;
        }
        std::cout << "Вы ввели что то не то" << std::endl;
        continue;
    }
}

void writeTest(std::string *test, const Task &exem)
{
    int tasks[] = {20, 12};
    std::ofstream file("test" + test[0] + ".txt");
    if(exem.number != 0)
        if(exem.type)
            file << "<<Задачи ЕГЭ номер - " << test[0] << " >>" << std::endl;
        else
            file << "<<Задачи ОГЭ номер - " << test[0] << " >>" << std::endl;    
    else
        if(exem.type)
            file << "<<Тест ЕГЭ номер - " << test[0] << " >>" << std::endl;
        else
            file << "<<Тест ОГЭ номер - " << test[0] << " >>" << std::endl;    
    for(int i = 1; i < tasks[exem.type]; i++)
        file << "Задание номер " << i << std::endl << test[i] << std::endl << "Ответ: " << std::endl;
    file.close();
} 

float* startTest(std::string *test, const Task &exem)
{
    int tasks[] = {20, 12};    
    float *yourUnswer = new float[tasks[exem.type]];
    for(int i = 1; i < tasks[exem.type]; i++)
    {
        std::cout << "<<Тест номер - " << test[0] << " >>" << std::endl;
        std::cout << "Задание номер " << i << std::endl << test[i] << std::endl << "Ответ: ";
        std::cin >> yourUnswer[i-1];
        system("clear");
    }
    return yourUnswer;
}

void chekTest(char *fileName)
{
    Task exem;
    std::ifstream file(fileName);
    std::string tmp;
    file >> tmp;
    if(tmp != "<<Задачи")
        exem.number = 0;
    file >> tmp;
    if(tmp == "ЕГЭ")
        exem.type = true;
    else 
        exem.type = false;
    file >> tmp >> tmp >> tmp;
    tmp = "uns" + tmp + ".txt";
    float *unswer = catchTheUnswer(tmp, exem.type);
    std::getline(file, tmp);//first line complete
    

}

float* catchTheUnswer(std::string file, bool type)
{
    int tasks[] = {20, 12};
    std::ifstream unsFile(file);
    if(!unsFile.is_open())
        throw except("Хьюстон, у нас проблема");
    float *unswer = new float[tasks[type]];
    for(int i = 0; i < tasks[type]; i++)
        unsFile >> unswer[i];
    return unswer;
}

int chekTest(const float *unswerArray, const std::string *test, const float *unswer, const Task &exem)
{
    int tasks[] = {20, 12};
    int score = 0;
    std::cout << "<<Тест номер - " << test[0] << " >>" << std::endl;
    for(int i = 1; i < tasks[exem.type]; i++)
    {
        std::cout << "Задание номер " << i << std::endl << test[i] << std::endl << "Ваш ответ: " << unswerArray[i] << std::endl;
        std::cout << "Ответ : " << unswer[i];
        if(unswerArray[i] == unswer[i])
        {
            score++;
            std::cout << "" << std::endl;
        }
        std::cin.get();
        system("clear");
    }
    return score;

}



std::string* generateTest(const Task &exem, float *unswers)
{   
    int tasks[] = {20, 12};
    if(exem.number == 0)
    {
        std::string* test = new std::string[tasks[exem.type] + 1];
        unswers = new float[tasks[exem.type] + 1];             
        for(int i = 1; i <= tasks[exem.type]; i++)
        {
            std::string name;
            if(exem.type)
                name = "ege_";
            if(!exem.type)
                name = "oge_";
            name += std::to_string(i) + ".txt";                   
            try
            {
                test[i] = generateTask(name, unswers[i-1]);
            }
            catch(except ex)
            {
                std::cout << ex.what() << std::endl;
            }
        }
        test[0] = generateNum(unswers);
        std::ofstream unsFile(test[0]);
        for(int i = 0; i < tasks[exem.type]; i++)
            unsFile << unswers[i] << std::endl;
        unsFile.close();
        return test;
    }
    if(exem.number < 0 && exem.number > tasks[exem.type])
        throw except("номер задания не соответствует тестовым заданиям");
    std::string name;//name of file with task (ege_1.txt, oge_1.txt ...)
    std::string *test;//array of tasks from test 
    if(!exem.type)
        name = "oge_";
    else 
        name = "ege_";
    name += std::to_string(exem.number) + ".txt";
    unswers = new float[exem.quantity];//arrsy with unswers
    try{
        
        test = generateTask(name, exem.quantity, unswers);
    }
    catch(except ex)
    {
        std::cout << ex.what() << std::endl;
    }
    test[0] = generateNum(unswers);
    std::string nameUnsFile = "uns" + test[0] + ".txt";//name of file with unswers
    std::ofstream unsFile(name);
    for(int i = 0; i < exem.quantity; i++)
       unsFile << unswers[i] << std::endl;
    unsFile.close();
    return test;    
}
//generate number of test, identification
std::string generateNum(float *unswers)//complete
{
    int name = unswers[0]*100 + unswers[0] * 32 + unswers[0]*0.43 + unswers[0]*3;//magic hash
    if(name < 0)
        name *= -1;
    std::string tmp = std::to_string(name);
    return tmp;
}
//generate array with specific task
std::string* generateTask(std::string name, const int &quantity, float *unswer)//complete
{
    std::ifstream file(name);
    if(!file.is_open())
    {
        name = "Файл с имянем " + name + " не существует";
        throw except(name);
    }
    int count;
    file >> count;
    if(quantity > count)
        throw except("Вы хотите больше задач, чем положено!");//rofl
    std::string *tmp = new std::string[quantity+1];
    std::getline(file, tmp[0]);//read empty space
    for(int i = 0; i < quantity; i++)
    {
        std::getline(file, tmp[i+1]);
        file >> unswer[i];
    }
    file.close();
    return tmp;
}

std::string generateTask(std::string name, float &unswer)//complete
{
    std::ifstream file(name);
    if(!file.is_open())
    {
        name = "Файл с имянем " + name + " не существует";
        throw except(name);
    }
    int count;
    file >> count;
    if(count == 0)
    {
        name = "Файл с имянем " + name + " не имеет задач!";
        throw except(name);
    }
    srand(time(NULL));
    int taskNum = 1 + rand()%count;
    for(int i = 0; i < taskNum-1; i++)
    {
        std::cout<<"hehe" << std::endl;
        std::string tmp;
        std::getline(file, tmp);
        std::getline(file, tmp);
    }
    std::string task;
    std::getline(file, task);
    task = "";
    std::getline(file, task);
    file >> unswer;
    file.close();
    return task;
}
