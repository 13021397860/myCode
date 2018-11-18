#ifndef OBLIGATORYCOURSE_H
#define OBLIGATORYCOURSE_H
#include<iostream>
#include<cstring>
#include "Course.h"
class ObligatoryCourse: public Course
{
	public:
		ObligatoryCourse();
		ObligatoryCourse(string);
		~ObligatoryCourse();
		void setMark(const int);
		int getScore();
		string getName();
		friend ostream& operator << (ostream &, ObligatoryCourse &);
	private:
		int mark;
		string oname;
 };
#endif
