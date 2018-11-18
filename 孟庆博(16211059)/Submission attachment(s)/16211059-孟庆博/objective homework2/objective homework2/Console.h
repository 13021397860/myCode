#pragma once
#include "stdafx.h"
#include"Student.h"
#include"MyException.h"
#include"GradeException.h"
#include"DateException.h"
#include"Date.h"
#include"Student.h"
#include"Course.h"
#include"ElectiveCourse.h"
#include"ObligataryCourse.h"
#include<cstdio>
#include<iostream>
#include<fstream>
#define MAX_SIZE 10
using namespace std;

class Console
{
public:
	Console();
	int run();
	virtual ~Console();
private:
	int displayMenu()const;
	Course* selectCourse();
	bool setCourseScore(int n,int g);
	void judge1(int a);
	Console& buildStudent();
	Console& buildCourse();
	Student *a;
	Course *oc[MAX_SIZE];
	Course *ec[MAX_SIZE];
	int ocNum;
	int ecNum;
};

