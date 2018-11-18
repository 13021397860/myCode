#include "ElectiveCourse.h"
#include<iostream>
#include<string>
#include"Course.h"
using namespace std;

int ElectiveCourse::getScore()const
{
    switch(grade)
    {
        case 'A':return 95;
        case 'B':return 85;
        case 'C':return 75;
        case 'D':return 65;
        case 'E':return 55;
    }
}
ElectiveCourse::~ElectiveCourse()
{
    //dtor
}
void ElectiveCourse::setGrade(const char s)
{
    grade = s;
}
const int ElectiveCourse::getGrade()const
{
    switch(grade)
    {
        case 'A':return 95;break;
        case 'B':return 85;break;
        case 'C':return 75;break;
        case 'D':return 65;break;
        case 'E':return 55;break;
        default:return 0;
    }
}
void ElectiveCourse::print()const
{
    cout<<"Ñ¡ÐÞ:";
    //Course::print();
}
