#include "ObligatoryCourse.h"

ObligatoryCourse::ObligatoryCourse(int ch,string nam,int m) :Course(nam,ch)
{
    setscore(m);
}

ObligatoryCourse::~ObligatoryCourse()
{
    //dtor
}
void ObligatoryCourse::setscore(int m)
{
   score=m;
}
int ObligatoryCourse::getscore()
{
    return score;
}
