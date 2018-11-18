#include "ObligatoryCourse.h"

void ObligatoryCourse::setMark(const int m)
{
    mark = m;
}

int ObligatoryCourse::getScore() const
{
    return mark;
}

ObligatoryCourse::~ObligatoryCourse()
{
    //dtor
}
