#include "Course.h"
#include<iostream>
#include<cstring>
using namespace std;
Course::Course(const string s,const int x)
{
	setname(s);
	setCreditHour(x);
}
string Course::getname() const
{
	return name;
}
int Course::getCreditHour() const
{
	return creditHour;
}
void Course::setCreditHour(const int x)
{
	creditHour=x;
}
void Course::setname(const string s)
{
	name=s;
}
ostream& operator<<(ostream& output,const Course& c)
{
	output<<"�γ���:"<<c.getname()<<" "<<"ѧ��:"<<c.getCreditHour()<<" "<<"�ɼ�:"<<c.getScore()<<endl;
	return output;
}
Course::~Course()
{
}
