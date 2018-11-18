#ifndef DATEEXCEPTION_H
#define DATEEXCEPTION_H

#include "MyException.h"


class DateException: public MyException
{
    public:
        DateException();
        bool DateExceptionCheck(int,int,int);
        const char *what(){return message;}
        virtual ~DateException();
    protected:
    private:
      const char *message;
};

#endif // DATEEXCEPTION_H
