#include "Course.h"
#include"ObligatoryCourse.h"
#include"Elective.h"
#include<iostream>
#include"Exception.h"

using namespace std;

Course::Course()
{
    //ctor
}

Course::~Course()
{
    //dtor
}
/*void Course::Print()
{
    cout<<name<<' '<<creditHour<<endl;
}*/
ostream& operator<<(ostream& output,Course& x)
{
    output<<"Coursename: "<<x.name<<"  CreditHour:"<<x.creditHour<<endl;
    if(x.getHaveMark())
    {
        Course *bp=&x;
        ObligatoryCourse *oc=dynamic_cast<ObligatoryCourse*>(bp);
        Elective *ec=dynamic_cast<Elective*>(bp);
        if(oc)
        {
            output<<"The mark is:"<<oc->getScore()<<endl;
        }
        else
        {
            output<<"The grade is:"<<ec->getScore()<<endl;
        }
    }
    return output;
}
