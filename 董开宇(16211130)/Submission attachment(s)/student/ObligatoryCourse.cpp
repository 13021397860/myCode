#include "ObligatoryCourse.h"

ObligatoryCourse::ObligatoryCourse()
{
    //ctor
}

ObligatoryCourse::ObligatoryCourse(int ma)
{
    mark=ma;
}

void ObligatoryCourse::setMark(int ma)
{
    mark=ma;
}

int ObligatoryCourse::getScore()
{
    return mark;
}
ObligatoryCourse::~ObligatoryCourse()
{
    //dtor
}
