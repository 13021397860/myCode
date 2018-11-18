#ifndef OBLIGATORYCOURSE_H
#define OBLIGATORYCOURSE_H

#include "Course.h"

class ObligatoryCourse : public Course
{
	public:
		ObligatoryCourse();
		ObligatoryCourse(const string &,const int &,const int &);
		~ObligatoryCourse();
		
		void setMark(const int &);
		int getScore()const;
	private:
		int mark;
};

#endif
