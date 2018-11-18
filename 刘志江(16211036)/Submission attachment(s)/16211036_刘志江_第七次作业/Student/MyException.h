#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H


class MyException
{
    public:
        MyException(const char *m):message(m){};
        virtual ~MyException();
        const char *what() const {return message;}

    protected:

    private:
        const char *message;
};

#endif // MYEXCEPTION_H
