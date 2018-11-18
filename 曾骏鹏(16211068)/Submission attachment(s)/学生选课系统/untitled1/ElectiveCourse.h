//
// Created by zjp on 2017/4/17.
//

#include "course.h"

#ifndef ELECTIVECOURSE_H
#define ELECTIVECOURSE_H


class ElectiveCourse : public course
{
public:
    ElectiveCourse(string s,int cHour);
    virtual ~ElectiveCourse();
    void setGrade(const char);
    virtual int getScore() const;
private:
    char grade;
};


#endif //ELECTIVECOURSE_H
