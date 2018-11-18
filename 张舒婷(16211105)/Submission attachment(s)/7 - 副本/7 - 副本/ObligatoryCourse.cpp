#include "ObligatoryCourse.h"
#include "MyException.h"

ObligatoryCourse::ObligatoryCourse(string name_,int creditHour_)
    :Course(name_,creditHour_)
{

}

ObligatoryCourse::~ObligatoryCourse()
{
    //dtor
}

void ObligatoryCourse::setMark(int mark_)
{
    if((mark_>=0&&mark_<=100))
        mark=mark_;
    else throw MyException(SCORE_INVALID);
}
