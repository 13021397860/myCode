#include "Student.h"
#include"Date.h"
#include<iostream>
#include<cstring>
#include"Course.h"
#include"ObligatoryCourse.h"
#include"ElectiveCourse.h"
#include"MyException.h"
#include<typeinfo>
using namespace std;

int Student::number=0;

ostream& operator <<(ostream& o,const Student& a)  //（如果是>>则不能加const，因为要修改值）
{
        o<<"姓名：";
        char *p=a.getName();
        int n=strlen(p)+1;
        for(int i=0;i<n;i++) {o<<*p;p++;}
        o<<"  出生日期："<<a.getBirthDate()<<endl;
        for(int i=0;i<a.courseNumber;i++)
            o<<*a.courseList[i]<<endl;
        return o;//(为了可以连续输出）
}

Student::Student()
{
    courseNumber=0;
    number++;
}

Student::Student(const char *n,Date D):birthDate(D)
{
    if(D.judgement()==false)
        throw MyException();
    delete [] name;
    name=new char[strlen(n)+1];
    strcpy(name,n);
    courseNumber=0;
    number++;
}

Student::Student(const Student &S) :birthDate(S.birthDate)
{
    name=S.name;
    courseNumber=0;
    number++;
}

Student::~Student()
{
    delete []name;
    number--;
}

Student& Student::addCourse(Course *course)
{
    if(courseNumber<MAX_SIZE)
    {
        courseList[courseNumber]=course;
        courseNumber++;
    }
    else
        cout<<"Error!"<<endl;
    return (*this);

}

bool Student::removeCourse(int i)
{
    if(i<0||i>courseNumber)
    {
        throw MyException();
        return 0;
    }
    else
    {
        courseList[i]=courseList[courseNumber];
        courseNumber--;
        return 1;
    }
}

double Student::calcCredit()
{
    int obGrade=0,elGrade=0,obCredit=0,elNum=0;
    double calc=0;
    for(int i=0;i<courseNumber;i++)
    {
        ObligatoryCourse testClass;
        if(typeid(testClass)==typeid(*courseList[i]))
        {
            obGrade+=(courseList[i]->getScore()*courseList[i]->getCreditHour());
            obCredit+=courseList[i]->getCreditHour();
        }
        else
        {
            elGrade+=courseList[i]->getScore();
            elNum++;
        }
    }
    if(obCredit) calc+=(obGrade/obCredit)*0.6;
    if(elNum) calc+=elGrade/elNum*0.4;
    return calc;
}
