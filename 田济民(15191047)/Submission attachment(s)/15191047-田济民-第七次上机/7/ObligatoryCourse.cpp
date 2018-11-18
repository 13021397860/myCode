#include "ObligatoryCourse.h"
#include"MyException.h"
ObligatoryCourse::ObligatoryCourse()
{
    //ctor
}
ObligatoryCourse::ObligatoryCourse(string a,int b)
{
    name=a;
    grehour=b;
}
ObligatoryCourse::~ObligatoryCourse()
{
    //dtor
}
bool ObligatoryCourse::setMark(int mk)
{
    mark=mk;
    return true;
}
int ObligatoryCourse::getMark()
{
    return mark;
}
void ObligatoryCourse::setScore(int x)
{
    if(mark>100||mark<0)
        throw(MyException(3));
    mark=x;
}
int ObligatoryCourse::getScore()
{
    return mark;
}
