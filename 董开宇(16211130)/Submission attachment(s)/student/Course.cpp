#include "Course.h"
#include <string>
using namespace std;
Course::Course(){}

Course::Course(const string na, const int cre)
{
    name=na;
    creditHour=cre;
}

void Course::setName(const string na)
{
    name=na;
}

void Course::SetCreditHour(const int cre)
{
    creditHour=cre;
}

string Course::getName()const
{
    return name;
}

int Course::GetCreditHour()const
{
    return creditHour;
}

ostream& operator<<(ostream &output, const Course &c)
{
    output<<"Course name: "<<c.getName()<<"    "<<"Course credit: "<<c.GetCreditHour();
    return output;
}

Course::~Course()
{
    //dtor
}
