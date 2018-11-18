#include "MyException.h"

MyException::MyException()
{
    //ctor
}
const char* MyException::DateError()
{
    return "Date Error!";
}

const char* MyException::CourseError()
{
    return "Course Error!";
}

const char* MyException::ScoreError()
{
    return "Score Error!";
}

MyException::~MyException()
{
    //dtor
}
