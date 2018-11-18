#define MAX_SIZE 12
#include "Stu.h"
#include "Time.h"
#include "Course.h"
#include <cstring>
#include <iostream>
#include<typeinfo>

using namespace std;
int Stu::count=0;
int Stu::courseNumber=0;
double Oweight=0.6;
double Eweight=0.4;
Stu::Stu(const char *n, int y1, int m1, int d1):birthDate(y1, m1, d1)
{
    name = new char (strlen(n) + 1);
    strcpy(name, n);
    count++;
}

Stu::Stu(const Stu &a):birthDate(a.birthDate)
{
    name = new char (strlen(a.name) + 1);
    strcpy(name, a.name);
}

Stu::~Stu()
{
    int i=courseNumber-1;
    while(i>0)
    {
        if(removeCourse(i)) i--;
    }
    delete[] name;
    count--;
}

ostream& operator << (ostream& outs,Stu& s)
{

    outs<<"Name:" << s.name <<endl<<"BirthDate:"<<s.birthDate.getYear()<<"-"<<s.birthDate.getMonth()<<"-"<<s.birthDate.getDay()<<endl;
    outs<<"course number: "<<s.courseNumber<<endl;
    for(int i=0;i<s.courseNumber;i++)
    {

        outs<<*s.courseList[i]<<endl;
    }
    outs<<"Credit:"<<s.calCredit()<<endl;
    return outs;
}

int Stu::setScore()
{
    for(int i = 0; i < courseNumber; i++)
    {
        if(typeid(*courseList[i]) == typeid(ObligatoryCourse))
        {
            cout << "No." << i+1 <<" obligatory " << *courseList[i] << "\nPlease input the grade(number)";
            int mark;
            cin >> mark;
            if(mark<=0||mark>=100)
                throw MyException(SCORE_INVALID);
            if(!dynamic_cast<ObligatoryCourse*>(courseList[i])->setMark(mark))
                cout<<"Wrong!"<<endl;
        }
        else
        {
            cout << "No." << i+1 <<" elective " << *courseList[i] << "\nPlease input the grade(class)";
            char grade;
            cin >> grade;
            if(!(grade=='A'||grade=='B'||grade=='C'||grade=='D'||grade=='E'||grade=='F'))
                throw MyException(SCORE_INVALID);
            if(!dynamic_cast<ElectiveCourse*>(courseList[i])->setGrade(grade))
               cout << "Wrong!"<<endl;
        }
    }
    return 0;
}



int Stu::print()
{
    cout << "Name:" << name << "\nBirthDate:"<<endl;
    birthDate.print();
}




bool Stu::removeCourse(const int i)
{
    if(i >= 0 && i < courseNumber)
    {
        delete courseList[i];
        for(int u = i; u < courseNumber-1; u++)
            courseList[u] = courseList[u+1];
        courseNumber--;
        return true;
    }
    else
        return false;
}

Stu& Stu::addCourse(const Course *const course)
{
    Course *c;
    if(typeid(*course) == typeid(ObligatoryCourse))
        c = new ObligatoryCourse();
    else
        c = new ElectiveCourse();
    *c = *course;
    courseList[courseNumber] = c;
    courseNumber++;
    return *this;
}


int Stu::setName(const char *n)
{
    delete []name;
    name = new char (strlen(n) + 1);
    strcpy(name, n);
    return 1;
}

int Stu::getName(char *n)const
{
    strcpy(n, name);
    return 1;
}



int Stu::getBirthDate(int &y, int &m, int &d)const
{
    y = birthDate.getYear();
    m = birthDate.getMonth();
    d = birthDate.getDay();
    return 1;
}


double Stu::calCredit()const
{
    double credit = 0;
    int h,sum1 = 0, sum2 = 0;
    string s;
    for(int i = 0; i < courseNumber; i++)
    {
        courseList[i]->getCourse(s,h);
        if(typeid(*courseList[i]) == typeid(ObligatoryCourse))
        {
            sum1 += h;
        }
        else if(typeid(*courseList[i]) == typeid(ElectiveCourse))
        {
            sum2 ++;
        }
    }
    for(int i = 0; i < courseNumber; i++)
    {
        courseList[i]->getCourse(s,h);
        if(typeid(*courseList[i]) == typeid(ObligatoryCourse))
        {
            credit += Oweight * courseList[i]->getScore() * h / sum1;
        }
        else if(typeid(*courseList[i]) == typeid(ElectiveCourse))
        {
            credit += Eweight * courseList[i]->getScore() / sum2;
        }
    }
    return credit;
}
