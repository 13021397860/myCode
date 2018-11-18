#include "ObligatoryCourse.h"


ObligatoryCourse::~ObligatoryCourse()
{
    //dtor
}

void ObligatoryCourse::setMark(int ma)
{
    if(ma<0 || ma>100){ma=0;throw MyException(score);}
    else mark=ma;
}

