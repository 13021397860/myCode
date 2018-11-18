#ifndef OBLIGATORYCOURSE_H
#define OBLIGATORYCOURSE_H

#include "Course.h"
#include <cstring>

class ObligatoryCourse : public Course
{
	public:
		ObligatoryCourse();
		ObligatoryCourse(std::string,int);
		ObligatoryCourse(const ObligatoryCourse &o);
		virtual~ObligatoryCourse();
		
		ObligatoryCourse& setMark(int);
		virtual int getScore()const;
		
	protected:
		int mark;
};

#endif
