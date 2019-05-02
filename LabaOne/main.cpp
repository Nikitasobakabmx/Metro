#include <iostream>
#include <string>
#include "Task.h"
#include "Test.h"


int main(int argc, char **argv)
{
    bool outPut;
    if(argc > 1)
    {
        system("clear");
        chekTest(argv[1]);
        std::cout << "Программа завершена";
        return 0;
    }
    system("clear");
    setlocale(LC_ALL, "Russian");
    std::string choose;
    Task exem = {1, 2, 1, 0};
    std::cout << "Выберите где будете решать в консоли(0) или в текстовом файле(1)" << std::endl;
    std::cin >> outPut;
    // while(true)
    // {
    //     std::cout << "Выберите ОГЭ или ЕГЭ" << std::endl;
    //     std::cin >> choose;
    //     if(choose == "ОГЭ" || choose == "ЕГЭ" || choose == "егэ" || choose == "огэ")
    //     {
    //         if(choose == "ОГЭ" || choose == "огэ")
    //             exem = setExem(false, outPut);
    //         else
    //             exem = setExem(true, outPut);
    //         break;
    //     }
    //     std::cout << "Вы ввели что то не то" << std::endl;         
    // }

    std::string *test = generateTest(exem);
    if(exem.io = 0)
        chekTest(startTest(test), test);
    else
    {
        writeTest(test);
        std::cout << "Решите тест внутри файла и запустите программу еще раз, указав название файла в качестве параметра" << std::endl;
    }
    std::cout << "Программа завершена";
    return 0;
}