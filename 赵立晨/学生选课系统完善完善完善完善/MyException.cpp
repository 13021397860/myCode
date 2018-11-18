#include "MyException.h"

MyException::MyException()
{
    //ctor
}
MyException::MyException(ExceptionType et):exceptionType(et)
{
    //ctor
}

MyException::~MyException()
{
    //dtor
}

const char* MyException::what()const
{
    switch(exceptionType)
    {
        case DATE_INVALID:
            return "���ڴ���!����������~";
        case RANGE_ERROR:
            return "���ڷ�Χ��!����������~~";
        case SCORE_INVALID:
            return "�ɼ��������!����������~";
        default:
            return "��������,���Բ����~~";
    }
}
