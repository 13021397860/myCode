#ifndef DATEEXCEPTION_H
#define DATEEXCEPTION_H
#include "myException.h"

class DateException : public MyException
{
    public:
        DateException();
        bool DateExceptionCheck(int,int,int);
        virtual ~DateException();
        DateException(char *);
        DateException(const DateException& other);
        
    private:
      const char *message;
};

#endif
