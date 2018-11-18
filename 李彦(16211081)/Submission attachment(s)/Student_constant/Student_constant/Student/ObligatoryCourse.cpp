#include "ObligatoryCourse.h"
#include<iostream>
using std::cout;
using std::string;
using std::endl;
using std::cin;
ObligatoryCourse::ObligatoryCourse()
{
    //ctor
}

ObligatoryCourse::ObligatoryCourse(string n, int c,int m)
{
    name=n;
    creditHour=c;
    mark=m;
    //ctor
}

ObligatoryCourse::~ObligatoryCourse()
{

}

void ObligatoryCourse::set_(string n,int c,int m)
{
    course::set_(n,c);;
    mark=m;
}

int ObligatoryCourse::getMark()
{
    return mark;
}


void ObligatoryCourse::print()
{
    cout<<"coursename:"<<name<<" creditHour:"<<creditHour<<" mark:"<<mark<<endl;
}
void ObligatoryCourse::setChengji(int m,char ch)
{
    mark=m;
}

int ObligatoryCourse::getScore() const
{
    return mark;
}
