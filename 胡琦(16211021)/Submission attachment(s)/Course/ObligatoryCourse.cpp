using namespace std;
#include "ObligatoryCourse.h"
#include "MyException.h"

ObligatoryCourse::ObligatoryCourse()
{
    //ctor
}

void ObligatoryCourse::setScore(const int m)
{
    if(m>100||m<0)
        throw MyException(SCORE_ILLEGAL);
    else
        mark=m;
}

ObligatoryCourse::~ObligatoryCourse()
{
    //dtor
}
