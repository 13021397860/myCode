#pragma warning(disable:4996)
#include "student.h"
#include"MyException.h"
#include"ObligatoryCourse.h"
#include<string>
#include<iostream>
using std::cout;

int stu::count = 0;

stu::stu()
{
	len = 4;
	name = new char[len + 1];
	std::strcpy(name, "NNNN");
	count++;
	date tmp(2011, 1, 1);
	birthDate = tmp;
	coursenumber = 0;
}

stu::stu(const char *s, date &d):birthDate(d)
{
	len = std::strlen(s);
	name = new char[len + 1];
	std::strcpy(name, s);
	count++;
	coursenumber = 0;
}

stu::stu(const char *s, int y, int m, int d) :birthDate(y, m, d)
{
	len = std::strlen(s);
	name = new char[len + 1];
	std::strcpy(name, s);
	count++;
	coursenumber = 0;
}

stu::stu(const stu &s)
{
	len = s.len;
	name = new char[len + 1];
	std::strcpy(name, s.name);
	count++;
	birthDate = s.birthDate;
	coursenumber = 0;
}

stu::stu(const std::string s, date &d) :birthDate(d)
{
	len = s.size();
	name = new char[len + 1];
	std::strcpy(name, s.c_str());
	count++;
	coursenumber = 0;
}

stu::~stu()
{
	count--;
	delete []name;
}

void stu::setname(const char *s)
{
	len = std::strlen(s);
	delete[]name;
	name = new char[len + 1];
	std::strcpy(name, s);
}

stu& stu::addcourse(course *cour)
{
	courselist[coursenumber++] = cour;
	return *this;
}
/*
stu& stu::addcourse(const string &courseName, int creditHour)
{
	course tmp(courseName, creditHour);
	courselist[coursenumber++] = &tmp;
	return *this;
}
*/
void stu::removecourse(int i)
{
	if (i > coursenumber || i < 1)
		throw bad_doman();
	for (int j = i; j < coursenumber; ++j)
	{
		courselist[j - 1] = courselist[j];
	}
	coursenumber--;
}

void stu::showcourse() const
{
	for (int i = 0; i < coursenumber; ++i)
	{
		cout << i + 1 << "." << *(courselist[i]) << "\n";
	}
}
/*
void stu::showcoursead() const
{
	for (int i = 0; i < coursenumber; ++i)
	{
		cout << i + 1 << "." << *(courselist[i]) <<"      成绩：";
		if ((*(courselist[i])).getscore() == -1)
			cout << "暂未设置\n";
		else
			cout << (*(courselist[i])).getscore() << "\n";
	}
}
*/
std::ostream & operator<<(std::ostream & os,const stu &s)
{
	os << "姓名：" << s.name << "     出生日期：" << s.birthDate << "选课信息如下" << "\n";
	for (int i = 0; i < s.coursenumber; ++i)
	{
		os << i + 1 << "." << (course &)(*(s.courselist[i])) << "\n";
	}
	return os;
}

double stu::calccredit() const
{
	int bxxf = 0, xxms = 0;
	double ans = 0;
	for (int i = 0; i < coursenumber; ++i)
	{
		if (courselist[i]->getscore() != -1)
		{
			if (courselist[i]->type())
				bxxf += courselist[i]->getch();
			else
				++xxms;
		}
	}
	for (int i = 0; i < coursenumber; ++i)
	{
		if (courselist[i]->getscore() != -1)
		{
			if (courselist[i]->type())
				ans += 0.6*(double)(courselist[i]->getscore()*courselist[i]->getch()) / (double)(bxxf);
			else
				ans += 0.4*(double)(courselist[i]->getscore()) / (double)(xxms);
		}
	}
	return ans;
}