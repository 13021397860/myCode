#ifndef OBLIGATORYCOURSE_H
#define OBLIGATORYCOURSE_H
#include "Course.h"

class ObligatoryCourse: public Course
{
	public:
		//ObligatoryCourse(int = 1);
		//~ObligatoryCourse();
	    void setScore(const int );
		int getScore() const;
		
	private:
		int mark;
};


#endif
