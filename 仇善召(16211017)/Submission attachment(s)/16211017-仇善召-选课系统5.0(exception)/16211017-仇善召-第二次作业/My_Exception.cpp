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
        return "日期非法，请重新输入";

    case 2:
        return "编号范围有误，请重新输入";

    case 3:
        return "成绩有误，请重新输入";
    default:
        return "";

    }
}
My_Exception::~My_Exception()
{
    //dtor
}
