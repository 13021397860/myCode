#ifndef COURSEEXCEPTION_H
#define COURSEEXCEPTION_H

#include "MyException.h"


class CourseException : public MyException
{
    public:
        CourseException();
        bool CourseException_check_1(int);
        bool CourseException_check_2(char);
        CourseException(char *);
        virtual ~CourseException();
        CourseException(const CourseException& other);
        CourseException& operator=(const CourseException& other);
        const char *what(){return message;}
    protected:
    private:
        const char *message;
};

#endif 
