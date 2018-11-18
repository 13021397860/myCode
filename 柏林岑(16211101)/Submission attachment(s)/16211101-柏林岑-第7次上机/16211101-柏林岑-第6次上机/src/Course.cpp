#include "Course.h"
#include<string>
#include<iostream>
using namespace std;
Course::Course()
{   name="NULL";
	creditHour=0;
}
Course::Course(const string na,const int cr)
{  name=na;
   creditHour=cr;
}
Course::~Course()
{

}
void Course::setname(const string na){
        name=na;
}
string Course::getname()const{
      return name;
}
void Course::setcreditHour(const int cr){
        creditHour=cr;
}
int Course::getcreditHour()const{
     return creditHour;
}

ostream &operator<<(ostream &output,const Course & _Course){
     output<<"Course name :"<<_Course.name<<" creditHour: "<<_Course.creditHour<<" Score: "<<_Course.getScore()<<"\n";
     return output;
}
