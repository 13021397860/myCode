#include "Course.h"
#include<iostream>
using namespace std;
Course::Course()
{
}
Course::Course(const string &a,const int b)
{
	name=a;
	creditHour=b;
}
Course::~Course()
{
}
void  Course::setCreditHour(int a)
{
	 creditHour=a;  
}
string Course::setName(string a)
{
	  name=a;
}
string  Course::getName()const
{
	return name;
}
int Course::getCreditHour()const
{
	return creditHour;
}
ostream &operator <<( ostream & out,const Course & a)
{
	out<<"  Course£º"<<a.getName()<<" CreditHour£º"<<a.getCreditHour();
       if(a.getScore()==-1)
          out<<"     NO Score£¡"<<endl;
		 else 
		 out<<"      Score£º  "<<a.getScore()<<endl; 
}

