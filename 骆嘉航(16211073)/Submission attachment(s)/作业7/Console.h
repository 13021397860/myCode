#ifndef CONSOLE_H
#define CONSOLE_H

#include <vector>
#include "Student.h"
#include "ObligatoryCourse.h"
#include "ElectiveCourse.h"
#include "Date.h"
#include "MyException.h"

class Console
{
	public:
		Console();
		virtual ~Console();
		int regist();
		int login();
		void createStudentList();
		void createOC();
		void createEC();
		void chooseCourse(Student&);
		void removeCourse(Student&);
		void showCL(Student&);
		void setGrade(Student&);
		void showGrade(Student&);
		void showGPA(Student&);
		void saveStudentList();
		void menu();
	private:
		vector <ObligatoryCourse> OCList;
		vector <ElectiveCourse> ECList;
		vector <Student> studentList; 
}; 

#endif
