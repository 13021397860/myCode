#include "Course.h"
#include<string>
#include<iostream>
#include<iomanip>

using namespace std;

Course::Course(string _name, int _creditHour):name(_name),creditHour(_creditHour)
{

}

Course::~Course()
{
    //dtor
}
string Course::getname() const {
    return name;
}
int Course::getcreditHour()const {
    return creditHour;
}
int Course::setcreditHour(int _creditHour){
    creditHour = _creditHour;
    return 1;
}
ostream &operator << (ostream &output,const Course &x){
    output <<setw(30)<<left<< x.name <<setw(15)<<left<< x.creditHour << x.getscore();
    return output;
}
