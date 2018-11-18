#ifndef CONSOLE_H
#define CONSOLE_H
#include <string> 
#include "Student.h"
#include "Date.h"
#include "Course.h"
#include "ObligatoryCourse.h"
#include "ElectiveCourse.h"
class Console
{
	public:
		Console();
		~Console();
		void ops();
		
	protected:
		
	private:
		void op1();
		void op2();
		void op3();
		void op4();
		void op5();
		int get_uint();
		double get_udou();
		int cnum,i,t,cre,score;
		std::string clist;
		Date b;
		Student s;
		Course *p[1005];
};

#endif
