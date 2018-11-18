#include "Course.h"

Course::Course(string nam,int ch)
{
    setname(nam);
    setcredithour(ch);
}

Course::~Course()
{
    //cout<<1;
}
void Course::setname(string nam)
{
        name=nam;
}
void Course::setcredithour(int ch)
{
    creditHour=ch;
}
string Course::getname()
{
    return name;
}
int Course::getcredithour()
{
    return creditHour;
}
 void Course::setscore(int)
{

}
 int Course::getscore()
{

}
void Course::toString()
{

}

