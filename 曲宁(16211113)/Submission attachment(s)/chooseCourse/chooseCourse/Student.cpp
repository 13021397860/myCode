#include "Student.h"
#include<cstdio>
#include<cstring>
#include "Course.h"
#include "ObligatoryCourse.h"
#include "ElectiveCourse.h"
#include <iostream>
int Student::stuCount=0;

Student::Student(const Student &s):birthDate(s.birthDate)
{
    name=new char[strlen(s.name)+1];
    strcpy(name,s.name);
    stuCount++;
}

Student::Student(char* name1,const Date &birthDate1):birthDate(birthDate1)
{
    name=new char[strlen(name1+1)];
    strcpy(name,name1);
    stuCount++;
}

int Student::getCourseNumber()const
{
    return courseNumber;
}

void Student::print()const
{
    cout<<"Name: "<<name<<"Birthday: "<<birthDate.getYear()<<"-"<<birthDate.getMonth()<<"-"<<birthDate.getDay()<<endl;
}

void Student::setName(char* name1)
{
    name=new char[strlen(name1)+1];
}

Student& Student::setName(const char * ,const char* n)
{
    if(name) delete[] name;
    name=new char[strlen(n)+1];
    strcpy(name,n);
    return *this;
}

const char* Student::getName()const
{
    return name;
}

bool Student::removeCourse(int c)
{
    if(c<courseNumber)
    {
        delete courseList[c];
        for(int i=c;i<courseNumber-1;i++)
        {
            courseList[i]=courseList[i+1];
        }
        courseNumber-=1;
        return true;
    }
    else
    {
        return false;
    }
}

Student& Student::addCourse(Course* course)
{
    if(courseNumber<MAX_SIZE)
    {
        courseList[courseNumber++]=course;
    }
    return *this;
}

Student& Student::addCourse(const string &courseName,int creditHour,int coursetype)
{
    if(courseNumber < MAX_SIZE)
    {
        if(coursetype==1)
            courseList[courseNumber]=new ElectiveCourse('A',courseName,creditHour);
        else
            courseList[courseNumber]=new ObligatoryCourse(100,courseName,creditHour);
        courseNumber++;
    }
    return *this;
}


ostream &operator<<(ostream& output,const Student &s)
{
    output<<"StudentName:  "<<s.name<<"    Birthday: "<<s.birthDate<<"  \nElective information:\n "<<endl;
    for(int i=0;i<s.courseNumber;i++)
    {
        output<<*s.courseList[i]<<endl;
    }
    return output;
}

void Student::settheScore(const int coursetype, const int score1,const char score2, const int ncourse)
{
      if(coursetype == 1)
        courseList[ncourse]->setScore(100,score2);
      else if(coursetype == 2)
        courseList[ncourse]->setScore(0,score1);
}

double Student::calcCredit(int xuanNumber,int biNumber)
{
    double jidian=0;
    for(int i=1;i<=xuanNumber;i++)
    {
        jidian+=0.4*(courseList[i-1]->getScore()/xuanNumber);
    }
    for(int i=1;i<=biNumber;i++)
    {
        jidian+=0.6*((courseList[i+xuanNumber-1]->getScore()*2)/(biNumber*2));
    }
    return jidian;
}

int Student::printGrade()const
{
    for(int i=1;i<=courseNumber;i++)
    {
        cout<<courseList[i-1]->getcourseName()<<": "<<courseList[i-1]->getScore()<<endl;
    }
}
Student::~Student()
{
    int i=courseNumber-1;
        while(i>0)
        {
            if(removeCourse(i))
                i--;
        }
    delete[] name;
    stuCount--;
}
