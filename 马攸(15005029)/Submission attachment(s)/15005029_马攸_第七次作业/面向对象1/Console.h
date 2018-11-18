#ifndef CONSOLE_H
#define CONSOLE_H
#include<iostream>
#include "Date.h"
#include "Student.h"
#include "Course.h"
#include "ObligatoryCourse.h"
#include "ElectiveCourse.h"
#define MAX_SIZE 200
using namespace std;
class Console
{
	public:
		int run();
		Console();
		virtual ~Console();
	protected:
	private:
		int displayMenu() const;
		Course* selectCourse(int);
		bool setCourseScore();
		Console& buildStudent();
		Console& buildCourse();
		void printScore();
		void printCalcCredit();
		Student *student;
		Course *oc[MAX_SIZE];
		Course *ec[MAX_SIZE];
		int ocNum;
		int ecNum;
};

#endif
