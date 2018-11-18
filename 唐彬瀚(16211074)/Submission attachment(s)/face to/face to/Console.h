#ifndef CONSOLE_H
#define CONSOLE_H
#include<iostream>
#include<cstring>
#include"Date.h"
#include "ObligatoryCourse.h"
#include "ElectiveCourse.h"
#include"Course.h"
#include"Student.h"
using namespace std;
class Console
{
	public:
		Console();
		Student initi();
		void select(Student &);
		void remove(Student &);
		void check(Student &);
		void load();
		void getList(Student &);
		void setcredit();
		int credit();
		void save(Student &); 
	private:
		ElectiveCourse *e[4];
		ObligatoryCourse *o[4];
		int credit_[20];
		int sum;
		int snumber;
		Student sl[10];
};
#endif
