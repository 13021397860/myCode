//
//  ElectiveCourse.hpp
//  Student
//
//  Created by apple on 2017/4/11.
//  Copyright © 2017年 apple. All rights reserved.
//

#ifndef ElectiveCourse_hpp
#define ElectiveCourse_hpp

#include <stdio.h>
#include "Course.hpp"
#include <string>
using namespace std;
class ElectiveCourse:public Course
{
public:
    ElectiveCourse();
    ElectiveCourse(const string &n,const int &ch):Course(n,ch)
    {
    }
    ElectiveCourse(const string &n,const int &ch,const char gr):Course(n,ch)
    {
    }
    friend ostream& operator <<(ostream &,ElectiveCourse &);
    void setgrade(const char &gr);
    int getScore();
    void print();
    void printf();
    virtual ~ElectiveCourse();

private:
    char grade;//等级
};
#endif /* ElectiveCourse_hpp */
