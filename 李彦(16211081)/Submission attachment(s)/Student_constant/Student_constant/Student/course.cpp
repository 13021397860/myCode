#include "course.h"
#include<iostream>
using std::ostream;
using std::string;
using std::cout;
using std::endl;
course::course()
{
    name="cplusplus";
    creditHour=0;//ctor
}

course::course(string n,int c)
{
    set_(n,c);
}

course::~course()
{
    cout<<this->getName()<<endl;
    cout<<"course is destroyed"<<endl;//dtor
}

string  course:: getName() const
{
    return name;
}

int course::getCredit() const
{
    return creditHour;
}

void course::set_(string n,int c)
{
    name=n;
    creditHour=c;
}


ostream &operator<<(ostream &os,const course &course_)
{
    os<<"course name:"<<course_.name<<"   credit:"<<course_.creditHour<<"   score:"<<course_.getScore()<<endl;
}
