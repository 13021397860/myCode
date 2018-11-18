#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H


class MyException
{
    public:
        MyException();
        virtual ~MyException();
        //
        const char* what()const{return messages;};

    protected:
        //
    private:
        char *messages;
};

#endif // MYEXCEPTION_H
