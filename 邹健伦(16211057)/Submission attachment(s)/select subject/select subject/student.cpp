#include "student.h"
#include"Date.h"
#include<iostream>
#include<cstring>
#include"obligatorycourse.h"
#include"electivecourse.h"
#include"typeinfo"
#include"course.h"
#include<fstream>
#include<cstdlib>
#include"Myexception.h"
using namespace std;

int student::count=0;
student::~student()
{
    cout<<"the student "<<name<<" has been destoryed"<<endl;//dtor
}

student::student(const student &t)
{
    name=t.name;
    birthdate=t.birthdate;
    coursenumber=0;
    calccredit=0;
}
student::student(const char*const q,const int &y,const int &m,const int &d)
{
    setname(q);
    setdate(y,m,d);
    coursenumber=0;
    count++;
}
void student::setdate(const int &y,const int &m,const int &d)
{
    birthdate.setdate(y,m,d);
}
char *student::getname()const
{
    return name;
}
int student::getyear()const
{
    return birthdate.getyear();
}
int student::getmonth()const
{
    return birthdate.getmonth();
}
int student::getday()const
{
    return birthdate.getday();
}
void student::nextday()
{
    birthdate.nextday();
}
void student::setname(const char*const p)
{
    name=new char;
    strcpy(name,p);
};
//student& student::addcourse(const string &n,int c)
//{
//    if(coursenumber<MAX_SIZE)
//   {
//     courselist[coursenumber]=new course(n,c);
//        coursenumber++;
//    }
 //   return (*this);
//}

student& student::addcourse(course*course)
{
    if(coursenumber<MAX_SIZE)
    {
        courselist[coursenumber]=course;
        coursenumber++;
    }
    return (*this);
}

course& student::getcourse(int i)const
{
    return *courselist[i];
}
ostream& operator<<(ostream& out,const student &x)
{
    ofstream outfile("student information.txt",ios::app);
    if(!outfile)
    {
        cerr<<"file could not be opened"<<endl;
        exit(1);
    }
    outfile<<"学生姓名："<<x.getname()<<"       "<<"出生日期："<<x.birthdate<<"，选课信息如下："<<endl;
    for(int i=0;i<x.coursenumber;i++)
    {
        outfile<<*x.courselist[i];
    }
    return out;
}
void student::print()const
{
    cout<<"学生姓名："<<getname()<<"       "<<"出生日期："<<birthdate<<"，选课信息如下："<<endl;
    for(int i=0;i<coursenumber;i++)
    {
        cout<<*courselist[i];
    }
}
/*ostream& operator<<(ostream& out,const student &x)
{
    out<<"学生姓名："<<x.getname()<<"       "<<"出生日期："<<x.birthdate<<"，选课信息如下："<<endl;
    for(int i=0;i<x.coursenumber;i++)
    {
        out<<*x.courselist[i];
    }
    return out;
}*/
/*ostream& operator<<(ostream& out,const student &x)
{
    out<<"学生姓名："<<x.getname()<<"       "<<"出生日期："<<x.birthdate<<"，选课信息如下："<<endl;
    for(int i=0;i<x.coursenumber;i++)
    {
        if(typeid(obligatorycourse)==typeid(*x.courselist[i]))
        {
            out<<dynamic_cast<obligatorycourse&>(*x.courselist[i]);
        }
        else if(typeid(electivecourse)==typeid(*x.courselist[i]))
        {
            out<<dynamic_cast<electivecourse&>(*x.courselist[i]);
        }
        else
        {
            out<<*x.courselist[i];
        }
    }
    return out;
}*/
bool student::removecourse(int i)
{
    if(i>=0&&i<=coursenumber-1)
    {
        for(int j=i;j<=coursenumber-2;j++)
        {
            courselist[j]=courselist[j+1];
        }
        courselist[coursenumber-1]=NULL;
        coursenumber--;
        return true;
    }
    else
    {
        throw Myexception();
    }
}
/*void student::calculate()
{
    double sum1,sum2,total1,total2;
    sum1=sum2=total1=total2=0;
    for(int i=0;i<coursenumber;i++)
    {
        if(typeid(obligatorycourse)==typeid(*courselist[i]))
        {
            sum1+=(dynamic_cast<obligatorycourse&>(*courselist[i]).getcred())*(dynamic_cast<obligatorycourse&>(*courselist[i]).getscore());
            total1+=dynamic_cast<obligatorycourse&>(*courselist[i]).getcred();
        }
        else if(typeid(electivecourse)==typeid(*courselist[i]))
        {
            sum2+=dynamic_cast<electivecourse&>(*courselist[i]).getscore();
            total2++;
        }
        sum1=sum1/total1;
        sum2=sum2/total2;
        calccredit=0.6*sum1+0.4*sum2;
    }
}*/
void student::calculate()
{
    double sum1,sum2,total1,total2;
    sum1=sum2=total1=total2=0;
    for(int i=0;i<coursenumber;i++)
    {
        if(typeid(obligatorycourse)==typeid(*courselist[i]))
        {
            sum1+=(courselist[i]->getcred())*(courselist[i]->getscore());
            total1+=courselist[i]->getcred();
        }
        else if(typeid(electivecourse)==typeid(*courselist[i]))
        {
            sum2+=courselist[i]->getscore();
            total2++;
        }
    }
    sum1/=total1;
    sum2/=total2;
    calccredit=0.6*sum1+0.4*sum2;
}
double student::getcalc()
{
    calculate();
    return calccredit;
}
