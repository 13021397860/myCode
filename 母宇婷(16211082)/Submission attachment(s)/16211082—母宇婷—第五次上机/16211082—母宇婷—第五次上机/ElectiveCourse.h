#ifndef ELECTIVECOURSE_H
#define ELECTIVECOURSE_H
#include <iostream>
#include <string.h>
#include "Course.h"

using namespace std;

class ElectiveCourse : public Course
{
	friend ostream &operator<<(ostream &,const ElectiveCourse&);
	public:
		ElectiveCourse(string,int,char);
		const int getScore()const;
		const double getWeight()const;
		ElectiveCourse(const ElectiveCourse &ec)
			:Course(ec),grade(ec.grade){}
		~ElectiveCourse();
	protected:
	private:
		char grade;
};

#endif
