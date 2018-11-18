#ifndef OBLIGATORYCOURSE_H
#define OBLIGATORYCOURSE_H
#include "Course.h"
#include <iostream>
using namespace std;
class ObligatoryCourse:public Course
{
	public:
		ObligatoryCourse(const string &,int =0,int=0);
		void setmark(int);
		virtual int getScore();
	protected:
		int mark;
};

#endif
