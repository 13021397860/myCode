#ifndef MYEXCEPTION_H_INCLUDED
#define MYEXCEPTION_H_INCLUDED
#include "date.h"
#include "student.h"
#include "course.h"
class myException
{
private:
    const char *message;
public:
    myException();
    const char *dateException();
    const char *courseException();
    const char *fenshuException();
};


#endif // MYEXCEPTION_H_INCLUDED
