#include<iostream>
#include<cstring>
#include "Date.h"
#include "Student.h"
#include "ObligatoryCourse.h"
#include "ElectiveCourse.h"
#include "MyException.h"
#include<typeinfo>
using namespace std;
int Student::count=0;
Student::Student(const char* const n,int y,int m,int d)
{
	name=new char[strlen(n)+1];
	strcpy(name,n);
	birthDate.setDate(y,m,d);
	count++;
	courseNumber=0;
}

Student::Student(const Student&t)
{
	name=new char[strlen(t.name)+1];
	strcpy(name,t.name);
	birthDate=t.birthDate;
	count++;
}
Student::~Student()
{
	int i=courseNumber-1;
	while(i>0)
	{
		if(removeCourse(i)==true)
		{
			i--;
		}
	}
	delete []name;
	count--;
}
char* Student::getname()
{
	return name;
}
Date Student::getbirthDate()
{
	return birthDate;
} 
int Student::getcount()
{
	return count;
}
int Student::getCourseNumber()
{
	return courseNumber;
}
void Student::setname(const char* n)
{
	if(name) delete[] name;
	name=new char[strlen(n)+1];
	strcpy(name,n);
}
Student& Student::addCourse(Course *course)
{
	courseList[courseNumber]=course;
	courseNumber++;
}
ostream& operator<<(ostream& output,Student& c)
{
	output<<"姓名:"<<c.getname()<<" "<<"出生日期:"<<c.getbirthDate()<<"选课信息如下:"<<endl;
	for(int i=0;i<=c.courseNumber-1;i++)
	{
		output<<*(c.courseList[i]);
	}
	return output;
}
bool Student::removeCourse(int i)
{
	if(i<courseNumber)
	{
		delete courseList[i];
		for(int j=i;j<courseNumber-1;j++)
		{
			courseList[j]=courseList[j+1];
		}
		courseNumber--;
		return true;
	}
	else
	{
		return false;
	}
}
Course& Student::operator[](int i)
{
	if(i<0||i>=courseNumber)
	{
		/*cerr<<"下标越界："<<i<<endl;
		exit(1);*/
		throw MyException(RANGE_ERROR);
	}
	return (*courseList[i]);
}
double Student::getCalcCredit()
{
	int bixiuzongxuefen=0,xuanxiushuliang=0;
	for(int i=0;i<=courseNumber-1;i++)
	{
		if(typeid(ObligatoryCourse)==typeid(*courseList[i]))
		{
			bixiuzongxuefen=bixiuzongxuefen+(*courseList[i]).getCreditHour();
		}
		else if(typeid(ElectiveCourse)==typeid(*courseList[i]))
		{
			xuanxiushuliang++;
		}
	}
	double sum,sum1=0,sum2=0;
	for(int i=0;i<=courseNumber-1;i++)
	{
		if(typeid(ObligatoryCourse)==typeid(*courseList[i]))
		{
			sum1=sum1+(double)((*courseList[i]).getScore()*(*courseList[i]).getCreditHour())/bixiuzongxuefen;
		}
		else if(typeid(ElectiveCourse)==typeid(*courseList[i]))
		{
			sum2=sum2+(double)(*courseList[i]).getScore()/xuanxiushuliang;
		}
	}
	sum=sum1*0.6+sum2*0.4;
	return sum;
	
}


