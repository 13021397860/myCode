#pragma once
#ifndef STUDENT_H
#define STUDENT_H

#define MAX_SIZE 20
#include"Course.h"
#include"Date.h"
#include"ObligatoryCourse.h"
#include"ElectiveCourse.h"

class Student
{
	friend ostream & operator <<(ostream &, const Student &s);
public:
	Student();
	Student(const char * const, const Date &);
	Student(const Student &);
	Student(const char *const _name, int y, int m, int d);
	virtual ~Student();

	Student& addCourse(Course *course);
	Student& addCourse(const string& n, int h);

	bool removeCourse(int i);
	bool removeCourse(const string &n);


	const Date& getbirthDate() const;
	const char* getname() const;
	
	void setname(const char * const a);
	void setbirthDate(const Date &a);

	bool print();//由于输出中存在对不合法日期的修改，没有加const。bool类型表示输出成功与否
	static int getcount();
	int getCourseNumber() {
		return courseNumber;
	}
	const Course & operator [](int index)const;
	Course & operator [](int index);
	const double getAchievement() const;
private:
	char *name;
	Date birthDate;
	static int count;

	int courseNumber;//, electiveNumber, obligatoryNumber;
	Course *courseList[MAX_SIZE];
};

#endif // !STUDENT_H
