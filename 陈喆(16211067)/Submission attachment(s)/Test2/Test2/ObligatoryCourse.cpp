#include "ObligatoryCourse.h"

ObligatoryCourse::ObligatoryCourse(const string a,const int b)
{
    SetName(a);
    SetCreditHour(b);
    mark=0;
    //ctor
}
ObligatoryCourse::ObligatoryCourse(ObligatoryCourse&A)
{
    SetName(A.GetName());
    SetCreditHour(A.GetCreditHour());
    SetMark(A.getScore());
}
ObligatoryCourse::~ObligatoryCourse()
{
    //dtor
}

void ObligatoryCourse::SetMark(const int m)
{
    mark=m;
}

int ObligatoryCourse::getScore()
{
    return mark;
}
