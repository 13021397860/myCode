#ifndef EXCEPTION_H
#define EXCEPTION_H

enum ExceptionType{Date_Invalid,Grade_Invalid,Range_Invalid};
class Exception
{
    public:
        Exception(ExceptionType et);
        virtual ~Exception();
        char* what() const;
    protected:

    private:
        ExceptionType exceptiontype;
};

#endif // EXCEPTION_H
