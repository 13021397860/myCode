#include <iostream>
#include "course.h"
#include "electiveCourse.h"
#include "obligatoryCourse.h"
#include <string>
#include <typeinfo>
#include <cstdlib>
using namespace std;

course::course(const string _name,const int _hour)
{
    name=_name;
    creditHour=_hour;
}
course::course()
{

}
course::~course()
{

}
void course::setName(const string _name)
{
    name=_name;
}
void course::setHour(const int _hour)
{
    creditHour=_hour;
}
void course::setCourse(const string _name,const int _hour)
{
    name=_name;
    creditHour=_hour;
}
const string course::getName() const
{
    return name;
}
const int course::getHour() const
{
    return creditHour;
}
void course::getCourse() const
{
    cout<<"Name: "<<this->name<<"    "<<"CreditHour: "<<this->creditHour<<endl;
}
ostream operator<<(ostream &cout,const course &c)
{
    cout<<"name: "<<c.getName()<<"credit hour: "<<c.getHour()<<">"<<endl;
}
