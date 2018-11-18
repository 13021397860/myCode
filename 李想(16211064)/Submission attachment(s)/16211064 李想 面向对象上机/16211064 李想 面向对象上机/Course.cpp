#include "Course.h"

#include<bits/stdc++.h>

using namespace std;

Course::Course()
{
	name="";
	creditHour=0;
}

Course::Course(Course& a)
{
    name=a.name;
    creditHour=a.creditHour;
}

Course::Course(string& _name,int& _creditHour):name(_name),creditHour(_creditHour)
{
    name=_name;
    creditHour=_creditHour;
}
void Course::setname(string _name)
{
    name=_name;
}

void Course::setcreditHour(int _creditHour)
{
    if(_creditHour<0)
        _creditHour=1;
    else
    creditHour=_creditHour;
}

string Course::getname()
{
    return name;
}

int Course::getcreditHour()
{
    return creditHour;
}

Course::~Course()
{
    //dtor
}

ostream& operator<<(ostream& output,const Course& c)
{
	output<<"课程名："<<c.name<<"\t"<<"学分："<<c.creditHour;
	return output;
}

int Course::setScore(int)
{
	return 0;
}

int Course::setScore(char)
{
	return 0;
}
