//
//  ElectiveCourse.cpp
//  Student
//
//  Created by apple on 2017/4/11.
//  Copyright © 2017年 apple. All rights reserved.
//

#include "ElectiveCourse.hpp"
#include <iostream>
#include<iomanip>
using namespace std;

void ElectiveCourse::setgrade(const char &gr)
{
    grade=gr;
}
int ElectiveCourse::getScore()
{
    switch (grade) {
        case 'A':
            return 95;
            break;
        case 'B':
            return 85;
            break;
        case 'C':
            return 75;
            break;
        case 'D':
            return 65;
            break;
        case 'E':
            return 55;
            break;
        default:
            break;
    }
    return 0;
}
void ElectiveCourse::print()
{
    cout<<left<<setw(20)<<"the electivecourse's name:"<<left<<setw(40)<<getname()<<endl;
    cout<<"    this course's score:"<<getCreditHour()<<endl;
}
ElectiveCourse::~ElectiveCourse()
{
    
}
ostream& operator <<(ostream &output,ElectiveCourse &ec)
{
    output<<"CourseName: "<<ec.getname()<<" Kind:  "<<"ElectiveCourse "<<"   Credit: "<<ec.getCreditHour()<<" Grade: "<<ec.getScore();
    return output;
}
