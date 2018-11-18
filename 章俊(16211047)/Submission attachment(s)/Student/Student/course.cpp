#include "course.h"
#include <iostream>
#include<string>
using namespace std;
using std::ostream;
using std::istream;
Course::Course(const string n,const int c)
{
    //ctor
    setCourse(n,c);
}
Course::~Course()
{
    //dtor
}
Course::Course(const Course &c)
{
    name=c.name;
    creditHour=c.creditHour;
}
void Course::setCourse(const string n,const int c)
{
    name=n;
    creditHour=c;
}
int Course::getcreditHour()const
{
    return creditHour;
}
string Course::getname()const
{
    return name;
}

ostream& operator << (ostream& output,Course& c)
{
    output<<"coursename: "<<c.getname()<<"    credit: "<<c.getcreditHour()<<"   score: "<<c.getScore();
    return output;
}



int Course::getObligatoryCredit() const
{
    return creditHour;
}
int Course::getObligatoryNumber() const
{
    return 1;
}
 int Course::getElectiveNumber() const
{
    return 1;
}


