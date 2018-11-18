#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H

/**
    枚举类型，表示该系统中可能存在的异常类型
*/
enum ExceptionType {DATE_INVALID, RANGE_ERROR, SCORE_INVALID};
/**
    异常类，记录发生异常时的信息
*/
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
