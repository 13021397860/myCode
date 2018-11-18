#ifndef OBLIGATORY_H
#define OBLIGATORY_H

#include "Course.h"

class ObligatoryCourse : public Course
{
	public:
		ObligatoryCourse(string, int, int);
		
		ObligatoryCourse &setMark(const int);
		int getScore() const	{return mark;}
		
		~ObligatoryCourse();
		
	protected:
		
	private:
		int mark;
		
};

#endif
