#include "ObligatoryCourse.h"

ObligatoryCourse::ObligatoryCourse(const string s,
    const int n,const int m) : Course(s,n)
{
    setScore(m);
}

void ObligatoryCourse::setScore(const int &m)
{
    mark=m;
}

int ObligatoryCourse::getScore() const
{
    return mark;
}


ObligatoryCourse::~ObligatoryCourse()
{
    //dtor
}
