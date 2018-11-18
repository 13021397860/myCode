#include "obligatorycourse.h"
#include "course.h"

ObligatoryCourse::ObligatoryCourse( string str, int cre, int x, double w ) : Course( str, cre )
{
    mark = x;
    weight = w;
    //ctor
}
ObligatoryCourse::~ObligatoryCourse()
{
    //dtor
}

void ObligatoryCourse::setGrade( int x )
{
    mark = x;
}

int ObligatoryCourse::getScore() const
{
    return mark;
}

double ObligatoryCourse::getWeight() const
{
    return weight;
}
