#include "MyException.h"

MyException::MyException(ExceptionType et):eType(et)
{
    //ctor
}

MyException::~MyException()
{
    //dtor
}

const char* MyException::err() const
{
    switch(eType)
    {
    case DATE_INVALID:
        return "���ڲ��Ϸ���";
    case RANGE_INVALID:
        return "�ɼ����Ϸ���";
    case SCORE_INVALID:
        return "�ɼ����Ϸ���";
    default:
        return "";
    }
}
