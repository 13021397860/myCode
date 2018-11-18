#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include "MyException.h"
#include "Student.h"
using namespace std;

#define OWeight 0.6
#define EWeight 0.4

int Student::count=0;
Student::Student(const char* n, int y, int m, int d)
{
    ++count;
    courseNumber=0;
    OCourseNumber=0;
    ECourseNumber=0;
    Credit=0;
    name=new char[100];
    if(n==NULL)setStudent("ABC",y,m,d);
    else
        setStudent(n,y,m,d);
}

Student::Student(Student &s)
{
    count++;
    name=new char[100];
    strcpy(name,s.name);
    birthDate=s.birthDate;
}

void Student::checkName()
{
    int len=strlen(name);
    if(len>20)
    {
        strncpy(name,"ABC",99);
    }
}

int Student::getCount()
{
    return count;
}

void Student::setStudent(const char* n, int y, int m, int d)
{
    if(name!=NULL)
    {
        delete []name;
    }
    if(n==NULL)
    {
        name=new char[100];
        strncpy(name,"ABC",99);
    }
    if(n!=NULL)
    {
        name=new char[100];
        strncpy(name,n,99);
    }
    birthDate.setDate(y,m,d);
    checkName();
}

ostream& operator<<(ostream& os,const Student& p)
{
    os<<"Name : "<<p.name<<"    Birthday : "<<p.birthDate<<"    Course Information : "<<endl;
    if(p.courseNumber>0)
        for(int i=0; i<p.courseNumber; i++)
        {
            os<<*p.courseList[i];
        }
    else
        os<<"No Course"<<endl;
    return os;
}

Student& Student::addCourse(Course *course,string type)
{
    if(course&&courseNumber<MAX_SIZE)
    {
        courseList[courseNumber]=course;
        courseList[courseNumber]->setCourseType(type);
        courseNumber++;
        if(type=="ObligatoryCourse")
            OCourseNumber++;
        else if(type=="ElectiveCourse")
            ECourseNumber++;
    }
    if(courseNumber>=MAX_SIZE)
        {
            MyException erange(courseNumber);
            throw erange;
        }
    return *this;
}

bool Student::removeCourse(int i)
{
    if(i>courseNumber||i<1)
    {
        MyException erange(i);
        throw erange;
    }
    else
    {
        for(int j=i-1; j<courseNumber-1; j++)
            courseList[j]=courseList[j+1];
        courseList[courseNumber-1]=NULL;
        courseNumber--;
        return true;
    }
}

void Student::setMark(int number,string mark)
{
    if(number>courseNumber||number<1)
    {
        MyException erange(number);
        throw erange;
    }
    else
    {
        if(mark=="A"||mark=="B"||mark=="C"||mark=="D"||mark=="E")
            courseList[number-1]->setGrade(mark);
        else
        {
            int m=atoi(mark.c_str());
            if(m<100&&m>0 && courseList[number-1]->getCourseType()=="ObligatoryCourse")
            {
                courseList[number-1]->setMark(m);
            }
            else
            {
                MyException egrade("a");
                throw egrade;
            }
        }
    }
}

Student::~Student()
{
    count--;
    delete []name;
    for(int i=0; i<courseNumber; i++)
        delete courseList[i];
    //cout<<"delete后的学生数目"<<count<<endl;
}

void Student::calcCredit()
{
    //必修课权重*SUM(必修课成绩*必修课学分/所选必修课总学分)+选修课权重*SUM(选修课成绩/所选选修课总门数)
    double Osum=0, Esum=0;
    int OsumHour=0,EsumHour=0;
    for(int i=0; i<courseNumber; i++)
    {
        if(courseList[i]->getCourseType()=="ObligatoryCourse")
            OsumHour+=courseList[i]->getCreditHour();
        else if(courseList[i]->getCourseType()=="ElectiveCourse")
            EsumHour+=courseList[i]->getCreditHour();
    }
    for(int i=0; i<courseNumber; i++)
    {
        if(courseList[i]->getCourseType()=="ObligatoryCourse")
            Osum+=(courseList[i]->getScore()*courseList[i]->getCreditHour()/OsumHour);
        else if(courseList[i]->getCourseType()=="ElectiveCourse")
            Esum+=(courseList[i]->getScore()/ECourseNumber);
    }
    Credit=OWeight*Osum+EWeight*Esum;
}

