#include "course.h"
#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

//Course constructor
Course::Course(const string n,const int c)//ctor
{
    setCourse(n,c);//set Course
}//end constructor

//set Course
void Course::setCourse(const string n,const int c)
{
    name = n;//validate name
    creditHour=c;//validate credit
}//end function setCourse

//get name
string Course::getName()const
{
    return name;
}//end function getName

//get credit
int Course::getCredit()const
{
    return creditHour;
}//end function getCredit

ostream &operator<<(ostream &opt,const Course *s)
{
    opt<<"课程名称："<<left<<setw(15)<<s->getName()<<"学分："<<left<<setw(5)<<s->getCredit()<<"成绩："<<s->getScore();
    return opt;
}

//copy constructor
Course::Course(const Course& other)//copy ctor
{
    setCourse(other.name,other.creditHour);
}

//destructor
Course::~Course()//dtor
{

}//end destructor
