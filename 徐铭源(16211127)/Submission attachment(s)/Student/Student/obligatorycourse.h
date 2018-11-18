#ifndef OBLIGATORY_H
#define OBLIGATORY_H
#include "Course.h"
class ObligatoryCourse:private Course
{
	public:
			ObligatoryCourse();
			ObligatoryCourse(const string tname,const int tcreditHour);
			void setMark(const int _mark);
			int getMark();
	protected:
	private:
			int mark;//³É¼¨ 
};

#endif
