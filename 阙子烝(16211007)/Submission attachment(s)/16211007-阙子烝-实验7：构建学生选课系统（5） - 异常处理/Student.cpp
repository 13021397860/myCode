#include <iostream>
#include <cstring>
#include <typeinfo>
#include "Student.h"
#include "Date.h"
#include "Course.h"
#include "ObligatoryCourse.h"
#include "ElectiveCourse.h"
const Date bDefault(1900,1,1); 
const char nDefault[200]="Faceless";
int Student::count=0;
//在.cpp中赋初始值
Student::Student(const char n[],const Date b):weight(0.6)
{
	if(n==NULL)
	{
		name=new char[1];
		name[0]='\0';
	}
	else
	{
		name=new char[strlen(n)+1];
		strcpy(name,n);
	}
	birthDate=b;
	courseNumber=0;
	++count;
}

Student::Student(const Student &s):weight(0.6)
{
	name=new char[strlen(s.name)+1];
	strcpy(name,s.name);
	birthDate=s.birthDate;
	courseNumber=s.courseNumber;
	for(int i=0;i<courseNumber;++i) 
	{
		courseList[i]=s.courseList[i];
	}
	++count;
}

Student::~Student()
{
	if(name!=NULL)
		delete []name;
	name=NULL;
	--count;
}

void Student::setName(const char n[])
{
	if(name!=NULL)
		delete []name;
	if(n==NULL)
	{
		name=new char[1];
		name[0]='\0';
	}
	else
	{
		name=new char[strlen(n)+1];
		strcpy(name,n);
	}
}

void Student::setBirthDate(const Date b)
{
	birthDate=b;
}

char* Student::getName()const
{
	return name;
}

const Date& Student::getBirthDate()const
{
	return birthDate;
}

Student& Student::addCourse(Course *course)
{
	if(courseNumber<MAX_SIZE && course!=NULL)
	{
		courseList[courseNumber]=course;
		++courseNumber;
	}
	else
	{
		std::cout<<"Error!\n";
	}
	return *this;
}

/*Student& Student::addCourse(const std::string &courseName, int creditHour)
{
	if(courseNumber<MAX_SIZE)
	{
		Course *p=new Course;
		p->setCourse(courseName,creditHour);
		courseList[courseNumber]=p;
		++courseNumber;
	}
	else
	{
		std::cout<<"Error!\n";
	}
	return *this;
}*/

std::ostream& operator<<(std::ostream& output,const Student& c)
{
	int i;
	output<<"姓名："<<c.getName()<<" 出生日期："<<c.getBirthDate()<<" 绩点："<<c.calcCredit()<<" ，选课信息如下：\n";
	for(i=0;i<c.courseNumber;++i)
	{
		output<<*c.courseList[i]<<'\n';
	}
	return output;
}

bool Student::removeCourse(int i)
{
	if(i>0 && courseNumber>=i)
	{
		int j;
		--courseNumber;
		--i; 
		for(j=0;j<courseNumber;++j)
			if(j>=i)
				courseList[j]=courseList[j+1];
		return true;
	}
	else
		return false;
}

bool Student::setGrade(int i,int grade)
{
	if(i>0 && courseNumber>=i)
	{
		(*courseList[i-1]).setScore(grade);
		return true;
	}
	else
		return false;
}

double Student::calcCredit()const
{
	double x=0,y=0,xc=0,yc=0,ans=0;
	int i;
	for(i=0;i<courseNumber;++i)
	{
		if(strcmp(typeid(*courseList[i]).name(),typeid(ObligatoryCourse).name())==0)
		{
			x+=courseList[i]->getScore()*courseList[i]->getCreditHour();
			xc+=courseList[i]->getCreditHour();
		}
		else if(strcmp(typeid(*courseList[i]).name(),typeid(ElectiveCourse).name())==0)
		{
			y+=courseList[i]->getScore()*courseList[i]->getCreditHour();
			yc+=courseList[i]->getCreditHour();
		}
	}
	if(xc)
		ans+=x*weight/xc;
	if(yc)
		ans+=y*(1.0-weight)/yc;
	return ans; 
}
