#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H

class MyException
{
    public:
        MyException(const char *mes):message(mes){};
        virtual ~MyException();
        const char *what() const{return message;};
    protected:

    private:
        const char *message;
};

#endif // MYEXCEPTION_H
