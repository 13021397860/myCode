#include "Exception.h"

Exception::Exception(ExceptionType et):exceptionType(et)
{
    //ctor
}

Exception::~Exception()
{
    //dtor
}

char* Exception::what() const
{
    switch(exceptionType)
    {
    case DATE_INVALID:
        return "�����������ݲ����ϣ�";
    case RANGE_ERROR:
        return "���뷶Χ���ݲ����ϣ�";
    case SCORE_INVALID:
        return "����ɼ����ݲ����ϣ�";
    default:
        return "";
    }
}
