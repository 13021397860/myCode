#ifndef SETEXCEPTION_H
#define SETEXCEPTION_H

#include "MyException.h"


class SetException: public MyException
{
    public:
        SetException();
        bool SetExceptionChecki(int);
        bool SetExceptionCheckc(char);
        const char *what(){return message;}
        virtual ~SetException();
    protected:
    private:
      const char *message;
};

#endif // DATEEXCEPTION_H
