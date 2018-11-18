#ifndef STUDENT_H
#define STUDENT_H
#include "Date.h"
#include "student.h"
#include "Course.h"
#include "ElectiveCourse.h"
#include "ObligatoryCourse.h"
#include <iostream>
#include <fstream>
#include <iterator>
#include <string>
#include <vector>
#define MAX_SIZE 20
using namespace std;
class student
{
	public:
		student();
		void setname(char *);
		bool setdate(int,int,int);
		char* getname();
		Date getDate();
		int getYear();
		int getMonth();
		int getDay();
		int getcount();
		student& addCourse(Course*);
		string getCourseName(int);
		int getCourseHour(int);
		int getCourseNumber();
		Course* getCourse(int);
		bool removeCourse(int i);
		int getmark(int);
		int calcCredit();
		void setJudgeCourse(int);
		void delStudentData();
	private:
		char *name;
		Date t;
		Course* courseList[MAX_SIZE];
		int judgeCourse[MAX_SIZE];
	static int courseNumber;
	static int count;
};
#endif

