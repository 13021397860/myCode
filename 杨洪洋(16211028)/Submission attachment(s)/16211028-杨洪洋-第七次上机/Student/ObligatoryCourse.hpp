//
//  ObligatoryCourse.hpp
//  Student
//
//  Created by apple on 2017/4/11.
//  Copyright © 2017年 apple. All rights reserved.
//

#ifndef ObligatoryCourse_hpp
#define ObligatoryCourse_hpp
#include "Course.hpp"
#include <stdio.h>
class ObligatoryCourse:public Course
{
public:
    ObligatoryCourse();
    ObligatoryCourse(const string &n,const int &ch):Course(n,ch)
    {
        mark=0;
    }
    ObligatoryCourse(const string &n,const int &ch,const int m):Course(n,ch)
    {
        mark=m;
    }
    void setMark(int m);
    int getScore();
    void printf();
    void print();
    friend ostream& operator <<(ostream &,ObligatoryCourse &);
    virtual ~ObligatoryCourse();
private:
    int mark;//必修课程成绩
};
#endif /* ObligatoryCourse_hpp */
