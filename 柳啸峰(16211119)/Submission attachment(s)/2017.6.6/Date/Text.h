#ifndef TEXT_H
#define TEXT_H
#include <iostream>
#include <iomanip>
#include "Date.h"
#include "Students.h"
#include "Course.h"
#include "ObligatoryCourse.h"
#include "ElectiveCourse.h" 
#include <cstdio>
#include "MyException.h"
class Text
{
	public:
		Text(); 
		void run();
		~Text();
};

#endif
