#pragma once
#ifndef _ObligatoryCourse_
#define _ObligatoryCourse_


#include"Course.h"
#include<string>
using namespace std;

class ObligatoryCourse :public Course {
public:
	ObligatoryCourse(string _name, int creditHour);
	~ObligatoryCourse();
	void setScore(int);
	int getScore(void)const;
protected:
private:
	int score;
};

#endif // !_ObligatoryCourse_

