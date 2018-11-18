//Student.h
#ifndef STUDENT_H
#define STUDENT_H

#include"ElectiveCourse.h"
#include"ObligatoryCourse.h"
#include"Date.h"
#include"MyException.h"
#define MAX_SIZE 10000

class Student {
public:
	Student();
	Student(const char*,const Date);
	Student(const char*,const int,const int,const int);
	Student(const Student&);

	void setName(const char*);
	void setGrade(int);

	void getName(char*&);
	char* getName() const;
	int getCourseNumber() const;

	void getBirthDate(Date* &);
	Date getBirthDate() const;

	static int getCount();

	Student& addCourse(Course *course);
//	Student& addCourse(const string &courseName, int creditHour);

	bool removeCourse(int);
	void gradeCheck(int,int,int);
	void gradeCheck(char,char,char);

	//void print();

	friend ostream& operator<<(ostream&, const Student&);

	virtual ~Student();

	double calcCredit(double) const ;

private:
	static int count;
	char* name;
	const Date birthDate;
	Course* courseList[MAX_SIZE];
	int courseNumber;
};

#endif // STUDENT_H
