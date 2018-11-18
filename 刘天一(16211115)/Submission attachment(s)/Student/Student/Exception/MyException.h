//
// Created by 76743 on 2017/5/30.
//

#ifndef STUDENT_MYEXCEPTION_H
#define STUDENT_MYEXCEPTION_H

enum ExceptionType{DATE_ERROR,RANGE_ERROR,GRADE_ERROR};
class MyException {
public:
    MyException(ExceptionType et):exceptionType(et) {}
    virtual ~MyException(){}
    const char* what() const ;
private:
    ExceptionType exceptionType;
};


#endif //STUDENT_MYEXCEPTION_H
