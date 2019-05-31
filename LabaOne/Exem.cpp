#include "Exem.h"
#include <string>
#include "except.h"
#include <fstream>
#include <iostream>

float* catchTheUnswer(std::string fileName, int amount);

std::string* Exem::generateTest()
{
    if(number_ == 0)//generate all test
    {   
        if(test_ != nullptr)
            delete [] test_;
        test_ = new std::string[tasks_[type_]];
        if(unswers_ != nullptr)
            delete [] unswers_;
        unswers_ = new float[tasks_[type_]];             
        for(int i = 0; i < tasks_[type_]; i++)
        {
            std::string name;
            if(type_)
                name = "ege_";
            else
                name = "oge_";
            name += std::to_string(i+1) + ".txt";                   
            try
            {
                test_[i] = generateTask(name, unswers_[i]);
            }
            catch(except ex)
            {
                std::cout << ex.what() << std::endl;
            }
        }
        std::cout << "work" <<std::endl;
        testId_ = generateID();
        std::ofstream unsFile("uns" + testId_ + ".txt");
        for(int i = 0; i < tasks_[type_]; i++)
            unsFile << unswers_[i] << std::endl;
        unsFile.close();
        return test_;
    }
    if(number_ < 0 && number_ > tasks_[type_])
        throw except("номер задания не соответствует тестовым заданиям");
    std::string name;//name of file with task (ege_1.txt, oge_1.txt ...)
    if(!type_)
        name = "oge_";
    else 
        name = "ege_";
    name += std::to_string(number_) + ".txt";
    if(unswers_ != nullptr)
        delete [] unswers_;
    unswers_ = new float[quantity_];
    try{
        if(test_ != nullptr)
            delete [] test_;
        test_ = generateTask(name);
    }
    catch(except ex)
    {
        std::cout << ex.what() << std::endl;
    }
    testId_ = generateID();
    std::ofstream unsFile("uns" + testId_ + ".txt");
    for(int i = 0; i < quantity_; i++)
       unsFile << unswers_[i] << std::endl;
    unsFile.close();
    return test_;    
}

std::string Exem::generateID()
{
    int name = unswers_[0]*100 + unswers_[0] * 32 + unswers_[0]*0.43 + unswers_[0]*3;//magic hash
    if(name < 0)
        name *= -1;
    while(name > 1000)
        name /= 10;
    if(number_ == 0)
        name += tasks_[type_] * 1000;
    else 
        name += quantity_ * 1000;
    std::string tmp = std::to_string(name);
    return tmp;
}

std::string Exem::generateTask(std::string name, float &unswer)
{
    std::ifstream file(name);
    if(!file.is_open())
        throw except("Файл с имянем " + name + " не существует");
    int count;
    file >> count;
    if(count == 0)
        throw except("Файл с имянем " + name + " не имеет задач!");
    srand(time(NULL));
    count = 1 + rand() % count;
    for(int i = 0; i < count-1; i++)
    {
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

std::string* Exem::generateTask(std::string name)
{
    std::ifstream file(name);
    if(!file.is_open())
        throw except("Файл с имянем " + name + " не существует");
    int count;
    file >> count;
    if(quantity_ > count)
        throw except("Вы хотите больше задач, чем положено!");//rofl
    if(test_ != nullptr)
        delete [] test_;
    test_ = new std::string[quantity_];
    std::getline(file, test_[0]);//read empty space
    for(int i = 0; i < quantity_; i++)
    {
        std::getline(file, test_[i]);
        file >> unswers_[i];
    }
    file.close();
    return test_;
}

void Exem::writeTest()
{
    std::ofstream file("test" + testId_ + ".txt");
    if(number_ != 0)
        if(type_)
            file << "<<Задачи ЕГЭ номер - " << testId_ << " >>" << std::endl;
        else
            file << "<<Задачи ОГЭ номер - " << testId_ << " >>" << std::endl;    
    else
        if(type_)
            file << "<<Тест ЕГЭ номер - " << testId_ << " >>" << std::endl;
        else
            file << "<<Тест ОГЭ номер - " << testId_ << " >>" << std::endl;    
    for(int i = 0; i < tasks_[type_]; i++)
        file << "Задание номер " << i+1 << std::endl << test_[i] << std::endl << "Ответ: " << std::endl;
    file.close();
}
int Exem::startTest()
{
    return this->startTest(std::cout, std::cin);
}


int Exem::startTest(std::ostream &cout, std::istream &cin)
{   
    int score = 0;
    myUnswers_ = new float[tasks_[type_]];
    for(int i = 0; i < tasks_[type_]; i++)
    {
        if(cin)
        {
            system("clear");
            cout << "<<Тест номер - " << testId_ << " >>" << std::endl;
            cout << "Задание номер " << i+1 << std::endl << test_[i] << std::endl << "Ваш ответ: ";
            cin >> myUnswers_[i];
            system("clear");
        }
        cout << "<<Тест номер - " << testId_ << " >>" << std::endl;
        cout << "Задание номер " << i+1 << std::endl << test_[i] << std::endl << "Ваш ответ: " << myUnswers_[i] << std::endl;
        cout << "Ответ : " << unswers_[i] << std::endl;
        if(myUnswers_[i] == unswers_[i])
        {
            score++;
            cout << "Верно!" << std::endl;
        }
        else
            cout << "Неверно!" << std::endl;
        if(cin)
        {
            cin.ignore(1);//for beauty
            cin.ignore(3,'\n');
            system("clear");
        }
    }
    return score;
}

void checkTest(char *fileName)
{
    Exem *exem = new Exem;
    std::ifstream file(fileName);
    std::string tmp;
    file.ignore(15, '-');
    file >> tmp;
    exem->testId_ = tmp;
    tmp = "uns" + tmp + ".txt";
    tmp.resize(tmp.size() - 3);
    int amount = std::stoi(tmp);
    exem->unswers_ = catchTheUnswer(tmp, amount);
    file.ignore(256, '\n');//first line complete
    exem->test_ = new std::string[amount];
    for(int i = 0; i < amount; i++)
    {
        file.ignore(256, '\n');//first line complete  
        std::getline(file, exem->test_[i]);
        file.ignore(256, ':');
        try
        {
            file >> exem->test_[i];
        }
        catch(const except& e)
        {
            std::cout << "Вы недорешали тест либо неправильно ввели значение\nВернитесь к тесту и дорешайте его!" << '\n';
            delete exem;
            return;
        }
        file.ignore(256, '\n');//добить хaпос
    }
    file.close();
    std::ofstream wFile(fileName);
    exem->startTest(wFile, file);

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


Exem::~Exem()
{
    if(test_ != nullptr)
        delete [] test_;
    if(unswers_ != nullptr)
        delete [] unswers_;
    if(myUnswers_ != nullptr)
        delete [] myUnswers_;
}