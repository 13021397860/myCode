#ifndef CONSOLE_H
#define CONSOLE_H

#include "Student.h"
#include "Date.h"
#include "ObligatoryCourse.h"
#include "ElectiveCourse.h"

#define ecMax 10
#define ocMax 10

class Console
{
	public:
		Console();
		virtual ~Console();
		
		int initConsole();
		int saveStudent(Student &);
		
		int run();
		
		int ObligatoryCourseElect(Student &);
		int ElectiveCourseElect(Student &);
		int CourseRemove(Student &);
		int setCourseMark(Student &);
		
		
	protected:
		ObligatoryCourse oc[ocMax];
		ElectiveCourse ec[ecMax];
		int ocn;
		int ecn;
};

#endif
