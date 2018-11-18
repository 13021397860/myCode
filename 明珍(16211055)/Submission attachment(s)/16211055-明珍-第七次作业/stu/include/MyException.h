#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H

#include<string>
using namespace std;
class MyException
{
    public:
        MyException(const string &info):info(info){

        };
        virtual ~MyException();

        string info;
    protected:

    private:
};

#endif // MYEXCEPTION_H
