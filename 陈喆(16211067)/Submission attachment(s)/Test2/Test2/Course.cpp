#include "Course.h"

Course::Course(const string a,const int b)
{
    SetCreditHour(b);
    SetName(a);
    //ctor
}

Course::~Course()
{
    //dtor
}

int Course::GetCreditHour() const
{
    return creditHour;
}

string Course::GetName() const
{
    return name;
}

bool Course::SetCreditHour(const int b)
{
    if(b<0)
    {
        creditHour=0;
        return 0;
    }
    creditHour=b;
    return 1;
}

bool Course::SetName(const string a)
{
    name=a;
    return 1;
}

ostream & operator << (ostream &output,Course &x)
{
    output<<"  course name: "<<setw(25)<<left<<x.GetName();
    output<<" credit hour: "<<x.GetCreditHour()<<" ";
    return output;
}
