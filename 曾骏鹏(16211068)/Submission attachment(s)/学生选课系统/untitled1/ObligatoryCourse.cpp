//
// Created by zjp on 2017/4/17.
//

#include "ObligatoryCourse.h"

void ObligatoryCourse::setMark(const int m)
{
    mark=m;
}

int ObligatoryCourse::getScore() const
{
    return mark;
}

ObligatoryCourse::ObligatoryCourse(string s, int cHour):course(s,cHour) {}

ObligatoryCourse::~ObligatoryCourse() {}