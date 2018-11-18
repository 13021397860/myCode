#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H
#include <stdexcept>
#include "Date.h"
using namespace std;
class MyException
{
    public:
        MyException();
        void testdate(Date);
        void testunder(int);
        void testsc(int);
        void testgrade(char);
        virtual ~MyException();

    protected:

    private:
};

#endif // MYEXCEPTION_H
