#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H
#include <cstring>
#include <iostream>
using namespace std;
class MyException
{
    public:
        MyException(int );
        void print() const;
        virtual ~MyException();

    protected:
    int errornum;
    char* errormessage[4] = {"","日期非法","下标越界","成绩非法"};
    private:
};

#endif // MYEXCEPTION_H
