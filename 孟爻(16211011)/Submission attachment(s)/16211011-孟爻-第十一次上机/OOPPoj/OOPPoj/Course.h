#pragma once
#ifndef _Course_
#define _Course_


#include<string>
#include<iostream>
using namespace std;

class Course {
public:
	Course(string,int);
	virtual ~Course();
	string getName(void)const;
	int getCreditHour(void)const;
	void setName(string);
	void setCreditHour(int);
	virtual void setScore(int);
	virtual void setScore(char);
	virtual int getScore(void)const=0;
	friend ostream& operator<<(ostream&,Course&);
	//string getTAG(void);
protected:
	string name;
	int creditHour;
	//string TAG;
private:
};

#endif // !_Course_
