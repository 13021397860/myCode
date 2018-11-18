#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H

enum ExceptionType {DATE_INVALID, RANGE_INVALID, SCORE_INVALID};

class MyException
{
    public:
        MyException(ExceptionType et);
        const char* err() const;
        virtual ~MyException();

    protected:

    private:
        ExceptionType eType;
};

#endif // MYEXCEPTION_H
