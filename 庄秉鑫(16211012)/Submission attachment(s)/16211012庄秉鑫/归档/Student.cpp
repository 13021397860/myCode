//
//  Student.cpp
//  Student
//
//  Created by Pirate Hero on 17/3/24.
//  Copyright © 2017年 mac. All rights reserved.
//

#include "Student.hpp"
#include <mm_malloc.h>
#include <iostream>
#include <string.h>
using namespace std;

Student::~Student()
{
    free(name);
}
void Student::set(long int l,char*g)
{
    length=l;
   name=(char*) malloc(l+1);
    strcpy(name,g);
   // birthdate.setDate();
    Count++;
}
void Student::get()
{
    name2=name;
    birthdate.getDate();
    year=birthdate.Year;
    month=birthdate.Month;
    day=birthdate.Day;
}
Student::Student()
{
    name=(char*) malloc(1);
    year=0;
    month=0;
    day=0;
    courseNumber=0;
    courseNumber2=0;
    E=0;
    O=0;
    GPA=0;
}

 int Student::Count=0;


Student::Student(const Student& X)
{
   name=X.name;
    birthdate=X.birthdate;
    day=X.day;
    month=X.month;
    year=X.year;
}

Student& Student:: addCourse(course *c)
{
    courseNumber++;
    OCName[courseNumber]=c;
    return *this;
    
}

void Student::addCourse(const string &M, int C)
{
    string a=M;
    int b=C;
    courseNumber++;
    ECName[courseNumber]=new ElectiveCourse;
    ECName[courseNumber]->set(a,b);

  
}
void Student::addCourse2(const string &M, int C)
{
    string a=M;
    int b=C;
    courseNumber2++;
   // cout<<"courseNumber2:"<<courseNumber2<<"学分："<<C<<endl;
    OCName[courseNumber2]=new ObligatoryCourse;
    OCName[courseNumber2]->set(a,b);
    
    
}

ostream & operator<<(ostream &out, Student &A)
{
    out<<"姓名： ";
    for(int i=0;i<=A.length-1;i++)
        out<<*(A.name+i);
    out<<endl;
   out <<"出生日期: "<<A.birthdate<<"选课信息如下： "<<endl;
    out<<"必修课："<<endl;
    out<<"必修课共 "<<A.courseNumber2<<" 门 "<<endl;
    
    for(int i=1;i<=A.courseNumber2;i++)
    {
        out<<*(A.OCName[i]);
        out<<"成绩为: ";
        out<<(A.o[i-1])->mark<<endl;
    }
  //  if(A.courseNumber2==0) out<<"无"<<endl;
    out<<"选修课："<<endl;
    out<<"选修课共 "<<A.courseNumber<<" 门"<<endl;

    for(int i=1;i<=A.courseNumber;i++)
    {
        out<<*(A.ECName[i]);
        out<<"成绩为: ";
        out<<(A.e[i-1])->mark<<endl;
    }
 //   if(A.courseNumber==0) out<<"无"<<endl;
    out<<"积点: "<<A.GPA<<endl;
    return out;
}
ostream & operator>>(ostream &in, Student &A)
{
    string s;
    in<<s;
    for(int i=0;i<=A.length-1;i++)
        in<<*(A.name+i);
    in<<endl;
    in <<s<<A.birthdate<<endl<<s<<endl;
    in<<s<<endl;
    in<<s<<A.courseNumber2<<s<<endl;
    
    for(int i=1;i<=A.courseNumber2;i++)
    {
        in<<*(A.OCName[i]);
        in<<s;
        in<<(A.o[i-1])->mark<<endl;
    }
    //  if(A.courseNumber2==0) out<<"无"<<endl;
    in<<s<<endl;
    in<<s<<A.courseNumber<<s<<endl;
    
    for(int i=1;i<=A.courseNumber;i++)
    {
        in<<*(A.ECName[i]);
        in<<s;
        in<<(A.e[i-1])->mark<<endl;
    }
    //   if(A.courseNumber==0) out<<"无"<<endl;
    in<<s<<A.GPA<<endl;
    return in;
}



void Student::calcCredit()
{
    double sum1=0;
    double Credit1=0;
    if(courseNumber2!=0)
    {
        for(int i=1;i<=courseNumber2;i++)
    {
        
     //  cout<<"HELLO:学分加入："<<OCName[i]->creditHour<<endl;
        Credit1+=OCName[i]->creditHour;
        //cout<<"学分"<<OCName[i]->CreditHour<<endl;
        
    }

        for(int i=1;i<=courseNumber2;i++)
    {
       // if(o[i-1]==NULL)cout<<"指针不存在"<<endl;
        sum1+=o[i-1]->mark*(OCName[i]->creditHour)/Credit1;
        
    }
        
        sum1=sum1*(0.6);
       cout<<"sum1"<<sum1<<endl;
    }
    double  sum2=0;
    double Credit2=0;
    
    if(courseNumber!=0)
    {
        for(int i=1;i<=courseNumber;i++)
        {
            
            
            Credit2+=ECName[i]->creditHour;
          //  cout<<"学分"<<ECName[i]->creditHour<<endl;
        }
    for(int i=1;i<=courseNumber;i++)
    {
        
        sum2+=e[i-1]->mark*(ECName[i]->creditHour/Credit2);
    }
    sum2=sum2*(0.4);
    }
    GPA=sum1+sum2;
  //  cout<<"GPA:"<<GPA<<endl;
}

