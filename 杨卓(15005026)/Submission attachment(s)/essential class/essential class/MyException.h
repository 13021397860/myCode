#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H


enum Exceptiontype{
    DATE_INVALID,RANGE_ERROR,SCORE_INVALID
};

class MyException
{
    public:
        MyException(Exceptiontype et);
        virtual ~MyException();
        const char * what() const;
    protected:

    private:
        Exceptiontype ext;
};

#endif // MYEXCEPTION_H
