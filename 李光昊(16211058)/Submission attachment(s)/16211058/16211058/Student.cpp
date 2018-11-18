#include "Student.h"
#include <iostream>
#include <iomanip>
#include <cstring>
#include <typeinfo>
#include "ObligatoryCourse.h"
#include "ElectiveCourse.h"
#include "MyException.h"
using namespace std;

int Student::count(0);

Student::Student()
:birthDate(1990,1,1)
{
	name=NULL;
	setname("someone");
	++count;
	courseNumber=-1;
	//cout<<"constructor  count="<<count<<"\n";
}

Student::Student(const char*const a, const Date &d)
:birthDate(d)
{
	name=NULL;
	setname(a);
	++count;
	courseNumber=-1;
	//cout<<"constructor  count="<<count<<"\n";
}

Student::Student(const char*const a,int y,int m,int d)
:birthDate(y,m,d)
{
	name=NULL;
	setname(a);
	++count;
	courseNumber=-1;
	//cout<<"constructor  count="<<count<<"\n";
}

Student::Student(const Student &s)
:birthDate(s.birthDate)
{
	name=NULL;
	setname(s.name);
	++count;
	//cout<<"constructor  count="<<count<<"\n";
}

Student::~Student()
{
	delete []name;
	while(courseNumber>-1)
	{
		removeCourse(1);
	}
	--count;
	//cout<<"destructor  count="<<count<<"\n";
}

const char*Student::getName()const
{
	return name;
}

void Student::getDate(int &y,int &m,int &d)
{
	y=birthDate.getYear();
	m=birthDate.getMonth();
	d=birthDate.getDay();
}

const Date& Student::getDate2()const
{
	return birthDate;
}

Student& Student::setname(const char *const a)
{
	if(name)delete[]name;
	name=new char [strlen(a)+1];
	strcpy(name,a);
	return *this;
}

//print
ostream &operator<<(ostream &output,const Student &s)
{
	output<<"姓名："<<s.getName()<<" 出生日期："<<s.getDate2()<<",选课信息如下：\n";
	if(s.getCourseNumber()==-1)output<<"暂无课程\n";
	else
	{
		for(int i=0;i<=s.getCourseNumber();i++)
		{
			output<<*s.getCourse(i)<<endl;
		}
	}
	return output;
}
void Student::print()const
{
	cout<<"姓名："<<name<<" 出生日期："<<birthDate<<",选课信息如下：\n";
}

void Student::printCourse2()const
{
	if(courseNumber==-1)cout<<"暂无课程\n";
	else
	{
		for(int i=0;i<=courseNumber;i++)
		{
			cout<<*courseList[i]<<endl;
		}
	}
}

bool Student::printCourse()const
{
	if(courseNumber==-1)
	{
		cout<<"暂无课程\n";
		return 0;
	}
	else
	{
		cout<<"课程数："<<courseNumber+1<<"\n";
		for(int i=0;i<=courseNumber;i++)
		{
			cout<<setw(3)<<left<<i+1<<*courseList[i]<<"\n";
		}
	}
	return 1;
}
//end print

int Student::getCourseNumber()const
{
	return courseNumber;
}

Student& Student::addCourse(Course *course)
{
	if(courseNumber<Maxsize-1)courseList[++courseNumber]=course;
	return *this;
}
/*
Student& Student::addCourse(const string &courseName, int creditHour)
{
	if(courseNumber<Maxsize-1)
	{
		courseList[++courseNumber]=new Course;
		courseList[courseNumber]->setName(courseName);
		courseList[courseNumber]->setCreditHour(creditHour);
	}
	return *this;
}
*/

Student& Student::initCourse(Course *acourselist[],int acoursenum)
{
	for(int i=0;i<=acoursenum;i++)
	{
		courseList[i]=acourselist[i];
	}
	courseNumber=acoursenum;
}

bool Student::courseFull()const
{
	return courseNumber>=Maxsize-1;
}

bool Student::removeCourse(int i)
{
	if(i<1||i>courseNumber+1)
	{
		throw MyException("下标越界！");
		return 0;
	}
	Course *c=courseList[i-1];
	for(int j=i-1;j<courseNumber;j++)
	{
		courseList[j]=courseList[j+1];
	}
	--courseNumber;
	delete c;
	return 1;
}

Course* Student::getCourse(int i)const//************
{
	if(i<1||i>courseNumber+1)
	{
		throw MyException("下标越界！");
		return NULL;
	}
	return courseList[i-1];
}

bool Student::setObligatoryCourseMark(int i,int j)
{
	if(i<1||i>courseNumber+1)return 0;
	//ObligatoryCourse *o=(*ObligatoryCourse)courseList[i-1];
	//o.setMark(j);
	return 1;
}

bool Student::setElectiveCourseMark(int i,char c)
{
	if(i<1||i>courseNumber+1)return 0;

	return 1;
}

double Student::calcCredit()const
{
	double sum=0;
	double occsum=0;
	int ecsum=0;
	for(int i=0;i<=courseNumber;i++)
	{
		if(typeid(*courseList[i])==typeid(ObligatoryCourse))
		{
			occsum+=courseList[i]->getCreditHour();
		}
		else
		{
			++ecsum;
		}
	}
	int sc;
	for(int i=0;i<=courseNumber;i++)
	{
		sc=courseList[i]->getScore();
		if(sc==-1)sc=0;

		if(typeid(*courseList[i])==typeid(ObligatoryCourse))
		{
			if(occsum)sum+=OCP*sc*(courseList[i]->getCreditHour())/occsum;
		}
		else
		{
			if(ecsum)sum+=(1-OCP)*sc/ecsum;
		}
	}
	return sum;
}

int Student::checkCourse(string s)
{
	for(int i=0;i<=courseNumber;i++)
	{
		if(courseList[i]->getName()==s)return 1;
	}
	return 0;
}
