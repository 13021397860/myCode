#include "ObligatoryCourse.h"

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
    if(mark_<=100&&mark_>=0)
        mark=mark_;
    else
    {
        throw MyException(gra);
    }
}
