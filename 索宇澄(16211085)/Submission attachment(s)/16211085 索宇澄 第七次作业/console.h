#include<iostream>
#include<cstring>
#include <typeinfo>
#include"date.h"
#include"student.h"
#include"Course.h"
#include"ObligatoryCourse.h"
#include"ElectiveCourse.h"
#include"DateException.h"
#include"CourseException.h"
#include"MyException.h"
#include"ArrException.h"
using namespace std;
#ifndef CONSOLE_H
#define CONSOLE_H

class Console
{
	public:
		void go();
	private:
		Course *obligatoryCourse[5];
		Course *electiveCourse[5];
};
#endif
