#ifndef DATEEXCEPTION_H
#define DATEEXCEPTION_H

#include "MyException.h"


class DateException : public MyException
{
    public:
        DateException();
        bool DateExceptionCheck(int,int,int);
        virtual ~DateException();
        DateException(char *);
        DateException(const DateException& other);
        DateException& operator=(const DateException& other);
        const char *what(){return message;}
    protected:
    private:
      const char *message;
};

#endif 
