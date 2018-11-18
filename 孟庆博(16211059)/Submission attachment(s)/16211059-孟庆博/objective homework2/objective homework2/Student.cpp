#include "stdafx.h"
#include "Student.h"
#include"Date.h"
#include"DateException.h"
#include<typeinfo>
#include<string>


int Student::count = 0;
Student::Student()
{
	name = new char[15];
	Etimes = 0;
	Ohour = 0;
}
Student::Student(const Student& a)
{
	name= a.name;
	birthDate=a.birthDate;
}
void Student::setName(char* const &p)
{
	strcpy_s(name, strlen(p) + 1, p);
}
int Student::getCount()const
{
	return count;
}
Student& Student::addCourse(Course *course)
{
	courseList[++courseNumber] = course;
	if (typeid(ObligataryCourse) == typeid(*courseList[courseNumber]))
	{
		Ohour += courseList[courseNumber]->getCredit();
	}
	else
	{
		Etimes++;
	}
	return *this;
}
void Student::setGrade(int i,int gra)
{
	ArrayException gg;
	if (i > courseNumber||i<1)
		throw gg;
	if (typeid(ObligataryCourse) == typeid(*courseList[i]))
	{
		ObligataryCourse *m = (ObligataryCourse*)courseList[i];
		m->setGrade(gra);
	}
	else if(typeid(ElectiveCourse) == typeid(*courseList[i]))
	{
		ElectiveCourse *m = (ElectiveCourse*)courseList[i];
		m->setGrade(gra);
	}
}
bool Student::nowCourse(int i)
{
	if (typeid(ObligataryCourse) == typeid(*courseList[i]))
	{
		return 1;
	}
	else if (typeid(ElectiveCourse) == typeid(*courseList[i]))
	{
		return 0;
	}
	return 0;
}
bool Student::removeCourse(int i)
{
	if (i > courseNumber)
		return false;
	if (typeid(ObligataryCourse) == typeid(*courseList[i]))
	{
		Ohour -= courseList[i]->getCredit();
	}
	else
	{
		Etimes --;
	}
	while (i<courseNumber)
	{
		courseList[i] = courseList[i + 1];
		i++;
	}
	courseList[i]=NULL;
	courseNumber--;
	return true;
}
void Student::printCourse()
{
	for (int i = 1; i <= courseNumber; i++)
	{
		cout << courseList[i]->getName() << endl;
	}
}
void Student::setBirth(const int & y, const int & m, const int & d)
{
	DateException gg;
	if (!birthDate.setDate(y, m, d))
		throw gg;
}
char* Student::getName()const
{
	return name;
}
int Student::getBirth(const char c)const
{
	return birthDate.getDate(c);
}
Student::~Student()
{
	int i = courseNumber - 1;
	while (i>0)
	{
		if (removeCourse(i))i--;
	}
	count--;
	delete []name;
}

void Student::calcCredit()
{
	GA = 0;
	for (int i = 1; i <= courseNumber; i++)
	{
		if (typeid(ObligataryCourse) == typeid(*courseList[i]))
		{
			double a(0);
			a =0.6 *courseList[i]->getCredit();
			GA += courseList[i]->getScore()*(a/ Ohour);
		}
		else
		{
			GA += courseList[i]->getScore()*(0.4/ Etimes);
		}
	}
}

ostream & operator<<(ostream &output, Student &c)
{
	if (c.courseNumber == 0)
	{
		output << "你都没选\n";
		return output;
	}
	output << "姓名：" << c.name << " 出生日期：" << c.birthDate << ".选课信息如下：\n";
	for (int i = 1; i <= c.courseNumber; i++)
	{
		cout << *c.courseList[i] << "      成绩：" << c.courseList[i]->getScore() << endl;
	}
	c.calcCredit();
	cout << "您的绩点成绩为： " << c.GA << endl;
	return output;
}

ofstream & operator<<(ofstream &f1, Student &c)
{
	f1 << "姓名：" << c.name << " 出生日期：" << c.birthDate << ".选课信息如下：\n";
	for (int i = 1; i <= c.courseNumber; i++)
	{
		f1 << *c.courseList[i] << "      成绩：" << c.courseList[i]->getScore() << endl;
	}
	c.calcCredit();
	f1 << "您的绩点成绩为： " << c.GA << endl;
	return f1;
}
