#include <iostream>
using namespace std;
#include "ObligatoryCourse.h"
ObligatoryCourse::ObligatoryCourse(string n,int c,int m):Course(n,c)
{
    mark=m;
}
/*
ObligatoryCourse::ObligatoryCourse(Course c,int m)
{
    name=c.getName();
    creditHour=c.getcreditHour();
    mark=m;
}*/
void ObligatoryCourse::CoursePrint()const{
    cout<<getName()<<" "<<getcreditHour()<<" "<<getScore()<<endl;
}
