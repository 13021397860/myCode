#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H
enum ExceptionType {Date_wrong,Grade_wrong,Number_wrong};
class MyException
{
    public:
        MyException(ExceptionType et);
        virtual ~MyException();
        const char* what() const;
    protected:

    private:
        ExceptionType wrong;
};

#endif
