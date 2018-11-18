#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H


class MyException
{
    public:
        MyException();
        virtual ~MyException();
        const char* what1() const {return message1;}
        const char* what2() const {return message2;}
        const char* what3() const {return message3;}
    protected:
    private:
        const char *message1;
        const char *message2;
        const char *message3;
};

#endif // MYEXCEPTION_H
