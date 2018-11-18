#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H
#include <cstdio>

class MyException
{
    public:
        MyException():s("Exception:"){};
        void wtfOfDate()const;
        void wtfOfCourse()const;
        void wtfOfGrade()const;
        //virtual ~MyException();

    //protected:
    private:
        const char *s;
};

#endif // MYEXCEPTION_H
