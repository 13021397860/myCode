#include "Date.h"
#include "Student.h"
#include<iomanip>
//#include"Course.h"
//#include"ObligatoryCourse.h"
//#include"ElectiveCourse.h"
#include<cstring>
#include<iostream>
#include<typeinfo>
using namespace std;
int Student::count=0;


Student::Student()
{
    //ctor
    count++;
    name=new char [256];
    courseNumber=0;
}

Student::Student(const char* const q,const int &y,const int &m,const int &d)
    :birthDate(y,d,m)
{
    count++;
    name=new char[256];
    strcpy(name,q);//const_cast<char*>,char*
    courseNumber=0;
}

Student::Student(const Student& t)
{
    count++;
    name=t.name;
    birthDate=t.birthDate;
    courseNumber=t.courseNumber;
}

Student::~Student()
{
    //dtor
    count--;
}

ostream & operator <<(ostream&os,const Student& s)
{
    os<<"Name:"<<setw(6)<<left<<s.name<<"\t"<<"BirthDate:"<<s.birthDate<<"\n";
    for(int i=1; i<=s.courseNumber; i++)
    {
        os<<*s.courseList[i]<<"\n";
    }
    return os;
}

bool Student::removeCourse(int i)
{
    if(i<=0||i>courseNumber)
    {
        MyException ex;
        ex.OutOfRange();
        throw ex;
        return false;
    }
    else
    {
        for(int j=i; j<courseNumber; j++)
        {
            courseList[j]=courseList[j+1];
        }
        //delete courseList[courseNumber];
        courseNumber--;
        return true;
    }
}

Student& Student::addCourse(Course *course)
{
    ++courseNumber;
    if(courseNumber<=MAX_SIZE-1)
    {
        courseList[courseNumber]=course;
        cout<<"课程\""<<course->getName()<<"\"已添加。\n";
    }
    else
    {
        --courseNumber;
        cout<<"选课门数超过上限，选课失败！\n";
    }
    return *this;
}

double Student::calcCredit()
{
    int oblisum=0;
    int oblicredit=0;
    int elecsum=0;
    int elecnum=0;
    for(int i=1;i<=courseNumber;i++)
    {
        if(typeid(ObligatoryCourse)==typeid(*courseList[i]))
        {
            oblisum+=courseList[i]->getScore()*courseList[i]->getcreditHour();
            oblicredit+=courseList[i]->getcreditHour();
        }
        else if(typeid(ElectiveCourse)==typeid(*courseList[i]))
        {
            elecsum+=courseList[i]->getScore();
            elecnum++;
        }
    }
    return 0.6*(double)oblisum/(double)oblicredit+0.4*(double)elecsum/(double)elecnum;
}

Course* Student::getCourse(const int i)
{
    if(i<1||i>courseNumber)
    {
        MyException ex;
        ex.OutOfRange();
        throw ex;
    }
    return courseList[i];
}

int Student::getCourseNumber()
{
    return courseNumber;
}

int Student::getCount()
{
    return count;
}

void Student::setName(const char* const q)
{
    strcpy(name,q);
}

char* Student::getName()
{
    return name;
}

void Student::setbirthDate(const int &y,const int &m,const int &d)
{
    birthDate.setDate(y,m,d);
}

Date Student::getbirthDate()
{
    return birthDate;
}

