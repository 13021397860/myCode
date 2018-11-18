#include "ObligatorayCourse.h"

ObligatorayCourse::ObligatorayCourse(const string _name,int _creditHour):Course(_name,_creditHour)
{
    mark = 0;
}

ObligatorayCourse::~ObligatorayCourse()
{
    //dtor
}
int ObligatorayCourse::getscore()const{
    return mark;
}
int ObligatorayCourse::setgrade(int _grade){
    if(_grade<0 ||_grade >100) throw -2;
    mark = _grade;
    return 1;
}
