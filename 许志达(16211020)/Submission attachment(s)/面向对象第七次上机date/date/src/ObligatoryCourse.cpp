#include "ObligatoryCourse.h"
#include<iostream>
using namespace std;
ObligatoryCourse::ObligatoryCourse()
{

}
ObligatoryCourse::ObligatoryCourse(const string & n,int creditHour,int m):Course(n,creditHour)
{
    setmark(m);
    //ctor
}
void ObligatoryCourse::setmark(int m)
{
    mark=(m>=0&&m<=100)?m:0;
}
int ObligatoryCourse::getScore()
{
    return mark;
}
void ObligatoryCourse::print()const
{
    cout<<name<<":"<<creditHour<<":"<<mark<<endl;
}
//void ObligatoryCourse::setCourse(const string & a,int b)
//{
  //  Course::Course(const string &a,int b);
//}
ObligatoryCourse::~ObligatoryCourse()
{
    //dtor
}
