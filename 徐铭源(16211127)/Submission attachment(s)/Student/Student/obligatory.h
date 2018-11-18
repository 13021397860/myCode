#ifndef ELECTIVECOURSE_H
#define ELECTIVECOURSE_H
#include "Course.h"
class OblicatoryCourse:private Course
{
	public: 
			OblicatoryCourse();
			OblicatoryCourse(const string tname,const int tcreditHour);
	        void setGrade(const char _grade);
		    int getmark(); 
	protected:
		    
	private:
			char mark;//³É¼¨ £¨A£¬B£© 
};
#endif
