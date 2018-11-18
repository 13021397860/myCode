#ifndef OBLIGATORY_H
#define OBLIGATORY_H

#include "course.h"

class ObligatoryCourse : public Course
{
	public:
		ObligatoryCourse(string, int, int);
		
		ObligatoryCourse &setMark(const int);
		int getScore() const;
		
		~ObligatoryCourse();
		
	protected:
		
	private:
		int mark;
		
};

#endif
