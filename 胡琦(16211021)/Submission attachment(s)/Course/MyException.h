#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H
#include "date.h"

enum ExceptionType {DATE_ILLEGAL, RANGE_ERROR, SCORE_ILLEGAL};

class MyException
{
    public:
        MyException(ExceptionType et);
        const char* what() const;
        virtual ~MyException();
    protected:
    private:
        ExceptionType exceptionType;
};

#endif // MYEXCEPTION_H
