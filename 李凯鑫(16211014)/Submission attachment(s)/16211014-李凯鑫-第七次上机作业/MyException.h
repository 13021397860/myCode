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
            message="���ڴ���";
        };
        MyException(int erange)
        {
            message="�����±����";
        };
        MyException(string egrade)
        {
            message="�ɼ�����";
        };
        virtual ~MyException();
        const char* what() const {return message;};
    protected:

    private:
        const char* message;
};

#endif // MYEXCEPTION_H
