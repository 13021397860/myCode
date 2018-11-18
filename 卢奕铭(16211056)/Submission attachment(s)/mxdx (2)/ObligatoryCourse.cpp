#include "ObligatoryCourse.h"

ObligatoryCourse::ObligatoryCourse()
{
    //ctor
}

ObligatoryCourse::ObligatoryCourse(const string s, const int h, const int m):Course(s, h)
{
    mark = m;
}

ObligatoryCourse::~ObligatoryCourse()
{
    //dtor
}

int ObligatoryCourse::setMark(const int m)
{
    mark = m;
    return 1;
}

int ObligatoryCourse::getScore()const
{
    return mark;
}
