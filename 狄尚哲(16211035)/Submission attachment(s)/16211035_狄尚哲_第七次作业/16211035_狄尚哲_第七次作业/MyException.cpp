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
        return "�������ڲ��Ϸ�!";
    case RANGE_ERROR:
        return "ѡ���쳣!";
    case SCORE_INVALID:
        return "����ɼ����Ϸ�!";
    }
}
