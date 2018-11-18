#include "ObligatoryCourse.h"
#include"Course.h"
#include<string>
#include<iostream>
using namespace std;

int ObligatoryCourse::getScore() const
{
    return mark;
}
ObligatoryCourse::~ObligatoryCourse()
{
    //dtor
}
void ObligatoryCourse::setMark(int grade)
{
    mark = grade;
}
void ObligatoryCourse::print()const
{
    cout<<"±ØÐÞ:";
    //Course::print();
}
