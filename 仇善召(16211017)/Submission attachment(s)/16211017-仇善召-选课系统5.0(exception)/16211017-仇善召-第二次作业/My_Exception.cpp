#include "My_Exception.h"

My_Exception::My_Exception()
{
    //ctor
}
My_Exception::My_Exception( int t )
{
    record = t;
}
const char* My_Exception::what() const
{
    switch (record)
    {
    case 1:
        return "���ڷǷ�������������";

    case 2:
        return "��ŷ�Χ��������������";

    case 3:
        return "�ɼ���������������";
    default:
        return "";

    }
}
My_Exception::~My_Exception()
{
    //dtor
}
