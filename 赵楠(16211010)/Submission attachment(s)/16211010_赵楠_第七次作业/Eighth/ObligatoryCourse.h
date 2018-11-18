#ifndef OBLIGATORYCOURSE_H
#define OBLIGATORYCOURSE_H

#include "Course.h"

class ObligatoryCourse : public Course
{
	public:
		ObligatoryCourse(const string,const int,const int);
		virtual~ObligatoryCourse();
		void setMark(int);
		virtual void setScore(int);
		virtual int getScore()const;
	private:
		int mark;
};

#endif
