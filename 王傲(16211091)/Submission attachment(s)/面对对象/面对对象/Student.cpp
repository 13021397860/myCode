#include "Student.h"
#include <iostream>
#include <cstring>
#include <typeinfo>
using namespace std;

int Student::count=0;

Student::Student(const char *studentName, int y, int m, int d) 
:birthDate(y, m, d)
{
    name=NULL;
    setName(studentName);
    count++;
}

Student::Student(const char *studentName, const Date &studentDate)
:birthDate(studentDate)
{
    name=NULL;
    setName(studentName);
	count++;	
}

Student::Student(const Student &stud)
:birthDate(stud.birthDate)
{
    name=NULL;
    setName(stud.name);
    count++;
}

Student &Student::setName(const char *studentName)
{
    if(studentName == NULL) delete[] studentName;
    name = new char[strlen(studentName)+1];
    strcpy(name, studentName);
    return *this;
}

ostream& operator <<(ostream& os,const Student& student)
{
	os<<"姓名："<<student.name<<" 出生日期：";
	os<<student.birthDate;
	os<<"选课信息如下："<<endl;
	for(int i=0;i<student.courseNumber;i++)
	{
		//student.courseList[i]->print();
		os<<*student.courseList[i];
	}
	return os;
}

Student::~Student()
{
	for (int i = 0; i < courseNumber; ++i)
		delete courseList[i];
	delete[] name;
	count--;
}
//退课 
bool Student::removeCourse(int i)
{
	if(i>courseNumber)
		return false;
	delete courseList[i-1];
	for (int t = i-1; t<courseNumber; ++t)
	{
		courseList[t]=courseList[t+1];
	}
	courseNumber--;
	return true;
}
//求和 
int Student::calcCredit()
{
	int re=0; 
	ObligatoryCourse o;
	ElectiveCourse e;
	for (int t = 0; t<courseNumber;t++)
	{
            if (typeid(*courseList[t]) == typeid(o))
            {
                ObligatoryCourse * p = dynamic_cast<ObligatoryCourse*>(courseList[t]);
                re+=p->getScore()*0.6;
            }
            else if (typeid(*courseList[t]) == typeid(e))
            {
                ElectiveCourse * p = dynamic_cast<ElectiveCourse*>(courseList[t]);
                re+=p->getScore()*0.4;
            }
	}
	return re;
}

