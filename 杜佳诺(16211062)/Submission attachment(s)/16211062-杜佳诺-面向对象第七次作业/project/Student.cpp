#include <iostream>
#include <iomanip>
#include <cstring>
#include <typeinfo>
#include "Student.h"
#include "Date.h"
#include "course.h"
#include "obligatorycourse.h"
#include "electivecourse.h"
#include "myexception.h"
using namespace std;

int Student::Count = 0;

Student::Student( const char* p,const Date *da )
: birthDate(*da)
{
    ++Count;
    int l = strlen(p);
    name = new char[l+1];
    strcpy( name, p );
    courseNumber = 0;
}

Student::Student( const Student &stu )
: birthDate(stu.birthDate)
{
    ++Count;
    delete []name;
    int l = strlen( stu.name );
    name = new char[l+1];
    strcpy( name, stu.name );
    courseNumber = 0;
}

Student::~Student()
{
    --Count;
    delete []name;

    /*for(int i=1;i<=courseNumber;i++)
    {
        if(dynamic_cast<ObligatoryCourse*>(courseList[i])!=NULL)
        {
            ObligatoryCourse *tmp=(ObligatoryCourse*)courseList[i];
            delete tmp;
        }

        if(dynamic_cast<ElectiveCourse*>(courseList[i])!=NULL)
        {
            ElectiveCourse *tmp=(ElectiveCourse*)courseList[i];
            delete tmp;
        }
    }*/
    delete []courseList;
}

char* Student::getName() const
{
    return name;
}

Date Student::getBirthDate() const
{
    return birthDate;
}

int Student::getCount()
{
    return Count;
}

void Student::setName( const char *p )
{
    delete []name;
    int l = strlen(p);
    name =new char[l+1];
    strcpy(name,p);
}

Student& Student::addCourse( Course* course )
{
    courseList[++courseNumber] = course;
    return *this;
}

/*Student& Student::addCourse( const string& courseName, int creditHour )
{
    Course cou( courseName, creditHour );
    courseList[++courseNumber] = &cou;
    return *this;
}*/

bool Student::courseExist( int x, string &str )
{
    if(x>courseNumber)return false;
    str = courseList[x]->getName();
    return true;
}

bool Student::removeCourse( int x )
{
    if(MyException::CourseListException(x,courseNumber)){
    for(int i=x;i<courseNumber;i++)
        courseList[i]=courseList[i+1];

    courseNumber--;
    return true;
    }
    return false;
}

void Student::setGrade( int x )
{
    if(dynamic_cast<ObligatoryCourse*>(courseList[x])!=NULL)
    {
        cout<<"Please input the mark( 0 to 100 ):\n";
        int m;cin>>m;

        while(cin.fail())
        {
            cout<<"Wrong input, please input again\n";
            cin.clear();
            cin.ignore();
            cin>>m;
        }

        while(!MyException::OcSetGradeException(m))
            cin>>m;

        courseList[x]->setGrade(m);
    }

    if(dynamic_cast<ElectiveCourse*>(courseList[x])!=NULL)
    {
        cout<<"Please input the grade( A to E ):\n";
        char m;cin>>m;
        cout<<m<<endl;

        while(cin.fail())
        {
            cout<<"Wrong input, please input again\n";
            cin.clear();
            cin.ignore();
            cin>>m;
        }

        while(!MyException::EcSetGradeException(m))
            cin>>m;

        courseList[x]->setGrade((int)m);
    }
}

bool Student::judgeCourse( int x )
{
    if(dynamic_cast<ObligatoryCourse*>(courseList[x])!=NULL)
        return true;

    if(dynamic_cast<ElectiveCourse*>(courseList[x])!=NULL)
        return false;
}

string Student::getCourseName( int x )
{
    return courseList[x]->getName();
}

int Student::getCourseNumber()
{
    return courseNumber;
}

double Student::caleCredit()
{
    double calecredit=0;
    double Ocre=0,Enum=0;
    for(int i=1;i<=courseNumber;i++)
    {
        if(courseList[i]->getWeight()==0.6)Ocre+=courseList[i]->getCreditHour();
        if(courseList[i]->getWeight()==0.4)Enum++;
    }

    for(int i=1;i<=courseNumber;i++)
    {
        if(courseList[i]->getWeight()==0.6)
            calecredit+=courseList[i]->getWeight()*((double)courseList[i]->getScore()*courseList[i]->getCreditHour()/Ocre);
        if(courseList[i]->getWeight()==0.4)
            calecredit+=courseList[i]->getWeight()*((double)courseList[i]->getScore()*courseList[i]->getCreditHour()/Enum);
    }

    if(Ocre==0)calecredit+=60;
    if(Enum==0)calecredit+=40;

    return calecredit;
}

void Student::VisitCourseList(int x)
{
    if(MyException::CourseListException(x,courseNumber))
    {
        cout<<*courseList[x]<<endl;
    }
}

ostream &operator<<( ostream &output, const Student &stu )
{
    output<<"Name:"<<stu.name<<setw(12)<<setfill(' ')<<right<<"BirthDate:"<<stu.birthDate<<setw(12)<<setfill(' ')<<"Course:\n";
    for(int i=1;i<=stu.courseNumber;i++)output<<i<<"."<<*stu.courseList[i]<<endl;
    return output;
}
