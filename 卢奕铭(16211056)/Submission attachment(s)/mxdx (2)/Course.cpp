#include"Course.h"
#include<iostream>
#include<string>
using namespace std;

Course::Course()
{

}

Course::Course(string n,int c)
{
	Name=n;
	credithour=c;
}

Course::~Course()
{
}

int Course::getCourse(string &s, int &h)const
{
    s = Name;
    h = credithour;
    return 1;
}

Course::setCourse(string n,int c)
{
	Name=n;
	credithour=c;
}
ostream& operator << (ostream& output,Course& c)
{
   output<<"Name: "<<c.Name<<" Credit: "<<c.credithour<<" Mark: "<<c.getScore()<<endl;

   return output;
}

string Course::getName()const
{
	return Name;
}

int Course::getCreditHour()const
{
	return credithour;
}

int Course::setName(string n)
{
	Name=n;
}

int Course::setCreditHour(int c)
{
	credithour=c;
}
