#ifndef COURSEEXCEPTION_H
#define COURSEEXCEPTION_H

#include "myException.h"


class CourseException : public MyException
{
    public:
        CourseException();
		CourseException(char *);
        bool CourseExceptionCheck(int);
        bool CourseExceptionCheck(char);
        
        virtual ~CourseException();
        CourseException(const CourseException& other);
       
    private:
        const char *message;
};

#endif
