#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H


class MyException
{
    public:
        MyException(const char* m):message(m){};
        const char* what()const
                        {return message;};
        virtual ~MyException();

    protected:

    private:
        const char* message;
};

#endif // MYEXCEPTION_H
