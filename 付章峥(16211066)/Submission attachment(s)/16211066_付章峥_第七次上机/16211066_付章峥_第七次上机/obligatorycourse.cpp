#include "obligatorycourse.h"
#include "course.h"
#include<iostream>
#include<string>

using namespace std;

//constructor
ObligatoryCourse::ObligatoryCourse(const string n,const int c,const int m)//ctor
{
    setObligatoryCourse(n,c,m);//set OC
}//end constructor

//set value of obligatoryCourse
void ObligatoryCourse::setObligatoryCourse(const string n,const int c,const int m)
{
    setCourse(n,c);
    setMark(m);
}//end function setObligatoryCourse

//set score of obligatoryCourse
void ObligatoryCourse::setMark(const int m)
{
    mark = m;
}//end function setMark

//get value of score
int ObligatoryCourse::getScore()const
{
    return mark;
}//end function getScore

//copy constructor
ObligatoryCourse::ObligatoryCourse(const ObligatoryCourse& other)//copy ctor
{
    setObligatoryCourse(other.name,other.creditHour,other.mark);
}//end copy

//destructor
ObligatoryCourse::~ObligatoryCourse()//dtor
{

}//end destructor
