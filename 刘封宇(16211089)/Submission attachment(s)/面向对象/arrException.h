#ifndef ARREXCEPTION_H
#define ARREXCEPTION_H
#include "myException.h"

class ArrException : public MyException
{
    public:
        ArrException();
        bool ArrExceptionCheck(int,int,bool);
        virtual ~ArrException();
        ArrException(char *);
        ArrException(const ArrException& other);
    protected:
    private:
      const char *message;
};

#endif
