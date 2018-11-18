#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H
#include <iostream>
using namespace std;

class MyException
{
    public:
        MyException();
        MyException(int eyear, int emonth, int eday)
        {
            message="日期错误";
        };
        MyException(int erange)
        {
            message="数组下标错误";
        };
        MyException(string egrade)
        {
            message="成绩错误";
        };
        virtual ~MyException();
        const char* what() const {return message;};
    protected:

    private:
        const char* message;
};

#endif // MYEXCEPTION_H
