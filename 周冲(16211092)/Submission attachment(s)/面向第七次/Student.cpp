#include "Student.h"
#include"Date.h"
#include"Course.h"
#include"ObligatoryCourse.h"
#include"ElectiveCourse.h"
#include<iostream>
#include<cstring>
#include<typeinfo>
int Student::number=0;
Student::Student()
{
    courseNumber=0;
    number++;
}
Student::Student(const char *n,Date D):birthDate(D)
{
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
        std::cout<<"Error!"<<std::endl;
    return (*this);
}
bool Student::removeCourse(int i)
{
    if(i<0||i>courseNumber)
    {
    	std::cout<<"Error!"<<std::endl;
        return 0;
    }
    else
    {
        courseList[i]=courseList[courseNumber];
        courseNumber--;
        return 1;
    }
}
std::ostream&operator<<(std::ostream& o,const Student& a)
{
        std::cout<<"姓名：";
        char *p=a.getName();
        int n=strlen(p)+1;
        for(int i=0;i<n;i++) 
		{
			std::cout<<*p;
			p++;
		}
        std::cout<<"  出生日期："<<a.getBirthDate()<<std::endl;
        for(int i=0;i<a.courseNumber;i++)
        	std::cout<<*a.courseList[i]<<std::endl;
        return o;
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
    if(obCredit)calc+=(obGrade/obCredit)*0.6;
    if(elNum)calc+=elGrade/elNum*0.4;
    return calc;
}
