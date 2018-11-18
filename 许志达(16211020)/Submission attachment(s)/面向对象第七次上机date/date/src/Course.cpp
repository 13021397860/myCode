#include "Course.h"
#include<iostream>
using namespace std;
Course::Course()
{

}
Course::Course(const string &n,int creditHour)
{
    name=n;
    setcreditHour(creditHour);
    //ctor
}
void Course::setname(string n)
{
    name=n;
}
void Course::setcreditHour(int c)
{
    creditHour=(c>0&&c<=4)?c:0;
}
int Course::getcreditHour()const
{
    return creditHour;
}
/*void Course::print()const
{
    cout<<"COURENAME:"<<name<<"\nCREDITOUR:"<<creditHour<<endl;
}*/
void Course::setScore(int s)
{
    Score=(s>=0&&s<=100)?s:-1;
}
void Course::setScore(char s)
{
    Score=((int)s>=65&&(int)s<=90)?s:'w';
}
void Course::setmark(int j)
{
    mark=(j>=0&&j<=100)?j:0;
}
int Course::getmark()
{
    return mark;
}
int Course::getScore()
{
    return Score;
}
ostream & operator<<(ostream & output,const  Course &c)
{
    output<<"COURENAME:"<<c.name<<"  CREDITOUR:"<<c.creditHour<<"  score:"<<c.mark<<endl;
}
Course::~Course()
{
    //dtor
}
