#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H

enum ExceptionType{DATE_INVALID,RANGE_ERROR,SCORE_INVALID};

class MyException
{
    public:
        MyException(ExceptionType et);
        virtual ~MyException();
        const char* what() const;

    private:
        int myexceptiontype;
        //const char* message;
};

#endif // MYEXCEPTION_H
