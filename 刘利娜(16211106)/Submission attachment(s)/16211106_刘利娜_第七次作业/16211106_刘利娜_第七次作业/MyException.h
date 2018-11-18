#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H

enum Type{date,student,gra};
class MyException
{
    public:
        MyException(Type e);
        virtual ~MyException();
        const char* what() const;
    protected:

    private:
        Type T;
};

#endif // MYEXCEPTION_H
