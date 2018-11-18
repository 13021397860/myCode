#pragma once
#include "stdafx.h"
#include<string>
using namespace std;
class Course
{
public:
	Course();
	string getName();
	void setName(string a);
	int getCredit();
	virtual int getScore() = 0;
	virtual void setCredit(int a);
	friend ostream& operator << (ostream&, Course&);
	~Course();
private:
	string name;
	int creditHour;
};

