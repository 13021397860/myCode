#ifndef ARREXCEPTION_H
#define ARREXCEPTION_H

#include "MyException.h"


class ArrException: public MyException
{
    public:
        ArrException();
        bool ArrExceptionCheck(int,int);
        const char *what(){return message;}
        virtual ~ArrException();
    protected:
    private:
      const char *message;
};

#endif // DATEEXCEPTION_H
