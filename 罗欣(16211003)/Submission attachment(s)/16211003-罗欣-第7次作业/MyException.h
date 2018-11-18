#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H
#include"ObligatoryCourse.h"
#include"ElectiveCourse.h"
#include"Course.h"
#include"Date.h"
#include"Student.h"
#include<string>

class MyException
{
    public:
        MyException(int);
        virtual ~MyException();
        void ThrowException();

        void DateException(Date);
        void CourseNumException(int,Student *);
        void GradeException(int);

    protected:

    private:
        int ExceptionType;
};

#endif // MYEXCEPTION_H
