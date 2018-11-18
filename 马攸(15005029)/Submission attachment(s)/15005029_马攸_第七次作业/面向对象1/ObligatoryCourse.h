#ifndef OBLIGATORYCOURSE_H
#define OBLIGATORYCOURSE_H
#include "Course.h"

class ObligatoryCourse : public Course
{
	public:
		ObligatoryCourse(const string &,const int &);
		bool setMark(int); 
		virtual int getScore() const;
		~ObligatoryCourse();
	protected:
	private:
		int Mark;
		
};

#endif
