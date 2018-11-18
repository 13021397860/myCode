#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string.h>
#include "Student.h"
#include "date.h"
#include "MyException.h"
using namespace std;
int Student::count=0;
Student::Student(char _name[], date _birthDate) : weight(0.6)
{
    if(!_birthDate.check())
        throw MyException(DATE_ILLEGAL);
    name = NULL;
    setBirthDate(_birthDate);
    setName(_name);
    count++;
    courseNumber=0;
}

Student::~Student()
{
    if(name!=NULL)
        delete []name;
    name=NULL;
    count--;
}

Student::Student(const Student &t) : weight(0.6)
{
    name=new char[strlen(t.name)+1];
    name=t.name;
    birthDate=t.birthDate;
    count++;
}

Student& Student::addCourse(Course* course)
{
    if(courseNumber < MAX_SIZE && course != NULL)
    {
        courseNumber++;
        courseList[courseNumber] = course;
    }
    return *this;
}

/*Student& Student::addCourse1(Course* course, int kind)
{
    if(courseNumber < MAX_SIZE && course != NULL)
    {
        courseNumber++;
        courseList[courseNumber] = course;
    }
    return *this;
}*/

void Student::setBirthDate(const date a)
{
    birthDate=a;
}

void Student::setName(const char a[])
{
    if(name!=NULL)
        delete[] name;
    if(a==NULL)
    {
        name=new char[11];
        name="no-student";
    }
    else
    {
        name=new char[sizeof(a)];
        strcpy(name,a);
    }
}

void Student::print()
{
    int i=courseNumber;
    cout<<"第"<<count<<"个同学的姓名是：";
    cout<<name<<endl;
    cout<<"该同学的生日是：";
    birthDate.print();
    puts("");

}

bool Student::removeCourse(int i)
{
    if(i<1||i>courseNumber)
        throw MyException(RANGE_ERROR);
    else
    {
        int j;
        for(j=i;j<courseNumber;j++)
            courseList[j]=courseList[j+1];
        courseNumber--;
        cout<<"退选成功"<<endl;
        return 1;
    }
}

ostream& operator<<(ostream& output, const Student& s)
{
    output<<"姓名："<<s.name<<" 出生日期：";
    output<<s.birthDate<<" 选课信息如下："<<endl;
    for(int j=1;j<=s.courseNumber;j++)
    {
        output<<j<<". ";
        output<<*s.courseList[j]<<" 成绩："<<s.courseList[j]->getScore()<<endl;
    }
    output<<"绩点成绩为："<<s.calcCredit()<<endl;
    return output;
}

void Student::setGrade(int i, int grade)
{
    if(i <= 0 || courseNumber < i)
    {
        cout<<"输入的编号不正确"<<endl;
    }
    else
        (*courseList[i]).setScore(grade);
}

double Student::calcCredit()const
{
    double ObligatoryGrade=0, ElectiveGrade=0, ObligatoryCredit=0, ElectiveCount=0, sum=0;
    int i=1;
    for(;i<=courseNumber;i++)
    {
        if((*courseList[i]).getKind()==1)
        {
            ObligatoryGrade+=courseList[i]->getScore()*courseList[i]->getCreditHour();
            ObligatoryCredit+=courseList[i]->getCreditHour();
        }
        else if((*courseList[i]).getKind()==2)
        {
            ElectiveGrade+=courseList[i]->getScore();
            ElectiveCount++;
        }
    }
    if(ObligatoryCredit)
        sum+=ObligatoryGrade*weight/ObligatoryCredit;
    if(ElectiveCount)
        sum+=(ElectiveGrade*(1-weight))/ElectiveCount;
    return sum;
}
