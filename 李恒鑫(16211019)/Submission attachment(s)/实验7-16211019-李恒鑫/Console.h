#ifndef CONSOLE_H
#define CONSOLE_H
#include <iostream>
#include <cstring>
#include "Date.h"
#include "student.h"
#include "Course.h"
#include "ElectiveCourse.h"
#include "ObligatoryCourse.h"
#include "MyException.h"
class Console
{
	public:
		Console();
		void run();
		
		
	protected:
	private:
		void displayMenu1() ;
		void displayMenu2() ;
	 	void selectCourse(int);
		bool setCourseScore();
		void buildStudent();
		void buildCourse();
		void PrintStudent();
		void PrintCourse();
		void getRTTI();
		void showCourseFile();
		void writeStudentFile();
		int CinCheck();
		int CinCheck2();
		void FileClear();
		
		student s1;
		MyException myException;
			
};

#endif
