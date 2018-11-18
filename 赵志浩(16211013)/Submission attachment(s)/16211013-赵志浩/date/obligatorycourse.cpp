#include "obligatorycourse.h"

ObligatoryCourse::ObligatoryCourse(string n,int c,int m):Course(n,c)
{
    this->mark=m;
}
ObligatoryCourse::ObligatoryCourse(const ObligatoryCourse &a):Course(a.name,a.creditHour)
{
    this->mark=a.mark;
}
ObligatoryCourse::~ObligatoryCourse()
{
    //dtor
}
