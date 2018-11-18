#include "ObligatoryCourse.h"
#include "Course.h"
ObligatoryCourse::~ObligatoryCourse()
{
    //dtor
}

void ObligatoryCourse::setmark(const int m)
{
    mark=m;
}
int ObligatoryCourse::getScore()const
{
    return mark;
}
