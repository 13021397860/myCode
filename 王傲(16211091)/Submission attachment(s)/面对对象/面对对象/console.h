#ifndef CONSOLE_H
#define CONSOLE_H
#include "Date.h"
#include "Student.h"
#include "course.h"
#include "obligatoryCourse.h"
#include "electiveCourse.h"
#include <iostream>
#include <typeinfo>
#include "DateException.h"
#include "MyException.h"
#include "SetException.h"
#include "ArrException.h"
using namespace std;
class Console
{
	public:
		void run();
		void show();
};

#endif
