#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H
#include<string>
#include"Date.h"

using std::string;

class MyException
{
    public:
        MyException(string _name,string _msg,Date &_date);
        MyException(string _msg);
        void InfoError();
        void LoadError();
        void SingleError();
        virtual ~MyException();
    private:
        string name;
        string msg;
        Date birthday;
};

#endif // MYEXCEPTION_H
