#include "ObligatoryCourse.h"

void ObligatoryCourse::setMark(const int m)
{
    mark=m;
    this->setSetSc();
}

int ObligatoryCourse::getScore() const
{
    return mark;
}

ObligatoryCourse::~ObligatoryCourse()
{
    //dtor
}
