#include "student.h"
#include"date.h"
#include "ElectiveCourse.h"
#include "Course.h"
#include"Console.h"
#include "ObligatoryCourse.h"
#include<string.h>
#include<iostream>
using namespace std;
int student::Count=0;
int student::getcount()
{
    return Count;
}
student::student(const char * const s,int y,int m,int d):birthdate(y,m,d)
{
    ++Count;
    name=new char[25];
    strcpy(name,s);
}
student::student(const student &t):birthdate(t.birthdate)
{
    name=new char[strlen(t.name)+1];
    strcpy(name,t.name);
    birthdate=t.birthdate;
}
student::~student()
{
    --Count;
     delete name;
    //dtor
}
char *student::getname()
{
    return name;
}
date student::getbirthdate()
{
    return birthdate;
}
void student::setbirthdate(int y,int m,int d)
{
    birthdate.setdate(y,m,d);
}
void student::setname(char*s)
{
    delete name;
    if(s==NULL)
    {
        cout<<"wrong name"<<endl;
        name=new char [25];
    char newname1[25]="jack";
    strcpy(name,newname1);
    }
    else if(strlen(s)>25)
    {
        cout<<"long name"<<endl;
         name=new char [25];
    char newname2[25]="john";
    strcpy(name,newname2);
    }
    else
    {
    name=new char[strlen(s)+1];
    strcpy(name,s);
    }

}
student& student::addCourse(Course *b)
{
    if(b==NULL)
        cout<<"Error"<<endl;
    else if(courseNumber>=MAX_SIZE)
        cout<<"FULL"<<endl;
    else
    {
        courseList[courseNumber]=b;
        courseNumber++;
    }
    return *this;
}
bool student::removeCourse(int i)
{
    if(i>courseNumber)
        return 0;
    delete courseList[i-1];
    for(int j=i;j<courseNumber;j++)
    {
        courseList[j-1]=courseList[j];
    }
    courseNumber--;
    return 1;
}
student&student ::addCourse(const string &Coursename,int credithour)
{

}
/*void student::print()
{
    cout<<"学生名字："<<name<<endl;
   //birthdate.print_ymd();
    cout<<birthdate<<endl;
}*/
/*double student::calcCredit()
{
    double sum1=0,sum2=0,sum3=0,sum4=0;
    Console d;
   for(int j=1;j<=d.c1;j++)
   {
       sum1+=d.chengji[j]*d.xuefeng[j];
       sum3+=d.xuefeng[j];
   }
   for(int j=1;j<=d.c2;j++)
   {
       sum2+=d.chengji[j]*d.xuefeng[j];
       sum4+=d.xuefeng[j];
   }
   if(sum3!=0&&sum4!=0)
   {
       gpa=0.6*sum1/sum3+0.4*sum2/sum4;
   }
   else
   {
       gpa=1;
   }
   return gpa;
}*/
ostream &operator<<(ostream & output,const student &c)
{
    output<<"姓名:"<<c.name<<"  "<<c.birthdate<<"选课信息如下:"<<endl;
}
