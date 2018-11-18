#pragma once
#ifndef STUDENT_H
#define STUDENT_H
#define MAX_SIZE 21

#include"Date.h"
#include"Course.h"
#include"ObligatoryCourse.h"
#include"ElectiveCourse.h"
#include<iomanip>

class Student
{
public:

	Student();
	Student( const char* const);
	Student(const char* const, const Date&);
	Student(const Student &);
	virtual ~Student();

	char* getName() { return name; }
	Date getDate() { return birthDate; }
	static int getCount() { return count; }
	int getCourseNumber() { return courseNumber; }
	double calcCredit(double, double)const;

	Student& setName(const char* const);
	Student& setDate(const Date const);
	Student& setCourseNumber(const int const);
	Student& addCourse(Course *);
	bool removeCourse(int);

	Course& operator [](int);
	friend ostream& operator<<(ostream &,const Student&);

protected:
	char* name;
	Date birthDate;
	static int count;
	Course *courseList[MAX_SIZE];
	int courseNumber;
};

#endif // !STUDENT_H;