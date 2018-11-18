#include "ObligatoryCourse.h"
#include<iostream>
#include"Course.h"
using namespace std;

ObligatoryCourse::ObligatoryCourse(string cname, int hour, int ma):Course(cname,hour)
{
    setMark(ma);
}

ObligatoryCourse::~ObligatoryCourse()
{
    //dtor
}

void ObligatoryCourse::setMark(int m)
{
    mark=m;
}

int ObligatoryCourse::getScore()
{
    return mark;
}
