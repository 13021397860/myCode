#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H

enum ExceptionType{DATE_INVALID, RANGE_ERROR, SCORE_INVALID};

class MyException
{
    public:
        MyException(ExceptionType e);
        virtual ~MyException();
        const char* what() const;

    protected:

    private:
        ExceptionType ex;
};

#endif // MYEXCEPTION_H
