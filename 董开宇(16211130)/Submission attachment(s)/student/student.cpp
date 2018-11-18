#include <iostream>
#include <cstring>
#include "student.h"
#include "Date.h"
#include <cstring>
#include "Course.h"
#include <typeinfo>
#include "ObligatoryCourse.h"
#include "ElectiveCourse.h"
#include "MyException.h"

#define ObligatoryPercent 0.6
#define ElectivePercent 0.4
using namespace std;

int student::StuNumber=0;

student::student(const char*na, const Date &birth):birthDate(birth)
{
    name= new (char [strlen(na)+1]);
    strcpy(name,na);
    StuNumber++;
    courseNumber=0;
}

student::student(const student &other):birthDate(other.birthDate)
{
    name= new (char [strlen(other.name)+1]);
    strcpy(name,other.name);
    StuNumber++;
    courseNumber=0;
}

char* student::getName()
{
    return name;
}

Date student::getBirthDate()const
{
    return birthDate;
}

void student::setName(const char* na)
{
    name= new (char [sizeof(na)]);
    strcpy(name,na);
}

void student::print()
{
    cout<<"Name:"<<name<<endl;
    cout<<"Birthday:";
    birthDate.print();
}

int student::getNumber()
{
    return StuNumber;
}

int student::getCourseNumber()
{
    return courseNumber;
}

student& student::addCourse(Course *co)
{
    if(courseNumber<MAX_SIZE)
        courseList[courseNumber++]=co;
    return *this;
}
/*
student& student::addCourse(const string &co, int cre)
{
    Course temp(co,cre);
    if(courseNumber<MAX_SIZE)
        courseList[courseNumber++]=&temp;
    return *this;
}
*/
ostream& operator<<(ostream &output, student &s)
{
    output<<"Name: "<<s.getName()<<"    "<<"Birthday: "<<s.getBirthDate()<<"    \n"<<"The information of choosing courses is as follows: \n";
    for(int i=0; i<s.courseNumber; i++)
    {
        cout<<*s.courseList[i]<<endl;
    }
    return output;
}

void student::setFenshu()
{
    for(int i=0;i<courseNumber;i++)
    {
        if(typeid(*courseList[i])==typeid(ObligatoryCourse))
        {
            cout<<"This is an obligatory course, please enter the grade(0~100)";
            int fenshu;
            try
            {
                cin>>fenshu;
                if(fenshu>100||fenshu<0)
                {
                    throw MyException();
                }
            }
            catch(MyException k)
            {
                cout<<"Error : "<<k.ScoreError()<<endl;
                cout<<"The score now is 60!"<<endl;
                fenshu=60;
            }
            courseList[i]->setMark(fenshu);
        }
        else if(typeid(*courseList[i])==typeid(ElectiveCourse))
        {
            cout<<"This is an elective course, please enter the grade(A~E)";
            char fenshu;
            try
            {
                cin>>fenshu;
                if(fenshu-'E'>0||fenshu-'A'<0)
                    throw MyException();
            }
            catch(MyException k)
            {
                cout<<"Error : "<<k.ScoreError()<<endl;
                cout<<"The score now is C!"<<endl;
                fenshu='C';
            }
            courseList[i]->setGrade(fenshu);
        }
    }
}

bool student::removeCourse(int i)
{
    if(i<courseNumber)
    {
        delete courseList[i];
        for(int j=i;j<courseNumber; j++)
        {
            courseList[j]=courseList[j+1];
        }
        courseNumber--;
        cout<<"Delete successfully!";
        return 1;
    }
    else return 0;
}

void student::printScore()
{
    for(int i=0;i<courseNumber;i++)
    {
        /*
        if(typeid(*courseList[i])==typeid(ObligatoryCourse))
        {
            cout<<*courseList[i]<<"    Score:"<<courseList[i]->getMark()<<endl;
        }
        else if(typeid(*courseList[i])==typeid(ElectiveCourse))
        {
            cout<<*courseList[i]<<"    Score:"<<courseList[i]->getScore()<<endl;
        }
        */
        cout<<*courseList[i]<<"    Score:"<<courseList[i]->getScore()<<endl;
    }
}

double student::calcCredit()
{
    double sum;
    double ObligatoryCredit=0;
    double ElectiveCredit=0;
    for(int i=0;i<courseNumber;i++)
    {

        if(typeid(*courseList[i])==typeid(ObligatoryCourse))
        {
            ObligatoryCredit+=courseList[i]->GetCreditHour();
        }
        else if(typeid(*courseList[i])==typeid(ElectiveCourse))
        {
            ElectiveCredit+=courseList[i]->GetCreditHour();
        }
    }
    for(int i=0;i<courseNumber;i++)
    {

        if(typeid(*courseList[i])==typeid(ObligatoryCourse))
        {
            sum+=courseList[i]->getScore()*courseList[i]->GetCreditHour()*ObligatoryPercent/ObligatoryCredit;
        }
        else if(typeid(*courseList[i])==typeid(ElectiveCourse))
        {
            sum+=courseList[i]->getScore()*courseList[i]->GetCreditHour()*ElectivePercent/ElectiveCredit;
        }
    }
    return sum;
}

void student::getCourseList(int i,Course*& temp)
{
    temp=courseList[i];
}

student::~student()
{
    delete[](name);
    for(int i=0; i<courseNumber; i++)
    {
        delete courseList[i];
    }
    StuNumber--;
    //dtor
}
