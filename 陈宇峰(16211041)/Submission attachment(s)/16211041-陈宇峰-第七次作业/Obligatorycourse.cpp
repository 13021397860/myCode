#include "Obligatorycourse.h"
#include "Myexception.h"
#include <iostream>

ObligatoryCourse::ObligatoryCourse()
{
    mark=0;
}

void ObligatoryCourse::setmark(const int _mark)
{
    if (!(_mark>=0&&_mark<=100))
        throw MyException(SCORE_INVALID);
    mark=_mark;
}

int ObligatoryCourse::getScore() const
{
    return mark;
}
