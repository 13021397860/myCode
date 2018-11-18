#include<cstdio>
#include<cstring>
#include<iostream>
#include<typeinfo>
#include"Exception.h"

#include"Student.h"
#include"Course.h"
#include"ObligatoryCourse.h"
#include"Elective.h"
#define Max_Size 10

using namespace std;

int Student::count=0;
Student::Student(const char * const n,int y,int m,int d)
    :birthDate(y,m,d)
    {
        name=NULL;
        setName(n);
        count++;
        courseNumber=0;
    }
Student::Student(const char * const n,const Date &d)
    :birthDate(d)
    {
        name=NULL;
        setName(n);
        count++;
        courseNumber=0;
    }
Student::Student(const Student &d)
    :birthDate(d.birthDate)
    {
        name=NULL;
        setName(d.name);
        count++;
        courseNumber=0;
    }
    //ctor

Student::~Student()
{
    int i=courseNumber-1;	//ÊÍ·Å¿Î³ÌÐÅÏ¢
	while(i>0)
	{
		if (removeCourse(i))
            i--;
	}
	delete[] name;
	count--;
}

Student::getCount()const
{
    return count;
}

void Student::setName(const char * const n)
{
    if(name)
        delete[] name;
    name=new char[strlen(n)+1];
    strcpy(name,n);
}

char* Student::getName()const
{
    return name;
}

int Student::getYear()const
{
    return birthDate.getYear();
}

int Student::getMonth()const
{
    return birthDate.getMonth();
}

int Student::getDay()const
{
    return birthDate.getDay();
}

ostream& operator<<(ostream& output,Student& x)
{
    output<<"Name: "<<x.getName()<<" BirhtDate: "
    <<x.getMonth()<<'/'<<x.getDay()<<'/'<<x.getYear()<<endl
    <<"CreditHour："<<x.calcAchievement()<<endl
    <<"The course he/she have choosed are:\n";
    for(int i=0;i<x.getCourseNumber();i++)
    {
        output<<*x.courseList[i];
    }
    return output;
}

Student& Student::addCourse(Course *course)
{
    if(course==NULL)
        return *this;
    if(courseNumber<Max_Size)
        courseList[courseNumber++]=course;
    return (*this);
}

bool Student::removeCourse(int i)
{
    if(i<courseNumber)
    {
        delete courseList[i];
        for(int j=i;j<courseNumber-1;j++){
            courseList[j]=courseList[j+1];
        }
        courseNumber--;
        return true;
    }
    else
    {
        throw Exception(Range_Invalid);
        return false;
    }
}
bool Student::removeCourse(const string& courseName)
{
    int i;
	for(i=0;i<courseNumber;i++)
    {
	    if(courseName==courseList[i]->getName())
            break;
	}
	if(i<courseNumber)
    {
		return removeCourse(i);
	}
	else
    {
		return false;
	}
}

int  Student::calcObligatoryCredit() const
{
	int totalCredit=0;
	for(int i=0;i<courseNumber;i++)
    {
		if(typeid(ObligatoryCourse&)==typeid(*courseList[i]))
		{
			totalCredit+=courseList[i]->getcreditHour();
		}
	}
	return totalCredit;
}

int Student::calcElectiveNumber() const
{
	int number=0;
	for(int i=0;i<courseNumber;i++)
    {
		if(typeid(Elective&)==typeid(*courseList[i]))
		{
			number++;
		}
	}
	return number;
}
double Student::calcAchievement() const
{
    int obligatoryCredit=calcObligatoryCredit();
    int electiveNumber=calcElectiveNumber();
    int obligatoryAchievement=0;
    int electiveAchievement=0;
    for(int i=0; i<courseNumber;i++)
    {
        if(typeid(ObligatoryCourse&)==typeid(*courseList[i]))
        {
            obligatoryAchievement+=((*this).courseList[i]->getScore())*((*this).courseList[i]->getcreditHour());
        }
        if(typeid(Elective&)==typeid(*courseList[i]))
        {
            electiveAchievement+=(*this).courseList[i]->getScore();
        }
    }
    double result=0;
    if(obligatoryCredit>0)
        result+=0.6*obligatoryAchievement/obligatoryCredit;
    if(electiveNumber>0)
        result+=0.4*electiveAchievement/electiveNumber;
    return result;
}

