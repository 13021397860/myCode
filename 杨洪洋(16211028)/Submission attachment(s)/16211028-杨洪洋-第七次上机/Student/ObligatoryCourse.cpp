//
//  ObligatoryCourse.cpp
//  Student
//
//  Created by apple on 2017/4/11.
//  Copyright © 2017年 apple. All rights reserved.
//

#include "ObligatoryCourse.hpp"
#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
void ObligatoryCourse::setMark(int m)
{
    mark=m;
}
int ObligatoryCourse::getScore()
{
    return mark;
}
void ObligatoryCourse::print()
{
    cout<<left<<setw(20)<<"the obligetorycourse's name:"<<left<<setw(40)<<getname()<<endl;
    cout<<"    this course's score:"<<getCreditHour()<<endl;
}
ObligatoryCourse::~ObligatoryCourse()
{
    
}
ostream& operator <<(ostream &output,ObligatoryCourse &oc)
{
    output<<"CourseName: "<<oc.getname()<<" Kind: "<<" ObligetoryCourse "<<" Credit: "<<oc.getCreditHour()<<" Grade: "<<oc.getScore();
    return output;
}
