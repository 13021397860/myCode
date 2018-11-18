#ifndef MYEXPECTION_H
#define MYEXPECTION_H
#include <iostream>
#include "Student.h"
#include "Date.h"
#include "ObligatoryCourse.h"
#include "Course.h"#include "ElectiveCourse.h"
#include "Console.h"

class MyExpection
{
	public:
		MyExpection(char *);
		char * time(int,int,int);
		const char* what()const;
		char * biao(char );
		char *ograde(int );
		char *egrade(char );
		~MyExpection();
	protected:
		char *message;
};

#endif
