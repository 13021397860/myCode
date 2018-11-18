#include "course.h"
#include<iostream>
#include<string>
using namespace std;

course::course()
{

}
//course::course(const course &co)
//{
//    name=co.name;
//    creditHour=co.creditHour;
//}
course::course(const string &n,const int &c)
{
    setname(n);//ctor
    setcred(c);
}

void course::setname(const string &n)
{
    name=n;
}

void course::setcred(const int &c)
{
    creditHour=c;
}

course::~course()
{
    //dtor
}

ostream& operator<<(ostream& out,const course &x)
{
    out<<"课程名："<<x.getname()<<"      "<<"学分："<<x.getcred()<<"      "<<"成绩："<<x.getscore()<<endl;
    return out;
}

