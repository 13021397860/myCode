#include "obligatorycourse.h"

ObligatoryCourse::ObligatoryCourse()
{
    //ctor
}

ObligatoryCourse::~ObligatoryCourse()
{
    //dtor
}
void ObligatoryCourse::setMark(const int m)
{
    mark=m;
}
void ObligatoryCourse::setCreditCard(const int credit)
{
    Course::setCreditCard(credit);
}
void ObligatoryCourse::setName(const string &s)
{
    Course::setName(s);
}
int ObligatoryCourse::getScore()
{
    return mark;
}
