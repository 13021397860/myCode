#include <iostream>
#include <cstring>
#include <typeinfo>
#include "date.h"
#include "student.h"
#include "course.h"
#include "obligatoryCourse.h"
#include "electiveCourse.h"
#include "myException.h"
using namespace std;

int student::count=0;

student::student(const char *N,const date &BD):birthDate(BD)
{
    int len=strlen(N);
    name=new char[len+1];
    strcpy(name,N);
    count++;
}
student::student(const student &other):birthDate(other.birthDate)
{
    int len=strlen(other.name);
    name=new char[len+1];
    strcpy(name,other.name);
    count++;
}
student::~student()
{
    delete []name;
    for(int i=0;i<this->getNumber();i++)
        delete courseList[i];
    count--;
    courseNumber=0;
}
student &student::addCourse(course *course)
{
    if(courseNumber>=MAX_SIZE)
        cout<<"add course error"<<endl;
    else
        courseList[courseNumber++]=course;
    return *this;
}
/*student &student::addCourse(const string &courseName,const int credithour)
{
    if(courseNumber>=MAX_SIZE)
        cout<<"add course error"<<endl;
    else
    {
        course add(courseName,credithour);
        courseList[courseNumber++]=&add;
    }
    return *this;
}*/
void student::getCourseList(int i,course *&temp)
{
    temp=courseList[i];
}
const char *student::getName() const
{
    return name;
}
const date student::getBirthDate() const
{
    return birthDate;
}
void student::setName(const char *N)
{
    int len=strlen(N);
    name=new char[len+1];
    strcpy(name,N);
}
void student::getInformation() const
{
    cout<<"The student's name is: "<<name<<endl;
    cout<<"The student's birthday is: ";
    cout<<birthDate;
}
int student::getCount()
{
    return count;
}
void student::print() const
{
    for(int i=0;i<this->courseNumber;i++)
    {
        cout<<"Class "<<i+1<<":"<<endl;
        this->courseList[i]->getCourse();
    }
}
int student::getNumber() const
{
    return courseNumber;
}
ostream &operator<<(ostream &cout,const student &stu)
{
    cout<<"name: "<<stu.getName()<<"  birthdate: "<<stu.getBirthDate()<<"class information: "<<endl;
    for(int i=0;i<stu.getNumber();i++)
    {
        cout<<"class: "<<stu.courseList[i]->getName()<<"    credit hour: "<<stu.courseList[i]->getHour()<<"    score: "<<stu.courseList[i]->getScore()<<endl;
    }
}
bool student::removeCourse(int i)
{
    if(i>courseNumber||i<=0||courseNumber==0)
        return 0;
    else
    {
        for(int j=i-1;j<courseNumber-1;j++)
            courseList[j]=courseList[j+1];
        delete courseList[--courseNumber];
        return 1;
    }
}
bool student::removeCourse(const string str)
{
    int i;
    for(i=0;i<courseNumber;i++)
    {
        if(str==courseList[i]->getName())
            break;
    }
    if(i==courseNumber)
        return 0;
    else
    {
        for(int j=i;j<courseNumber-1;j++)
            courseList[j]=courseList[j+1];
        delete courseList[--courseNumber];
        return 1;
    }
}
void student::setFenshu()
{
    for(int i=0;i<courseNumber;i++)
    {
        bool judgeo=true;
        bool judgee=true;
        if(typeid(*courseList[i])==typeid(obligatoryCourse))
        {
            cout<<"It's an obligatory course, please input a mark;"<<endl;
            int mark;
            try
            {
                cin>>mark;
                if(mark<0||mark>100)
                {
                    judgeo=false;
                    throw myException();
                }
            }
            catch(myException ex)
            {
                cout<<"Error: "<<ex.fenshuException();
                cout<<"The score has been set to 95;"<<endl;
                courseList[i]->setMark(95);
            }
            if(judgeo)
                courseList[i]->setMark(mark);
            else
                judgeo=false;
        }
        if(typeid(*courseList[i])==typeid(electiveCourse))
        {
            cout<<"It's an elective course, please input a grade;"<<endl;
            char grade;
            try
            {
                cin>>grade;
                if(grade<'A'||grade>'E')
                {
                    judgee=false;
                    throw myException();
                }
            }
            catch(myException ex)
            {
                cout<<"Error: "<<ex.fenshuException();
                cout<<"The score has been set to 95;"<<endl;
                courseList[i]->setGrade('A');
            }
            if(judgee)
                courseList[i]->setGrade(grade);
        }
    }
}
float student::calcCredit()
{
    float sum=0;
    int obhour=0;
    int elhour=0;
    for(int i=0;i<courseNumber;i++)
    {
        if(typeid(*courseList[i])==typeid(obligatoryCourse))
            obhour+=courseList[i]->getHour();
        if(typeid(*courseList[i])==typeid(electiveCourse))
            elhour+=courseList[i]->getHour();
    }
    for(int i=0;i<courseNumber;i++)
    {
        if(typeid(*courseList[i])==typeid(obligatoryCourse))
            sum+=0.6*courseList[i]->getScore()*courseList[i]->getHour()/obhour;
        if(typeid(*courseList[i])==typeid(electiveCourse))
            sum+=0.4*courseList[i]->getScore()*courseList[i]->getHour()/elhour;
    }
    return sum;
}
course *student::getCourse(int i)
{
    return courseList[i];
}
