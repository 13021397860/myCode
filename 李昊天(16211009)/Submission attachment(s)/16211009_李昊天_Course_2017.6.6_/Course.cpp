#include "Course.h"
#include<iostream>
#include<string>
#include<sstream>
using namespace std;

Course::Course()
{

}

Course::Course(string na,int cre)
{
    setName(na);
    setCreditHour(cre);
}

Course::~Course()
{
    //dtor
}

void Course::setName(string na)
{
    name=na;

}

void Course::setCreditHour(int cre)
{
    creditHour=cre;
}
/*
void Course::print()
{
    cout<<"Course name:\n";
    cout<<name<<endl;
    cout<<"Course type:\n";
    cout<<courseType<<endl;
    cout<<"Course Credit Hour:\n";
    cout<<creditHour<<endl;
    /*cout<<"Course Score:\n";
    cout<<getScore()<<endl;
}
*/
ostream& operator<<(ostream& os,Course& p){
    os<<p.toString();
    return os;
}

string Course::toString()
{
    string ch,ch1;
    int a=getScore();
    stringstream chs,chs1;
    chs << creditHour;
    chs >> ch;
    chs1 << a;
    chs1 >> ch1;
    return "Course Type:"+courseType+"  Course Name:"+name+"  "+"Course Credit Hour:"+ch+"  Score:"+ch1;
}
