#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H
#include<iostream>
#include<string>
using namespace std;

class MyException
{
    public:
        MyException()
        :message("WRONG£¡£¡"){};
        const char* what()const
        {
            return message;
        }
        int getWrong(int i)
        {
           cout<<ex[i]<<endl;
        }
        virtual ~MyException();

    protected:

    private:
        const char* message;
        string ex[3]={"WRONG DATE","WRONG ID","WRONG GRADE"};
};

#endif // MYEXCEPTION_H
