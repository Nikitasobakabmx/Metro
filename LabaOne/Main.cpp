#include <iostream>
#include <fstream>
#include <string>
#include "Exem.h"
#include "except.h"
//#include "Ansvers.h"
        


// Exem* setExem();

// Exem* setExem(bool flag, bool outPut)
// {
//     std::string tmp;
//     while(true)
//     {
//         std::cout << "Веберите конкретное задание или тест" << std::endl;
//         std::cin >> tmp;
//         if(tmp == "задание" || tmp == "конкретное задание")
//         {
//             int Num;
//             std::cout << "Выберите номер задания" << std::endl;
//             std::cin >> Num;
//             if(Num > tasks[flag] || Num <= 0)
//             {
//                 std::cout << "Вы ввели что то не то" << std::endl;
//                 continue;
//             }
//             std::cout << "Выберите колличество задания данного номера" << std::endl;
//             int quan; //quantity
//             std::cin >> quan;
//             if(quan <= 0)
//             {
//                 std::cout << "Вы ввели что то не то" << std::endl;
//                 continue;
//             }
//             Task exem(flag, Num, quan, outPut); 
//             return exem;
//         }
//         if(tmp == "тест")
//         {
//             Task exem(flag, 0, 1, outPut); 
//             return exem;
//         }
//         std::cout << "Вы ввели что то не то" << std::endl;
//         continue;
//     }
// }


int main(int argc, char **argv)
{
    //bool outPut;
    if(argc == 2)
    {
        system("clear");
        checkTest(argv[1]);
        std::cout << "Программа завершена";
        return 0;
    }
    system("clear");
    setlocale(LC_ALL, "Russian");
    std::string choose;
    Exem * exem = new Exem(1, 0, 1, 0);
    std::cout << "Выберите где будете решать в консоли(0) или в текстовом файле(1)" << std::endl;
    std::cin >> exem->output_;
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
    exem->generateTest();
    if(!exem->output_)
    {
        int score = exem->startTest();
        std::cout << "Ваш результат : " << score;
        std::cout << "\\" << exem->tasks_[exem->type_] << std::endl;        
    }
    else
    {
        exem->writeTest();
        std::cout << "Решите тест внутри файла test" << exem->testId_ <<  ".txt и запустите программу еще раз, указав название файла в качестве параметра" << std::endl;
    }
    std::cout << "Программа завершена" << std::endl;
    return 0;
}
