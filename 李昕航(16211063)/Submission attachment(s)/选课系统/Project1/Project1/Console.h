#pragma once
#ifndef CONSOLE_H
#define CONSOLE_H
#include"Student.h"
#include<fstream>

class Console
{
public:
	Console();
	virtual ~Console();

	static bool student();
	static int printGUI();
	static bool selectCourse(Student&);
	static bool removeCourse(Student&);
	static bool setCourseGrade(Student&);

protected:
	static ObligatoryCourse* OC[500];
	static ElectiveCourse* EC[500];
	int OCnum;
	int ECnum;
};

#endif // !Console_H;

