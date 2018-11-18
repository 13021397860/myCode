#include "ObligatoryCourse.h"

ObligatoryCourse::ObligatoryCourse( string a,int b, int c):
    Course(a,b),mark(c)
{
    //ctor
}

int ObligatoryCourse::getScore() const
{
    return mark;
}

void ObligatoryCourse::setScore( int b )
{
    mark = b;
}
string ObligatoryCourse::toString() const
{
    return name;
}
ObligatoryCourse::~ObligatoryCourse()
{
    //dtor
}
