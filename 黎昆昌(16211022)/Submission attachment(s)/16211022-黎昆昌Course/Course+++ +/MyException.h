#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H

enum ExceptionType {DATE_INVALID, RANGE_ERROR, SCORE_INVALID, NOT_DIGIT};

class MyException
{
    public:
        MyException(ExceptionType et);
        virtual ~MyException();
        const char* what() const;
    protected:

    private:
        ExceptionType exceptionType;
};

#endif // MYEXCEPTION_H
