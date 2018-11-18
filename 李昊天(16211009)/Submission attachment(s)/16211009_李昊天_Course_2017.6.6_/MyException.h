#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H

enum err{range, date, score};

class MyException
{
    public:
        MyException(err er):e(er){};
        MyException& operator= (const MyException&) throw();
        virtual ~MyException() {};
        const char* what();
    protected:

    private:
        err e;
};

#endif // MYEXCEPTION_H
