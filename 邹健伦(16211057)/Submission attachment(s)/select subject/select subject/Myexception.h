#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H
#include"student.h"

class Myexception
{
    public:
        Myexception();
        void datewrong(student*);
        void setgradewrong();
        void counumwrong();
        virtual ~Myexception();

    protected:

    private:
};

#endif // MYEXCEPTION_H
