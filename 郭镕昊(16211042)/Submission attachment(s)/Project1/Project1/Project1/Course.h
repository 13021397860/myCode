#pragma once

#ifndef COURSE_H
#define COURSE_H

#include<string>
#include<iostream>
using namespace std;

class Course
{
	friend ostream & operator <<(ostream & output, const Course & c);
	
public:
	Course(const string &n = "", int h = 0);
	Course(const Course &a);
	virtual ~Course();

	void setCreditHour(int h) {
		creditHour = h;
	}
	void setName(const string &n) {
		name = n;
	}

	int getCreditHour() const {
		return creditHour;
	}
	const string& getName() const {
		return name;
	}
	virtual int getScore() const = 0;
	///*Èç¹û¶àÌ¬£º
	virtual int getElectiveCredit() const = 0;
	virtual int getObligatoryNumber() const = 0;
	//*/
protected:
	string name;
	int creditHour;
};

#endif // ! COURSE_H
