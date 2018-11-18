#include "student.h"
#include <cstring>
#include <iostream>
#include "date.h"
#include "course.h"
#include <typeinfo>
int student::amount=0;
student::student()
{
    courseNumber=0;
    amount++;
    //ctor
}
student::student(student& a)
{
    name=a.name;
    birthDate=a.birthDate;
    amount++;
}
bool student::setBirthDate(int m,int d,int y)
{
    return birthDate.setdate(m,d,y);
}
bool student::setName(const string s)
{
    if(s.size()<=20)
    {
        name=s;
        return true;
    }
    else
    {
        std::cout<<"too long"<<endl;
        return false;
    }
}
bool student::removeCourse(int k)
{
    if(k>courseNumber||k<=0) return false;
    delete CourseList[k-1];
    for (int i=k-1;i<courseNumber-1;i++)
        CourseList[i]=CourseList[i+1];
    courseNumber--;
    return true;
}
bool student::setScore(int num,int score)
{
    if(num>courseNumber||num<=0)
    {
        cout<<"course do not exit"<<endl;
        return false;
    }
    CourseList[num-1]->setScore(score);
    return true;
}
student& student::addCourse(Course* course)
{
    if(course)
    {
        CourseList[courseNumber]=course;
        courseNumber++;
    }
    return *this;
}
student& student::addObligatoryCourse(const string &courseName,int creditHour)
{
    CourseList[courseNumber]=new ObligatoryCourse(courseName,creditHour);
    courseNumber++;
    return *this;
}
student& student::addElectiveCourse(const string &courseName,int creditHour)
{
    CourseList[courseNumber]=new ElectiveCourse(courseName,creditHour);
    courseNumber++;
    return *this;
}
double student::calcCredit() const
{
    int sumo=0,credito=0,sume=0,nume=0;
    ElectiveCourse e;
    ObligatoryCourse o;
    for (int i=0;i<courseNumber;i++)
    {
        if(typeid(*CourseList[i])==typeid(o))
        {
            sumo+=CourseList[i]->getScore()*CourseList[i]->getCredictHour();
            credito+=CourseList[i]->getCredictHour();
        }
        else if(typeid(*CourseList[i])==typeid(e))
        {
            sume+=CourseList[i]->getScore();
            nume++;
        }
    }
    double ans=0.0;
    if(credito!=0)
        ans+=0.6*sumo/credito;
    if(nume!=0)
        ans+=0.4*sume/nume;
    return ans;
}
student::~student()
{
    delete []CourseList;
    for (int i=0;i<=courseNumber;i++)   CourseList[i]=NULL;
    //dtor
}
