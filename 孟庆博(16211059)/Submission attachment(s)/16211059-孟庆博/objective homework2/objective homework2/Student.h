#pragma once
#include "stdafx.h"
#include<iostream>
#include"Date.h"
#include"Course.h"
#include"ObligataryCourse.h"
#include"DateException.h"
#include"ElectiveCourse.h"
#include"ArrayException.h"
#include<typeinfo>
#include<fstream>
#define MAX_SIZE 10
using namespace std;
class Student
{
public:
	Student();
	Student(const Student&);
	void setName(char* const &p);
	void setBirth(const int &y, const int &m, const int &d);
	char* getName()const;
	int getBirth(const char)const;
	int getCount()const;
	Student & addCourse(Course * course);
	void setGrade(int i, int gra);
	bool nowCourse(int i);
	bool removeCourse(int i);
	friend ostream& operator << (ostream&, Student&);
	friend ofstream& operator<< (ofstream&, Student&);
	void printCourse();
	virtual ~Student();
private:
	char *name;
	static int count;
	int courseNumber;
	Date birthDate;
	Course *courseList[MAX_SIZE+1];
	double GA;
	int Ohour;
	int Etimes;
	void calcCredit();
};

