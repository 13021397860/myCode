//
// Created by zjp on 2017/5/28.
//

#include <exception>
#include "myException.h"
using namespace std;

myException::myException(ExceptionType et) {
    exceptionType=et;
}

myException::~myException() {}

const char* myException::what() const {
    switch(exceptionType)
    {
        case DATE_INVALID:
            return "输入日期有误，请检查日期合法性后重新输入：";
            break;
        case RANGE_ERROR:
            return "输入课程序号有误，请检查课程数后重新输入：";
            break;
        case SCORE_INVALID:
            return "输入课程成绩有误，请检查当前课程待定成绩范围后重新输入：";
            break;
    }
}