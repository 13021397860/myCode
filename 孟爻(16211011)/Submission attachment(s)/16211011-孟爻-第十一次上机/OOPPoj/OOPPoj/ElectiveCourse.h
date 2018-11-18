#pragma once
#ifndef _ElectiveCourse_
#define _ElectiveCourse_


#include"Course.h"
#include<string>
using namespace std;

class ElectiveCourse:public Course{
public:
	ElectiveCourse(string, int);
	~ElectiveCourse();
	int getScore(void)const;
	void setScore(char);
protected:
private:
	char grade;
};

#endif // !_ElectiveCourse_
