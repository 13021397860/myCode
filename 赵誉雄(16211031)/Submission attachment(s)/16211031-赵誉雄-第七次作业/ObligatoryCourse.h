#ifndef OBLIGATORYCOURSE_H
#define OBLIGATORYCOURSE_H

#include "Course.h"

class ObligatoryCourse : public Course
{
	public:
		ObligatoryCourse();
		ObligatoryCourse(const string,const int);
		void setScore(const int);
		virtual int getScore() const;
		virtual int O_credit() const;
		virtual int if_E() const;
	protected:
	private:
		int mark;
};

#endif
