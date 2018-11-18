#include "ObligatoryCourse.h"
#include <iostream>
using namespace std;

ObligatoryCourse::ObligatoryCourse(const string &s,const int x,const int m)
:Course(s,x)
{
    setGrade(m,'w');//ctor
}

void ObligatoryCourse::setGrade(const int m,const char n)
{
    mark=m;
}

int ObligatoryCourse::getScore()const
{
    return mark;
}

void ObligatoryCourse::print1()
{
    cout<<mark<<endl;
}
ObligatoryCourse::~ObligatoryCourse()
{
    //dtor
}
