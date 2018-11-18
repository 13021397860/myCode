#ifndef CONSOLE_H
#define CONSOLE_H
#include "Student.h"
#include "Course.h"
#include "ObligatoryCourse.h"
#include "ElectiveCourse.h"
#include "Date.h"

class Console
{
	public:
		Console();
		int run();
		~Console();
	protected:
	private:
		static int num;
};

#endif
