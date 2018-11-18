//
// Created by zjp on 2017/5/28.
//

#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H

#include <iostream>
#include <exception>
#include "date.h"
#include "student.h"
using namespace std;

enum ExceptionType {DATE_INVALID,RANGE_ERROR,SCORE_INVALID};

class myException
{
public:
    myException(ExceptionType et);
    virtual ~myException();
    virtual const char* what() const;
private:
    ExceptionType exceptionType;
};


#endif //MYEXCEPTION_H

/*
（1.1）设计异常处理类MyException，记录异常代码和异常消息，能否分布表示日期类、学生类和课程类中的异常信息

（1.2）主要的异常信息应至少包括：构造日期时，如果输入的日期信息非法，则抛出日期非法的异常；
 访问学生类中的所选的课程，如果下标访问越界则抛出下标越界异常；设置学生成绩时，如果课程成绩非法，则抛出成绩非法的异常

（2）在实验6编写Console类中

（2.1）添加异常处理机制，捕获和处理异常信息
 */