#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H


class MyException
{
    public:
        MyException()
        :wrong("wrong!"){};
        const char* what() const {return wrong;};
        virtual ~MyException();
    protected:
    private:
        const char* wrong;
};

#endif // MYEXCEPTION_H
