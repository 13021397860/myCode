#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H
#include "date.h"

class MyException
{
    public:
        MyException();
        void excDate(Date dt);
        void excCrsO(int cs);
        void excCrsE(char cs);
        void excStd(int sd);
        bool da;
        bool ob;
        bool el;
        bool st;
        virtual ~MyException();
        MyException(const MyException& other);

    protected:

    private:
};

#endif // MYEXCEPTION_H
