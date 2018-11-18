#include "ObligatoryCourse.h"

ObligatoryCourse::ObligatoryCourse()
{
    mark = -1;
    //ctor
}

ObligatoryCourse::~ObligatoryCourse()
{
    //dtor
}

void ObligatoryCourse::setScore(int a)
{
    mark = a;
}

int ObligatoryCourse::getScore()const{
    return mark;
}
