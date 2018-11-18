#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H
#include<iostream>

class MyException
{
    public:
        MyException();
        MyException(std::string);
        MyException(const MyException &);
        virtual ~MyException();
        std::string what();

    protected:

    private:
        std::string exceptionInfor;
};

#endif // MYEXCEPTION_H
