#include "student.h"
#include "course.h"
#ifndef CONSOLE_H
#define CONSOLE_H

class Console{
	public:
		int run();
		Console();
        ~Console();
       void setCourseGrade(Student &);
    private:
		Course *obligatoryCourse[5];
		Course *electiveCourse[5];
    
};

#endif
