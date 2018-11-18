#include "ObligatoryCourse.h"

ObligatoryCourse::ObligatoryCourse(string n,int c,int m) : Course(n,c)
{
    setMark(m);
}

int ObligatoryCourse::oCreditHour = 0;

void ObligatoryCourse::addOCreditHour(int c)
{
    oCreditHour += c;
}

int ObligatoryCourse::getOCreHour() const
{
    return oCreditHour;
}

void ObligatoryCourse::setMark(int m)
{
    mark = (m > 0)? m:0;
}

int ObligatoryCourse::getMark() const
{
    return mark;
}

int ObligatoryCourse::getScore() const
{
    return mark;
}

ObligatoryCourse::~ObligatoryCourse()
{
    //dtor
}
