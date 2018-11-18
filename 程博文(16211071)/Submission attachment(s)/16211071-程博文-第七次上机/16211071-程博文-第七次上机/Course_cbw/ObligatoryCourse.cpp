#include "ObligatoryCourse.h"

ObligatoryCourse::ObligatoryCourse()
{
    //ctor
    mark=100;
}

ObligatoryCourse::~ObligatoryCourse()
{
    //dtor
}

void ObligatoryCourse::setMark(int _mark)
{
    mark=_mark;
}

int ObligatoryCourse::getScore() const
{
    return mark;
};
