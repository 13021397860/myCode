#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H

enum ExceptionType{DATE_INVALID, RANGE_ERROR, SCORE_INVALID};

class MyException
{
    public:
        MyException(ExceptionType et);
        virtual ~MyException();
        virtual const char* what() const;
    private:
        ExceptionType exceptionType;
};

#endif // MYEXCEPTION_H
