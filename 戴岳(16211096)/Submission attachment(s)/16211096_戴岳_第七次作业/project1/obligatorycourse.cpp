#include "obligatorycourse.h"
#include <iomanip>
using namespace std;

ObligatoryCourse::ObligatoryCourse()
{
    mark=0;
    //ctor
}

ObligatoryCourse::ObligatoryCourse(const string n,const int h):Course(n,h)
{
    mark=0;
}

ObligatoryCourse::ObligatoryCourse(const string n,const int h,int x):Course(n,h)
{
    mark=x;
}

void ObligatoryCourse::setScore(int m)
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
