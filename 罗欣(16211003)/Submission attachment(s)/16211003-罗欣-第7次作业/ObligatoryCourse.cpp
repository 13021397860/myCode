#include "ObligatoryCourse.h"
#include<iostream>

ObligatoryCourse::ObligatoryCourse()
{
    //ctor
}

ObligatoryCourse::~ObligatoryCourse()
{
    //dtor
}

void ObligatoryCourse::setmark(const int x)
{
    mark=x;
}

int ObligatoryCourse::getScore()const
{
    return mark;
}
