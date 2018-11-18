#include "ElectiveCourse.h"
#include<string>
#include"MyException.h"
using namespace std;
ElectiveCourse::ElectiveCourse()
{
    //ctor
}
ElectiveCourse::ElectiveCourse(string a,int b)
{
    name=a;
    gred=b;
}
ElectiveCourse::~ElectiveCourse()
{
    //dtor
}
void ElectiveCourse::setScore(int s)
{
    if(s>100||s<0)
        throw(MyException(3));
    if(s>=90)
    {
        grade='A';
    }
    else if(s>=80)
    {
        grade='B';
    }
    else if(s>=70)
    {
        grade='C';
    }
    else if(s>=60)
    {
        grade='D';
    }
    else
    {
        grade='E';
    }

}
int ElectiveCourse::getScore()
{
    if(grade=='A')
    {
        return 95;
    }
    else if(grade=='B')
    {
        return 85;
    }
    else if(grade=='C')
    {
        return 75;
    }
    else if(grade=='D')
    {
        return 65;
    }
    else
    {
        return 55;
    }
}
