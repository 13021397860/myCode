#include "ObligatoryCourse.h"
#include "Course.h"
#include <iostream>
#include <cstring>
#include <typeinfo>
using namespace std;

ObligatoryCourse::ObligatoryCourse(){

}
ObligatoryCourse::ObligatoryCourse(const string na, const int cr):Course(na,cr)
{
    setcourseName(na);
    setCreditHour(cr);
    mark=0;
    //ctor
}

ObligatoryCourse::~ObligatoryCourse()
{
    //dtor
}

int ObligatoryCourse::getscore()const{
    return getScore();
}

void ObligatoryCourse::setMark(const int ma){
    mark=ma;
}

int ObligatoryCourse::getScore()const{
    return mark;
}
