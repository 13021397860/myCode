#ifndef OBLIGATORYCOURSE_H
#define OBLIGATORYCOURSE_H
#include"Course.h"
#include <typeinfo>
class ObligatoryCourse:public Course
{
	public:
		ObligatoryCourse(string, int, int);
		int getScore() const	{return mark;}
		ObligatoryCourse & setmark(int ) ;
		~ObligatoryCourse();
	private:
		int mark;
};
#endif
