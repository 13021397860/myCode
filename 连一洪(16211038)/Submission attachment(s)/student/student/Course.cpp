#include "Course.h"
#include <cstring>
#include <iostream>

using namespace std;
using std::ostream;
Course::Course(){

}
Course::Course(const string na, const int cr)
{
    setcourseName(na);
    setCreditHour(cr);
}

Course::~Course()
{
    //dtor
}

string Course::getName()const{
    return name;
}

int Course::getCreditHour()const{
    return creditHour;
}

void Course::setcourseName(const string na){
    name=na;
}

void Course::setCreditHour(const int cre){
    creditHour=cre;
}

ostream& operator<<(ostream& output, Course &c){
    output<<"The course name: "<<c.name<<"          The course credit: "<<c.creditHour<<" "<<"        Your course score: "<<c.getscore()<<" ";
    return output;
}
