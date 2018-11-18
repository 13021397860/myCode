#include "ObligatoryCourse.h"
#include <iostream>
#include <cstring>
using namespace std;
ObligatoryCourse::ObligatoryCourse(string A,double cH,int t,double m):Course(A,cH,1)
{
    setScore(m);
    //ctor
}

ObligatoryCourse::~ObligatoryCourse()
{
    //dtor
}

void ObligatoryCourse::setScore(double m)
{
    mark=m;
}

double ObligatoryCourse::getScore()
{
    return (double)mark;
}
