#ifndef CONSOLE_H
#define CONSOLE_H

#include"Date.h"
#include"MyException.h"
#include"Student.h"
#include"Course.h"
#include"ObligatoryCourse.h"
#include"ElectiveCourse.h"
#include<iostream>
#include<fstream>
#include<iomanip>
#include<vector>
#include<windows.h>

using namespace std;

class Console {
public:
	Console();
	void initCourse();
	void run();

	void mainMenu();
	void Choose();
	void Remove();
	void SetGrade();
	void StudentCreate();
	void SaveFile();
	void commandCheck(int,int,int);


	virtual ~Console();

private:
	vector<Course*> courseList;
	Student *student;
};

#endif // CONSOLE_H
