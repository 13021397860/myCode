#include "MyException.h"

MyException::MyException()
:BEmessage("异常处理机制朝你抛了一个媚眼：你输入了错误的日期类型！")
,CEmessage("异常处理机制朝你抛了一个媚眼：你输入了错误的课程编码！")
,GEmessage("异常处理机制朝你抛了一个媚眼：你输入了错误的成绩类型！")
{

}

MyException::~MyException()
{

}
