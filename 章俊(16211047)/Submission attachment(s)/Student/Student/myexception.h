#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H

enum MyExceptionType {DATE_INVALID, RANGE_ERROR,SCORE_INVALID};
class MyException
{
    public:
        MyException(MyExceptionType e);
        virtual ~MyException();
        virtual const char* what() const;
    protected:

    private:
        MyExceptionType ex;
};

#endif // MYEXCEPTION_H
