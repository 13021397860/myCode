#include <iostream>
using namespace std;
#include "Course.h"
#ifndef OBLIGATORY_H
#define  OBLIGATORY_H
class ObligatoryCourse :public Course
{
private:
    int mark;
public:
    virtual int getScore()const{return mark;}
    void setMark(int m){mark=m;}
    ObligatoryCourse(string n="NoFound",int c=0,int m=0);
    void CoursePrint()const;
 //   ObligatoryCourse(Course c,int m);
    ~ObligatoryCourse(){}
};
#endif // OBLIGATORY_H

