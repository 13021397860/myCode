#ifndef ELECTIVECOURSE_H
#define ELECTIVECOURSE_H
#include "Course.h"
#include <iostream>
using namespace std;
class ElectiveCourse:public Course
{
	public:
		ElectiveCourse(const string & ,int=0,char='F');
		void setgrade(char);
		virtual int getScore();		
	protected:
		char grade;
};

#endif
