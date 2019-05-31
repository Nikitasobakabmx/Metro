#pragma once 
#include <string>

class Exem
{
    private:
        std::string *test_ = nullptr;//
        float *unswers_ = nullptr;//
        float *myUnswers_ = nullptr;//

    public:
        std::string testId_;//
        int tasks_[2];
        bool type_;//ОГЭ - 0/ ЕГЭ - 1
        int number_;// 0 for all
        int quantity_;//колличество заданий каждого типа
        bool output_;//0 - console / 1 - text file
        Exem(){};
        Exem(bool a, int b, int c, bool d) : type_(a), number_(b), quantity_(c), output_(d){tasks_[0] = 20; tasks_[1] = 12;};
        /***********************************************
        * generate test, put it to string array(test_) *
        * return string array(test_)                   *
        ***********************************************/
        std::string* generateTest();
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
        /*********************************
        * start test in console          *
        * return float array(myUnswers_) *
        *********************************/
        int startTest();
        int startTest(std::ostream &cout, std::istream &cin);
        /*****************************
        * check test in console      *
        * take your unswer           *
        * compress with truth unswer *
        * return result              *
        *****************************/
        //int checkTest();//union with startTest()
        /*******************************
        * catch truth unswers for test *
        *******************************/
        friend void checkTest(char *fileName);
        /********************************
        * read file with unswer         *
        * read file with your unswer    *
        * rewrite file with your unswer *
        * add result to file            *
        ********************************/
        
        ~Exem();
};