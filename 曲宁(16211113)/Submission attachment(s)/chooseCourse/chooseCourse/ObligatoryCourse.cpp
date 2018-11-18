#include "ObligatoryCourse.h"

ObligatoryCourse::ObligatoryCourse(int m,const string& n,int k):Course(n,k)
{
    setScore(10,m);
}

void ObligatoryCourse::setScore(int q,int m)
{
    mark=m;
}

 int ObligatoryCourse::getScore()const
{
    return mark;
}

int ObligatoryCourse::print()const
{
    cout<<getScore()<<endl;
}

ObligatoryCourse::~ObligatoryCourse()
{
    //dtor
}
