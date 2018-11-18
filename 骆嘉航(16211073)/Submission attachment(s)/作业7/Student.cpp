#include <iostream>
#include <cstring>
#include <vector>
#include <typeinfo>
#include "Date.h"
#include "Student.h"
#include "Course.h"
#include "ObligatoryCourse.h"
#include "ElectiveCourse.h"

using namespace std;

int Student::count=0;

Student::Student():BirthDate()
{
	name=NULL;
	set_name("NULL");
	count++;
}

Student::Student(const char* const x,const Date &y):BirthDate(y)
{
	name=NULL;
	set_name(x);
	count++;
}

Student::Student(const char* const x,const int &i,const int &j,const int &k):BirthDate(i,j,k)
{
	name=NULL;
	set_name(x);
	count++;
}

Student::Student(const Student &t):BirthDate(t.BirthDate)
{
	name=NULL;
	set_name(t.name);
	count++;
}

Student::~Student()
{
	delete []name;
	count--;
}

char* Student::get_name()const
{
	return name;
}

Date Student::get_date()const
{
	return BirthDate;
}

void Student::set_name(const char* const x)
{
	if(name)
		delete []name;
	name=new char[strlen(x)+1];
	strcpy(name,x);
}

int Student::get_count()
{
	return count;
}

Student& Student::addCourse(Course *course)
{
	courseList.push_back(course);
	return *this;
}

int Student::getCourseCounter()const
{
	return courseList.size();
}

Course* Student::getCourse(const int &x)const
{
	return courseList[x];
}

ostream& operator << (ostream& output,Student &x)
{
	output << "姓名:" << x.get_name() << " 出生日期:" << x.BirthDate << "，选课信息如下:" << endl;
	for(int i=0;i<x.getCourseCounter();i++)
		output << x.courseList[i] <<endl;
	return output;
}

void Student::removeCourse(const int &x)
{
	if(x>courseList.size()||x<0)
		throw MyException();
	vector<Course*>::iterator res= courseList.begin(); 
	for(int i=2;i<=x;i++)
		res++;
	courseList.erase(res);
} 

bool Student::checkOC(const int &x)
{
	if(x>=courseList.size()||x<0)
		throw MyException();
	if(typeid(*courseList[x])==typeid(ObligatoryCourse))
		return 1;
	return 0;
}

double Student::calcGrade()
{
	double OCCredit=0;
	double ECCredit=0;
	double sumOC=0;
	double sumEC=0;
	for(int i=0;i<courseList.size();i++)	
		if(checkOC(i))
		{
			OCCredit+=courseList[i]->getCreditHour();
			sumOC+=courseList[i]->getCreditHour()*courseList[i]->getScore();
		}
		else
		{
			ECCredit++;
			sumEC+=courseList[i]->getScore();
		}
	return 0.6*sumOC/OCCredit+0.4*sumEC/ECCredit;
}
