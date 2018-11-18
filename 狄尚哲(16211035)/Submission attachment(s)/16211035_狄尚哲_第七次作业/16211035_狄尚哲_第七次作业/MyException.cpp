#include "MyException.h"

/*
    DATE_INVALID:
        throw: Date::setDate()
        catch: Console::CreateStudent()
    RANGE_ERROR:
        throw: Student::setGrade()
        catch: Console::setGrade()
    SCORE_INVALID:
        throw: ObligatoryCourse::setScore(), ElectiveCourse::setScore()
        catch: Student::setGrade()
*/


MyException::MyException(ExceptionType e)
{
    ex = e;
    //ctor
}

MyException::~MyException()
{
    //dtor
}

const char* MyException::what() const{
    switch(ex){
    case DATE_INVALID:
        return "输入日期不合法!";
    case RANGE_ERROR:
        return "选择异常!";
    case SCORE_INVALID:
        return "输入成绩不合法!";
    }
}
