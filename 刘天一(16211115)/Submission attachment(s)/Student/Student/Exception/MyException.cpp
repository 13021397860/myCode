//
// Created by 76743 on 2017/5/30.
//

#include "MyException.h"
#include <iostream>

const char* MyException::what() const {
    switch (exceptionType) {
        case DATE_ERROR:return "Date Error!\n";break;
        case RANGE_ERROR:return "Range Error!\n";break;
        case GRADE_ERROR:return "Grade Error!\n";break;
        default:return " ";
    }
}
