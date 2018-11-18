#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H

/**
    ö�����ͣ���ʾ��ϵͳ�п��ܴ��ڵ��쳣����
*/
enum ExceptionType {DATE_INVALID, RANGE_ERROR, SCORE_INVALID};
/**
    �쳣�࣬��¼�����쳣ʱ����Ϣ
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

