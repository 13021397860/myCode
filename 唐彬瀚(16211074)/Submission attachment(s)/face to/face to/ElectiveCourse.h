#ifndef ELECTIVECOURSE_H
#define ELECTIVECOURSE_H
#include<iostream>
#include<cstring>
#include "Course.h"
using namespace std;
class ElectiveCourse: public Course
{
	public:
		ElectiveCourse();
		ElectiveCourse(string);
		~ElectiveCourse();
		void setGrade(const char);
		int const getGrade() const;
		int getScore();
		string getName();
		friend ostream& operator << (ostream &, ElectiveCourse &);
	private:
		char grade;
		string ename; 
};
#endif
