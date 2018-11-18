#include "Student.h"
#include<string>
#include<iostream>
#include<cstdio>
#include"Date.h"
#include"MyException.h"
using namespace std;
int Student::COUNT=0;

Student::Student()
{
    COUNT++;
    Date a;
    birthDate=a;
    name="xiaoming";
    courseNumber=0;
}
Student::Student(Date birda,string nm)
{
    courseNumber=0;
    COUNT++;
    name=nm;
    birthDate=birda;
}
Student::Student(string nm,int y,int m,int d)
{
    birthDate.setDate(y,m,d);
    courseNumber=0;
    COUNT++;
    name=nm;
}

Student::~Student()
{
    COUNT--;
    //  std::cout<<"COUNT:  "<<COUNT<<"\n";
    //  std::cout<<"destroy"<<"\n";
    //dtor
    for(int i=0; i<courseNumber; i++)
    {
        delete courseList[i];
    }
}
void Student::showName()
{
    std::cout<<name<<"\n";
}

bool Student::setBirthDate(int y,int m,int d)
{
    birthDate.setDate(y,m,d);
    return true;
}
bool Student::setName(string nm)
{
    name=nm;
    return true;
}
void Student::showDate()
{
    cout<<birthDate;
}
const string Student::getName()
{
    return name;
}
Date& Student::getBirthDate()
{
    return  birthDate;
}
int Student::getCOUNT()
{
    return COUNT;
}
Student& Student::addCourse(Course *c)
{
    if(courseNumber>=MAX_SIZE)
    {
        std::cerr<<"too many classes\n";
        return *this;
    }
    courseList[courseNumber]=c;
    if(c==NULL)
    {
        std::cerr<<"error:NULL ptr\n";
    }
    else
    {
        courseNumber++;
    }
    return *this;
}
/*Student& Student::addCourse(const string &courseName, int creditHour)
{
    if(courseNumber>=MAX_SIZE)
    {
        std::cerr<<"too many classes\n";
        return *this;
    }
    Course*a;
    a=new Course;
    courseList[courseNumber]=a;
    a->setName(courseName);
    a->setCreditHour(creditHour);
    courseNumber++;
    return *this;
}*/
bool Student::removeCourse(int i)
{
    if(i>=courseNumber)
    {
        //      cout<<"false";
        return false;
    }
    courseList[i]=NULL;
    for(int j=i+1; j<courseNumber; j++)
    {
        courseList[j-1]=courseList[j];
    }
    courseNumber--;
    //  cout<<"true";
    return true;
}
bool  Student::setscore(int s,int pos)
{
    if(pos>=courseNumber||pos<0)
        throw(MyException(2));

    courseList[pos]->setScore(s);
    return true;
}
double Student::calcCredit()
{
    double totalOb=0;
    double totalEL=0;
    double a=0;
    for(int i=0; i<courseNumber; i++)
        if(typeid(ObligatoryCourse)==typeid(*courseList[i]))
        {
            ObligatoryCourse*temp=dynamic_cast<ObligatoryCourse*>(courseList[i]);
            totalOb+=(temp->getCreditHour());
        }
        else if(typeid(ElectiveCourse)==typeid(*courseList[i]))
        {
            ElectiveCourse*temp1=dynamic_cast<ElectiveCourse*>(courseList[i]);
            totalEL+=temp1->getCreditHour();
        }
    //   cout<<"totalob: "<<totalOb<<endl;
    //   cout<<"totalel: "<<totalEL<<endl;
    for(int i=0; i<courseNumber; i++)
    {
        if(typeid(ObligatoryCourse)==typeid(*courseList[i]))
        {
            //   cout<<courseList[i]->getCreditHour()<<" line 148\n";
            a=a+0.6*(courseList[i]->getCreditHour()/totalOb)*(courseList[i]->getScore());
            cout<<"a: "<<a<<" i: "<<i<<"\n";
        }
        else if(typeid(ElectiveCourse)==typeid(*courseList[i]))
        {
            cout<<courseList[i]->getCreditHour()<<" line 156\n";
            cout<<courseList[i]->getScore()<<" line 157\n";
            a=a+0.4*(courseList[i]->getCreditHour()/totalOb)*(courseList[i]->getScore());
            cout<<"a: "<<a<<" i: "<<i<<"\n";
        }
    }
    //  cout<<totalEL<<endl;
//   cout<<totalOb<<endl;
    return a;
}
