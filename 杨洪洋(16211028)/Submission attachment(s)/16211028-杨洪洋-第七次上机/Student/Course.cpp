//
//  Course.cpp
//  Student
//
//  Created by apple on 2017/4/11.
//  Copyright © 2017年 apple. All rights reserved.
//

#include "Course.hpp"
#include<iostream>
#include<string>
using namespace std;
Course::Course(const string name,int credithour)
{
    coursename=name;
    setCreditHour(credithour);
}
void Course::setname(const string &n)
{
    //coursename=n;
}
void Course::setCreditHour(const int &ch)
{
    creditHour=ch;
}
string Course::getname()
{
    return this->coursename;
}
int Course::getCreditHour()
{
    return creditHour;
}
 void Course::print()
{
    cout<<"the course is:"<<getname()<<endl;
    cout<<"the creditHour is:"<<getCreditHour()<<endl;
}
Course::Course()
{
    
}
Course ::~Course()
{
    
}
ostream& operator <<(ostream &output,Course &course)
{
    output<<"CourseName: <"<<course.coursename<<"> Credit: <"<<course.creditHour<<">"<<" Grade: "<<course.getScore()<<endl;
    return output;
}
