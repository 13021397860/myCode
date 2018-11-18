#pragma once
#ifndef COURSE_H
#define COURSE_H

#include"MyException.h"
#include<string>
#include<iostream>
using namespace std;

class Course
{
public:
	Course();
	Course(string, int);
	~Course();

	int getCreditHour() const;
	string getName() const;
	virtual int getScore() const=0 { return 0; }

	void setCreditHour(int);
	void setName(string);
	virtual void setGrade() {}

	friend ostream& operator<<(ostream &,const Course&);

protected:
	string name;
	int creditHour;
};

#endif // !COURSE_H;

