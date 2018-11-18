#include "electivecourse.h"
#include "course.h"
#include<iostream>
#include<string>

using namespace std;

//constructor
ElectiveCourse::ElectiveCourse(const string n,int c,const char g)//ctor
{
    setElectiveCourse(n,c);//set EC
    setGrade(g);
}//end constructor

//set electiveCourse
void ElectiveCourse::setElectiveCourse(const string n,const int c,const char g)
{
    setCourse(n,c);
    setGrade(g);
}//end function setElectiveCourse

//set grade of electiveCourse
void ElectiveCourse::setGrade(const char g)
{
    grade = g;
}//end function setGrade

char ElectiveCourse::getGrade()const
{
    return grade;
}

//get value of grade
int ElectiveCourse::getScore()const
{
    switch(grade)
    {
    case 'A':
        return 95;
    case 'B':
        return 85;
    case 'C':
        return 75;
    case 'D':
        return 65;
    case 'E':
        return 55;
    default:
        return 0;
    }
}//end function getGrade

//copy constructor
ElectiveCourse::ElectiveCourse(const ElectiveCourse& other)//copy ctor
{
    setElectiveCourse(other.name,other.creditHour,other.grade);
}//end copy

//destructor
ElectiveCourse::~ElectiveCourse()//dtor
{

}//end destructor
