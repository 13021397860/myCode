#include "Course.h"
#include <iostream>
#include <iomanip>
using namespace std;

Course::Course(string newname , int grade )
{
    SetCoursename(newname);
    SetCreditHour(grade);
    //ctor
}

void Course::SetCoursename(string newname)
{
    name = newname;
}

void Course::SetCreditHour(int grade)
{
    creditHour = (grade > 0)? grade: 0;
}

const string Course::GetCoursename()
{
    return name;
}

const int Course::GetCreditHour()
{
    return creditHour;
}


Course::~Course()
{
    //cout << "delete\n";
    //dtor
}

ostream &operator<<( ostream &output, const Course& c)
{
    output << "Course name:"<< std::left<< setw(15)<< c.name<< " Credit hour:" <<c.creditHour;
    output << " Score: "<< c.getScore()<<endl;
    return output;
}
