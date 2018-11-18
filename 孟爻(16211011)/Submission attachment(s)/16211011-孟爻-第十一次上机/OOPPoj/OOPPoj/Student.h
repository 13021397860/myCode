#pragma once
#ifndef _STUDENT_H_
#define _STUDENT_H_

#include"Date.h"
#include"Course.h"
#include"ObligatoryCourse.h"
#include"ElectiveCourse.h"

#define MAX_SIZE 100
#include<iostream>
using namespace std;
class Student {
public:
	Student(const char *n, Date *bd);
	~Student();
	Student(const Student &stu);
	void SetName(const char *n);
	char* GetName(void);
	void SetBirthday(Date *bd);
	Date* GetBirthday(void);
	static int GetCount(void);
	int getCourseCount(void);
	Student& addCourse(Course *);
	friend ostream& operator<<(ostream&, Student&);
	bool removeCourse(int);
	bool setScore(int, int);
	bool setScore(int, char);
	float calcCredit(void);
	//string getCourseTAG(int);
protected:
private:
	char *name;
	Date *birthDate;
	static int count;
	Course *courseList[MAX_SIZE];
	int courseNumber;
};

#endif // !_STUDENT_H_
