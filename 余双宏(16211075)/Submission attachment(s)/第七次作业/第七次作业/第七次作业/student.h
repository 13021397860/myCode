#include"date.h"
#include"course.h"
#include<string>
#include<iostream>
#define MAXSIZE 20
#ifndef STUDENT_H_
#define STUDENT_H_
class stu
{

private:
	char *name;
	int len;
	date birthDate;
	course * courselist[MAXSIZE];
	int coursenumber;
	static int count;
public:
	stu();
	stu(const char *s,date &d);
	stu(const char *s, int y, int m, int d);
	stu(const stu &s);
	stu(const std::string s, date &d);
	~stu();
	char *getname() const { return name; }
	const int& getlen() const{ return len; }
	const date &getbirth() const{ return birthDate; }
	void setname(const char * const s);
	void setbirthDate(const date &d) { birthDate = d; }
	void setbirthDate(int y, int m, int d) { date tmp(y, m, d); birthDate = tmp; }
	int getcount() const { return count; }
	int getcoursenum()const { return coursenumber; }
	stu& addcourse(course *cour);
	//stu& addcourse(const string &courseName, int creditHour);
	void removecourse(int i);
	course *getcourse(int i) { return courselist[i]; }
	void showcourse() const;
	void showcoursead() const;
	friend std::ostream & operator<<(std::ostream &os,const stu &s);
	double calccredit() const;
};
#endif