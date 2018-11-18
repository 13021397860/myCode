#ifndef COURSE_H
#define COURSE_H
#include <string>
#include <iostream>
using namespace std;
#define  _CRT_SECURE_NO_WARNINGS

class Course
{
public:
	friend ostream& operator<<(ostream& o,const Course& c);
    Course(const string& n, int h) {
		courseName = n;
		creditHour = h;
	}
	virtual ~Course() {}

	string getCname() const
	{
		return courseName;
	}
	void setName(string name)
	{
		courseName = name;
	}
	int getCreditHour()const{
		return creditHour;
	}
	void setCreditHour(int CreditHour) {

	}

	virtual int getScore()const =0;
	int type;//1Îª±ØÐÞ
protected:

	int creditHour;
	string courseName;
private:


};

#endif // COURSE_H
