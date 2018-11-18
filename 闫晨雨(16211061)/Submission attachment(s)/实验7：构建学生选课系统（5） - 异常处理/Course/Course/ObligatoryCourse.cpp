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
    if(m < 0 || m > 100)
        throw MyException(SCORE_INVALID);
    mark = m;
    return 1;
}

int ObligatoryCourse::getScore()const
{
    return mark;
}
