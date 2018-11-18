#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H
#include<iostream>
#include<cstring>
#include<iomanip>
#include<fstream>
#include<strstream>
#include<typeinfo>
using namespace std;

class MyException
{
    public:
        MyException():DE("The Data is illegal!"),SE("The course is illegal!"),CE("The grade is illegal!"){};
        virtual ~MyException();
        const char* whatD(){return DE;}
        const char* whatS(){return SE;}
        const char* whatC(){return CE;}

    protected:

    private:
        const char *DE;
        const char *SE;
        const char *CE;
};

#endif // MYEXCEPTION_H
